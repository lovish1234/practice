/**
 * @input A : String termination by '\0'
 * @input B : String termination by '\0'
 * 
 * @Output Integer
 */
 
int numOfPoints(char *A)
{
    char *itr=A;
    int ans=0;
    while(*itr!='\0')
    {
        if(*itr=='.')
        {
            ans++;
        }
        itr++;
    }
    return ans;
}
int numOfDigits(char *A)
{
    char *itr=A;
    int ans=0;
    while(*itr!='\0')
    {
        if(*itr!='.')
        {
            ans++;
        }
        itr++;
    }
    
    return ans;
}

int reverseNum(int num, int length)
{
    //printf("%d\n",num);
    int rem, ans=0,i;
    for(i=0;i<length;i++)
    {
        ans+=(num%10)*pow(10,length-i-1);
        num/=10;
    }
    //printf("%d\n",ans);
    return ans;
}

void fillDigits(char *A, int* P_A)
{
    char*itr=A;
    int* itrP=P_A;
    int ans=0,i=0;
    while(*itr!='\0')
    {
        
        if(*itr=='.')
        {
            //do final calculation and put in P_A
            
            *itrP=reverseNum(ans,i);
            itrP++;
            ans=0;
            i=0;
            itr++;
        }
        else
        {
            
            // continue adding
            ans+=pow(10,i)*(*itr-'0');
            i++;
            itr++;
            
            if(*itr=='\0')
            {
                *itrP=reverseNum(ans,i);
                
            }
            
        }
    }
    
}

    
    

int compareVersion(char* A, char* B) {
    
    int nP_A=numOfPoints(A);
    int nP_B=numOfPoints(B);
    int max=(nP_A>nP_B)?nP_A:nP_B;
    int* P_A=(int*)malloc(sizeof(int)*(max+1));
    int* P_B=(int*)malloc(sizeof(int)*(max+1));
    int i;
    for(i=0;i<max+1;i++)
    {
        P_A[i]=0;
        P_B[i]=0;
    }
    
    
   // printf("%d %d\n",(nP_A+1),(nP_B+1));
    
    fillDigits(A,P_A);
    fillDigits(B,P_B);
    
    
    /*
    for(i=0;i<(max+1);i++)
    {
        printf("%d ",P_A[i]);
    }
    printf("\n");
    
    for(i=0;i<(max+1);i++)
    {
        printf("%d ",P_B[i]);
    }
    printf("\n");
    */
    // chnaged to accommodate 1.1.0 vs 1.1 comparison
    i=0;
    while(i<(max+1))
    {
        if(P_A[i]>P_B[i])
        {
            return 1;
        }
        else if(P_A[i]<P_B[i])
        {
            return -1;
        }
        else
        {
            i++;
        }
            
    }
    return 0;
   
    
    
}

