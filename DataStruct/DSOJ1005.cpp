//��֪һ������������LinkSortList��main�����Ĳ��ִ������£������LinkSortList��ĳ�Ա�������õ���Ӧ�����н������Ķ�main������
////�������
//template <class T>
//class LinkSortList
//{
//public:
//    LinkSortList(); //����ֻ��ͷ���Ŀ�����
//    ~LinkSortList();             //��������
//    void Insert(T x);   //�����������в���Ԫ��xʹ����������
//    int Length();      //���
//    int DeleteOdd();     //�ڵ�������ɾ����������������ֵΪ��������
//    void DispList();     //��������������������������Ԫ��
//private:
//    Node<T>* first; //�������ͷָ��
//};
//int main() {
//    LinkSortList<int> sa;
//    int x;
//    while (1)
//    {
//        cin >> x;
//        if (!x)break;
//        sa.Insert(x);
//    }
//    sa.DispList();
//    int count = sa.DeleteOdd();
//    cout << "Count of deleted odds:" << count << endl;
//    sa.DispList();
//    return 0;
//}
//�������� 
//42 5 32 56 34 7 233 1 0
//������� 
//The length : 8
//The elements : 1 5 7 32 34 42 56 233
//Count of deleted odds : 4
//The length : 4
//The elements : 32 34 42 56

#include <iostream>
using namespace std;

template <class T>
struct Node {
	T data;
	Node<T>* next;
};

template<class T>
class LinkSortList
{
	public:
	LinkSortList(); //����ֻ��ͷ���Ŀ�����
	~LinkSortList();             //��������
	void Insert(T x);   //�����������в���Ԫ��xʹ����������
	int Length();      //���
	int DeleteOdd();     //�ڵ�������ɾ����������������ֵΪ��������
	void DispList();     //��������������������������Ԫ��
	private:
		Node<T>* first; //�������ͷָ��
};

template<class T>
LinkSortList<T>::LinkSortList() {
	first = new Node<T>;
	first->next = NULL;
}

template<class T>
LinkSortList<T>::~LinkSortList() {
	Node<T>* p = first;
	while (first != NULL) {
		p = first;
		first = first->next;
		delete p;
	}
}

template<class T>
void LinkSortList<T>::Insert(T x) {
	Node<T>* p = first;
	Node<T>* q = new Node<T>;
	q->data = x;
	while (p->next != NULL && p->next->data < x) {
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
}

template<class T>
int LinkSortList<T>::Length() {
	Node<T>* p = first->next;
	int count = 0;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

template<class T>
int LinkSortList<T>::DeleteOdd() {
	Node<T>* p = first;
	int count = 0;
	while (p->next != NULL) {
		if (p->next->data % 2 == 1) {
			Node<T>* q = p->next;
			p->next = q->next;
			delete q;
			count++;
		}
		else {
			p = p->next;
		}
	}
	return count;
}

template<class T>
void LinkSortList<T>::DispList() {
	Node<T>* p = first->next;
	cout << "The length:" << Length() << endl;
	cout << "The elements:";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main() {
	LinkSortList<int> sa;
	int x;
	while (1)
	{
		cin >> x;
		if (!x)break;
		sa.Insert(x);
	}
	sa.DispList();
	int count = sa.DeleteOdd();
	cout << "Count of deleted odds:" << count << endl;
	sa.DispList();
	return 0;
}