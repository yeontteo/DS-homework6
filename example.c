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
    char charType; // char 자료형 변수 charType 선언
    int integerType; // int 자료형 변수 integerType 선언
    float floatType; // float 자료형 변수 floatType 선언
    double doubleType; // double 자료형 변수 doubleType 선언 

    printf("[----- 남연서 2023041030 -----]\n");

    printf("Size of char: %ld byte\n",sizeof(charType)); // 자료형 char로 선언한 변수 charType의 크기를 출력한다.
    printf("Size of int: %ld bytes\n",sizeof(integerType)); // 자료형 int로 선언한 변수 integerType의 크기를 출력한다.
    printf("Size of float: %ld bytes\n",sizeof(floatType)); // 자료형 float로 선언한 변수 floatType의 크기를 출력한다.
    printf("Size of double: %ld bytes\n",sizeof(doubleType)); // 자료형 double로 선언한 변수 doubleType의 크기를 출력한다.

    printf("-----------------------------------------\n");

    printf("Size of char: %ld byte\n",sizeof(char)); // 자료형 char의 크기를 출력한다.
    printf("Size of int: %ld bytes\n",sizeof(int)); // 자료형 int의 크기를 출력한다.
    printf("Size of float: %ld bytes\n",sizeof(float)); // 자료형 float의 크기를 출력한다.
    printf("Size of double: %ld bytes\n",sizeof(double)); // 자료형 double의 크기를 출력한다.

    printf("-----------------------------------------\n");

    printf("Size of char*: %ld byte\n",sizeof(char*)); // char형 포인터 변수의 크기를 출력한다.
    printf("Size of int*: %ld bytes\n",sizeof(int*)); // int형 포인터 변수의 크기를 출력한다.
    printf("Size of float*: %ld bytes\n",sizeof(float*)); // float형 포인터 변수의 크기를 출력한다.
    printf("Size of double*: %ld bytes\n",sizeof(double*)); // double형 포인터 변수의 크기를 출력한다.

    return 0; 
}
*/

