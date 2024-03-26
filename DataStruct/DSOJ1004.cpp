//
//已知链表类的定义如下，实现各个成员函数。主函数中输入数据（以0结束）利用Insert函数依次将数据插入到表的1号位置，利用DispList按照逻辑次序输出表中元素，再输入一个要查找的元素，利用查找函数Locate查找其在表中的位置，最后利用Reverse函数将数据逆序，再利用DispList输出。
//template <class T>
//class LinkList
//{
//public:
//    LinkList(); //建立只有头结点的空链表
//    ~LinkList();             //析构函数
//    int Length();          //求单链表的长度
//    int Locate(T x);       //求单链表中值为x的元素序号
//    void Insert(int i, T x);   //在单链表中第i个位置插入元素值为x的结点
//    void Reverse();        //reverse list
//    void DispList();           //遍历单链表，按序号依次输出各元素
//private:
//    Node<T>* first; //单链表的头指针
//};
//输入样例说明：
//例如输入数据为：1 2 3 4 5 6 0 3，即将1, 2, 3, 4, 5, 6插入表中的1号位置，得到逻辑次序为6, 5, 4, 3, 2, 1的顺序表，3为在表中待查找的数据，3的位置为4。
//若输入：1 2 3 4 5 6 0 13
//13在表中无，则输出：No found
//即输出结果：
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
