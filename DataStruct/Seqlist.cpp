#include <iostream>

using namespace std;

const int MaxSize = 10; //������󳤶�

/*��ģ�� */

template <class T> //��ģ��Ķ���
class qzaSeqList
{
private:
	int length; //˳���ĳ���
	T data[MaxSize];
public:
	qzaSeqList(){length = 0;} //���캯��
	qzaSeqList(T a[], int n);
	~qzaSeqList(){} //��������
	//��λ����
	void Insert(int locate,T x);
	//�������ݣ�Ȼ������
	void sortInsert(T x);
	//ɾ�������±�ɾ��)
	void Delete(int locate);
	//���ң���ֵ���ң�����������Ԫ��
	void FindX(T x);
	//��λ����
	void Find(int l);
	void Print(); //���˳���
	void getlength() {cout << "˳���ĳ���Ϊ��" << length << endl;}
};
template <class T>
qzaSeqList<T>::qzaSeqList(T a[], int n)
{
	length = n;
	for(int k =0 ; k < length; k++)
		data[k] = a[k];
}

template <class T>
void qzaSeqList<T>::Insert(int locate, T x)
{
	//�����һ��Ԫ�ؿ�ʼ����locate��Ԫ����������ƶ�
	for(int k = length; k > locate; k--)
		data[k] = data[k-1];
	data[locate] = x;
	length++;
	} //����Ԫ��


template<class T>
void qzaSeqList<T>::FindX(T x)
{
	int i;
	for(i = 0; i < length; i++)
		if (data[i] == x)
		{
			cout << "��" << i << "��Ԫ��Ϊ��" << x << endl;
			break;
		}
	if (i == length)
		cout << "û���ҵ�" << x << endl;
} //����Ԫ��

template<class T>
void qzaSeqList<T>::Find(int locate)
{
	if (locate < 0 || locate >= length)
	{
		cout << "λ�ò��Ϸ�" << endl;
		return;
	}
	cout << "��" << locate << "��Ԫ��Ϊ��" << data[locate] << endl;
} //����Ԫ��

template<class T>
void qzaSeqList<T>::Delete(int locate)
{
	if (locate < 0 || locate >= length)
	{
		cout << "λ�ò��Ϸ�" << endl;
		return;
	}
	for(int k = locate; k < length-1; k++)
		data[k] = data[k+1];
	length--;
} //ɾ��Ԫ��

template <class T>
void qzaSeqList<T>::Print() 
{
	cout << "˳����Ԫ��Ϊ��";
	for(int k = 0; k < length; k++)
		cout << data[k] << " ";
	cout << endl;
} //���˳���

template <class T>
void qzaSeqList<T>::sortInsert(T x)
{//���룬Ȼ��ð������
	data[length] = x;
	length++;
	for(int i = 0; i < length; i++)
		for(int j = 0; j < length - i - 1; j++)
			if (data[j] > data[j + 1])
			{
				T temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
} //����Ԫ��

int main() {
	int x=1;
	int i = 0;
	int a[10] = {0};
	cout << "�������ݣ�" << endl;
	while (x != 0) {
		cin >> x;
		a[i] = x;
		i++;
	}
	qzaSeqList<int> s1(a,i-1);
	cout << "��ǰ����" ;
	s1.Print();
	 s1.getlength();
	cout <<"�������λ�úͲ���Ԫ��" << endl;
	int locate;
	cin >> locate >> x;
	s1.Insert(locate,x);
	cout << "����������" ;
	s1.Print();
	cout << "������������" << endl;
	cin >> x;
	s1.sortInsert(x);
	cout << "����������" << endl;
	s1.Print();
	cout << "����ɾ����λ��" << endl;
	cin >> locate;
	s1.Delete(locate);
	cout << "ɾ���������" << endl;
	s1.Print();
	cout << "������ҵ�Ԫ��" << endl;
	cin >> x;
	s1.FindX(x);
	cout << "������ҵ�λ��" << endl;
	cin >> locate;
	s1.Find(locate);

	return 0;
}
