/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
typedef struct stack
{
    char array[1000000];
    int top;
}stack;

int IsFull(stack *S)
{
    if(S->top==999999)
    {
        return 1;
    }
    return 0;
}

int IsEmpty(stack *S)
{
    if(S->top==-1)
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
        S->array[S->top]=c;
    }
    else
    {
        printf("Stack Overflow S \n");
    }
}

char pop(stack *S)
{
    char x;
    if(IsEmpty(S)!=1)
    {
        x=S->array[S->top];
        S->top=S->top-1;
        return x;
    }
    else
    {
        printf("Stack Underflow S\n");
    }
}

 
int braces(char* A) {
    stack S;
    S.top=-1;
    
    stack O;
    O.top=-1;
    
    char* itrA=A;
    char x;
    while(*itrA!='\0')
    {
        if(*itrA=='+' || *itrA=='-' || *itrA=='*' || *itrA=='/')
        {
            if(IsEmpty(&S)!=1)
            {
                push(&O,*itrA);
            }
        }
        else if (*itrA=='(')
        {
            push(&S,*itrA);
        }
        else if( *itrA==')')
        {
            if(pop(&S)=='(')
            {
                if(IsEmpty(&O)!=1)
                {
                    x=pop(&O);
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                printf("Invalid Input");
            }
            
        }
        else
        {
            itrA++;
            continue;
        }
        itrA++;
    }
    
    return IsEmpty(&S)?0:1;
}
