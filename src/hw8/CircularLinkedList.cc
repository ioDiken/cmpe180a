/**
 * @file CircularLinkedList.h
 * @brief Circular Linked List
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include <new>

// #define DEBUG_
#ifdef DEBUG_
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList()
{
    head = NULL;
    tail = NULL;
    dir = ClockWise;
    len = 0;
}


CircularLinkedList::~CircularLinkedList()
{
    free_all();
}


void CircularLinkedList::push(int i , ClockDirection d)
{
    DEBUG("\nBeginning %s\n", __func__);

    if (NULL != head)
    {
        DEBUG("Head: %08x\nNext: %08x\nPrev: %08x\n", head, head->next, head->prev);
    }

    node_t* node = head, 
        *prev;

    dir = d;
    ++len;

    if ((NULL == head)
        || (1 == len))
    {
        head = new node_t;
        head->prev = NULL;
        head->next = NULL;
        head->val = i;
    }

    else if (ClockWise == d)
    {
        head = new node_t;

        node->next = head;
        head->val = i;
        head->next = tail;
        head->prev = node;

        // necessary for the second added item
        if (NULL == tail)
        {
            head->next = node;
            tail = node;
            tail->next = head;
            tail->prev = head;
        }
    }

    else
    {
        head = new node_t;

        prev = node->prev;
        head->next = node;
        head->prev = prev;
        head->val = i;

        // necessary for the seond added item
        if (NULL == tail)
        {
            head->prev = node;
            tail = node;
            tail->next = head;
            tail->prev = head;
        }
    }

    DEBUG("Head: %08x\nNext: %08x\nPrev: %08x\n", head, head->next, head->prev);
    DEBUG("Pushed: %d\n", head->val);
    DEBUG("Len: %d\n", len);
}


int CircularLinkedList::pop(ClockDirection d)
{
    DEBUG("\nBeginning %s\n", __func__);
    DEBUG("\nLen: %d\n", len);
    DEBUG("Head: %08x\nNext: %08x\nPrev: %08x\n", head, head->next, head->prev);
    int ret_val = 0;

    if ((NULL == head)
        || (len == 0))
    {
        // do nothing
    }
    else
    {
        node_t *prev, *next;
        dir = d;
        --len;

        ret_val = head->val;
        prev = head->prev;
        next = head->next;

        delete head;

        head = next;
        head->prev = prev;
    }

    if (0 == len)
    {
        tail = NULL;
    }

    DEBUG("Head: %08x\nNext: %08x\nPrev: %08x\n", head, head->next, head->prev);
    DEBUG("*Popping: %d\n", ret_val);
    return ret_val;
}


int CircularLinkedList::peek()
{
    DEBUG("\nBeginning %s\n", __func__);

    if (NULL == head)
    {
        return 0;
    }
    else
    {
        return head->val;
    }
}


void CircularLinkedList::rotate(unsigned int n, ClockDirection d)
{
    DEBUG("\nBeginning %s\n", __func__);

    if ((n > len) || (len == 0))
    {
        return;
    }

    if (d == ClockWise) {
        for (int i = 0; i < n; i++) {
            head = head->next;
            tail = head->prev;
        }
    } else if (d == CounterClockWise) {
        for (int i = 0; i < n; i++) {
            tail = tail->prev;
            head = tail->next;
        }
    }
}

std::ostream& operator<<(std::ostream& os, CircularLinkedList& lst)
{
    unsigned int i = lst.len;
    node_t *hd = lst.head;

    DEBUG("\nBeginning %s\n", __func__);
    DEBUG("\nLen: %d\n", lst.len);

    for (; 0 < i; --i)
    {
        DEBUG("\nVal: %d\ni: %d\n", hd->val, i);
        DEBUG("Next: %08x\nPrev: %08x\n", hd->next, hd->prev);

        os << hd->val;
        hd = (ClockWise == lst.dir) ? hd->next : hd->prev;
    }

    return os;
}

void CircularLinkedList::free_all()
{
    DEBUG("\nBeginning %s\n", __func__);

    while(len)
    {
        this->pop(dir);
    }
}
