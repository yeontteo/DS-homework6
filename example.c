/*
#include <stdio.h>

int main(void){
    int i, *p;

    i = 10;

    printf("value of i = %d\n", i);  
    printf("address of i = %p\n", &i);
    printf("value of p = %p\n", p);  
    printf("address of p = %p\n", &p);  

    p = &i;  

    printf("\n\n----- after p = &i ----- \n\n");

    printf("value of p = %p\n", p);  
    printf("address of p = %p\n", &p); 
    printf("dereferening *p = %d\n", *p); 

    return 0;
}
*/

/*
#include <stdio.h>

int main(){
    char charType; // char �ڷ��� ���� charType ����
    int integerType; // int �ڷ��� ���� integerType ����
    float floatType; // float �ڷ��� ���� floatType ����
    double doubleType; // double �ڷ��� ���� doubleType ���� 

    printf("[----- ������ 2023041030 -----]\n");

    printf("Size of char: %ld byte\n",sizeof(charType)); // �ڷ��� char�� ������ ���� charType�� ũ�⸦ ����Ѵ�.
    printf("Size of int: %ld bytes\n",sizeof(integerType)); // �ڷ��� int�� ������ ���� integerType�� ũ�⸦ ����Ѵ�.
    printf("Size of float: %ld bytes\n",sizeof(floatType)); // �ڷ��� float�� ������ ���� floatType�� ũ�⸦ ����Ѵ�.
    printf("Size of double: %ld bytes\n",sizeof(doubleType)); // �ڷ��� double�� ������ ���� doubleType�� ũ�⸦ ����Ѵ�.

    printf("-----------------------------------------\n");

    printf("Size of char: %ld byte\n",sizeof(char)); // �ڷ��� char�� ũ�⸦ ����Ѵ�.
    printf("Size of int: %ld bytes\n",sizeof(int)); // �ڷ��� int�� ũ�⸦ ����Ѵ�.
    printf("Size of float: %ld bytes\n",sizeof(float)); // �ڷ��� float�� ũ�⸦ ����Ѵ�.
    printf("Size of double: %ld bytes\n",sizeof(double)); // �ڷ��� double�� ũ�⸦ ����Ѵ�.

    printf("-----------------------------------------\n");

    printf("Size of char*: %ld byte\n",sizeof(char*)); // char�� ������ ������ ũ�⸦ ����Ѵ�.
    printf("Size of int*: %ld bytes\n",sizeof(int*)); // int�� ������ ������ ũ�⸦ ����Ѵ�.
    printf("Size of float*: %ld bytes\n",sizeof(float*)); // float�� ������ ������ ũ�⸦ ����Ѵ�.
    printf("Size of double*: %ld bytes\n",sizeof(double*)); // double�� ������ ������ ũ�⸦ ����Ѵ�.

    return 0; 
}
*/