/*
#include <stdio.h> 

int main()
{
    int i; // int형 변수 i 선언
    int *ptr; // int형 포인터 변수 ptr 선언
    int **dptr; // int형 이중포인터 변수 dptr 선언

    i = 1234; // i의 값은 1234

    printf("[----- 남연서 2023041030 -----]\n");
    
    printf("[checking values before ptr = &i] \n"); // ptr에 i의 주소를 할당하기 전 값을 확인
    printf("value of i == %d\n", i); // i의 값 출력
    printf("address of i == %p\n", &i); // i의 주소 출력
    printf("value of ptr == %p\n", ptr); // ptr의 값 출력 (초기화되지 않은 포인터의 값이므로 쓰레기값인 주소이다.)
    printf("address of ptr == %p\n", &ptr); // ptr의 주소 출력 

    
    ptr = &i;  // ptr is now holding the address of i
                // prt에 i의 주소 할당

    printf("\n[checking values after ptr = &i] \n"); // ptr에 i의 주소를 할당한 후 값을 확인
    printf("value of i == %d\n", i); // i의 값 출력
    printf("address of i == %p\n", &i); // i의 주소 출력
    printf("value of ptr == %p\n", ptr); // ptr의 값 출력 (i의 주소가 출력된다.)
    printf("address of ptr == %p\n", &ptr); // ptr의 주소 출력 (값만 할당한 것이므로 주소는 변함이 없다.)
    printf("value of *ptr == %d\n", *ptr); // ptr이 가리키는 주소의 값 출력 (=i의 값, 역참조연산자 사용)


    dptr = &ptr; // dptr is now holding the address of ptr
                // dptr에 ptr의 주소 할당

    printf("\n[checking values after dptr = &ptr] \n"); // dptr에 ptr의 주소를 할당한 후 값을 확인
    printf("value of i == %d\n", i); // i의 값 출력
    printf("address of i == %p\n", &i); // i의 주소 출력
    printf("value of ptr == %p\n", ptr); // ptr의 값 출력 (i의 주소가 출력된다.)
    printf("address of ptr == %p\n", &ptr); // ptr의 주소 출력 (값만 할당한 것이므로 주소는 변함이 없다.)
    printf("value of *ptr == %d\n", *ptr); // ptr이 가리키는 주소의 값 출력 (=i의 값, 역참조연산자 사용)
    printf("value of dptr == %p\n", dptr); // dptr의 값 출력 (dptr에 ptr의 주소를 할당했으므로 ptr의 주소가 출력된다.)
    printf("address of dptr == %p\n", &dptr); // dptr의 주소 출력
    printf("value of *dptr == %p\n", *dptr); // dptr이 가리키는 주소의 값 출력 (=ptr의 값이므로 ptr이 담고있는 주소가 출력된다.)
    printf("value of **dptr == %d\n", **dptr); // dptr이 가리키는 주소(값)가 가리키는 주소의 값 출력 (=ptr의 주소를 가리키므로 ptr이 가리키고 있는 주소의 값인 i의 값이 출력된다.)

    *ptr = 7777; // changing the value of *ptr

    printf("\n[after *ptr = 7777] \n"); // ptr이 가리키는 주소의 값을 7777로 바꾼 후
    printf("value of i == %d\n", i); // i의 값 출력 (7777)
    printf("value of *ptr == %d\n", *ptr); // ptr이 가리키는 주소의 값 출력 (역참조연산자 사용, 7777)
    printf("value of **dptr == %d\n", **dptr); // dptr이 가리키는 주소가 가리키는 주소의 값 출력 (이중포인터 사용, 7777) 

    **dptr = 8888; // changing the value of **dptr

    printf("\n[after **dptr = 8888] \n"); // dptr이 가리키는 주소가 가리키는 주소의 값을 8888로 바꾼 후
    printf("value of i == %d\n", i); // i의 값 출력 (8888)
    printf("value of *ptr == %d\n", *ptr); // ptr이 가리키는 주소의 값 출력 (역참조연산자, 8888)
    printf("value of **dptr == %d\n", **dptr); // dptr이 가리키는 주소가 가르키는 주소의 값 출력 (이중포인터 사용, 8888)

    return 0;
}   
*/

/*
#include <stdio.h>
#include <stdlib.h>

void main() {
    printf("----- [남연서] [2023041030] -----\n");

    int list[5];
    int *plist[5] = {NULL,}; // plist 배열을 모두 NULL로 초기화

    plist[0] = (int *)malloc(sizeof(int));  // plist[0]에 int 사이즈(4)의 메모리 할당
 
    list[0] = 1; // list[0]의 값=1
    list[1] = 100; // list[1]의 값=100
    *plist[0] = 200; // plist[0]이 가리키는 주소가 담고있는 값=200

    printf("list[0]            = %d\n", list[0]); // list[0]의 값 출력=1
    printf("&list[0]           = %p\n", &list[0]); // list[0]의 주소 출력=0061FF0C
    printf("list               = %p\n", list); // list 출력=배열의 이름은 배열의 시작주소이므로 0061FF0C
    printf("&list              = %p\n", &list); // list의 주소 출력=배열의 주소는 시작주소이므로 0061FF0C 출력 (&list[0]=list)
    
    printf("----------------------------------------\n\n");
    printf("list[1]            = %d\n", list[1]); // list[1]의 값 출력=100
    printf("&list[1]           = %p\n", &list[1]); // list[1]의 주소 출력=0061FF10
    printf("*(list+1)          = %d\n", *(list + 1)); // list의 시작주소에서 int 자료형의 크기인 4바이트만큼 옮긴 주소가 담고 있는 값을 출력=100 (list의 시작주소+4바이트)
    printf("list+1             = %p\n", list+1);  // list의 시작주소에서 4바이트(=int 자료형 1만큼의 크기)만큼 옮긴 주소를 출력=0061FF10 (0061FF0C + 4)

    printf("----------------------------------------\n\n");
    printf("*plist[0]          = %d\n", *plist[0]); // plist[0]이 가리키고 있는 주소가 담고있는 값 출력=200
    printf("&plist[0]          = %p\n", &plist[0]); // plist[0]의 주소 출력=0061FEF8
    printf("&plist             = %p\n", &plist); // plist의 주소 출력=0061FEF8 (&plist[0]=&plist)
    printf("plist              = %p\n", plist); // plist 출력=0061FEF8 (배열의 이름은 배열의 시작주소이므로 plist[0]의 주소가 출력된다.)
    printf("plist[0]           = %p\n", plist[0]); // plist[0] 출력=00722F48 (heap 영역에 할당된 메모리의 주소)
    printf("plist[1]           = %p\n", plist[1]); // plist 배열에서 plist[0]말고는 모두 초기화되어있는 상태이기때문에 NULL값을 담고 있다.
    printf("plist[2]           = %p\n", plist[2]); // NULL값
    printf("plist[3]           = %p\n", plist[3]); // NULL값
    printf("plist[4]           = %p\n", plist[4]); // NULL값

    free(plist[0]); // plist[0]의 동적할당을 해제한다.
}
*/

