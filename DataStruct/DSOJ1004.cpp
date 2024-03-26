//
//��֪������Ķ������£�ʵ�ָ�����Ա���������������������ݣ���0����������Insert�������ν����ݲ��뵽���1��λ�ã�����DispList�����߼������������Ԫ�أ�������һ��Ҫ���ҵ�Ԫ�أ����ò��Һ���Locate�������ڱ��е�λ�ã��������Reverse��������������������DispList�����
//template <class T>
//class LinkList
//{
//public:
//    LinkList(); //����ֻ��ͷ���Ŀ�����
//    ~LinkList();             //��������
//    int Length();          //������ĳ���
//    int Locate(T x);       //��������ֵΪx��Ԫ�����
//    void Insert(int i, T x);   //�ڵ������е�i��λ�ò���Ԫ��ֵΪx�Ľ��
//    void Reverse();        //reverse list
//    void DispList();           //������������������������Ԫ��
//private:
//    Node<T>* first; //�������ͷָ��
//};
//��������˵����
//������������Ϊ��1 2 3 4 5 6 0 3������1, 2, 3, 4, 5, 6������е�1��λ�ã��õ��߼�����Ϊ6, 5, 4, 3, 2, 1��˳���3Ϊ�ڱ��д����ҵ����ݣ�3��λ��Ϊ4��
//�����룺1 2 3 4 5 6 0 13
//13�ڱ����ޣ��������No found
//����������
//The length : 6
//The elements :
//6 5 4 3 2 1
//No found
//The length : 6
//The elements :
//1 2 3 4 5 6
#include <iostream>
using namespace std;

template <class T>
struct Node{
	T data;
	Node<T>* next;
};

template<class T>
class LinkList{
public:
	LinkList();
	~LinkList();
	int Length();
	int Locate(T x);
	void Insert(int i, T x);
	void Reverse();
	void DispList();
private:
	Node<T>* first;
};

template<class T>
LinkList<T>::LinkList() {
	first = new Node<T>;
	first->next = NULL;
}

template<class T>
LinkList<T>::~LinkList() {
	Node<T>* p = first;
	while (first != NULL) {
		p = first;
		first = first->next;
		delete p;
	}
}

template<class T>
int LinkList<T>::Length() {
	Node<T>* p = first->next;
	int count = 0;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

template<class T>
int LinkList<T>::Locate(T x) {
	Node<T>* p = first->next;
	int count = 1;
	while (p != NULL) {
		if (p->data == x) {
			return count;
		}
		count++;
		p = p->next;
	}
	return -1;
}

template<class T>
void LinkList<T>::Insert(int i, T x) {
	Node<T>* p = first;
	int count = 0;
	while (p != NULL && count < i - 1) {
		p = p->next;
		count++;
	}
	if (p == NULL || count > i - 1) {
		cout << "Insert position error" << endl;
		return;
	}
	Node<T>* q = new Node<T>;
	q->data = x;
	q->next = p->next;
	p->next = q;
}

template<class T>
void LinkList<T>::Reverse() {
	Node<T>* p = first->next;
	Node<T>* q = NULL;
	first->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = first->next;
		first->next = p;
		p = q;
	}
}

template<class T>
void LinkList<T>::DispList() {
	Node<T>* p = first->next;
	cout << "The length : " << Length() << endl;
	cout << "The elements :" << endl;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main() {
		LinkList<int> list;
	int x;
	while (cin >> x && x != 0) {
		list.Insert(1, x);
	}
	list.DispList();
	int y;
	cin >> y;
	int pos = list.Locate(y);
	if (pos == -1) {
		cout << "No found" << endl;
	}
	else {
		cout <<"Found position:" << pos << endl;
	}
	list.Reverse();
	list.DispList();
	return 0;
}