/*
#include <stdio.h> 

int main()
{
    int i; // int�� ���� i ����
    int *ptr; // int�� ������ ���� ptr ����
    int **dptr; // int�� ���������� ���� dptr ����

    i = 1234; // i�� ���� 1234

    printf("[----- ������ 2023041030 -----]\n");
    
    printf("[checking values before ptr = &i] \n"); // ptr�� i�� �ּҸ� �Ҵ��ϱ� �� ���� Ȯ��
    printf("value of i == %d\n", i); // i�� �� ���
    printf("address of i == %p\n", &i); // i�� �ּ� ���
    printf("value of ptr == %p\n", ptr); // ptr�� �� ��� (�ʱ�ȭ���� ���� �������� ���̹Ƿ� �����Ⱚ�� �ּ��̴�.)
    printf("address of ptr == %p\n", &ptr); // ptr�� �ּ� ��� 

    
    ptr = &i;  // ptr is now holding the address of i
                // prt�� i�� �ּ� �Ҵ�

    printf("\n[checking values after ptr = &i] \n"); // ptr�� i�� �ּҸ� �Ҵ��� �� ���� Ȯ��
    printf("value of i == %d\n", i); // i�� �� ���
    printf("address of i == %p\n", &i); // i�� �ּ� ���
    printf("value of ptr == %p\n", ptr); // ptr�� �� ��� (i�� �ּҰ� ��µȴ�.)
    printf("address of ptr == %p\n", &ptr); // ptr�� �ּ� ��� (���� �Ҵ��� ���̹Ƿ� �ּҴ� ������ ����.)
    printf("value of *ptr == %d\n", *ptr); // ptr�� ����Ű�� �ּ��� �� ��� (=i�� ��, ������������ ���)


    dptr = &ptr; // dptr is now holding the address of ptr
                // dptr�� ptr�� �ּ� �Ҵ�

    printf("\n[checking values after dptr = &ptr] \n"); // dptr�� ptr�� �ּҸ� �Ҵ��� �� ���� Ȯ��
    printf("value of i == %d\n", i); // i�� �� ���
    printf("address of i == %p\n", &i); // i�� �ּ� ���
    printf("value of ptr == %p\n", ptr); // ptr�� �� ��� (i�� �ּҰ� ��µȴ�.)
    printf("address of ptr == %p\n", &ptr); // ptr�� �ּ� ��� (���� �Ҵ��� ���̹Ƿ� �ּҴ� ������ ����.)
    printf("value of *ptr == %d\n", *ptr); // ptr�� ����Ű�� �ּ��� �� ��� (=i�� ��, ������������ ���)
    printf("value of dptr == %p\n", dptr); // dptr�� �� ��� (dptr�� ptr�� �ּҸ� �Ҵ������Ƿ� ptr�� �ּҰ� ��µȴ�.)
    printf("address of dptr == %p\n", &dptr); // dptr�� �ּ� ���
    printf("value of *dptr == %p\n", *dptr); // dptr�� ����Ű�� �ּ��� �� ��� (=ptr�� ���̹Ƿ� ptr�� ����ִ� �ּҰ� ��µȴ�.)
    printf("value of **dptr == %d\n", **dptr); // dptr�� ����Ű�� �ּ�(��)�� ����Ű�� �ּ��� �� ��� (=ptr�� �ּҸ� ����Ű�Ƿ� ptr�� ����Ű�� �ִ� �ּ��� ���� i�� ���� ��µȴ�.)

    *ptr = 7777; // changing the value of *ptr

    printf("\n[after *ptr = 7777] \n"); // ptr�� ����Ű�� �ּ��� ���� 7777�� �ٲ� ��
    printf("value of i == %d\n", i); // i�� �� ��� (7777)
    printf("value of *ptr == %d\n", *ptr); // ptr�� ����Ű�� �ּ��� �� ��� (������������ ���, 7777)
    printf("value of **dptr == %d\n", **dptr); // dptr�� ����Ű�� �ּҰ� ����Ű�� �ּ��� �� ��� (���������� ���, 7777) 

    **dptr = 8888; // changing the value of **dptr

    printf("\n[after **dptr = 8888] \n"); // dptr�� ����Ű�� �ּҰ� ����Ű�� �ּ��� ���� 8888�� �ٲ� ��
    printf("value of i == %d\n", i); // i�� �� ��� (8888)
    printf("value of *ptr == %d\n", *ptr); // ptr�� ����Ű�� �ּ��� �� ��� (������������, 8888)
    printf("value of **dptr == %d\n", **dptr); // dptr�� ����Ű�� �ּҰ� ����Ű�� �ּ��� �� ��� (���������� ���, 8888)

    return 0;
}   
*/

