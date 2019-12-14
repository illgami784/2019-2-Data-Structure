#pragma once

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


class UnsortedList
{
public:
	/**
	*	default constructor.
	*/

	UnsortedList()
	{
		m_Length = 0;
		max = 100;
		m_Array = new int[100];
		ResetList();
		
	}


	/**
	*	destructor.
	*/
	~UnsortedList() = default;
	/*
	*	�⺻ ������ ���ø� ���� �Լ�.
	*/
	int setMax(int _max)
	{
		delete[] m_Array;
		max = _max;
		m_Array = new int[max];
		return 1;
	}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(int data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(int& data);

	/** [�ۼ�]
	*	@brief �Է¹��� �������� Id�� ������ �����ϴ� �Ŷ� ������ �� �������� �����͸� ��ȯ
	*	@pre	�������� 1���� �����ؾ���.
	*	@post none
	*	@param data ��ġ�� ������ Id���� ������ ��
	*	@return Id�� ���� �������� ������
	*/
	int Get(int& data);

	/** [�ۼ�]
	*	@brief �Է¹��� �������� �ð��� ������ �����ϴ� �Ŷ� ������ �� �������� ����
	*	@pre �������� �ϳ��� �����ؾ���.
	*	@post �������� �ϳ� �����˴ϴ�.
	*	@param data ������ ������ �ð����� ������ ��
	*	@return none
	*/
	void Delete(int data);


	/** [�ۼ�]
	*	@brief �Է¹��� �������� Id�� ������ �����ϴ� �Ŷ� ������ �� �������� �Է¹޾� ����
	*	@pre �������� �ϳ��� �����ؾ���
	*	@post ������ ���ڵ带 ��ü�մϴ�.
	*	@param data ������ ������ Id���� ������ ��
	*	@return none
	*/
	void Replace(int data);

	void Print();

private:
	int* m_Array;  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
	int max;
};

// Make list empty.
void UnsortedList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int UnsortedList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool UnsortedList::IsFull()
{
	if (m_Length > max - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int UnsortedList::Add(int inData)
{
	if (IsFull()) {
		cout << "\n\t����Ʈ�� ���� á���ϴ�.";
		return 0;
	}
	int location = 0;
	bool moreToSearch;

	moreToSearch = (location < m_Length);
	while (moreToSearch) {
		if (inData == m_Array[location])
		{
			cout << "\n\t������ ID�� �����մϴ�.";
			return 0;
		}
		else if (inData < m_Array[location])
		{
			location++;
			moreToSearch = (location < m_Length);
		}
		else
		{
			moreToSearch = false;
		}
	}
	for (int i = m_Length; i > location; i--) {
		m_Array[i] = m_Array[i - 1];
	}
	m_Array[location] = inData;
	m_Length++;
	return 1;
}

int  UnsortedList::Get(int& data) {
	int temp;
	ResetList();
	GetNextItem(temp);
	int location = 0;
	while (m_CurPointer < m_Length) {
		if (data == m_Array[location])
		{
			data = temp;
			return 1;
		}
		else if (data < m_Array[location])
		{
			return 0;
		}
		else
		{
			GetNextItem(temp);
		}
	}
	return 0;
}

void  UnsortedList::Delete(int data) {
	int location = 0;

	while (data != m_Array[location]) {
		if (location >= m_Length) {
			return;
		}

		location++;
	}
	for (int i = location + 1; i < max; i++) {
		m_Array[i - 1] = m_Array[i];
	}
	m_Length--;
}


void  UnsortedList::Replace(int data) {
	int temp = data;
	if (Get(data)) {
		cout << "\n\t" << "��ü �����߽��ϴ�.";
		m_Array[m_CurPointer] = data;
	}
	else
	{
		cout << "\n\t" << "���� ���� ���� ��ü�� �����߽��ϴ�.";
		return;
	}
}

// Initialize list iterator.
void UnsortedList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int UnsortedList::GetNextItem(int& data)
{
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == max)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

void UnsortedList::Print()
{
	int temp;
	ResetList();
	GetNextItem(temp);
	int location = 0;
	while (m_CurPointer < m_Length) {
		cout << m_Array[m_CurPointer] << ' ';
		GetNextItem(temp);
	}
}