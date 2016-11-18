//
//  addTwoNumbers.c
//  kLeetCode
//
//  Created by klaudz on 18/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "addTwoNumbers.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }
    
    struct ListNode *r = NULL;
    struct ListNode *tmpL1 = l1;
    struct ListNode *tmpL2 = l2;
    struct ListNode *tmpR = NULL;
    int addition = 0;
    while (tmpL1 != NULL || tmpL2 != NULL || addition > 0) {
        struct ListNode *t = malloc(sizeof(struct ListNode));
        memset(t, 0, sizeof(struct ListNode));
        int sum = (tmpL1 ? tmpL1->val : 0) + (tmpL2 ? tmpL2->val : 0) + addition;
        t->val = sum % 10;
        addition = sum / 10;
        if (r == NULL) {
            r = tmpR = t;
        } else {
            tmpR = tmpR->next = t;
        }
        if (tmpL1 != NULL) tmpL1 = tmpL1->next;
        if (tmpL2 != NULL) tmpL2 = tmpL2->next;
    }
    return r;
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

void test_addTwoNumbers()
{
    int num1[] = { 2, 4, 3 };
    int size1 = sizeof(num1) / sizeof(int);
    struct ListNode *l1 = createListNode(num1, size1);
    int num2[] = { 5, 6, 4 };
    int size2 = sizeof(num2) / sizeof(int);
    struct ListNode *l2 = createListNode(num2, size2);
    
    struct ListNode *r = addTwoNumbers(l1, l2);
    
    printListNode(l1);
    printListNode(l2);
    printListNode(r);
    
//    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//    Output: 7 -> 0 -> 8
}