/*
#include <stdio.h>
#include <stdlib.h>

void main() {
    printf("----- [������] [2023041030] -----\n");

    int list[5];
    int *plist[5] = {NULL,}; // plist �迭�� ��� NULL�� �ʱ�ȭ

    plist[0] = (int *)malloc(sizeof(int));  // plist[0]�� int ������(4)�� �޸� �Ҵ�
 
    list[0] = 1; // list[0]�� ��=1
    list[1] = 100; // list[1]�� ��=100
    *plist[0] = 200; // plist[0]�� ����Ű�� �ּҰ� ����ִ� ��=200

    printf("list[0]            = %d\n", list[0]); // list[0]�� �� ���=1
    printf("&list[0]           = %p\n", &list[0]); // list[0]�� �ּ� ���=0061FF0C
    printf("list               = %p\n", list); // list ���=�迭�� �̸��� �迭�� �����ּ��̹Ƿ� 0061FF0C
    printf("&list              = %p\n", &list); // list�� �ּ� ���=�迭�� �ּҴ� �����ּ��̹Ƿ� 0061FF0C ��� (&list[0]=list)
    
    printf("----------------------------------------\n\n");
    printf("list[1]            = %d\n", list[1]); // list[1]�� �� ���=100
    printf("&list[1]           = %p\n", &list[1]); // list[1]�� �ּ� ���=0061FF10
    printf("*(list+1)          = %d\n", *(list + 1)); // list�� �����ּҿ��� int �ڷ����� ũ���� 4����Ʈ��ŭ �ű� �ּҰ� ��� �ִ� ���� ���=100 (list�� �����ּ�+4����Ʈ)
    printf("list+1             = %p\n", list+1);  // list�� �����ּҿ��� 4����Ʈ(=int �ڷ��� 1��ŭ�� ũ��)��ŭ �ű� �ּҸ� ���=0061FF10 (0061FF0C + 4)

    printf("----------------------------------------\n\n");
    printf("*plist[0]          = %d\n", *plist[0]); // plist[0]�� ����Ű�� �ִ� �ּҰ� ����ִ� �� ���=200
    printf("&plist[0]          = %p\n", &plist[0]); // plist[0]�� �ּ� ���=0061FEF8
    printf("&plist             = %p\n", &plist); // plist�� �ּ� ���=0061FEF8 (&plist[0]=&plist)
    printf("plist              = %p\n", plist); // plist ���=0061FEF8 (�迭�� �̸��� �迭�� �����ּ��̹Ƿ� plist[0]�� �ּҰ� ��µȴ�.)
    printf("plist[0]           = %p\n", plist[0]); // plist[0] ���=00722F48 (heap ������ �Ҵ�� �޸��� �ּ�)
    printf("plist[1]           = %p\n", plist[1]); // plist �迭���� plist[0]����� ��� �ʱ�ȭ�Ǿ��ִ� �����̱⶧���� NULL���� ��� �ִ�.
    printf("plist[2]           = %p\n", plist[2]); // NULL��
    printf("plist[3]           = %p\n", plist[3]); // NULL��
    printf("plist[4]           = %p\n", plist[4]); // NULL��

    free(plist[0]); // plist[0]�� �����Ҵ��� �����Ѵ�.
}
*/

/*
#include <stdio.h> 
#include <stdlib.h>

void main() {
    printf("----- [������] [2023041030] -----\n");

    int list[5]; 
    int *plist[5];

    list[0] = 10; // list[0]�� ������ 10 �Ҵ�
    list[1] = 11; // list[1]�� ������ 11 �Ҵ�

    plist[0] = (int*)malloc(sizeof(int)); // plist[0]�� int �ڷ��� �������� �����Ҵ�

    printf("list[0] \t= %d\n", list[0]); // list[0]�� �� ���=10
    printf("list \t\t= %p\n", list); // list ���=0061FF0C (�迭�� �̸��� �迭�� �����ּ��̹Ƿ� list[0]�� �ּ�)
    printf("&list[0] \t= %p\n", &list[0]); // list[0]�� �ּ� ���=0061FF0C
    printf("list + 0 \t= %p\n", list+0); // list�� 0�� �������Ƿ� �����ּҿ� 0�� ���� �Ͱ� ���� ������ ����. =0061FF0C
    printf("list + 1 \t= %p\n", list+1); // list�� 1�� �������Ƿ� �����ּҿ� int �ڷ��� 1(4����Ʈ)�� ���� �ּ� ���=0061FF10 (=list[1]�� �ּ�)
    printf("list + 2 \t= %p\n", list+2); // list�� 2�� �������Ƿ� �����ּҿ� int �ڷ��� 2(8����Ʈ)�� ���� �ּ� ���=0061FF14 (=list[2]�� �ּ�)
    printf("list + 3 \t= %p\n", list+3); // list�� 3�� �������Ƿ� �����ּҿ� int �ڷ��� 3(12����Ʈ)�� ���� �ּ� ���=0061FF18 (=list[3]�� �ּ�)
    printf("list + 4 \t= %p\n", list+4); // list�� 4�� �������Ƿ� �����ּҿ� int �ڷ��� 4(16����Ʈ)�� ���� �ּ� ���=0061FF1C (=list[4]�� �ּ�)
    printf("&list[4] \t= %p\n", &list[4]); // list[4]�� �ּ� ���=0061FF1C

    free(plist[0]); // plist[0] �����Ҵ� ����
}
*/

