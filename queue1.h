#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
};
template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    Node<T> *prev;
    Node<T> *temp;
    int length;
    bool isEmpty()
    {
        return head == NULL;
    }
public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    void enqueue(T x)
    {
        temp = new Node<T>;
        temp->data = x;
        temp->next = NULL;
        if(isEmpty())
        {
            head = temp;
            tail = temp;
            length++;
        }
        else
        {
            prev = tail;
            tail->next = temp;
            tail = temp;
            length++;
        }
    }

    void dequeue(T& input)
    {
        temp = head;
        input = temp->data;
        head = head->next;
        length--;
    }
