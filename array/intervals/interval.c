/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 *
 * typedef struct Interval interval;
 */
/*
 * intervals : the array of interval
 * sz : number of entries in intervals
 * newInterval : new Interval to be inserted
 * len : populate the length of returned array of intervals in len
 */
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

int min(int a, int b)
{
    if(a>b)
    {
        return b;
    }
    return a;
}
int overlap(interval A, interval N)
{
    int ans;
    ans = max(A.start, N.start) <= min(A.end, N.end);
    if(ans==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

interval superInterval (interval A, interval N)
{
    interval ans;
    ans.start = min(A.start, N.start);
    ans.end = max(A.end, N.end);
    return ans;
}

int checkInterval(interval* A, int sz, interval N)
{
    int i;
    for(i=0;i<sz;i++)
    {
        if(A[i].end < N.start && A[i+1].start > N.end)
        {
            return i;
        }
    }
    return -1;
}

interval* insert(interval *intervals, int sz, interval newInterval, int *len) 
{
    // Intervels are already sorted in increasing order.
    int i,count=0,ibegin;
    interval superInt = newInterval;
    for(i=0;i<sz;i++)
    {
        if (overlap(intervals[i], superInt)==1)
        {
            if(count==0)
            {
                ibegin=i;
            }
            count++;
            
            superInt = superInterval(intervals[i],superInt);
           // printf("%d %d \n",superInt.start,superInt.end);
        }
        
    }
    
    // if size of previous sequence is 0
    if (sz==0)
    {
        *len = 1;
        interval* result = (interval*)malloc(sizeof(interval)*(*len));
        result[0]=newInterval;
        return result;
    }
    // if new interval falls before every other interval
    if( newInterval.end < intervals[0].start)
    {
        *len = sz+1;
        interval* result = (interval*)malloc(sizeof(interval)*(*len));
        result[0]=newInterval;
        for(i=1;i<sz+1;i++)
        {
            result[i]=intervals[i-1];
        }
        return result;
    }
    // if new interval falls after every other interval
    if( newInterval.start > intervals[sz-1].end)
    {
        *len = sz+1;
        interval* result = (interval*)malloc(sizeof(interval)*(*len));
        result[sz]=newInterval;
        for(i=0;i<sz;i++)
        {
            result[i]=intervals[i];
        }
        return result;
        
    }
    // if new interval falls inbetween two intervals 
    int midIndex = checkInterval( intervals,  sz, newInterval);
    
    if (midIndex!=-1)
    {
        *len = sz+1;
        interval* result = (interval*)malloc(sizeof(interval)*(*len));
       
        //printf("%d\n",midIndex);
        for(i=0;i<sz+1;i++)
        {
            if(i==(midIndex+1))
            {
                result[i]=newInterval;
                //printf(" New %d %d\n",newInterval.start,newInterval.end);
            }
            else if(i<midIndex+1)
            {
                result[i]=intervals[i];
                //printf("%d %d\n",intervals[i].start,intervals[i].end);
            }
            else
            {
                result[i]=intervals[i-1];
            }
        }
        
    
        return result;
        
    }
    
    
   // printf("%d %d\n",ibegin,count);
    
    *len = sz-count+1;
    interval* result = (interval*)malloc(sizeof(interval)*(*len));
    
    for(i=0;i<(*len);i++)
    {
        if(i==ibegin)
        {
            result[i] = superInt;
        }
        else if(i<ibegin)
        {
            result[i] = intervals[i];
        }
        else
        {
            result[i] = intervals[i+count-1];
        }
    }
    
    return result;
    
}
