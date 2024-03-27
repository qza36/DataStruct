//��֪˳�����Ķ������£�ʵ�ָ�����Ա���������������������ݣ���0����������Insert�������ν����ݲ��뵽���1��λ�ã�����DispList�����߼������������Ԫ�أ�������һ��Ҫ���ҵ�Ԫ�أ����ò��Һ���Locate�������ڱ��е�λ�ã��������Reverse��������������������DispList�����
//template <class T>
//class SeqList {
//public:
//    SeqList(); //���캯���������ÿ�
//    ~SeqList() {} //����
//    int Locate(T x); //����Ԫ��x�ڱ��е�λ�ã��ɹ�����x�ڱ��е�λ�ã����򷵻�0
//    void Insert(int i, T x); //�ڱ��iλ�ò���Ԫ��x
//    void Reverse(); //�����������
//    void DispList();
//private:
//    T data[MaxSize];    //�洢Ԫ��
//    int length;              //˳���ʵ�ʳ���
//};
//����
//��������˵����������������Ϊ��1 2 3 4 5 6 0 3������1, 2, 3, 4, 5, 6������е�1��λ�ã��õ��߼�����Ϊ6, 5, 4, 3, 2, 1��˳���3Ϊ�ڱ��д����ҵ����ݣ�3��λ��Ϊ4��
//���룺1 2 3 4 5 6 0 3
//�����
//The length : 6
//The elements :
//6 5 4 3 2 1
//Found position : 4
//The length : 6
//The elements :
//1 2 3 4 5 6
//
//�����ҵ����ݲ����ڣ��������No found����������
//
//���룺1 2 3 4 5 6 0 9
//�����
//The length : 6
//The elements :
//6 5 4 3 2 1
//No found
//The length : 6
//The elements :
//1 2 3 4 5 6
//
//�������� Copy
//1 2 3 4 5 6 0 3
//������� Copy
//The length : 6
//The elements :
//6 5 4 3 2 1
//Found position : 4
//The length : 6
//The elements :
//1 2 3 4 5 6

#include <iostream>

using namespace std;

const int MaxSize = 100;
template<class T>
struct Node {
	T data;
	Node<T>* next;
};
template <class T>
class SeqList {
public:
	SeqList(); //���캯���������ÿ�
	~SeqList() {} //����
	int Locate(T x); //����Ԫ��x�ڱ��е�λ�ã��ɹ�����x�ڱ��е�λ�ã����򷵻�0
	void Insert(int i, T x); //�ڱ��iλ�ò���Ԫ��x
	void Reverse(); //�����������
	void DispList();
private:
		T data[MaxSize];    //�洢Ԫ��
		int length;              //˳���ʵ�ʳ���
};

template<class T>
SeqList<T>::SeqList() {
	length = 0;
}

template<class T>
int SeqList<T>::Locate(T x) {
	for (int i = 0; i < length; i++) {
		if (data[i] == x) {
			return i  +1;
		}
	}
	return 0;
}

template<class T>
void SeqList<T>::Insert(int i, T x) {
	for (int j = length; j >= i; j--) {
		data[j] = data[j - 1];
	}
	data[i - 1] = x;
	length++;
}

template<class T>
void SeqList<T>::Reverse() {
	T temp;
	for (int i = 0; i < length / 2; i++) {
		temp = data[i];
		data[i] = data[length - i - 1];
		data[length - i - 1] = temp;
	}
}

template<class T>
void SeqList<T>::DispList() {
	cout << "The length : " << length << endl;
	cout << "The elements :" << endl;
	for (int i = 0; i < length; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

int main() {
	SeqList<int> list;
	int x;
	while (cin >> x && x != 0) {
		list.Insert(1, x);
	}
	list.DispList();
	cin >> x;
	int pos = list.Locate(x);
	if (pos == 0) {
		cout << "No found" << endl;
	}
	else {
		cout << "Found position : " << pos << endl;
	}
	list.DispList();
	return 0;
}