/*
#include <stdio.h> 

#define MAX_SIZE 100

float sum1(float list[], int);
float sum2(float *list, int);
float sum3(int n, float *list);

float input[MAX_SIZE], answer; 
int i;

void main(void) 
{
    printf("----- [������] [2023041030] -----\n");

    for(i=0; i < MAX_SIZE; i++) // i=0�� �������� 1�� ���ϸ� input[i]�� 0���� n���� �� i�� �Ҵ��Ѵ�
        input[i] = i;
    // for checking call by reference 
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input�� ����Ѵ� (�迭�̹Ƿ� �����ּҰ� ��µȴ�.)

    answer = sum1(input, MAX_SIZE); // sum1�� ����� list�� &list�� �ּ�, �ּ��� ���� ����Ѵ�. (������ ���� ��µ� input�� �ּҿʹ� �ٸ���.)     
    printf("The sum is: %f\n\n", answer);

    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n"); 

    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input�� ����Ѵ� (�迭�̹Ƿ� �����ּҰ� ��µȴ�.)

    answer = sum2(input, MAX_SIZE); 
    printf("The sum is: %f\n\n", answer); // sum2�� ����� list�� &list�� �ּ�, �ּ��� ���� ����Ѵ�. (������ ���� ��µ� input�� �ּҿʹ� �ٸ���.)

    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input�� ����Ѵ� (�迭�̹Ƿ� �����ּҰ� ��µȴ�.)

    answer = sum3(MAX_SIZE, input); 
    printf("The sum is: %f\n\n", answer); // sum3�� ����� list�� &list�� �ּ�, �ּ��� ���� ����Ѵ�. (������ ���� ��µ� input�� �ּҿʹ� �ٸ���.)
}

float sum1(float list[], int n) {
    printf("list \t= %p\n", list); //list ��� (list �迭�� �����ּҰ� ��µȴ�)
    printf("&list \t= %p\n\n", &list); // list�� �����ּ� ��� (������ list�� ����ϴ� �Ͱ��� ���� �ٸ��� ���´�.)

    int i;
    float tempsum = 0; 
    for(i = 0; i < n; i++) // i�� 0���� n���� �ݺ��ϸ� list[i]�� ���� tempsum�� ���Ѵ� 
        tempsum += list[i]; 
    return tempsum;
}

float sum2(float *list, int n) {
    printf("list \t= %p\n", list); // list ��� (�迭�� �̸��� �迭�� �����ּ��̴�.)
    printf("&list \t= %p\n\n", &list); // list�� �����ּ� ��� (������ list�� ����ϴ� �Ͱ� ���� �ٸ��� ���´�.)

    int i;
    float tempsum = 0;
    for(i = 0; i < n; i++) // list�� �����ּҺ��� i*4 (������ int�� ũ��)��ŭ ���ϸ� list[i]�� ����Ű�� �ּ��� ���� tempsum�� ���Ѵ�.
        tempsum += *(list + i);
    return tempsum; 
}

// stack variable reuse test
float sum3(int n, float *list) {
    printf("list \t= %p\n", list); // list ��� (�迭�� �̸��� �迭�� �����ּ��̴�.)
    printf("&list \t= %p\n\n", &list); // list�� �����ּ� ��� (������ list�� ����ϴ� �Ͱ� ���� �ٸ��� ���´�.)
    
    int i;
    float tempsum = 0;
    for(i = 0; i < n; i++) // list�� �����ּҺ��� i*4 (������ int�� ũ��)��ŭ ���ϸ� list[i]�� ����Ű�� �ּ��� ���� tempsum�� ���Ѵ�.
        tempsum += *(list + i); 
    return tempsum; 
}
*/

