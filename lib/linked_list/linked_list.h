/**
 * @file linked_list.h
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief 
 * @date 2020-07-20
 */

#pragma once

#include "global.h"
#include <stdint.h>

typedef struct node_t {
    uint16_t val;
    struct node_t *next;
} node_t;

class LinkedList
{
public:
    LinkedList() { head = NULL; }
    ~LinkedList() { free_lst(); }

    bool push(uint16_t val); // ret P/F
    int pop(); // ret -1 if DNE else val

    int get_len();
    void free_lst();

    void reverse_lst();
    int get_element(int i); // ret -1 if DNE else val
    int remove_element(int i); // ret -1 if DNE else val
    bool remove_vals(uint16_t val); // remove vals that match

    void print_list();

private:
    node_t *head;
};
