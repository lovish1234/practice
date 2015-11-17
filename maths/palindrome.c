/**
 * @input A : Integer
 * 
 * @Output Integer 0 / 1. Return 0 if the number is not palindrome, else return 1
 */
int isPalindrome(int A) {
    
    if(A<0)
    {
        return 0;
    }
    int numDig=0,i=0,num=A;
    
    while(A)
    {
        A/=10;
        numDig++;
    }
   
    int *array = (int*)malloc(sizeof(int)*(numDig));

    while(num)
    {
        
        
        array[i] = num%10;
        i++;
        
        num/=10;
        
    }
    
   
    if(numDig%2==1)
    {
        for(i=0;i<((numDig/2)+1);i++)
        {
            
            if(array[i]==array[numDig-1-i])
            {
              
                continue;
            }
            else
            {
               
                return 0;
            }
        }
        return 1;
    }
    else
    {
        for(i=0;i<(numDig/2);i++)
        {
            if(array[i]==array[numDig-1-i])
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        return 1;
        
    }
    

        
}
