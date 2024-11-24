#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n;
    scanf("%d",&n);

    int k;
    for(k=1;1;k++){
        if(n>pow(2,k) && n<pow(2,k+1)-1){
            break;
        }
    }
    int i=1;
    for(i=1;n-pow(2,k)>0;n--){
        i +=2;
    }

    printf("%d",i);
}