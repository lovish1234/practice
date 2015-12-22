/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */

typedef struct stack
{
    //char data[10000];
    int type[250000];
    //int direction[100];
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
    if(S->top==249999)
    {
        return 1;
    }
    return 0;
}

void push(stack *S, char c, int t)
{
    if(IsFull(S)!=1)
    {
        S->top=S->top+1;
        //S->data[S->top]=c;
        S->type[S->top]=t;
        //S->direction[S->top]=d;
     
    }
    else
    {
        printf("Stack Overflow");
    }
}

int paranType(char c)
{
    if(c=='{' || c=='}')
    {
        return 1;
    }
    else if(c=='(' || c==')')
    {
        return 2;
    }
    else if(c=='[' || c==']')
    {
        return 3;
    }
    else
    {
        printf("Wrong character");
        return 0;
    }
}

int paranDirec(char c)
{
    if(c=='{' || c=='(' || c=='[')
    {
        return 1;
    }
    else if(c=='}' || c==')' || c==']')
    {
        return 2;
    }
    else
    {
        printf("Wrong character");
        return 0;
    }
}

void pop(stack *S)
{
    //char x;
    if(IsEmpty(S)!=1)
    {
        //x=S->data[S->top];
        S->top=S->top-1;
        //return x;
    }
    else
    {
        printf("Stack Underflow");
    }
}

int t(stack *S)
{
    int x;
    if(IsEmpty(S)!=1)
    {
        x=S->type[S->top];
        return x;
    }
    else
    {
        printf("Stack Underflow");
    }
}

int isValid(char* A) {
    
    stack S;
    S.top=-1;
    
    char* itrA=A;
    while(*itrA!='\0')
    {
        //printf("%d ",paranDirec(*itrA));
        if(IsFull(&S)==1)
        {
            printf("Stack is Full\n");
            break;
        }
        
        if(paranDirec(*itrA)==1)
        {
            push(&S,*itrA,paranType(*itrA));
            //printf("pushing %c to stack",*itrA);
        
        }
        else if(paranDirec(*itrA)==2 && IsEmpty(&S)!=1 && t(&S)==paranType(*itrA))
        {
            pop(&S);
        }
        else
        {
            //printf("Symbol not valid.\n");
            return 0;
        }
        
        
        itrA++;
    }
    
    return IsEmpty(&S)?1:0;
    
}
