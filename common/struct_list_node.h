//
//  struct_list_node.h
//  KLeetCode
//
//  Created by klaudz on 11/26/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#ifndef struct_list_node_h
#define struct_list_node_h

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

#endif /* struct_list_node_h */
