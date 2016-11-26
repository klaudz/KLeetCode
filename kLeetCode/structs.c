//
//  structs.c
//  kLeetCode
//
//  Created by klaudz on 11/26/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "structs.h"

struct ListNode *createListNode(int *num, int size)
{
    struct ListNode *l = NULL;
    struct ListNode *tmp = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode *t = malloc(sizeof(struct ListNode));
        memset(t, 0, sizeof(struct ListNode));
        t->val = num[i];
        if (l == NULL) {
            l = tmp = t;
        } else {
            tmp = tmp->next = t;
        }
    }
    return l;
}

void freeListNode(struct ListNode *l)
{
    // Do free
}

void printListNode(struct ListNode *l)
{
    if (l == NULL) {
        printf("(NULL)\n");
        return;
    }
    
    struct ListNode *tmp = l;
    printf("(");
    while (tmp) {
        if (tmp != l) {
            printf(" -> ");
        }
        printf("%d", tmp->val);
        tmp = tmp->next;
    }
    printf(")\n");
}
