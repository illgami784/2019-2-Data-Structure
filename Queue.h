
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
		length = 0;
		prev = NULL;
		temp = NULL;
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

//    void find(int x)
//    {
//        int i;
//        for(i=1, temp = head;temp->next != NULL && temp->data != x;temp = temp->next, i++);
//        if(temp->data == x)
//        {
//            cout << "Found at position:" << i << endl;
//        }
//        else if(temp->next == NULL)
//        {
//            cout << "Error: Number Not found..." << endl;
//        }
//    }

    void display()
    {
        if(!isEmpty())
        {
            for(temp = head; temp != NULL; temp=temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "Queue is Empty!" << endl;
        }
    }
    int getLength(){
		return length;
    }
    
    void MakeEmpty(){
     for(temp = head; temp != NULL; temp = temp->next)
         delete temp;
      head = NULL;
      tail = NULL;
    }
};
