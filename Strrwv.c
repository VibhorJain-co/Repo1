#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse_and_replace_vowels(char *str, char replacement) {
    // Complete the function
}
int is_substring(char *str1, char *str2) {
    // Complete the function
}
int main() {
    char *str1 = (char *)malloc(101*sizeof(char));
    char replacement;
    char *str2 = (char *)malloc(101*sizeof(char));
    char *str3 = (char *)malloc(101*sizeof(char));
    int size;
    
    getline(&str1&size,stdin);
    scanf("%c",&replacement);
    scanf("%s",str2);
    scanf("%s",str3);
    
    printf("%s",str1);
    printf("%c\n",replacement);
    printf("%s\n",str2);
    printf("%s\n",str3);
    
    // reverse_and_replace_vowels(str1,replacement);
    
    return 0;
}