/*
#include <stdio.h>

    void print_one(int *ptr, int rows); 

int main()
{
    printf("----- [������] [2023041030] -----\n");

    int one[] = {0, 1, 2, 3, 4}; 
    printf("one     = %p\n", one); // one ���=0061FF0C (=�����ּ��� one[0]�� �ּ�)
    printf("&one    = %p\n", &one); // one�� �ּ� ���=0061FF0C (=�����ּ��� one[0]�� �ּ�)
    printf("&one[0] = %p\n", &one[0]); // one[0]�� �ּ� ���=0061FF0C
    printf("\n");

    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5); // one[0]���� one[4]���� �ּҿ� �� �ּҰ� ����ִ� ���� ����Ѵ�.

    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5); // one�� �����ּҺ��� ���ʷ� 4�� ���� �ּҿ� ����ִ� ���� 5���� ����Ѵ�.

    return 0; 
}

void print_one(int *ptr, int rows)
{// print out a one-dimensional array using a pointer

    int i;
    printf ("Address \t Contents\n"); 
    for (i = 0; i < rows; i++) // i�� 0���� rows�̸����� 1�� Ŀ���� ���� ptr�� �����ּҿ� i*4�� ���� �ּҿ� �� �ּҰ� ����ִ� ���� ����Ѵ�. 
        printf("%p \t  %5d\n", ptr + i, *(ptr + i)); 
    printf("\n");
}
*/

/*
#include<stdio.h> 
#include<stdlib.h>

void main()
{
    printf("[-----    ������        2023041030    -----]\n");

    int **x; // ���������� x ����

    printf("sizeof(x) = %lu\n", sizeof(x)); // x�� ũ�� ��� = �����ͺ����� ũ��� 4����Ʈ�̴�.
    printf("sizeof(*x) = %lu\n", sizeof(*x)); // x�� ����Ű�� ���� ������ ��� = ���������Ͷ� �������� ũ���� 4����Ʈ�̴�.
    printf("sizeof(**x) = %lu\n", sizeof(**x)); // x�� ����Ű�� ���� ����Ű�� ���� ������ ��� = int �ڷ����� ũ���� 4����Ʈ�̴�.
}
*/

/*
#include <stdio.h> 

struct student1 { // student1 ����ü ����
    char lastName; 
    int studentId; 
    char grade;
};

typedef struct { // typedef ������ ����� student2 ����ü ����
    char lastName; 
    int studentId; 
    char grade;
} student2;

int main() {

    printf("[-----    ������        2023041030    -----]");

    struct student1 st1 = {'A', 100, 'A'}; // student1 ����ü�� �ڷ������� st1 ���� �� �� ���� �Ҵ�

    printf("st1.lastName = %c\n", st1.lastName); // A�� ��µȴ�.
    printf("st1.studentId = %d\n", st1.studentId); // 100�� ��µȴ�.
    printf("st1.grade = %c\n", st1.grade); // A�� ��µȴ�.

    student2 st2 = {'B', 200, 'B'}; // student2 ����ü�� �ڷ������� st2 ���� �� �� ���� �Ҵ�

    printf("\nst2.lastName = %c\n", st2.lastName); // B�� ��µȴ�.
    printf("st2.studentId = %d\n", st2.studentId); // 200�� ��µȴ�.
    printf("st2.grade = %c\n", st2.grade); // B�� ��µȴ�.
    
    student2 st3; // student2 �ڷ����� ����ü st3 ����
    
    st3 = st2; // st3�� st2 �Ҵ�
    
    printf("\nst3.lastName = %c\n", st3.lastName);
    printf("st3.studentId = %d\n", st3.studentId);
    printf("st3.grade = %c\n", st3.grade);

    // equality test 
    if(strcmp(st2.lastName, st3.lastName)==0 && strcmp(st2.studentId, st3.studentId)==0 && strcmp(st2.grade, st3.grade)==0) 
        printf("equal\n");
    else
        printf("not equal\n"); 
    return 0;
}
*/

