
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

			while (m_CurPointer <= m_Length) //ó������ ������
			{
				if (CurItem> data || m_CurPointer == m_Length)   //���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
				{
					for (int i = m_Length; i > m_CurPointer; i--)   //�ǵڿ��� ���� �ϳ��� �����.
						m_Array[i] = m_Array[i - 1];   //�迭 �б�
					m_Array[m_CurPointer] = data;   //�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
					m_Length++;   //���� ����
					break;
				}
				GetNextItem(CurItem);   //��������������
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

