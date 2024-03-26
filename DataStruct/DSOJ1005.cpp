//已知一个有序链表类LinkSortList及main函数的部分代码如下，请完成LinkSortList类的成员函数，得到对应的运行结果，勿改动main函数。
////有序表类
//template <class T>
//class LinkSortList
//{
//public:
//    LinkSortList(); //建立只有头结点的空链表
//    ~LinkSortList();             //析构函数
//    void Insert(T x);   //在有序单链表中插入元素x使序列仍有序
//    int Length();      //求表长
//    int DeleteOdd();     //在单链表中删除所有奇数，返回值为奇数个数
//    void DispList();     //遍历有序单链表，按序号依次输出各元素
//private:
//    Node<T>* first; //单链表的头指针
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
//样例输入 
//42 5 32 56 34 7 233 1 0
//样例输出 
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
	LinkSortList(); //建立只有头结点的空链表
	~LinkSortList();             //析构函数
	void Insert(T x);   //在有序单链表中插入元素x使序列仍有序
	int Length();      //求表长
	int DeleteOdd();     //在单链表中删除所有奇数，返回值为奇数个数
	void DispList();     //遍历有序单链表，按序号依次输出各元素
	private:
		Node<T>* first; //单链表的头指针
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