//
//  mergeTwoLists.c
//  kLeetCode
//
//  Created by klaudz on 11/28/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"
#include "common/structs.h"

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    
    struct ListNode *l = NULL;
    struct ListNode *c = NULL;
    while (l1 != NULL && l2 != NULL) {
        struct ListNode *t = NULL;
        if (l1->val <= l2->val) {
            t = l1;
            l1 = l1->next;
        } else {
            t = l2;
            l2 = l2->next;
        }
        if (l == NULL) {
            c = l = t;
        } else {
            c = c->next = t;
        }
    }
    struct ListNode *t = l1 ? : l2;
    if (l == NULL) {
        l = t;
    } else {
        c->next = t;
    }
    return l;
}

int main(void)
{
    int num1[] = { 2, 3, 3 };
    int size1 = sizeof(num1) / sizeof(int);
    struct ListNode *l1 = createListNode(num1, size1);
    int num2[] = { 2, 6, 9 };
    int size2 = sizeof(num2) / sizeof(int);
    struct ListNode *l2 = createListNode(num2, size2);
    
    struct ListNode *r = mergeTwoLists(l1, l2);
    printListNode(r);
}
