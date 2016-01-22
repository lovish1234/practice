/**
 * @input A : 2D char array 
 * @input n11 : char array's ( A ) rows
 * @input n12 : char array's ( A ) columns
 * 
 * @Output Void. Just modifies the args passed by reference 
 */
 
/*
Keeping in mind the sudoku board is of length 9*9. For any other n*n, we can have sqrt(n) as the size
of box
*/
int validBox(char **A, int i, int j)
{
    int x,y;
    int tI= (i)%3;
    int tJ= (j)%3;
    
    //if tX is 0, first row or column of this box, need to vary x from i to i+2
    // if tX is 1, middle row or column of this box, need to vary x from i-1 to i+1
    // if tX is 2, last row or column of this box,need to vary x from i-2 to i
    
    for(x=i-tI;x<=i-tI+2;x++)
    {
        for(y=j-tJ;y<=j-tJ+2;y++)
        {
            if( i!=x && j!=y && A[i][j]==A[x][y])
            {
                return 0;
            }
        }
    }
    return 1;
}

int validRow(char **A, int i, int j)
{
    int k;
    for(k=0;k<9;k++)
    {
        if(k!=i && A[k][j]==A[i][j])
        {
            return 0;
        }
    }
    return 1;
}

int validColumn(char **A, int i, int j)
{
    int k;
    for(k=0;k<9;k++)
    {
        if(k!=j && A[i][j]==A[i][k])
        {
            return 0;
        }
    }
    return 1;
}



void getSets(char **A, int i, int j, char** ans)
{
    int x,l,m;

    if(j==9 && i==9)
    {
        for(l=0;l<9;l++)
        {
            for(m=0;m<9;m++)
            {
                ans[l][m]=A[l][m];
            }
        }
        return;
    }
    
    //if the gird at position i or j is empty or unassigned
    if(A[i][j]=='.')
    {
        for(x=1;x<=9;x++)
        {
            A[i][j]=x+'0';
            if(validColumn(A,i,j) && validRow(A,i,j) && validBox(A,i,j))
            {

                if(i==8 && j==8)
                {
                    getSets(A,i+1,j+1,ans);
                    
                }
                else if(i==8)
                {
                    getSets(A,0,j+1,ans);
                }
                else
                {
                    getSets(A,i+1,j,ans);
                }
            }
            A[i][j]='.';
        }
    }
    else
    {
        if(i==8 && j==8)
        {
            getSets(A,i+1,j+1,ans);
        }
        else if(i==8)
        {
            getSets(A,0,j+1,ans);
        }
        else
        {
            getSets(A,i+1,j,ans);
        }
    }

    
}
 
void solveSudoku(char** A, int n11, int n12) {
    // assuming n11 and n12 to be 9 for now
    int i,j;
    char**ans=(char**)malloc(sizeof(char*)*9);
    for(i=0;i<9;i++)
    {
        ans[i]=(char*)malloc(sizeof(char)*9);
    }
    
    getSets(A,0,0,ans);
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            A[i][j]=ans[i][j];
        }
    }

}
