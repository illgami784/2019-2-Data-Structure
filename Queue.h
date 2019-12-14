
#pragma once

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
	Node<T>* prev=NULL;
    Node<T> *next=NULL;
};

template <typename T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;
    int length;
    bool isEmpty()
    {
		return length == 0;
    }
public:
    Queue()
    {
		head = new Node<T>;
		tail= new Node<T>;
		length = 0;
    }

    void enqueue(T x)
    {
        Node<T>* temp = new Node<T>;
        temp->data = x;
        if(isEmpty())
        {
            
			head->next = temp;
			temp->prev = head;
			temp->next = tail;
			tail->prev = temp;
            length++;
        }
        else
        {
			tail->prev->next = temp;
			temp->prev = tail->prev;
			temp->next = tail;
			tail->prev = temp;
            length++;
        }
    }

    void dequeue(T& input)
    {
		Node<T>* temp = head;
		head = head->next;
		input = temp->data;
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

 
    int getLength(){
		return length;
    }
    
    void MakeEmpty(){
		Node<T>* temp = head;
		Node<T>* t = temp;
		while (temp->next!=tail)
		{
			t = temp;
			temp = temp->next;
			delete t;
		}
		delete temp;

		
		length = 0;
    }
};
