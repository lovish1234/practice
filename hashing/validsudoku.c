/**
 * @input A : Read only ( DON'T MODIFY ) array of strings termination by '\0'
 * @input n1 : number of strings in array A
 * 
 * @Output Integer
 */
int isValidSudoku(const char** A, int n1) {
    int R[9][9], C[9][9], B[3][3][9];
    int i,j,k,number;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            R[i][j]=0;
            C[i][j]=0;
        }
    }
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<9;k++)
            {
                B[i][j][k]=0;
            }
        }
    }
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(A[i][j]>'0' && A[i][j]<='9')
            {
                // -'1' and not -'0' because the R[i][9] will cause problems 
                number=A[i][j]-'1';
                //printf("%c %d\n",A[i][j],number);
                if(R[i][number])
                {
                    return 0;
                }
                else
                {
                    R[i][number]=1;
                }
                
                if(C[j][number])
                {
                    return 0;
                }
                else
                {
                    C[j][number]=1;
                }
                
                if(B[i/3][j/3][number])
                {
                    return 0;
                }
                else
                {
                    B[i/3][j/3][number]=1;
                }
            }
        }
    }
    return 1;
}

