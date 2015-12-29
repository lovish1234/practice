#define MAX 1000000

typedef struct stack
{
    int array[MAX];
    int top;
}stack;

stack S;
stack MS;

    
void init() {
    

    S.top=-1;   
    MS.top=-1;
  
}


int IsFullC(stack *S)
{
    if(S->top==(MAX-1))
    {
        return 1;
    }
    return 0;
}

int IsEmptyC(stack *S)
{
    if(S->top==-1)
    {
        return 1;
    }
    return 0;
}

void pushC(stack *S, int c)
{
    S->top=S->top+1;
    S->array[S->top]=c;
}

int topC(stack *S)
{
    int x;
    x=S->array[S->top];
    return x;
}

void popC(stack *S)
{
    S->top=S->top-1;
}


void push(int x) {
    pushC(&S, x);
    if(IsEmptyC(&MS)==1)
    {
        pushC(&MS,x);
    }
    else
    {
        if(topC(&MS)>=x)
        {
            pushC(&MS,x);
        }
    }
}

void pop() {
  
    if(IsEmptyC(&S)!=1)
    {
        if(topC(&S)==topC(&MS))
        {
            popC(&S);
            popC(&MS);
        }
        else
        {
            popC(&S);
        }
    }

}

int top() {
    
    if(IsEmptyC(&S)!=1)
    {
        return topC(&S);
    }
    else
    {
        return -1;
    }
}

int getMin() {
    
    if(IsEmptyC(&MS)==1)
    {
        return -1;
    }
    else
    {
        return topC(&MS);
    }
}
