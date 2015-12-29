/**
 * @input A : array of strings termination by '\0'
 * @input n1 : number of strings in array A
 * 
 * @Output Integer
 */
 
#define MAX 1000000

typedef struct stack
{
    int array[MAX];
    int flag;
}stack;

int IsEmpty(stack *S)
{
    if(S->flag==-1)
    {
        return 1;
    }
    return 0;
}

int IsFull(stack *S)
{
    if(S->flag==(MAX-1))
    {
        return 1;
    }
    return 0;
}

void push(stack *S, int val)
{
    if(IsFull(S)!=1)
    {
        S->flag=S->flag+1;
        S->array[S->flag]=val;
    }
}

void pop(stack *S)
{
    if(IsEmpty(S)!=1)
    {
        S->flag=S->flag-1;
    }
}

int top(stack *S)
{
    if(IsEmpty(S)!=1)
    {
        return S->array[S->flag];
    }
}


typedef struct stackC
{
    char array[MAX];
    int flag;
    int prec[MAX];
}stackC;

int IsEmptyC(stackC *S)
{
    if(S->flag==-1)
    {
        return 1;
    }
    return 0;
}

int IsFullC(stackC *S)
{
    if(S->flag==(MAX-1))
    {
        return 1;
    }
    return 0;
}

void pushC(stackC *S, char val)
{
    if(IsFullC(S)!=1)
    {
       
        S->flag=S->flag+1;
        S->array[S->flag]=val;
        if(val=='+'||val=='-')
        {
            S->prec[S->flag]=1;
            
        }
        else
        {
            S->prec[S->flag]=2;
        }
    }
}

void popC(stackC *S)
{
    if(IsEmptyC(S)!=1)
    {
        S->flag=S->flag-1;
    }
}

char topC(stackC *S)
{
    if(IsEmptyC(S)!=1)
    {
        return S->array[S->flag];
    }
}

int getPrec(stackC *S)
{
    if(IsEmpty(S)!=1)
    {
        return S->prec[S->flag];
    }
}

int reverse(int number, int power)
{
    int answer=0;
    while(power>0)
    {
        answer+=(number%10)*pow(10,power-1);
        power--;
        number/=10;
    }
    return answer;
}


int evalRPN(char** A, int n1) {
    int i,number,power,negetive,op1,op2,integer=0;
    char *itrA;
    
    stack S;
    S.flag=-1;
    
    stackC SC;
    SC.flag=-1;
    
    // push the numbers and operators in two stacks
    for(i=0;i<n1;i++)
    {
        itrA=A[i];
        number=0;
        power=0;
        negetive=1;
        integer=0;
        // iterate over 
        while(*itrA!='\0')
        {
            if(*itrA=='*' )
            {
                op1=top(&S);
                pop(&S);
                op2=top(&S);
                pop(&S);
                number=op2*op1;
                push(&S,number);
            }
            else if(*itrA=='/')
            {
                op1=top(&S);
                pop(&S);
                op2=top(&S);
                pop(&S);
                number=op2/op1;
                push(&S,number);
            }
            else if(*itrA=='+' )
            {
                if(*(itrA+1)=='\0')
                {
                    op1=top(&S);
                    pop(&S);
                    op2=top(&S);
                    pop(&S);
                    number=op2+op1;
                    push(&S,number);
                }
                else
                {
                    //its a positive integer
                    negetive=1;
                    integer=1;
                }
            }
            else if(*itrA=='-' )
            {
                if(*(itrA+1)=='\0')
                {
                    op1=top(&S);
                    pop(&S);
                    op2=top(&S);
                    pop(&S);
                    number=op2-op1;
                    push(&S,number);
                }
                else
                {
                    //its a negetive integer
 
                    negetive=-1;
                    integer=1;
                }
            }
            else
            {
                integer=1;
                number+=(*itrA-'0')*pow(10,power);
                power++;
            }
            itrA++;
        }
        
        if(integer)
        {
            push(&S,reverse(number,power)*negetive);
        }
        
    }
    
   
    return top(&S);
}
