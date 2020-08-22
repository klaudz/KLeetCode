//
//  structs.h
//  kLeetCode
//
//  Created by klaudz on 11/26/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#ifndef structs_h
#define structs_h

#include "defines.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

k_extern
struct ListNode *createListNode(int *num, int size);

k_extern
void freeListNode(struct ListNode *l);

k_extern
void printListNode(struct ListNode *l);

#endif /* structs_h */
