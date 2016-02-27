/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int bulbs(int* A, int n1) {
    int state= 0, ans = 0, i;
    for ( i = 0; i < n1;i++) 
	{
        if (A[i] == state) 
		{
            ans++;
            state = 1 - state;
        }
    }
     
    return ans;
}

