#include <stdio.h>
#define MAXNUM  5

int main(){
    char inpString[MAXNUM][20];
    char tempStr[20];
    
    for(int i = 0; i < MAXNUM; i++)
    {
        printf("문자열 입력 %d: ", i+1);
        scanf("%s", &inpString[i]);
    }

    for(int i = 0; i < MAXNUM; i++)
    {
        printf("%s\n", inpString[i]);
    }
    return 0;
}