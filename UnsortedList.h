#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
class UnsortedList
{
public:
    /**
    *	default constructor.
    */

    UnsortedList()
    {
        m_Length = 0;
        max = 0;
        ResetList();
    }

    UnsortedList(int _max)
    {
        m_Length = 0;
        max = _max;
        m_Array = new T[max];
        ResetList();
    }

    /**
    *	destructor.
    */
    ~UnsortedList()
    {
        delete[] m_Array;
    }

    /*
    *	기본 생성자 사용시를 위한 함수.
    */
    int setMax(int _max)
    {
        max = _max;
        m_Array = new T[max];
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
    int Add(T data);

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
    int GetNextItem(T& data);

    /** [작성]
    *	@brief 입력받은 데이터의 Id가 기존의 존재하는 거랑 같을시 그 아이템의 포인터를 반환
    *	@pre	아이템이 1개라도 존재해야함.
    *	@post none
    *	@param data 서치할 아이템 Id만을 가지면 됨
    *	@return Id가 같은 아이템의 포인터
    */
    int Get(T& data);

    /** [작성]
    *	@brief 입력받은 데이터의 시간이 기존의 존재하는 거랑 같을시 그 아이템을 삭제
    *	@pre 아이템이 하나라도 존재해야함.
    *	@post 아이템이 하나 삭제됩니다.
    *	@param data 삭제할 아이템 시간만을 가지면 됨
    *	@return none
    */
    void Delete(T data);


    /** [작성]
    *	@brief 입력받은 데이터의 Id가 기존의 존재하는 거랑 같을시 그 아이템을 입력받아 갱신
    *	@pre 아이템이 하나라도 존재해야함
    *	@post 아이템 레코드를 대체합니다.
    *	@param data 삭제할 아이템 Id만을 가지면 됨
    *	@return none
    */
    void Replace(T data);

private:
    T* m_Array;  ///< list array.
    int m_Length;				///< number of elements in list.
    int m_CurPointer;			///< iterator pointer.
    int max;
};
#endif

// Make list empty.
template <typename T>
void UnsortedList<T>::MakeEmpty()
{
    m_Length = 0;
}


// Get a number of records in current list.
template <typename T>
int UnsortedList<T>::GetLength()
{
    return m_Length;
}


// Check capacity of list is full.
template <typename T>
bool UnsortedList<T>::IsFull()
{
    if (m_Length > max - 1)
        return true;
    else
        return false;
}


// add a new data into list.
template <typename T>
int UnsortedList<T>::Add(T inData)
{
    if (IsFull()) {
        cout << "\n\t리스트가 가득 찼습니다.";
        return 0;
    }
    int location = 0;
    bool moreToSearch;

    moreToSearch = (location < m_Length);
    while (moreToSearch) {
        if (inData == m_Array[location])
        {
            cout << "\n\t동일한 ID가 존재합니다.";
            return 0;
        }
        else if(inData < m_Array[location])
        {
            location++;
            moreToSearch = (location < m_Length);
        }
        else
        {
            moreToSearch = false;
        }
    }
    cout << "\n\t추가에 성공했습니다.";
    for (int i = m_Length; i > location; i--) {
        m_Array[i] = m_Array[i - 1];
    }
    m_Array[location] = inData;
    m_Length++;
    return 1;
}

template <typename T>
int  UnsortedList<T>::Get(T& data) {

    ResetList();
    T temp;
    GetNextItem(temp);
    for (int i = 0; i < m_Length; i++)
    {
        if (data == temp)
        {
            data = temp;
            return m_CurPointer;
        }
        GetNextItem(temp);
    }
    return -1;
}

template <typename T>
void  UnsortedList<T>::Delete(T data) {
    int location = 0;

    while ( data != m_Array[location]) {
        if (location >= m_Length) {
            cout << "\n\tID가 같은 값이 없습니다.";
            return;
        }

        location++;
    }
    for (int i = location + 1; i < max; i++) {
        m_Array[i - 1] = m_Array[i];
    }
    cout << "\n\t삭제에 성공했습니다.";
    m_Length--;
}


template <typename T>
void  UnsortedList<T>::Replace(T data) {
    T temp = data;
    if (Get(data)) {
        cout << "\n\t" << "대체 성공했습니다.";
        m_Array[m_CurPointer] = data;
    }
    else
    {
        cout << "\n\t" << "같은 값이 없어 대체에 실패했습니다.";
        return;
    }
}

// Initialize list iterator.
template <typename T>
void UnsortedList<T>::ResetList()
{
    m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
template <typename T>
int UnsortedList<T>::GetNextItem(T& data)
{
    m_CurPointer++;	// list pointer 증가
    if (m_CurPointer == max)	// end of list이면 -1을 리턴
        return -1;
    data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

    return m_CurPointer;
}

