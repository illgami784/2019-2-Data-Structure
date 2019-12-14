
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
		m_Array = new T[maxsize];
	}

	/**
	*	destructor.
	*/
	~SortedList()
	{
		delete[] m_Array;
	}

	void setMax(int _max)
	{
		// delete[] m_Array;
		maxsize = _max;
		m_Array = new T[maxsize];
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
		if (!IsFull())
		{
			T CurItem;
			ResetList();
			GetNextItem(CurItem);

			while (m_CurPointer <= m_Length) //처음부터 끝까지
			{
				if (CurItem> data || m_CurPointer == m_Length)   //만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
				{
					for (int i = m_Length; i > m_CurPointer; i--)   //맨뒤에서 부터 하나씩 땡긴다.
						m_Array[i] = m_Array[i - 1];   //배열 밀기
					m_Array[m_CurPointer] = data;   //배열 밀은 후 현재 포인터에 아이템 넣는다.
					m_Length++;   //개수 증가
					break;
				}
				GetNextItem(CurItem);   //다음아이템으로
			}
		}
		else
			return 0;

		return 1;
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

