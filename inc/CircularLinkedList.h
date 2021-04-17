/**
 * @file CircularLinkedList.h
 * @brief Circular Linked List
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#pragma once

#include <stdint.h>
#include <ostream>

#include "ClockDirection.h"

typedef struct node_t {
    int val;
    struct node_t *next;
    struct node_t *prev;
} node_t;

class CircularLinkedList
{
public:
    CircularLinkedList();
    ~CircularLinkedList();

    void push(int i , ClockDirection d);
    int pop(ClockDirection d);
    int peek();
    void rotate(unsigned int n, ClockDirection d);

    friend std::ostream& operator<<(std::ostream& os, CircularLinkedList& lst);

private:

    node_t* head;
    node_t* tail;
    unsigned int len;
    ClockDirection dir;

    void free_all();
};
