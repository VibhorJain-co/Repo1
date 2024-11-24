#include <stdio.h>

int main(){
    int tc;
    scanf("%d",&tc);
    for(int i=0;i<tc;i++){
        int n;
        scanf("%d",&n);

        int p[n],q[n];
        if(n%2 != 0){
            for(int j=0;j<n;j++){
                scanf("%d",&p[j]);
                if(p[j] > (n+1)/2){
                    q[j] = p[j] - (n+1)/2;
                }else if (p[j] < (n+1)/2){
                    q[j] = p[j] + (n+1)/2;
                }else{
                    q[j] = p[j];
                }
                
            }
        }else{
            for(int j=0;j<n;j++){
                scanf("%d",&p[j]);
            }
        }

        for(int j=0;j<n;j++){   
                printf("%d ",q[j]);
            }
    }
    return 0;
}