#include <iostream>

using namespace std;

const int MaxSize = 10; //������󳤶�

/*��ģ�� */

template <class T> //��ģ��Ķ���
class SeqList
{
private:
	int length; //˳���ĳ���
	T data[MaxSize];
public:
	SeqList(){length = 0;} //���캯��
	SeqList(T a[], int n);
	~SeqList(){} //��������
	//��λ����
	void Insert(int locate,T x);
	//��ֵ����
	void Insert(T x);
	//ɾ������������
	//���ң���ֵ���ң�
	void FindX(T x);
	//��λ����
	void Find(int l);
	//ɾ��
	void Delete(int l);
	void Print(); //���˳���

};
template <class T>
SeqList<T>::SeqList(T a[], int n)
{
	length = n;
	for(int k =0 ; k < length; k++)
		data[k] = a[k];
}

template <class T>
void SeqList<T>::Insert(int locate, T x)
{
	//�����һ��Ԫ�ؿ�ʼ����locate��Ԫ����������ƶ�
	for(int k = length; k > locate; k--)
		data[k] = data[k-1];
	data[locate] = x;
	length++;
} //����Ԫ��

template<class T>
void SeqList<T>::Insert(T x)
{
	if (length == MaxSize)
	{
		cout << "����" << endl;
		return;
	}
	data[length] = x;
	length++;
} //����Ԫ��

template<class T>
void SeqList<T>::FindX(T x)
{
	int k = 0;
	while(k < length && data[k] != x)
		k++;
	if(k == length)
		cout << "û���ҵ�" << endl;
	else
		cout << "�ҵ���" << endl;
} //����Ԫ��

template<class T>
void SeqList<T>::Find(int locate)
{
	if (locate < 0 || locate >= length)
	{
		cout << "λ�ò��Ϸ�" << endl;
		return;
	}
	cout << "��" << locate << "��Ԫ��Ϊ��" << data[locate] << endl;
} //����Ԫ��

template<class T>
void SeqList<T>::Delete(int locate)
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
void SeqList<T>::Print() 
{
	cout << "˳����Ԫ��Ϊ��";
	for(int k = 0; k < length; k++)
		cout << data[k] << " ";
	cout << endl;
} //���˳���

int main() {
	int x=1;
	int i = 0;
	int a[6] = {0};
	while (x != 0) {
		cin >> x;
		a[i] = x;
		i++;
	}
	SeqList<int> s1(a,6);
	cout << "��ǰ����" ;
	s1.Print();
	cout << "������Ҫ�����λ�ú���ֵ" << endl;
	int locate1;
	int x1;
	cin >> locate1 >> x1;
	s1.Insert(locate1,x1);
	cout << "����������" ;
	s1.Print();
	cout << "������Ҫɾ����λ��"<<endl;
	int locate;
	cin >> locate;
	s1.Delete(locate);
	cout << "�����������" ;
	s1.Print();
	return 0;
}
