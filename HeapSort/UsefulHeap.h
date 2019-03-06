//
//  UsefulHeap.h
//  CDataStructure_2019
//
//  Created by MINJAE KIM on 27/01/2019.
//  Copyright © 2019 MINJAE KIM. All rights reserved.
//

#ifndef UsefulHeap_h
#define UsefulHeap_h

#define TRUE        1
#define FALSE       0

#define HEAP_LEN    100

typedef char HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap{
    PriorityComp *comp;
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif /* UsefulHeap_h */