/*
#include <stdio.h> 
#include <stdlib.h>

void main() {
    printf("----- [남연서] [2023041030] -----\n");

    int list[5]; 
    int *plist[5];

    list[0] = 10; // list[0]의 값으로 10 할당
    list[1] = 11; // list[1]의 값으로 11 할당

    plist[0] = (int*)malloc(sizeof(int)); // plist[0]에 int 자료형 사이즈의 동적할당

    printf("list[0] \t= %d\n", list[0]); // list[0]의 값 출력=10
    printf("list \t\t= %p\n", list); // list 출력=0061FF0C (배열의 이름은 배열의 시작주소이므로 list[0]의 주소)
    printf("&list[0] \t= %p\n", &list[0]); // list[0]의 주소 출력=0061FF0C
    printf("list + 0 \t= %p\n", list+0); // list에 0을 더했으므로 시작주소에 0을 더한 것과 같고 변함이 없다. =0061FF0C
    printf("list + 1 \t= %p\n", list+1); // list에 1을 더했으므로 시작주소에 int 자료형 1(4바이트)을 더한 주소 출력=0061FF10 (=list[1]의 주소)
    printf("list + 2 \t= %p\n", list+2); // list에 2를 더했으므로 시작주소에 int 자료형 2(8바이트)를 더한 주소 출력=0061FF14 (=list[2]의 주소)
    printf("list + 3 \t= %p\n", list+3); // list에 3을 더했으므로 시작주소에 int 자료형 3(12바이트)을 더한 주소 출력=0061FF18 (=list[3]의 주소)
    printf("list + 4 \t= %p\n", list+4); // list에 4를 더했으므로 시작주소에 int 자료형 4(16바이트)를 더한 주소 출력=0061FF1C (=list[4]의 주소)
    printf("&list[4] \t= %p\n", &list[4]); // list[4]의 주소 출력=0061FF1C

    free(plist[0]); // plist[0] 동적할당 해제
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
    printf("----- [남연서] [2023041030] -----\n");

    for(i=0; i < MAX_SIZE; i++) // i=0을 시작으로 1씩 더하며 input[i]에 0부터 n까지 값 i를 할당한다
        input[i] = i;
    // for checking call by reference 
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input을 출력한다 (배열이므로 시작주소가 출력된다.)

    answer = sum1(input, MAX_SIZE); // sum1의 결과로 list와 &list의 주소, 주소의 합을 출력한다. (하지만 위에 출력된 input의 주소와는 다르다.)     
    printf("The sum is: %f\n\n", answer);

    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n"); 

    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input을 출력한다 (배열이므로 시작주소가 출력된다.)

    answer = sum2(input, MAX_SIZE); 
    printf("The sum is: %f\n\n", answer); // sum2의 결과로 list와 &list의 주소, 주소의 합을 출력한다. (하지만 위에 출력된 input의 주소와는 다르다.)

    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input을 출력한다 (배열이므로 시작주소가 출력된다.)

    answer = sum3(MAX_SIZE, input); 
    printf("The sum is: %f\n\n", answer); // sum3의 결과로 list와 &list의 주소, 주소의 합을 출력한다. (하지만 위에 출력된 input의 주소와는 다르다.)
}

float sum1(float list[], int n) {
    printf("list \t= %p\n", list); //list 출력 (list 배열의 시작주소가 출력된다)
    printf("&list \t= %p\n\n", &list); // list의 시작주소 출력 (하지만 list를 출력하는 것과는 값이 다르게 나온다.)

    int i;
    float tempsum = 0; 
    for(i = 0; i < n; i++) // i를 0부터 n까지 반복하며 list[i]의 값을 tempsum에 더한다 
        tempsum += list[i]; 
    return tempsum;
}

float sum2(float *list, int n) {
    printf("list \t= %p\n", list); // list 출력 (배열의 이름은 배열의 시작주소이다.)
    printf("&list \t= %p\n\n", &list); // list의 시작주소 출력 (하지만 list를 출력하는 것과 값이 다르게 나온다.)

    int i;
    float tempsum = 0;
    for(i = 0; i < n; i++) // list의 시작주소부터 i*4 (정수형 int의 크기)만큼 더하며 list[i]가 가리키는 주소의 값을 tempsum에 더한다.
        tempsum += *(list + i);
    return tempsum; 
}

// stack variable reuse test
float sum3(int n, float *list) {
    printf("list \t= %p\n", list); // list 출력 (배열의 이름은 배열의 시작주소이다.)
    printf("&list \t= %p\n\n", &list); // list의 시작주소 출력 (하지만 list를 출력하는 것과 값이 다르게 나온다.)
    
    int i;
    float tempsum = 0;
    for(i = 0; i < n; i++) // list의 시작주소부터 i*4 (정수형 int의 크기)만큼 더하며 list[i]가 가리키는 주소의 값을 tempsum에 더한다.
        tempsum += *(list + i); 
    return tempsum; 
}
*/

