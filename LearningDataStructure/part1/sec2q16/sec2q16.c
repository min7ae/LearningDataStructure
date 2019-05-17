#include <stdio.h>

int main(){
    char c;

    while('\n' != scanf("%c", &c) ){
        if(c >= 'a' && c <= 'z'){
            printf("%c", c+'A'-'a');
        } else if (c >= 'A' && c <= 'Z'){
            printf("%c", c-'A'+'a');
        } else {
            printf("%c", c);
        }
    }
    
    return 0;
}