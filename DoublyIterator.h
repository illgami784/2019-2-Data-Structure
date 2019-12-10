#pragma once

#include "DoublySortedLinkedList.h"
#include <iostream>

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

class Ride;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	����Ʈ ������.
	*/
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList�� ģ�� Ŭ����.
	

	bool NotNull();
	bool NextNotNull();
	T First();
	T Next();
	DoublyNodeType<T> GetCurrentNode();
	DoublyNodeType<T>* GetCurrentNodePointer();
private:
	const DoublySortedLinkedList<T> &m_List;
	DoublyNodeType<T>* m_pCurPointer;
};

template <typename T>
bool DoublyIterator<T> :: NotNull()
{
	if(m_pCurPointer == NULL)
		return false;
	else
		return true;
}

template <typename T>
bool DoublyIterator<T> :: NextNotNull()
{
	if(m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}
template <typename T>
T DoublyIterator<T> :: First()
{
	m_pCurPointer = m_List.m_pFirst;
	return m_List.m_pFirst->data;
}

template <typename T>
T DoublyIterator<T> :: Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

template <typename T>
DoublyNodeType<T> DoublyIterator<T> :: GetCurrentNode()
{
	return *m_pCurPointer;
}
template<typename T>
DoublyNodeType<T>* DoublyIterator<T>::GetCurrentNodePointer()
{
	return m_pCurPointer;
}