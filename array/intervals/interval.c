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
 
 struct Event 
 {
     int timeStamp;
     char beginOrEnd;
 };
 
 typedef struct Event event;
 
int compareFunction(const void* a, const void* b) {
        event value1 = *((event *)a);
        event value2 = *((event *)b);
        if (value1.timeStamp < value2.timeStamp) 
        {
            // Return -1 if you want ascending. 1 if you want descending. 
            return -1;
        } 
        else if (value1.timeStamp > value2.timeStamp) 
        {
            // Return 1 if you want ascending. -1 if you want descending. 
            return 1;
        }
        return 0;
    }
    
interval* insert(interval *intervals, int sz, interval newInterval, int *len) 
{
    int i, marker=0,noInterval=0;
    // add event timestamp and its type 
    event *a = (event*)malloc(sizeof(event)*(2*sz+2));
    
    for(i=0;i<sz;i++)
    {
        a[i].timeStamp = intervals[i].start;
        a[i].beginOrEnd = 'B';
    }
    
    for(i=sz;i<(2*sz);i++)
    {
        a[i].timeStamp = intervals[i].end;
        a[i].beginOrEnd = 'E';
    }
    
    a[2*sz+1].timeStamp = newInterval.start;
    a[2*sz+1].beginOrEnd = 'B';
    
    a[2*sz+2].timeStamp = newInterval.end;
    a[2*sz+2].beginOrEnd = 'E';
    
    qsort(a, (2*sz+2), sizeof(event), compareFunction );
    
    // count the number of intervels in result
    for(i=0;i<(2*sz+2);i++)
    {
        if(a[i].beginOrEnd=='B' )
        {
            if(marker==0)
            {
                noInterval++;
            }
            marker++;
        }
        else
        {
            marker--;
        }
    }
    
    interval* result = (interval*)malloc(sizeof(interval)*(noInterval));
    marker=0;
    noInterval=0;
    for(i=0;i<(2*sz+2);i++)
    {
        if(a[i].beginOrEnd=='B')
        {
            if(marker==0)
            {
                result[noInterval].start = a[i].timeStamp;
            }
            marker++;
            
        }
        else
        {
            marker--;
            if(marker==0)
            {
                result[noInterval].end = a[i].timeStamp;
                noInterval++;
            }
        }
    }
    
    return result;
}
