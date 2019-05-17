/**
 * Name: cusInfo.h  ver1.0
 * Content: 고객 관리 구조체
 * Implementation
 * 
 * Last modified 
*/

#ifndef __CUSINFO_H__
#define __CUSINFO_H__

#define ID_LEN  10
#define NAME_LEN  10
#define PHONE_LEN  10

typedef struct _curInfo
{
    char ID[ID_LEN];
    char name[NAME_LEN];
    char phoneNum[PHONE_LEN];
} cusInfo;

#endif