//
//  addTwoNumbers.c
//  kLeetCode
//
//  Created by klaudz on 18/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"
#include "common/structs.h"

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

int main(void)
{
    int num1[] = { 2, 4, 3 };
    int size1 = sizeof(num1) / sizeof(int);
    struct ListNode *l1 = create_list_node(num1, size1);
    int num2[] = { 5, 6, 4 };
    int size2 = sizeof(num2) / sizeof(int);
    struct ListNode *l2 = create_list_node(num2, size2);
    
    struct ListNode *r = addTwoNumbers(l1, l2);
    
    print_list_node(l1);
    print_list_node(l2);
    print_list_node(r);
    
//    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//    Output: 7 -> 0 -> 8
}
