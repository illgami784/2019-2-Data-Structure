
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



/**
*	array based simple sorted list.
*/
template <class T>
class SortedList
{
public:
	/**
	*	default constructor.
	*/
	SortedList()
	{
		m_Array = NULL;
		m_Length = 0;
		ResetList();
		maxsize = 1;
	}

	/**
	*	destructor.
	*/
	~SortedList()
	{
		delete[] m_Array;
	}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty()
	{
		delete[] m_Array;

	}

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength()
	{
		return m_Length;
	}

	int IsFull()
	{
		if (maxsize == m_Length)
			return 1;
		else return 0;
	}


	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data)
	{
		if (m_Length == 0)
		{
			m_Array = new T[maxsize];
			m_Array[0] = data;
			cout << "추가에 성공했습니다." << endl;
			m_Length++;
			return 1;
		}
		else
		{
			T temp;
			ResetList();
			GetNextItem(temp);
			for (int i = 0; i < m_Length; i++)
			{
				if (data == temp)
				{
					cout << "\tError" << endl;
					cout << "\t동일한 메일 항목 존재" << endl;
					return 0;
				}
				GetNextItem(temp);
			}
		}
		if (IsFull())
		{
			T* temp = new T[maxsize];
			for (int i = 0; i < m_Length; i++)
			{
				temp[i] = m_Array[i];
			}
			delete[] m_Array;

			maxsize++;
			m_Array = new T[maxsize];
			for (int i = 0; i < m_Length; i++)
			{
				m_Array[i] = temp[i];
			}
			delete[] temp;

			T temp2 = m_Array[m_Length - 1];
			if (temp2 > data)
			{
				m_Array[m_Length] = data;
				m_Length++;
				return 1;
			}

			ResetList();
			T item;
			GetNextItem(item);
			for (int i = 0; i < m_Length; i++)
			{
				T temp3 = m_Array[i];
				if (temp3 < data)
				{
					for (int j = m_Length; j > m_CurPointer; j--)
					{
						m_Array[j] = m_Array[j - 1];
					}
					m_Array[i] = data;
					m_Length++;
					return 1;
				}
				GetNextItem(item);
			}
			return 0;
		}
	}

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList()
	{
		m_CurPointer = -1;
	}

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data)
	{
		m_CurPointer++;

		if (m_CurPointer == m_Length)
			return -1;
		data = m_Array[m_CurPointer];

		return m_CurPointer;
	}

	/**
	*	@brief	찾을려는 아이템 이름을 통해 찾음. 찾은 경우 파라미터의 객체로 찾은 아이템을 가져옴,
	*	@pre	아이템 존재
	*	@post	찾은 아이템 가져옴
	*	@param  찾은 아이템을 가져올 객체
	*	@return 성공시 찾은 아이템의 인덱스를 반환 아니면 -1
	*/
	int Get(T& data)
	{
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

	/**
	*	@brief 찾을려는 아이템 이름을 통해서 아이템 삭제
	*	@pre   아이템 존재
	*	@post  아이템 삭제, 길이 -1
	*	@param 삭제할 아이템의 이름을 가진 객체
	*	@return 성공시 1 실패시 0
	*/
	int Delete(T data)
	{
		if (m_Length == 0)
		{
			cout << "\t삭제할 데이터가 없습니다. " << endl;
			return 0;
		}
		T temp;
		temp = data;
		if (Get(temp) != -1)
		{
			for (int i = m_CurPointer; i < m_Length - 1; i++)
			{
				m_Array[i] = m_Array[i + 1];
			}
			m_Length--;
			return 1;
		}
		return 0;
	}

	/**
	*	@brief data의 객체로 리스트의 데이터를 변환
	*	@pre   list에 data와 동일 이름 존재
	*	@post  list data 변환
	*	@param 변환시킬 객체
	*	@return
	*/
	int Replace(T data)
	{
		T temp;
		ResetList();
		GetNextItem(temp);
		for (int i = 0; i < m_Length; i++)
		{
			if (temp == data)
			{
				temp = data;
				return 1;
			}
		}
		cout << "\t해당 메일이 없습니다" << endl;
		return 0;
	}


	/*
	*	@brief 첫번째 파라미터에 포인터로 begin과 end사이의 key값으로 배열을 가져옴
	*	@pre	key값들은 string 타입이여야함
	*	@post	포인터에 배열이 추가
	*	@return 사이에 존재하는 개수 반환
	*/
	int GetItemInterval(T* p, string begin, string end)
	{
		T temp;
		ResetList();
		GetNextItem(temp);
		int cnt = 0;
		for (int i = 0; i < m_Length; i++)
		{
			if (temp > begin&& temp < end)
			{
				p[cnt] = temp;
				cnt++;
			}
			GetNextItem(temp);
		}
		return cnt;
	}


private:
	T* m_Array;  ///< list array.
	int m_Length;				///< number of elements in list.
	int maxsize;
	int m_CurPointer;			///< iterator pointer.
};

