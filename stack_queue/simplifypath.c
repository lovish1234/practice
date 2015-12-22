/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
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

typedef struct stackI
{
    int array[1000000];
    int top;
}stackI;

int IsFullI(stackI *S)
{
    if(S->top==999999)
    {
        return 1;
    }
    return 0;
}

int IsEmptyI(stackI *S)
{
    if(S->top==-1)
    {
        return 1;
    }
    return 0;
}

void pushI(stackI *S, int c)
{
    if(IsFullI(S)!=1)
    {
        S->top=S->top+1;
        S->array[S->top]=c;
    }
    else
    {
        printf("Stack Overflow SI\n");
    }
}
 
int popI(stackI *S)
{
    int x;
    if(IsEmptyI(S)!=1)
    {
        x=S->array[S->top];
        S->top=S->top-1;
        return x;
    }
    else
    {
        printf("Stack Underflow SI\n");
    }
}

int strLength(char *A)
{
    int count=0;
    char *itrA=A;
    while(*itrA!='\0')
    {
        count++;
        itrA++;
    }
    return count;
}

void reverse(char *string) 
{
   int length, c;
   char *begin, *end, temp;
 
   length = strLength(string);
   begin  = string;
   end    = string;
 
   for (c = 0; c < length - 1; c++)
      end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

char* simplifyPath(char* A) {
    stack S;
    S.top=-1;
    
    stackI SI;
    SI.top=-1;
    
    char* itrA=A;
    int countdots=0, countchar=0,itrSI=0;
    char dummy;
    
    while(*itrA!='\0')
    {
        //printf("%c\n",*itrA);
        
        if(*itrA=='.')
        {
            countdots++;
            if(countdots==2)
            {
                countdots=0;
                if(IsEmptyI(&SI)!=1)
                {
                    itrSI=popI(&SI);
                }
                //pop from S till SI[top]
                //printf("%d Y\n",itrSI);

                while(itrSI)
                {
                    dummy=pop(&S);
                    itrSI--;
                }
            }
            
        }
        else if(*itrA=='/')
        {
            if(countdots==1)
            {
                countdots=0;
            }
            else
            {
                //printf("%d\n",countchar);
                if(countchar!=0)
                {
                    pushI(&SI,countchar);
                }
                countchar=0;
            }
            //push countchar to SI[top]
            //printf("Here1\n");
            
        }
        else
        {
            push(&S,*itrA);
            countchar++;
            //push to S[top]
            //printf("Here2\n");
        }
        
        
        itrA++;
    }
    if(countchar!=0)
    {
        pushI(&SI,countchar);
    }
    
    char ans[1000000];
    int i=0;
    
    if(IsEmpty(&S)==1)
    {
        return "/";
    }
    while(IsEmpty(&S)!=1 && IsEmpty(&SI)!=1)
    {
        itrSI=popI(&SI);
       
        //printf("%d X\n",itrSI);
        
        while(itrSI)
        {
            ans[i]=pop(&S);
            //printf("%c ",ans[i]);
            itrSI--;
            i++;
        }
        //printf("\n");
        ans[i]='/';
        i++;
        
    }
    ans[i]='\0';
    reverse(ans);
 
    
    return ans;
}