/*
#include <stdio.h>

    void print_one(int *ptr, int rows); 

int main()
{
    printf("----- [남연서] [2023041030] -----\n");

    int one[] = {0, 1, 2, 3, 4}; 
    printf("one     = %p\n", one); // one 출력=0061FF0C (=시작주소인 one[0]의 주소)
    printf("&one    = %p\n", &one); // one의 주소 출력=0061FF0C (=시작주소인 one[0]의 주소)
    printf("&one[0] = %p\n", &one[0]); // one[0]의 주소 출력=0061FF0C
    printf("\n");

    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5); // one[0]부터 one[4]까지 주소와 그 주소가 담고있는 값을 출력한다.

    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5); // one의 시작주소부터 차례로 4씩 더한 주소와 담고있는 값을 5개씩 출력한다.

    return 0; 
}

void print_one(int *ptr, int rows)
{// print out a one-dimensional array using a pointer

    int i;
    printf ("Address \t Contents\n"); 
    for (i = 0; i < rows; i++) // i가 0부터 rows미만까지 1씩 커짐에 따라 ptr의 시작주소에 i*4를 더한 주소와 그 주소가 담고있는 값을 출력한다. 
        printf("%p \t  %5d\n", ptr + i, *(ptr + i)); 
    printf("\n");
}
*/

/*
#include<stdio.h> 
#include<stdlib.h>

void main()
{
    printf("[-----    남연서        2023041030    -----]\n");

    int **x; // 이중포인터 x 선언

    printf("sizeof(x) = %lu\n", sizeof(x)); // x의 크기 출력 = 포인터변수의 크기는 4바이트이다.
    printf("sizeof(*x) = %lu\n", sizeof(*x)); // x가 가리키는 값의 사이즈 출력 = 이중포인터라 포인터의 크기인 4바이트이다.
    printf("sizeof(**x) = %lu\n", sizeof(**x)); // x가 가리키는 값이 가리키는 값의 사이즈 출력 = int 자료형의 크기인 4바이트이다.
}
*/

