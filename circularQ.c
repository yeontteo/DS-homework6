/*
 * circularQ.c
 *
 * School of Computer Science, 
 * Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
   element queue[MAX_QUEUE_SIZE]; // Q 사이즈 = 4 (4칸)
   int front, rear; // front = 첫번째 데이터를 가리킨다, rear = 마지막 데이터를 가리킨다
}QueueType;


QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item); // insert
void deQueue(QueueType *cQ, element* item); // delete
void printQ(QueueType *cQ); // print
void debugQ(QueueType *cQ); // debug
element getElement(); // 입력

int main(void)
{
   QueueType *cQ = createQueue(); // Q 생성, front=rear=0
   element data;
   char command;


   do{
      printf("--------------- [남연서]   [2023041030] --------------\n");      
      printf("                     Circular Q                   \n");
      printf("------------------------------------------------------\n");
      printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
      printf("------------------------------------------------------\n");

      printf("Command = ");
      scanf(" %c", &command);

      switch(command) {
      case 'i': case 'I': // insert
         data = getElement();
         enQueue(cQ, data);
         break;
      case 'd': case 'D': // delete
         deQueue(cQ, &data);
         break;
      case 'p': case 'P': // print
         printQ(cQ);
         break;
      case 'b': case 'B': // debug
         debugQ(cQ);
         break;
      case 'q': case 'Q': // quit
              freeQueue(cQ);
         break;
      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');


   return 1;
}

QueueType *createQueue()
{
   QueueType *cQ;
   cQ = (QueueType *)malloc(sizeof(QueueType));
   cQ->front = 0;
   cQ->rear = 0;
   return cQ;
}

int freeQueue(QueueType *cQ)
{
    if(cQ == NULL) return 1;
    free(cQ);
    return 1;
}

element getElement()
{
   element item;
   printf("Input element = ");
   scanf(" %c", &item);
   return item;
}


/* 큐가 비어있는지 확인하는 함수 */
int isEmpty(QueueType *cQ)
{
   if (cQ->front==cQ->rear){ // rear와 front의 값이 같다면 큐가 비어있다는 뜻이다.      
      printf("Queue is empty!!!!!!!!!!!!!!!\n"); // 큐가 비어있다는 메세지를 출력한다.
      return 1; // 1 리턴
   }
   else{
      return 0; // rear와 front의 값이 같지 않다면 그대로 진행한다.
   }
}

/* 큐가 가득 차있는지 확인하는 함수 */
int isFull(QueueType *cQ)
{
   if((cQ->rear+1)%MAX_QUEUE_SIZE == cQ->front){ 
      // rear가 한 칸 앞으로 가기 전 rear+1을 한 값을 큐의 사이즈로 나눴을 때 front와 같은 값이면 큐가 가득 찬 것이다.
      printf("Queue is full.\n"); // 큐가 꽉 차 있다는 메세지를 출력한다.
      return 1; // 1리턴
   }
   else{ // 큐가 가득 찬 것이 아니라면 그대로 진행한다.
      return 0;
   }
}


/* 입력함수 */
void enQueue(QueueType *cQ, element item)
{
   if(isFull(cQ)) { // 큐가 가득 차있는지 확인하고, 가득 차있다면 함수를 종료한다.
      return;
   } 
   else {
      cQ->rear = (cQ->rear+1) % MAX_QUEUE_SIZE; 
      // 큐는 사이즈 안에서 사이클을 돌아야하므로 큐의 사이즈로 나눈 나머지값을 할당한다. 
      // 따라서 큐가 마지막 칸에 왔을 때도 다음 칸으로 이동시 처음 칸으로 돌아갈 수 있다.
      cQ->queue[cQ->rear] = item; // rear 위치에 item값을 할당한다.
   }
}

/* 큐의 데이터를 제거하는 함수 */
void deQueue(QueueType *cQ, element *item)
{
   if(isEmpty(cQ)) { // 큐가 비어있다면 뺄 데이터가 없기 때문에 함수를 종료한다.
      return; 
   }
   else {
      cQ->front = (cQ->front+1)% MAX_QUEUE_SIZE; 
      // front의 값을 1 증가시켜 rear가 이동할 수 있도록 큐의 자리를 만들어준다.
      // 입력함수와 마찬가지로 front를 항상 큐의 사이즈로 나눠 큐의 사이즈 안에서 돌아가게 한다.
      *item = cQ->queue[cQ->front]; // front의 위치에 있는 데이터를 활용할 변수에 할당한다.
   }
}


void printQ(QueueType *cQ)
{
   int i, first, last;

   first = (cQ->front + 1)%MAX_QUEUE_SIZE;
   last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

   printf("Circular Queue : [");

   i = first;
   while(i != last){
      printf("%3c", cQ->queue[i]);
      i = (i+1)%MAX_QUEUE_SIZE;

   }
   printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

   printf("\n---DEBUG\n");
   for(int i = 0; i < MAX_QUEUE_SIZE; i++)
   {
      if(i == cQ->front) {
         printf("  [%d] = front\n", i);
         continue;
      }
      printf("  [%d] = %c\n", i, cQ->queue[i]);

   }
   printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}