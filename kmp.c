#include <stdio.h>
#include <string.h>

#define TAM (int)1e6+10

int main() {
    // Write C code here
    char string[TAM];
    char pattern[TAM];
    int lenString;
    int lenPattern;
    
    scanf("%s", string);
    scanf("%s", pattern);
    
    lenString = strlen(string);
    lenPattern = strlen(pattern);
    
    int lps[lenPattern];
    int len = 0;
    
    lps[0] = 0;
    
    for (int i = 1; i < lenPattern; i++){
        if (pattern[len] == pattern[i]){
            len++;
            lps[i] = len;
        }
        
        else {
            if (len == 0) {
                lps[i] = 0;
            }
            else {
                len = lps[len - 1];
                i = i - 1;
            }
        }
    }
    
    int j = 0;
    int count = 0;
    
    for (int i = 0; i < lenString; i++) {
        if (pattern[j] == string[i]){
            j++;
            
            if (j == lenPattern){
                count++;
                j = lps[j - 1];
            }
            
        }
        
        else {
            if (j != 0) {
                j = lps[j - 1];
                i--;
            }
        }
    }
    
    printf("%d\n", count);

    return 0;
}