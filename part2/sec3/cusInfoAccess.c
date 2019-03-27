/**
 * Name: cusInfoAccess  ver1.0
 * Content: 고객 정보 저장 및 참조 함수들의 정의
 * Implementation
 * 
 * Last modified 
*/

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER    100

static cusInfo* cusList[MAX_CUSTOMER];
static int numOfCustomer=0;

/**
 * 함수: int AddCusInfo(char* ID, char* name, char* num)
 * 기능: cusInfo 할당 및 저장
 * 반환: 성공 시 '등록된 정보의 개수', 실패시 0을 반환
*/
int AddCusInfo(char* ID, char* name, char* num){

    cusInfo *pCus;

    if (numOfCustomer >= MAX_CUSTOMER) {
        return 0;
    }
    pCus = (cusInfo*) malloc(sizeof(cusInfo));
    strcpy(pCus->ID, ID);
    strcpy(pCus->name, name);
    strcpy(pCus->phoneNum, num);
    cusList[numOfCustomer++] = pCus;
    return numOfCustomer;
}

/**
 * 함수: cusInfo* GetCusPtrByID(char *ID)
 * 기능: 해당 ID의 정보를 담고 있는 변수의 포인터 반환
 * 반환: 등록 안된 ID의 경우 NULL 포인터 반환
*/
cusInfo* GetCusPtrByID(char *ID){
    for(int i = 0; i < numOfCustomer; i++)
    {
        if (!strcmp(cusList[i]->ID, ID)) {
            return cusList[i];
        }
    }
    return NULL;
}

/**
 * 함수: int ISRegistID(char *ID)
 * 기능: 가입 된 ID인지 확인
 * 반환: 가입 되었으면 1, 아니면 0 반환
*/

int IsRegistID(char *ID){
    cusInfo *pCus = GetCusPtrByID(ID);
    if (pCus == 0) {
        return 0;
    } else {
        return 1;
    }
    
}