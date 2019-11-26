#pragma once

#include "DoublyIterator.h"


template<typename T>
class DoublyIterator;

/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< �� ����� ������.
	DoublyNodeType *prev=NULL; ///< ����� ���� ����Ű�� ������.
	DoublyNodeType *next=NULL; ///< ����� ������ ����Ű�� ������.
};

/**
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator�� ģ�� Ŭ����.
public:
	/**
	*	����Ʈ ������.
	*/
	DoublySortedLinkedList();

	/**
	*	�Ҹ���.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	���� á���� �ƴ����� �˷��ش�.
	*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*/
	void Delete(T& item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	void Replace(T item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T &item);

private:
	DoublyNodeType<T>* m_pFirst; ///< �ּҰ��� ������ ����Ʈ�� �� ó��.
	DoublyNodeType<T>* m_pLast; ///< �ִ��� ������ ����Ʈ�� �� ��.
	int m_nLength; ///< ����Ʈ�� ����.
};

template <typename T>
DoublySortedLinkedList<T> :: DoublySortedLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;


	m_pLast->prev = m_pFirst;
	m_pFirst->next = m_pLast;

	m_nLength = 0;
}

template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	MakeEmpty();
	delete m_pFirst;
	delete m_pLast;
}

template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty()
{
	if (m_nLength == 0)
		return 1;
	return 0;
}

template <typename T>
bool DoublySortedLinkedList<T>::IsFull()
{
	return 0;
}

template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T> *temp;
	DoublyIterator<T> itor(*this);
	itor.Next(); 

	while(itor.NextNotNull())
	{
		temp= itor.m_pCurPointer;
		itor.Next(); 
		delete temp; 
	}

	m_pFirst->next = m_pLast;
	m_pLast->prev = m_pFirst;

}

template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	if (this == NULL)
		return 0;
	return m_nLength;
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::Add(T item)
{
	DoublyNodeType<T>* temp = new DoublyNodeType<T>;
	temp->data = item;
	T buf;
	DoublyIterator<T> itor(*this);
	itor.Next(); 
	if(IsEmpty()) 	
	{
		temp->prev = m_pFirst;
		temp->next = m_pLast;
		m_pFirst->next = temp;
		m_pLast->prev = temp; 
		m_nLength++;
		return 1;
	}
	else 
	{
		while(itor.NextNotNull())
		{
			if(item < itor.m_pCurPointer->data) 
			{
				temp->prev = itor.m_pCurPointer->prev;
				temp->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = temp;
				itor.m_pCurPointer->prev = temp; 
				m_nLength++;
				return 1;
			}
				itor.Next();		
		}
		itor.m_pCurPointer->prev->next = temp;
		temp->prev = itor.m_pCurPointer->prev->prev;
		temp->next = m_pLast;
		m_pLast->prev = temp;
		m_nLength++;
		return 1;
	}
	return 0;
}

template <typename T>
void DoublySortedLinkedList<T>::Delete(T& item)
{
	DoublyIterator<T> itor(*this);
	T buf;
	itor.Next(); 

	while(itor.NextNotNull())
	{
		if(itor.m_pCurPointer->data == item) 
		{
			DoublyNodeType<T> *temp = new DoublyNodeType<T>;
			temp = itor.m_pCurPointer;
			itor.Next();
			temp->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = temp->prev; 
			delete temp;
			m_nLength--;
			break;
		}
		itor.Next();
	}
}

template <typename T>
void DoublySortedLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); 
	 
	while(itor.NextNotNull())
	{
		if(itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; 
			break;
		}
		itor.Next();
	}

}

template <typename T>
int DoublySortedLinkedList<T>::Get(T &item)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	while(itor.NextNotNull())
	{
		if(itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return 1; 
		}
		itor.Next();
	}

	return 0;
}

