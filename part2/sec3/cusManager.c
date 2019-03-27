/**
 * Name: cusManager.c  ver1.0
 * Content: 고객 관련 업무 처리 함수들의 정의
 * Implementation
 * 
 * Last modified 
*/

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

/**
 * 함수: void RegistCustomer (void)
 * 기능: 신규 회원 가입
 * 반환: void
*/
void RegistCustomer(){
    char ID[ID_LEN];
    char name[NAME_LEN];
    char num[PHONE_LEN];

    printf("ID 입력: ");
    scanf("%s", ID);
    if (IsRegistID(ID) == 1) {
        printf("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해주세요.\n");
        return;
    }
    printf("이름 입력: ");
    scanf("%s", name);
    printf("전화번호 입력: ");
    scanf("%s", num);
    if (!AddCusInfo(ID, name, num)) {
        printf("정상적인 데이터 저장에 실패하였습니다.\n");
        getchar();
        return;
    }
    printf("가입이 완료되었습니다.\n");
    getchar();
}

/**
 * 함수: void SearchCusInfo (void)
 * 기능: ID를 통한 회원 정보 검색
 * 반환: void
*/
void SearchCusInfo(){
    char ID[ID_LEN];
    printf("찾는 ID 입력: ");
    scanf("%s", ID);
    cusInfo *Info;
    Info = GetCusPtrByID(ID);
    if (Info != NULL) {
        ShowCustomerInfo(Info);
    } else {
        printf("회원정보를 찾을 수 없습니다.\n);
    }
    
}

