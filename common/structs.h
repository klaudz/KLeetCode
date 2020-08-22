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

klt_extern
struct ListNode *create_list_node(int *num, int size);

klt_extern
void free_list_node(struct ListNode *l);

klt_extern
void print_list_node(struct ListNode *l);

#endif /* structs_h */
