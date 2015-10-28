i/**
 * @input X : Integer array corresponding to the X co-ordinate
 * @input n1 : Integer array's ( X ) length
 * @input Y : Integer array corresponding to the Y co-ordinate
 * @input n2 : Integer array's ( Y ) length
 *
 * Points are represented by (X[i], Y[i])
 * 
 * @Output Integer
 *
 */
int coverPoints(int* X, int n1, int* Y, int n2) {
    int i,sum=0;
    
    for (i=0;i<n1-1;i++)
    {
        sum+=(abs(X[i+1]-X[i]) > abs(Y[i+1]-Y[i]) ? abs(Y[i+1]-Y[i]) : abs(X[i+1]-X[i]))+abs(abs(X[i+1]-X[i]) - abs(Y[i+1]-Y[i]));
    }
    return sum;
}
