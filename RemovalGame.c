#include <stdio.h>

int main(){
    int TC,n;
    scanf("%d",&TC);
    for(int i=0;i<TC;i++){
        scanf("%d",&n);
        int alice[n],bob[n];
        int same = 1,revsame=1;
        for (int j = 0; j < n; j++){
            scanf("%d",&alice[j]);
        }
        for (int j = 0; j < n; j++){
            scanf("%d",&bob[j]);
        }
        for (int j = 0; j < n; j++){
            if(alice[j]!=bob[j]){
                same=0;
            }
            if(alice[n-1-j]!=bob[j]){
                revsame=0;
            }
        }

        if (same || revsame)
        {
            printf("Bob\n");
        }else{
            printf("Alice\n");
        }
        if(0){
            printf("");
        }
    }
    return 0;
}