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
   element queue[MAX_QUEUE_SIZE]; // Q ������ = 4 (4ĭ)
   int front, rear; // front = ù��° �����͸� ����Ų��, rear = ������ �����͸� ����Ų��
}QueueType;


QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item); // insert
void deQueue(QueueType *cQ, element* item); // delete
void printQ(QueueType *cQ); // print
void debugQ(QueueType *cQ); // debug
element getElement(); // �Է�

int main(void)
{
   QueueType *cQ = createQueue(); // Q ����, front=rear=0
   element data;
   char command;


   do{
      printf("--------------- [������]   [2023041030] --------------\n");      
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


/* ť�� ����ִ��� Ȯ���ϴ� �Լ� */
int isEmpty(QueueType *cQ)
{
   if (cQ->front==cQ->rear){ // rear�� front�� ���� ���ٸ� ť�� ����ִٴ� ���̴�.      
      printf("Queue is empty!!!!!!!!!!!!!!!\n"); // ť�� ����ִٴ� �޼����� ����Ѵ�.
      return 1; // 1 ����
   }
   else{
      return 0; // rear�� front�� ���� ���� �ʴٸ� �״�� �����Ѵ�.
   }
}

/* ť�� ���� ���ִ��� Ȯ���ϴ� �Լ� */
int isFull(QueueType *cQ)
{
   if((cQ->rear+1)%MAX_QUEUE_SIZE == cQ->front){ 
      // rear�� �� ĭ ������ ���� �� rear+1�� �� ���� ť�� ������� ������ �� front�� ���� ���̸� ť�� ���� �� ���̴�.
      printf("Queue is full.\n"); // ť�� �� �� �ִٴ� �޼����� ����Ѵ�.
      return 1; // 1����
   }
   else{ // ť�� ���� �� ���� �ƴ϶�� �״�� �����Ѵ�.
      return 0;
   }
}


/* �Է��Լ� */
void enQueue(QueueType *cQ, element item)
{
   if(isFull(cQ)) { // ť�� ���� ���ִ��� Ȯ���ϰ�, ���� ���ִٸ� �Լ��� �����Ѵ�.
      return;
   } 
   else {
      cQ->rear = (cQ->rear+1) % MAX_QUEUE_SIZE; 
      // ť�� ������ �ȿ��� ����Ŭ�� ���ƾ��ϹǷ� ť�� ������� ���� ���������� �Ҵ��Ѵ�. 
      // ���� ť�� ������ ĭ�� ���� ���� ���� ĭ���� �̵��� ó�� ĭ���� ���ư� �� �ִ�.
      cQ->queue[cQ->rear] = item; // rear ��ġ�� item���� �Ҵ��Ѵ�.
   }
}

/* ť�� �����͸� �����ϴ� �Լ� */
void deQueue(QueueType *cQ, element *item)
{
   if(isEmpty(cQ)) { // ť�� ����ִٸ� �� �����Ͱ� ���� ������ �Լ��� �����Ѵ�.
      return; 
   }
   else {
      cQ->front = (cQ->front+1)% MAX_QUEUE_SIZE; 
      // front�� ���� 1 �������� rear�� �̵��� �� �ֵ��� ť�� �ڸ��� ������ش�.
      // �Է��Լ��� ���������� front�� �׻� ť�� ������� ���� ť�� ������ �ȿ��� ���ư��� �Ѵ�.
      *item = cQ->queue[cQ->front]; // front�� ��ġ�� �ִ� �����͸� Ȱ���� ������ �Ҵ��Ѵ�.
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