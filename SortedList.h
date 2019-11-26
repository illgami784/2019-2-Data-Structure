
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
			cout << "�߰��� �����߽��ϴ�." << endl;
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
					cout << "\t������ ���� �׸� ����" << endl;
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
	*	@brief	ã������ ������ �̸��� ���� ã��. ã�� ��� �Ķ������ ��ü�� ã�� �������� ������,
	*	@pre	������ ����
	*	@post	ã�� ������ ������
	*	@param  ã�� �������� ������ ��ü
	*	@return ������ ã�� �������� �ε����� ��ȯ �ƴϸ� -1
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
	*	@brief ã������ ������ �̸��� ���ؼ� ������ ����
	*	@pre   ������ ����
	*	@post  ������ ����, ���� -1
	*	@param ������ �������� �̸��� ���� ��ü
	*	@return ������ 1 ���н� 0
	*/
	int Delete(T data)
	{
		if (m_Length == 0)
		{
			cout << "\t������ �����Ͱ� �����ϴ�. " << endl;
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
	*	@brief data�� ��ü�� ����Ʈ�� �����͸� ��ȯ
	*	@pre   list�� data�� ���� �̸� ����
	*	@post  list data ��ȯ
	*	@param ��ȯ��ų ��ü
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
		cout << "\t�ش� ������ �����ϴ�" << endl;
		return 0;
	}


	/*
	*	@brief ù��° �Ķ���Ϳ� �����ͷ� begin�� end������ key������ �迭�� ������
	*	@pre	key������ string Ÿ���̿�����
	*	@post	�����Ϳ� �迭�� �߰�
	*	@return ���̿� �����ϴ� ���� ��ȯ
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

