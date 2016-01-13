/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxArea(int* A, int n1) {
    if(n1==1)
    {
        return 0;
    }
    
    int mArea=INT_MIN,area,i=0,j=n1-1,height,width,minIndex;
    
    while(j>=i)
    {
        height=(A[i]<A[j])?A[i]:A[j];
        
        // if i is minimum bottleneck set minIndex to 1 else 0
        minIndex=(A[i]<A[j])?1:0;
        width=(j-i);
        area=height*width;
        mArea=(area>mArea)?area:mArea;
        if(minIndex==1)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return mArea;
}
