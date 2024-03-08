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
	for(knt k = length; k > locate; k--)
		data[k] = data[k-1];
	data[locate] = x;
	length++;
} //����Ԫ��

template <class T>
void SeqList<T>::Print() 
{
	cout << "˳����Ԫ��Ϊ��";
	for(int k = 0; k < length; k++)
		cout << data[k] << " ";
	cout << endl;
} //���˳���

int main() {
	int a[5] = {1,2,3,4,5};
	SeqList<int> s1(a,5);
	s1.Print();
	return 0;
}
