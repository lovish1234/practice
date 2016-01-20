/**
 * @input A : Integer
 * 
 * @Output 2D string array. You need to malloc memory. Fill in len1 as row, len2 as columns. All strings should end with '\0'. 
 * For example, a valid output : [["..Q.","Q...", "...Q", ".Q.." ], [".Q..", "...Q", "Q...", "..Q."]] 
 * len1 = 2, len2 = 4. 
 */
#define SOL_MAX 10000
int k;

void init()
{
    k=0;
}

// if the queens on board are threatened due to new queen, the layout is invalid.
// queens are threatened if they lie in same row, column, up-diagonal or down-diagonal
int threatQueens(char **temp, int A, int row, int column)
{
    //printf("Here\n");
    int i;
    // as we are already placing one queen in one row, we only need to check columns and diagonals
    
    //column
    for(i=0;i<A;i++)
    {
        if(i!=row)
        {
            if(temp[i][column]=='Q')
            {
                return 1;
            }
        }
    }

    //up-diagonal
    i=1;
    while((i+row)<A && (column-i)>=0 )
    {
        if(temp[row+i][column-i]=='Q')
        {
            //printf("Threatened at upper diagonal %d %d\n",row+i,column-i);
            return 1;
        }
        i++;
    }
    
    i=1;
    while((row-i)>=0 && (column+i)<A)
    {
        if(temp[row-i][column+i]=='Q')
        {
            //printf("Threatened at upper diagonal %d %d\n",row-i,column+i);
            return 1;
        }
        i++;
    }
    
    
    
    //down-diagonal
    i=1;
    while((row+i)<A &&  (column+i)<A)
    {
        if(temp[row+i][column+i]=='Q')
        {
            //printf("Threatened at down diagonal %d %d\n",row+i,column+i);
            return 1;
        }
        i++;

    }
    
    i=1;
    while((row-i)>=0 && (column-i)>=0)
    {
        if(temp[row-i][column-i]=='Q')
        {
            //printf("Threatened at down diagonal %d %d\n",row-i,column-i);
            return 1;
        }
        i++;
    }
    
    
    return 0;
}

void getSets(char*** resultInt, int row, char** temp, int A)
{
    int i,j;
    //printf("%d\n",row);
    // if placed one queen in every row of chess board successfully
    if(row==A)
    {
        for(i=0;i<A;i++)
        {
            for(j=0;j<A;j++)
            {
                resultInt[k][i][j]=temp[i][j];
            }
        }
        k++;
        return;
    }
    else
    {
        for(i=0;i<A;i++)
        {
            // place the queen at ith column of row and check if threatens other queens present on board
            temp[row][i]='Q';
            
            if(threatQueens(temp, A, row, i)==0)
            {
                getSets(resultInt, row+1, temp, A);
            }
            temp[row][i]='.';
        }
    }
}

char*** solveNQueens(int A, int *len1, int *len2) {
    
    int i,j,x;
    
    char*** resultInt=(char***)malloc(sizeof(char**)*SOL_MAX);
    for(i=0;i<SOL_MAX;i++)
    {
        resultInt[i]=(char**)malloc(sizeof(char**)*A);
        for(j=0;j<A;j++)
        {
            resultInt[i][j]=(char*)malloc(sizeof(char)*A);
        }
    }
    for(x=0;x<SOL_MAX;x++)
    {
        for(i=0;i<A;i++)
        {
            for(j=0;j<A;j++)
            {
                resultInt[x][i][j]='.';
            }
        }
    }
    
    
    char** temp=(char**)malloc(sizeof(char*)*A);
    for(i=0;i<A;i++)
    {
        temp[i]=(char*)malloc(sizeof(char)*A);
    }
    for(i=0;i<A;i++)
    {
        for(j=0;j<A;j++)
        {
            temp[i][j]='.';
        }
    }
    
    
    init();
    getSets(resultInt, 0, temp, A);
    

    
    *len1=k;
    *len2=A;
    return resultInt;
}
