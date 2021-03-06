/**
 * Name: main.c  ver1.0
 * Content: DVD 대여 관리 프로그램 main
 * Implementation
 * 
 * Last modified 
*/

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"

enum {CUS_REGIST = 1,
    CUS_SEARCH,
    QUIT};

int main(){
    int inputMenu = 0;

    while(1){
        ShowMenu();
        scanf("%d", &inputMenu);
        getchar();
        
        switch (inputMenu)
        {
            case CUS_REGIST:
                RegistCustomer();
                break;

            case CUS_SEARCH:
                SearchCusInfo();
                break;

            if (inputMenu == QUIT) {
                puts("이용해 주셔서 고마워요");
                break;
            }
            
        }
    }

    return 0;
}