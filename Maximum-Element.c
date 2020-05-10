#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
};

struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
}

void push(struct Stack* stack, int data)
{
    if(stack->top==stack->capacity-1)
        return;
    stack->array[++stack->top] = data;
}

void pop(struct Stack* stack)
{
    if(stack->top==-1)
        return;
    stack->top--;
}

int print_max(struct Stack* stack)
{
    int max=0;
    while(stack->top!=-1)
    {
        int data = stack->array[stack->top];
        if(data>max)
            max = data;
        stack->top--;
    }
    return max;
}

int main() {
    int T;
    struct Stack* s = createStack(100000);
    struct Stack* m = createStack(100000);
    scanf("%d",&T);
    while(T--)
    {
        int comm;
        scanf("%d",&comm);
        if(comm==1)
        {
            int x;
            scanf("%d",&x);
            push(s,x);
            int max = m->array[m->top];
            if(x>max)
                push(m,x);
            else
                push(m,max);
        }
        else if(comm==2)
        {
            pop(s);
            pop(m);
        }   
        else
            printf("%d\n",m->array[m->top]);
    }
    return 0;
}