/*
#include <stdio.h> 

struct student1 { // student1 구조체 선언
    char lastName; 
    int studentId; 
    char grade;
};

typedef struct { // typedef 문장을 사용한 student2 구조체 선언
    char lastName; 
    int studentId; 
    char grade;
} student2;

int main() {

    printf("[-----    남연서        2023041030    -----]");

    struct student1 st1 = {'A', 100, 'A'}; // student1 구조체를 자료형으로 st1 선언 후 각 변수 할당

    printf("st1.lastName = %c\n", st1.lastName); // A가 출력된다.
    printf("st1.studentId = %d\n", st1.studentId); // 100이 출력된다.
    printf("st1.grade = %c\n", st1.grade); // A가 출력된다.

    student2 st2 = {'B', 200, 'B'}; // student2 구조체를 자료형으로 st2 선언 후 각 변수 할당

    printf("\nst2.lastName = %c\n", st2.lastName); // B가 출력된다.
    printf("st2.studentId = %d\n", st2.studentId); // 200이 출력된다.
    printf("st2.grade = %c\n", st2.grade); // B가 출력된다.
    
    student2 st3; // student2 자료형의 구조체 st3 선언
    
    st3 = st2; // st3에 st2 할당
    
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
    printf("[-----    남연서       2023041030    -----]\n");

    struct student pst; // 구조체 student의 자료형으로 pst 선언

    printf("size of student = %ld\n", sizeof(struct student));
    // 패딩으로 바이트가 채워지기때문에 
    // lastName 13바이트+패딩 3바이트 (=16이므로 4의 배수)
    // studentID 4바이트 (그대로 가능)
    // grade 2바이트+패딩 2바이트 (=4이므로 4의 배수)
    // 따라서 13+3+4+2+2 = 24바이트가 출력된다
    printf("size of int     = %ld\n", sizeof(int));
    printf("size of short   = %ld\n", sizeof(short));

    return 0; 
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_martix(int, int, int **); // 행렬을 출력하는 함수
void addition_matrix(int, int, int **, int **); // 행렬 합 함수 (A+B)
void subtraction_matrix(int, int, int **, int **); // 행렬 뺄셈 함수 (A-B)
void transpose_matrix(int, int, int **, int **); // 전치행렬 함수
void multiply_matrix(int, int, int **, int **); // 행렬 곱 함수
int** create_matrix(int, int); // 행렬 생성 함수
void free_matrix(int, int, int **); // 동적할당 해제 함수

int main(){

    printf("-----[남연서] [2023041030]-----");
    int row, column; // 행과 열의 크기 입력
    scanf("행을 입력하세요: %d", &row);
    scanf("열을 입력하세요: %d", &column);

    int **mat1 = create_matrix(row, column); // 첫 번째 행렬 생성
    srand(time(NULL));
    printf("A 행렬\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            mat1[i][j] = rand()%100;
        }
    }

    int **mat2 = create_matrix(row, column); // 두 번째 행렬 생성
    printf("B 행렬\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            mat2[i][j] = rand()%100;
        }
    }

    printf("A + B 행렬\n"); // 덧셈 행렬 출력
    addition_matrix(row, column, mat1, mat2);

    printf("A - B 행렬\n"); // 뺄셈 행렬 출력
    subtraction_matrix(row, column, mat1, mat2);

    printf("A 전치행렬\n"); // 전치 행렬 출력
    int **transposed_mat = create_matrix(column, row);
    transpose_matrix(row, column, mat1, transposed_mat);
    print_matrix(column, row, transposed_mat);
    free_matrix(column, transposed_mat);

    printf("A * B 행렬\n"); // 곱셈 행렬 출력
    multiply_matrix(row, column, mat1, mat2);

    free_matrix(row, mat1); // 메모리 해제
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
    int ** x = (int **)malloc(sizeof(int *)*a); //이중포인터형 변수 x에 동적할당

    for(int i=0;i<a;i++){
        x[i] = (int *)malloc(sizeof(int)*b); //배열 x에 int사이즈로 동적할당
    }
    return x;
}

void free_matrix(int a, int ** c){ //배열의 실제 값이 들어간 부분 해제
    for(int i=0;i<a;i++){
        free(c[i]);
    }
    free(c); //배열의 각 행의 주소들을 저장한 동적할당 해제
}
*/