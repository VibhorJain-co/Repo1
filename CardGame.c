#include <stdio.h>

int main(){
    int rounds;
    scanf("%d",&rounds);
    for (int i = 0; i < rounds; i++){
        int a1,a2,b1,b2;
        scanf("%d%d%d%d",&a1,&a2,&b1,&b2);

        int ways=0;
        if ((a1>=b1 && a2>=b2) & (a1 != b1 || a2 != b2)){
            ways +=2;
        }
        if ((a1>=b2 && a2>=b1) & (a1 != b2 || a2 != b1)){
            ways +=2;
        }
        printf("%d\n",ways);
    }
    
    return 0;
}