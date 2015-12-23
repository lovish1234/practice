/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

typedef struct stack
{
    int array[1000000];
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

void push(stack *S, int c)
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

int pop(stack *S)
{
    int x;
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

 
int* prevSmaller(int* A, int n1, int *len1) {
    int i,j;
    *len1=n1;
    int* result=(int*)malloc(sizeof(int)*(*len1));
    result[0]=-1;
    
    stack S1;
    S1.top=-1;
    
    int temp;
    
    for(i=1;i<n1;i++)
    {
       if(A[i-1]<A[i])
       {
           result[i]=A[i-1];
           push(&S1,A[i-1]);
       }
       else
       {
           while(IsEmpty(&S1)!=1)
           {
               // as soon as you get an element less than A[i]
               temp=pop(&S1);
               if(temp<A[i])
               {
                   result[i]=temp;
                   push(&S1,temp);
                   break;
               }
           }
           if(IsEmpty(&S1)==1)
           {
               result[i]=-1;
               push(&S1,A[i]);
           }
           
       }
    }
    
    return result;
}