/*
#include <stdio.h> 

struct student {
    char lastName[13];   // 13 bytes  
    int studentId;       /* 4 bytes  
    short grade;         /* 2 bytes
};

int main() 
{
    printf("[-----    ������       2023041030    -----]\n");

    struct student pst; // ����ü student�� �ڷ������� pst ����

    printf("size of student = %ld\n", sizeof(struct student));
    // �е����� ����Ʈ�� ä�����⶧���� 
    // lastName 13����Ʈ+�е� 3����Ʈ (=16�̹Ƿ� 4�� ���)
    // studentID 4����Ʈ (�״�� ����)
    // grade 2����Ʈ+�е� 2����Ʈ (=4�̹Ƿ� 4�� ���)
    // ���� 13+3+4+2+2 = 24����Ʈ�� ��µȴ�
    printf("size of int     = %ld\n", sizeof(int));
    printf("size of short   = %ld\n", sizeof(short));

    return 0; 
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_martix(int, int, int **); // ����� ����ϴ� �Լ�
void addition_matrix(int, int, int **, int **); // ��� �� �Լ� (A+B)
void subtraction_matrix(int, int, int **, int **); // ��� ���� �Լ� (A-B)
void transpose_matrix(int, int, int **, int **); // ��ġ��� �Լ�
void multiply_matrix(int, int, int **, int **); // ��� �� �Լ�
int** create_matrix(int, int); // ��� ���� �Լ�
void free_matrix(int, int, int **); // �����Ҵ� ���� �Լ�

int main(){

    printf("-----[������] [2023041030]-----");
    int row, column; // ��� ���� ũ�� �Է�
    scanf("���� �Է��ϼ���: %d", &row);
    scanf("���� �Է��ϼ���: %d", &column);

    int **mat1 = create_matrix(row, column); // ù ��° ��� ����
    srand(time(NULL));
    printf("A ���\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            mat1[i][j] = rand()%100;
        }
    }

    int **mat2 = create_matrix(row, column); // �� ��° ��� ����
    printf("B ���\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            mat2[i][j] = rand()%100;
        }
    }

    printf("A + B ���\n"); // ���� ��� ���
    addition_matrix(row, column, mat1, mat2);

    printf("A - B ���\n"); // ���� ��� ���
    subtraction_matrix(row, column, mat1, mat2);

    printf("A ��ġ���\n"); // ��ġ ��� ���
    int **transposed_mat = create_matrix(column, row);
    transpose_matrix(row, column, mat1, transposed_mat);
    print_matrix(column, row, transposed_mat);
    free_matrix(column, transposed_mat);

    printf("A * B ���\n"); // ���� ��� ���
    multiply_matrix(row, column, mat1, mat2);

    free_matrix(row, mat1); // �޸� ����
    free_matrix(row, mat2);

    return 0;
}

void print_matrix(int a, int b, int **c){
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void addition_matrix(int a, int b, int ** c, int ** d){
    int ** sum = create_matrix(a,b);
    for(int i=0;i<a;i++){
        for(int j=0; j<b; j++){
            sum[i][j] = c[i][j] + d[i][j];
        }
        printf("\n");
    }
    print_matrix(sum, a, b);
    free_matrix(sum, a, b);
}

void subtraction_matrix(int a, int b, int ** c, int ** d){
    int ** sub = create_matrix(a, b);

    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            sub[i][j] = c[i][j] - d[i][j];
        }
        printf("\n");
    }
    print_matrix(sub, a, b);
    free_matrix(sub, a, b);
}

void transpose_matrix(int a, int b, int ** c, int ** d){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            d[i][j] = c[i][j];
        }
    }
}

void multiply_matrix(int a, int b, int ** c, int ** d){
    int sum = 0;
    int ** mul = create_matrix(a, a);
    for(int i=0;i<a;i++){ 
        for(int j=0;j<a;j++){ 
            sum += (c[i][j]*d[j][i]);
            mul[i][j] = sum;
        }
        sum = 0;     
        }
        printf("\n");
    print_matrix(a, b, mul);
    free_matrix(a, b, mul);
}

int** create_matrix(int a, int b){
    int ** x = (int **)malloc(sizeof(int *)*a); //������������ ���� x�� �����Ҵ�

    for(int i=0;i<a;i++){
        x[i] = (int *)malloc(sizeof(int)*b); //�迭 x�� int������� �����Ҵ�
    }
    return x;
}

void free_matrix(int a, int ** c){ //�迭�� ���� ���� �� �κ� ����
    for(int i=0;i<a;i++){
        free(c[i]);
    }
    free(c); //�迭�� �� ���� �ּҵ��� ������ �����Ҵ� ����
}
*/