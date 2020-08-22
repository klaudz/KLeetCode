//
//  25_reverse_nodes_in_kgroup.c
//  KLeetCode
//
//  Created by klaudz on 11/26/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"
#include "common/structs.h"

struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    
    if (k == 0) {
        return head;
    }
    
    struct ListNode *newHead = head;
    
    struct ListNode *lastGTail = NULL;
    struct ListNode *curr = head;
    int i = 1;
    while (curr != NULL) {
        
        struct ListNode *next = curr->next;
        
        if (i % k == 0) {
            // Reverse group
            // ... 0 | - [1] 2 3 4 | 5 ...
            // ... 0 | 1 - [2] 3 4 | 5 ...
            // ... 0 | 2 1 - [3] 4 | 5 ...
            // ... 0 | 3 2 1 - [4] | 5 ...
            struct ListNode *newGTail = (lastGTail == NULL ? head : lastGTail->next);
            struct ListNode *newGHead = newGTail;
            struct ListNode *curr2 = newGTail;
            while (curr2 != next) {
                struct ListNode *next2 = curr2->next;
                curr2->next = newGHead;
                newGTail->next = next2;
                newGHead = curr2;
                curr2 = newGTail->next;
            }
            if (lastGTail != NULL) {
                lastGTail->next = newGHead;
            } else {
                newHead = newGHead;
            }
            newGTail->next = next;
            lastGTail = newGTail;
        }
        
        curr = next;
        i++;
    }
    
    return newHead;
}

int main(void)
{
    {
        int num[] = { 1, 2, 3, 4, 5 };
        int size = sizeof(num) / sizeof(int);
        struct ListNode *l = create_list_node(num, size);
        struct ListNode *r = reverseKGroup(l, 2);
        print_list_node(r);
    }
    {
        int num[] = { 1, 2, 3, 4, 5 };
        int size = sizeof(num) / sizeof(int);
        struct ListNode *l = create_list_node(num, size);
        struct ListNode *r = reverseKGroup(l, 3);
        print_list_node(r);
    }
    {
        int num[] = { 1, 2, 3, 4, 5 };
        int size = sizeof(num) / sizeof(int);
        struct ListNode *l = create_list_node(num, size);
        struct ListNode *r = reverseKGroup(l, -1);
        print_list_node(r);
    }
    {
        int num[] = { 1, 2, 3, 4, 5 };
        int size = sizeof(num) / sizeof(int);
        struct ListNode *l = create_list_node(num, size);
        struct ListNode *r = reverseKGroup(l, 0);
        print_list_node(r);
    }
    {
        int num[] = { 1, 7, 3, 2, 7, 0, 1, 0, 0 };
        int size = sizeof(num) / sizeof(int);
        struct ListNode *l = create_list_node(num, size);
        struct ListNode *r = reverseKGroup(l, 4);
        print_list_node(r);
    }
}
