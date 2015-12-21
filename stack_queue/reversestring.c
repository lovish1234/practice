/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */
typedef struct stack
{
    char data[100];
    int top;
}stack;

int IsEmpty(stack *S)
{
    if(S->top==-1)
    {
        return 1;
    }
    return 0;
}

int IsFull(stack *S)
{
    if(S->top==99)
    {
        return 1;
    }
    return 0;
}

void push(stack *S, char c)
{
    if(IsFull(S)!=1)
    {
        S->top=S->top+1;
        S->data[S->top]=c;
    }
    else
    {
        printf("Stack Overflow");
    }
}

char topS(stack *S)
{
    if(IsEmpty(S)!=-1)
    {
        return S->data[S->top];
    }
    else
    {
        printf("Stack is empty. Nothing to return");
    }
}

char pop(stack *S)
{
    char x;
    if(IsEmpty(S)!=-1)
    {
        x=topS(S);
        S->top=S->top-1;
        return x;
    }
    else
    {
        printf("Stack already empty. Nothing to pop");
    }
    
}
char* reverseString(char* A) {
    stack S;
    S.top=-1;
    
    char *itrA=A;
    while(*itrA!='\0')
    {
       // printf("%c\n",*itrA);
        push(&S,*itrA);
        itrA++;
    }
    
    int i=0;
    while(!IsEmpty(&S))
    {
        A[i]=pop(&S);
        i++;
    }
    A[i]='\0';
    return A;
    
}
