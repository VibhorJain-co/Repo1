#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse_and_replace_vowels(char *str, char replacement) {
    for(int i=0;*(str+i)!='\0';i++){
        if(*(str+i)=='a'||*(str+i)=='e'||*(str+i)=='i'||*(str+i)=='o'||*(str+i)=='u'){
            *(str+i)=replacement;
        }else if(*(str+i)=='\n'){
            *(str+i)=' ';
            
        }
    }
    
    int len =0;
    for(int i=0;*(str+i)!= '\0';i++){
        if(*(str+i)!= ' '){
            len++;
            // printf("%c",*(str+i));
            if(*(str+i) =='\0'){
                printf(" here ");
            }
        }else{
            i--;
             
            for(int j=0;j<=len/2;j++){
                char temp =*(str+i-j);
                *(str+i-j) = *(str+i+j-len+1);
                *(str+i+j-len+1) = temp;
                // printf("\n%c %c",*(str+i-j), *(str+i+j-len+1));
            }
            // printf("\n");
            i++;
            len = 0;
        }
    }
}

int is_substring(char *str1, char *str2) {
    int matching = 0;
    int lenmatch = 0;
    for(int i =0;*(str1+i)!= '\0';i++){
        if(*(str2+lenmatch)=='\0' && matching){
            return 1;
        }
        if(*(str1+i)==*(str2+lenmatch)){
            matching = 1;
            lenmatch++;
        }else{
            matching = 0;
            lenmatch = 0;
        }
    }
    if(*(str2+lenmatch)=='\0' && matching){
            return 1;
    }
    
    return 0;
}

int main() {
    char *str1 = (char *)malloc(101*sizeof(char));
    char replacement;
    char *str2 = (char *)malloc(101*sizeof(char));
    char *str3 = (char *)malloc(101*sizeof(char));
    int size;
    
    getline(&str1,&size,stdin);
    scanf("%c",&replacement);
    scanf("%s",str2);
    scanf("%s",str3);
    
    // printf("%s",str1);
    // printf("%c\n",replacement);
    // printf("%s\n",str2);
    // printf("%s\n",str3);
    
    reverse_and_replace_vowels(str1,replacement);
    printf("%s\n",str1);

    int matching = 0;
    matching = is_substring(str2,str3);
    if(matching){
        printf("yes");
    }else{
        printf("no");
    }
    
    return 0;
}