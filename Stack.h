#pragma once

#include <iostream>
using namespace std;
template <class T>
class Stack
{
public:
	Stack()
	{
		stack_length = 0;
		max = 0;
		m_stack = new T[max];
	}
	~Stack()
	{

		delete[] m_stack;
	}

	void setMax(int _max)
	{
		delete[] m_stack;
		stack_length = 0;
		max = _max;
		m_stack = new T[max];
	}

	void Empty()
	{
		stack_length = 0;
	}
	/**
	*	@brief	stack depth
	*	@pre	none.
	*	@post	
	*	@return	stack depth
	*/
	void GetLength()
	{
		for (int i = 0; i < stack_length; i++)
		{
			cout << m_stack[i]->GetPath();
		}
	}
	/**
	*	@brief	pop item
	*	@pre	none.
	*	@post	length -=1
	*	@return	item pointer
	*/
	T Pop()
	{
		if (IsEmpty())
		{
			return m_stack[0];
		}
		else
		{
			stack_length -= 1;
			return m_stack[stack_length];
		}
	}
	/**
	*	@brief	push item
	*	@pre	none.
	*	@post	length -=1
	*	@param  data pointer
	*	@return	if function works well, return 1 ,otherwise return 0;
	*/
	int Push(T data)
	{
		if (!IsFull())
		{
			m_stack[stack_length] = data;
			stack_length += 1;;
			return 1;
		}
		else
		{
			cout << "\tCannot Push" << endl;
		}

		return 0;
	}
	/**
	*	@brief	check stack is full
	*	@pre	none.
	*	@post	none.
	*	@param  none,
	*	@return	if function works well, return 1 ,otherwise return 0;
	*/
	int IsFull()
	{
		if (stack_length == max)
		{
			cout << "\tStack is full" << endl;
			return 1;
		}
		return 0;
	}
	/**
	*	@brief	check stack is empty
	*	@pre	none.
	*	@post	none.
	*	@param  none,
	*	@return	if function works well, return 1 ,otherwise return 0;
	*/
	int IsEmpty()
	{
		if (stack_length == 0)
			return 1;
		return 0;
	}
	/**
	*	@brief	print all item
	*	@pre	none.
	*	@post	none.
	*	@param  none,
	*	@return	none.
	*/
	void Print()
	{
		for (int i = 0; i < stack_length; i++)
		{
			cout << m_stack[i] << endl;
		}
	}
private:
	T* m_stack;
	int stack_length;
	int max;
};

