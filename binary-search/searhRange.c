/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 
int searchInd(const int *A, int n1, int B, int low, int high)
{
    int mid;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid]==B)
        {
            return mid;
        }
        else if(A[mid] > B)
        {
            high = mid -1;
        }
        else
        {
            low = mid +1;
        }
    }
    return -1;
}


int* searchRange(const int* A, int n1, int B, int *len1) {
    int low=0, high=n1-1,mid,midPrev,midNext,rangeStart=-1,rangeEnd=-1;
    *len1 = 2;
    int * result = (int*)malloc(sizeof(int)*(*len1));
    
    mid = searchInd(A,n1,B,low,high);
    midPrev = mid;
    midNext=mid;
    //printf("%d\n",mid);
    if(mid==-1)
    {
        result[0]=-1;
        result[1]=-1;
        return result;
    }
    
    while(midPrev!=-1)
    {
        midPrev=searchInd(A,n1,B,low,midPrev-1);
        //printf("%d\n",midPrev);
        if(midPrev!=-1)
        {
            rangeStart=midPrev;
   
        }
        
    }
    
    while(midNext!=-1)
    {
        midNext=searchInd(A,n1,B,midNext+1,high);
        if(midNext!=-1)
        {
            rangeEnd=midNext;

        }
        
    }
    
    if(rangeStart!=-1 && rangeEnd!=-1)
    {
        result[0]=rangeStart;
        result[1]=rangeEnd;
    }
    else if(rangeStart!=-1 && rangeEnd==-1)
    {
        result[0]=rangeStart;
        result[1]=mid;
    }
    else if(rangeStart==-1 && rangeEnd!=-1)
    {
        result[0]=mid;
        result[1]=rangeEnd;
    }
    else
    {
        result[0]=mid;
        result[1]=mid;
    }
   
   
    return result;
   
}

