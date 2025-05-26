/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int top;
}Stack;

void initializeStack(Stack *S)
{
    S->top = -1;
}

int isFull(Stack *S)
{
    return S->top == MAX - 1;
}

int isEmpty(Stack *S)
{
    return S->top == -1;
}

void push(Stack *S, int a)
{
    if (isFull(S))
    {
        printf("Stack overflow\n");
        return;
    }
    
    S->arr[++S->top] = a;
    printf("Pushed %d onto the stack\n", a);
}

int pop(Stack *S)
{
    if (isEmpty(S))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    
    return S->arr[S->top--];
}

int peek(Stack *S)
{
    if(isEmpty(S))
    {
        printf("Stack is empty\n");
        return -1;
    }
    
    return S->arr[S->top];
}

int main()
{
    Stack S;
    initializeStack(&S);
    
    // Push elements onto the Stack
    push(&S, 10);
    push(&S, 20);
    push(&S, 30);
    
    // Peek at the top element
    printf("Top element is: %d\n", peek(&S));
    
    // Pop elements from the stack
    printf("Popped: %d\n", pop(&S));
    printf("Popped: %d\n", pop(&S));
    printf("Popped: %d\n", pop(&S));
    
    // Check if the stack is isEmpty
    if (isEmpty(&S))
        printf("Stack is empty\n");
    
    return 0;
}
