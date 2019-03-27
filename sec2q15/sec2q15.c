#include <stdio.h>

int main(){
    char toinpchar;

    while( EOF != (toinpchar = getchar())){
        if(toinpchar >= 'a' && toinpchar <= 'z'){
            printf("입력하신 문자는 알파벳 소문자입니다.\n");
        } else if (toinpchar >= 'A' && toinpchar <= 'Z'){
            printf("입력하신 문자는 알파벳 대문자입니다.\n");
        } else if (toinpchar >= '0' && toinpchar <= '9' ){
            printf("입력하신 문자는 아라비아숫자입니다.\n");
        } else {
            printf("특수문자를 입력하셨군요.\n");
        }
        getchar();
    }

    printf("프로그램을 종료합니다.\n");  
    return 0;
}