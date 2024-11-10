#include <stdio.h>

int main(){
    int tc,size,n;
    scanf("%d",&tc);
    for(int i=0; i<tc;i++){
        
        scanf("%d",&size);
        long long temp[size];
        char str[size+1];
        
        for(int j=0;j<size;j++){
            scanf("%lld",&temp[j]);
        }
        
        scanf("%d",&n);
        
        for(int  j=0;j<n;j++){
            int same = 1;
            int lenstr = 0;
            
            scanf("%s",str);
            
            for(int l=0; str[l]!='\0';l++){
                lenstr++;
            }

            for(int k=0;k<size;k++){
                for(int l=1;l<size-k;l++){
                    if((temp[k]==temp[k+l]) ^ (str[k]==str[k+l])){
                        same = 0;
                        break;
                    }
                }
                if(!same)break;
            }
            if(same && size==lenstr){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    
    return 0;
}