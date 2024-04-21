/** 
 * postfix.c
 *
 * School of Computer Science, 
 * Chungbuk National University
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack 내에서 우선순위, lparen = 0 가장 낮음 */
typedef enum{
	lparen = 0,  /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호*/
	times = 7,   /* * 곱셈 */
	divide = 6,  /* / 나눗셈 */
	plus = 5,    /* + 덧셈 */
	minus = 4,   /* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/* 계산을 위해 필요한 스택 */

int postfixStackTop = -1;  /* postfixStack용 top */
int evalStackTop = -1;	   /* evalStack용 top */

int evalResult = 0;	   /* 계산 결과를 저장 */

void postfixpush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char* c);
void toPostfix();
void debug();
void reset();
void evaluation();

int main()
{
	char command;

	do{
		printf("-------------------- [남연서]   [2023041030] -------------------\n"); 
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x;
}

char postfixPop()
{
    char x;
    if(postfixStackTop == -1)
        return '\0';
    else {
    	x = postfixStack[postfixStackTop--];
    }
    return x;
}

void evalPush(int x)
{
    evalStack[++evalStackTop] = x;
}

int evalPop()
{
    if(evalStackTop == -1)
        return -1;
    else
        return evalStack[evalStackTop--];
}

/**
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp);
}

precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}
}

precedence getPriority(char x)
{
	return getToken(x);
}

/**
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix()
{
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char *exp = infixExp;
	char x; /* 문자하나를 임시로 저장하기 위한 변수 */

	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
	while (*exp != '\0') {
        /* 필요한 로직 완성 */
        if (getPriority(*exp) == operand) { // 추출한 문자가 상수일 경우
            charCat(exp);  // 그대로 출력할 후위표기 문자열로 전달한다.
        } 
		else if (getPriority(*exp) == lparen) { // 추출한 문자가 왼쪽 소괄호('(')인 경우
            postfixPush(*exp); // 출력하지 않고 push만 한다.
        }
        else if (getPriority(*exp)==rparen){ //추출한 문자가 오른쪽 소괄호(')')인 경우
			while (getPriority(postfixStack[postfixStackTop]) != lparen){ // stack의 탑이 왼쪽 소괄호('(')을 만날 때까지
				x = postfixPop(); // stack 안의 데이터를 pop한다.
				charCat(&x); // pop한 데이터를 출력할 후위포기 문자열로 전달한다.
			}
			x=postfixPop(); // 왼쪽 소괄호는 후휘포기 문자열로 넘기지 않고 데이터를 pop한다.
		}
		else{ // 상수와 괄호가 아닌 다른 연산자인 경우
			while (getPriority(postfixStack[postfixStackTop]) >= getPriority(*exp)){
				// stack 안의 연산자가 stack으로 들어갈 연산자보다 우선순위가 높은 경우
				// stack 안의 연산자의 우선순위가 들어갈 연산자의 우선순위보다 적을 때까지 pop한다.
				x = postfixPop(); // pop한 데이터는 출력할 문자열로 전달한다.
				charCat(&x);
			}
			postfixPush(*exp);
			// stack 안의 연산자의 우선순위보다 stack으로 들어갈 연산자의 우선순위가 낮을 경우
			// stack 안으로 연산자를 push한다.
		}

		exp++; // 다음 infixExp의 원소로 
	}

	while(postfixStackTop != -1){ 
		// 데이터가 남아있는 경우에는 그 데이터를 모두 pop하고 postfixExp로 전달한다.
		x = postfixPop();
		charCat(&x);
	}
}

void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';
         
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation() // 결과를 계산하는 함수
{
	char *exp = postfixExp; // char형 포인터변수 exp에 postfixExp의 주소를 할당한다.
	int x1, x2;

	while(*exp!='\0'){ // postfixExp의 길이만큼 반복한다.
		if (*exp == '+'){ // 만약 exp의 값이 '+'일 경우
			x2 = evalPop();
			x1 = evalPop();
			// 연산자 앞의 두 상수를 계산 stack에서 추출해서 더한다.
			evalPush(x1+x2); // 계산한 결과를 계산 stack으로 push한다.
		}
		else if(*exp == '/'){ // 만약 exp의 값이 '/'일 경우
			x2 = evalPop();
			x1 = evalPop();
			// 연산자 앞의 두 상수를 추출한다.
			evalPush(x1/x2); // 계산한 결과를 계산 stcak으로 push한다.
		}
		else if(getPriority(*exp)==operand){ // 만약 추출한 문자가 상수일 경우
			evalPush(*exp - '0'); // 추출한 문자에서 상수 값 0을 빼서 int형으로 바꿔준다.
		}
		else{
			break;
		}
		exp++; // 문자열 다음 원소로
	}
	evalResult = evalPop(); // 연산 결과
}

