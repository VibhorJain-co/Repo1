#include <stdio.h>

int main(){
    int l1,r1,l2,r2,n;
    scanf("%d",&n);

    for(int j=0;j<n;j++){
        scanf("%d %d %d %d",&l1,&r1,&l2,&r2);

        int end=0,start=0,common=0;

        if(l1==l2){start = 1;}
        if (r1==r2){end=1;}
        for(int i=l1;i<=r1;i++){
            if(i<=r2 && i>=l2){
                common++;
            }
        }

        printf("%d\n",common + 1 - end - start);
    }

    return 0;
}