#pragma once

#include "DoublyIterator.h"


template<typename T>
class DoublyIterator;

/**
*	연결리스트에서 쓰이는 NodeType의 구조체
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< 각 노드의 데이터.
	DoublyNodeType *prev=NULL; ///< 노드의 앞을 가리키는 포인터.
	DoublyNodeType *next=NULL; ///< 노드의 다음를 가리키는 포인터.
};

/**
*	정렬된 더블연결리스트 클래스
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator와 친구 클래스.
public:
	/**
	*	디폴트 생성자.
	*/
	DoublySortedLinkedList();

	/**
	*	소멸자.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	리스트가 비었는지 아닌지 검사한다.
	*	@pre	m_nLength가 값을 가지고 있어야 한다.
	*	@post	비었는지 아닌지를 알려준다.
	*	@return	비어있으면 true, 아니면 false를 반환.
	*/
	bool IsEmpty();

	/**
	*	@brief	리스트가 가득 찼는지 아닌지 검사한다.
	*	@pre	m_nLength가 값을 가지고 있어야 한다.
	*	@post	가득 찼는지 아닌지를 알려준다.
	*	@return	가득 차있으면 true, 아니면 false를 반환.
	*/
	bool IsFull();

	/**
	*	@brief	리스트를 비운다.
	*	@pre	없음.
	*	@post	m_pFirst와 m_pLast를 제외한 모든 데이터를 지운다.
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트의 길이를 반환한다.
	*	@pre	없음.
	*	@post	리스트의 길이를 반환.
	*	@return	m_nLength 리스트의 길이 반환.
	*/
	int GetLength() const;

	/**
	*	@brief	새로운 아이템을 리스트에 추가한다.
	*	@pre	item을 입력받는다.
	*	@post	아이템을 리스트에 추가한다.
	*	@return	같은 아이템이 있으면 0을 반환하고, 입력에 성공하면 1을 반환.
	*/
	int Add(T item);

	/**
	*	@brief	입력받은 아이템을 리스트에서 삭제한다.
	*	@pre	item을 입력받는다.
	*	@post	입력받은 아이템을 리스트에서 찾아 삭제한다.
	*/
	void Delete(T& item);

	/**
	*	@brief	입력받은 아이템으로 정보를 바꾼다.
	*	@pre	item을 입력받는다.
	*	@post	새로운 정보로 교체된다.
	*/
	void Replace(T item);

	/**
	*	@brief	입력받은 아이템의 정보와 비교하여 같은 리스트의 아이템을 가져온다.
	*	@pre	item을 입력받는다.
	*	@post	검색된 데이터를 아이템에 넣는다.
	*	@return	일치하는 데이터를 찾으면 1, 그렇지 않으면 0을 반환.
	*/
	int Get(T &item);

private:
	DoublyNodeType<T>* m_pFirst; ///< 최소값을 가지는 리스트의 맨 처음.
	DoublyNodeType<T>* m_pLast; ///< 최댓값을 가지는 리스트의 맨 끝.
	int m_nLength; ///< 리스트의 길이.
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

// 아이템을 입력받아 리스트의 맞는 자리를 찾아 삽입한다.
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

