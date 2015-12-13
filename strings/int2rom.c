/**
 * @input A : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
 
int strLength(int A)
{
    int ans=0, rem=(A%10);
    while(A>0)
    {
        rem=(A%10);
        if(rem==1 || rem==5)
        {
            ans+=1;
        }
        else if(rem==2 || rem==4 || rem==9 || rem==6)
        {
            ans+=2;
        }
        else if(rem==3 || rem==7)
        {
            ans+=3;
        }
        else if(rem==8)
        {
            ans+=4;
        }
        else if(rem==0)
        {
            A/=10;
            continue;
        }
        else
        {
            printf("Error");
        }
        A/=10;
    }
    return ans;
}


char* intToRoman(int A) {
    int length = strLength(A);
    //printf("%d\n",length);
    char *result = (char*)malloc(sizeof(char)*(length+1));
    // i iterator on result array, j iterator on number
    int i=length-1,rem,j=0;
    result[i+1]='\0';
    while(A>0)
    {
        rem=A%10;
        
        if(rem==1)
        {
            if(j==0)
            {
                result[i]='I';
            }
            else if(j==1)
            {
                result[i]='X';
            }
            else if(j==2)
            {
                result[i]='C';
            }
            else  if(j==3)
            {
                result[i]='M';
            }
            else
            {
                printf("Error");
            }
            i--;
        }
        else if(rem==5)
        {
            if(j==0)
            {
                result[i]='V';
            }
            else if(j==1)
            {
                result[i]='L';
            }
            else if(j==2)
            {
                result[i]='D';
            }
            else
            {
                printf("Error");
            }
            i--;
            
        }
        else if(rem==2 )
        {
            if(j==0)
            {
                result[i]='I';
                result[i-1]='I';
            }
            else if(j==1)
            {
                result[i]='X';
                result[i-1]='X';
            }
            else if(j==2)
            {
                result[i]='C';
                result[i-1]='C';
            }
            else  if(j==3)
            {
                result[i]='M';
                result[i-1]='M';
            }
            else
            {
                printf("Error");
            }
            i-=2;
        }
        else if(rem==4)
        {
            if(j==0)
            {
                result[i]='V';
                result[i-1]='I';
            }
            else if(j==1)
            {
                result[i]='L';
                result[i-1]='X';
            }
            else if(j==2)
            {
                result[i]='D';
                result[i-1]='C';
            }
            else
            {
                printf("Error");
            }
            i-=2;
            
        }
        else if(rem==9)
        {
            if(j==0)
            {
                result[i]='X';
                result[i-1]='I';
            }
            else if(j==1)
            {
                result[i]='C';
                result[i-1]='X';
            }
            else if(j==2)
            {
                result[i]='M';
                result[i-1]='C';
            }
            else
            {
                printf("Error");
            }
            i-=2;
            
            
        }
        else if(rem==6)
        {
            if(j==0)
            {
                result[i]='I';
                result[i-1]='V';
            }
            else if(j==1)
            {
                result[i]='X';
                result[i-1]='L';
            }
            else if(j==2)
            {
                result[i]='C';
                result[i-1]='D';
            }
            else
            {
                printf("Error");
            }
            i-=2;
            
        }
        else if( rem==3)
        {
            if(j==0)
            {
                result[i]='I';
                result[i-1]='I';
                result[i-2]='I';
            }
            else if(j==1)
            {
                result[i]='X';
                result[i-1]='X';
                result[i-2]='X';
            }
            else if(j==2)
            {
                result[i]='C';
                result[i-1]='C';
                result[i-2]='C';
            }
            else  if(j==3)
            {
                result[i]='M';
                result[i-1]='M';
                result[i-2]='M';
            }
            else
            {
                printf("Error");
            }
            i-=3;
        }
        else if( rem==7)
        {
            if(j==0)
            {
                result[i]='I';
                result[i-1]='I';
                result[i-2]='V';
            }
            else if(j==1)
            {
                result[i]='X';
                result[i-1]='X';
                result[i-2]='L';
            }
            else if(j==2)
            {
                result[i]='C';
                result[i-1]='C';
                result[i-2]='D';
            }
            else
            {
                printf("Error");
            }
            i-=3;
        }
        else if(rem==8)
        {
            if(j==0)
            {
                result[i]='I';
                result[i-1]='I';
                result[i-2]='I';
                result[i-3]='V';
            }
            else if(j==1)
            {
                result[i]='X';
                result[i-1]='X';
                result[i-2]='X';
                result[i-3]='L';
            }
            else if(j==2)
            {
                result[i]='C';
                result[i-1]='C';
                result[i-2]='C';
                result[i-3]='D';
            }
            else
            {
                printf("Error");
            }
            i-=4;
            
        }
        else if(rem==0)
        {
            A/=10;
            j++;
            continue;
        }
        else
        {
            printf("Error");
        }
        
        A/=10;
        j++;
    }
    return result;
    
}

