#include <stdio.h>

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k); //n=rows  m=columns

    int count = 1;    

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j]=0;
        }
        
    }

    for (int i = 0; i < k; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        arr[x][y] = -1;

        for (int i = 0; i < count; i++)
        {
            /* code */
        }
        
    }
    
    

}