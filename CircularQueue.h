#include <iostream>
using namespace std;

#define maxQueue 10

/**
*	@brief	Exception class thrown by Enqueue when queue is full.
*/
class FullQueue
{
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};


/**
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	Display a message for empty queue on screen.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};


/**
*	@brief	Queue class.
*	@details	This class processes as First In, First Out (FIFO), ���ø��� ������ �پ��� ���� Ÿ���� ������ �� �ִ�.
*/
template <typename T>
class CircularQueue
{
public:
	/**
	*	@brief	Allocate dynamic array whose size is maxQueue.
	*	@pre	The maxQueue is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularQueue();

	/**
	*	@brief	Allocate dynamic array whose size is max.
	*	@pre	none.
	*	@post	Member of items points the allocated array.
	*/
	CircularQueue(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for queue pointer.
	*	@post	none.
	*/
	~CircularQueue();


	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Makes the queue empty.
	*	@pre	Queue has been initialized.
	*	@post	m_iFront�� m_iRear is set same value as Constructer.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	void EnQueue(T item);

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	void DeQueue(T& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void Print();

private:
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxQueue;	//max size of the queue.
	T* m_pItems;	//pointer for dynamic allocation.
};

//Allocate dynamic array whose size is maxQueue.
template <typename T>
CircularQueue<T>::CircularQueue()
{
	m_pItems = new T[maxQueue];	//m_pItems�� ũ�Ⱑ maxQueue�� �迭�� �����.
	m_nMaxQueue = maxQueue;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//��� �������� �ʱ�ȭ�����ش�.
}

//Allocate dynamic array whose size is max.
template <typename T>
CircularQueue<T>::CircularQueue(int max)
{
	m_pItems = new T[max];	//m_pItems�� ũ�Ⱑ max�� �迭�� �����.
	m_nMaxQueue = max;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//��� �������� �ʱ�ȭ�����ش�.
}

//Destruct the object. Free the array dynamically allocated.
template <typename T>
CircularQueue<T>::~CircularQueue()
{
	delete[] m_pItems;	//�����Ҵ��ߴ� �޸𸮸� �������ش�.
}

//Determines whether the queue is full.
template <typename T>
bool CircularQueue<T>::IsFull()
{
	if (m_iFront - m_iRear == 1 || m_iRear - m_iFront == m_nMaxQueue - 1)
		return 1;	//m_iFront�� m_iRear���� 1 ���϶��� �� �����̹Ƿ� 1�� �����Ѵ�. m_iFront�� 0�϶��� m_iRear�� m_nMaxQueue-1�� ������ �� �����̴�.
	return 0;	//�� ���� �ʾ����� 0�� �����Ѵ�.
}

//Determines whether the queue is empty.
template <typename T>
bool CircularQueue<T>::IsEmpty()
{
	if (m_iFront == m_iRear)
		return 1;	//m_iFront�� m_iRear�� ���� ���� queue�� ����ִ� �����̹Ƿ� 1�� �����Ѵ�.
	return 0;	//������� ������ 0�� �����Ѵ�.
}

//Makes the queue empty.
template <class T>
void CircularQueue<T>::MakeEmpty()
{
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//�����ڿ� ���� ������ m_iFront�� m_iRear�� �������ش�.
}

//Adds newItem to the last of the queue.
template <class T>
void CircularQueue<T>::EnQueue(T item)
{
	if (IsFull())
		throw FullQueue;	//�� á���� throw FullQueue

	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item;	//m_iRear�� 1���������ְ� item���� �־��ش�.
	int front = m_iFront;
	int rear = m_iRear;
	if (front < rear)
	{
		for (int i = front + 1; i < rear; i++)
		{
			if (item == m_pItems[i])
			{
				for (int j = i; j < rear; j++)
				{
					m_pItems[j] = m_pItems[j + 1];
				}
				m_iRear = (m_iRear - 1) % m_nMaxQueue;
				if (m_iRear - 1 < 0)
				{
					m_iRear = m_nMaxQueue - 1;
					break;
				}
				break;
			}
		}
	}
	else if (front > rear)
	{
		for (int i = (front + 1) % m_nMaxQueue; i != rear; i++)
		{
			i = i % m_nMaxQueue;
			if (item == m_pItems[i])
			{
				for (int j = i; j != rear; j++)
				{
					j = j % m_nMaxQueue;
					m_pItems[j] = m_pItems[(j + 1) % m_nMaxQueue];
				}
				m_iRear = (m_iRear - 1) % m_nMaxQueue;

				break;
			}
		}

	}
	/*if ((m_iRear - m_iFront)*(m_iRear - m_iFront) == 1)
	{

	}*/
}

//Removes first item from the queue.
template <typename T>
void CircularQueue<T>::DeQueue(T& item)
{
	if (IsEmpty())
		throw EmptyQueue;	//��������� throw EmptyQueue
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront];	//m_iFront�� 1 ���������ְ� ������ ���� item�� �������ش�.
}

//Print all the items in the queue on screen
template <typename T>
void CircularQueue<T>::Print()
{
	if (m_iFront > m_iRear)	//m_iFront�� m_iRear���� Ŭ��
	{
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++)
		{
			cout << m_pItems[i] << endl;
		}	//m_iFront ���� �׸���� �迭�� ������ ����Ѵ�.
		for (int i = 0; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << endl;
		}	//�迭�� ó������ m_iRear���� ������ش�.
	}
	else	//m_iRear�� m_iFront���� Ŭ��
	{
		for (int i = m_iFront + 1; i <= m_iRear; i++)
		{
			cout << m_pItems[i] << endl;
		}	//m_iFront+1�������� m_iRear���� ���
	}
	cout << endl;
}