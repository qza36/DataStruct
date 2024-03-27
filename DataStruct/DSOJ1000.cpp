//已知顺序表类的定义如下，实现各个成员函数。主函数中输入数据（以0结束）利用Insert函数依次将数据插入到表的1号位置，利用DispList按照逻辑次序输出表中元素，再输入一个要查找的元素，利用查找函数Locate查找其在表中的位置，最后利用Reverse函数将数据逆序，再利用DispList输出。
//template <class T>
//class SeqList {
//public:
//    SeqList(); //构造函数，将表置空
//    ~SeqList() {} //析构
//    int Locate(T x); //查找元素x在表中的位置，成功返回x在表中的位置，否则返回0
//    void Insert(int i, T x); //在表的i位置插入元素x
//    void Reverse(); //逆序表中数据
//    void DispList();
//private:
//    T data[MaxSize];    //存储元素
//    int length;              //顺序表实际长度
//};
//输入
//输入样例说明：例如输入数据为：1 2 3 4 5 6 0 3，即将1, 2, 3, 4, 5, 6插入表中的1号位置，得到逻辑次序为6, 5, 4, 3, 2, 1的顺序表，3为在表中待查找的数据，3的位置为4。
//输入：1 2 3 4 5 6 0 3
//输出：
//The length : 6
//The elements :
//6 5 4 3 2 1
//Found position : 4
//The length : 6
//The elements :
//1 2 3 4 5 6
//
//若查找的数据不存在，则输出：No found，例如下例
//
//输入：1 2 3 4 5 6 0 9
//输出：
//The length : 6
//The elements :
//6 5 4 3 2 1
//No found
//The length : 6
//The elements :
//1 2 3 4 5 6
//
//样例输入 Copy
//1 2 3 4 5 6 0 3
//样例输出 Copy
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
	SeqList(); //构造函数，将表置空
	~SeqList() {} //析构
	int Locate(T x); //查找元素x在表中的位置，成功返回x在表中的位置，否则返回0
	void Insert(int i, T x); //在表的i位置插入元素x
	void Reverse(); //逆序表中数据
	void DispList();
private:
		T data[MaxSize];    //存储元素
		int length;              //顺序表实际长度
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