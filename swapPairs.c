//
//  swapPairs.c
//  kLeetCode
//
//  Created by klaudz on 11/26/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"
#include "common/structs.h"

struct ListNode *swapPairs(struct ListNode *head) {
    
    struct ListNode *newHead = head;
    
    struct ListNode *pair = head;
    struct ListNode *lastPair = NULL;
    while (pair != NULL && pair->next != NULL) {
        struct ListNode *temp = pair;
        pair = pair->next;
        temp->next = pair->next;
        pair->next = temp;
        
        if (lastPair != NULL) {
            lastPair->next->next = pair;
        }
        if (newHead == head) {
            newHead = pair;
        }
        lastPair = pair;
        pair = temp->next;
    }
    
    return newHead;
}

int main(void)
{
    {
        int num[] = { 1, 2, 3, 4 };
        int size = sizeof(num) / sizeof(int);
        struct ListNode *l = create_list_node(num, size);
        struct ListNode *r = swapPairs(l);
        print_list_node(r);
    }
    {
        int num[] = { };
        int size = sizeof(num) / sizeof(int);
        struct ListNode *l = create_list_node(num, size);
        struct ListNode *r = swapPairs(l);
        print_list_node(r);
    }
    {
        int num[] = { 1 };
        int size = sizeof(num) / sizeof(int);
        struct ListNode *l = create_list_node(num, size);
        struct ListNode *r = swapPairs(l);
        print_list_node(r);
    }
    {
        int num[] = { 2, 4, 3 };
        int size = sizeof(num) / sizeof(int);
        struct ListNode *l = create_list_node(num, size);
        struct ListNode *r = swapPairs(l);
        print_list_node(r);
    }
}
