//
//  UsefulHeap.c
//  CDataStructure_2019
//
//  Created by MINJAE KIM on 27/01/2019.
//  Copyright © 2019 MINJAE KIM. All rights reserved.
//

#include "UsefulHeap.h"

void HeapInit(Heap *ph, PriorityComp pc){
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph){
    if (ph->numOfData == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int GetParentIDX(int idx){
    return idx/2;
}

int GetLChildIDX(int idx){
    return idx*2;
}

int GetRChildIDX(int idx){
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx){
    if ( GetLChildIDX(idx) > ph->numOfData ) {
        return 0;
    } else if (GetLChildIDX(idx) == ph->numOfData) {
        return GetLChildIDX(idx);
    } else {
        ph->comp(
    }
}

void HInsert(Heap *ph, HData data){
    
    
    if (<#condition#>) {
        <#statements#>
    }
}
HData HDelete(Heap *ph);
