/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int canJump(int* A, int n) {
    int currentMax = 0, jumps = 0, i = 0;
    while(currentMax<n-1) 
    {
        int lastMax = currentMax;
        for(; i<=lastMax; i++) 
            currentMax = max(currentMax,i+A[i]);
        jumps++;
        if(lastMax == currentMax) return -1;
    }
    return jumps;
}
