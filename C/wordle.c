#include <stdio.h>
#include <string.h>

int n,m;
// int letters[26] = {0};

int checkword(char cword[],char oword[],int check[]){
    int letters[26] = {0};
    for(int i =0; i<m-1; i++){
        letters[(int)(oword[i]) - 97]++;
    }

    for(int i =0; i<m-1; i++){
        if(cword[i] == oword[i]){
            check[i] = 1;
            letters[cword[i] - 97]--;
            continue;
        }
        //issue: camel lcaml 
        //displayed:   22221
        //correct:     02221

        if(letters[cword[i] - 97]){
            check[i] = 2;
            letters[cword[i] - 97]--;
            continue;
        }else{
            check[i] = 0;
        }
    }

    // for(int i =0; i<m-1; i++){
    //     printf("%d ",check[i]);
    // }     

    // printf("\n");


    return 0;

}

int ValidGuess(char word1[],char word2[],char oword[]){
    int check1[m];
    int check2[m];
    int sum11=0,sum12=0,sum21=0,sum22=0;
    
    sum11 = checkword(word1,oword,check1);
    sum11 = checkword(word2,oword,check2);
    
    for(int i=0;i<m;i++){
        if(check1[i]==2){
            sum12+= 2;
        }else if(check1[i]==1){
            sum11 += 1;
        }

        if(check2[i]==2){
            sum22+= 2;
        }else if(check2[i]==1){
            sum21 += 1;
        }
    }

    for(int i=0;i<m-1;i++){
        if(check1[i] ==1 && check2[i] != 1){
            // printf("error in 1\n");
            return 0;
        }else if(check1[i] ==1 && check2[i] == 1){
         sum11 --;
         sum21 --;   
        }else if((sum22 + sum21*2) < sum12){
            // printf("error in 2\n");
            // printf("%d %d %d",sum12,sum21,sum22);
            return 0;
        }
    } 

    return 1;
}



int main(){
    scanf("%d %d",&n,&m);
    n++;
    m++;
    char words[n][m];
    for(int i=0; i<n; i++){
        scanf("%s",words[i]);
        // printf("hi");
    }

    char oword[m];
    strcpy(oword,words[n-1]);

    // for(int i =0; i<m-1; i++){
    //     letters[(int)(oword[i]) - 97]++;
    // }

    // for(int i =0; i<26; i++){
    //     printf("%d ",letters[i]);
    // }

    //ValidGuess(words[0],words[1],oword)

    for(int i=0; i<n-1; i++){
        int count = 0;
        for(int j=0; j<n-1; j++){
            if(j==i) continue;

            if(ValidGuess(words[i],words[j],oword)){
                for(int k=0; k<n-1; k++){
                    if(k==j) continue;
                    else if(k==i) continue;

                    if(ValidGuess(words[j],words[k],oword)){
                        count++;
                    }
                }
            }
        }
        printf("%d\n",count);
    }

    return 0;
}