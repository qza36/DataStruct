#include <iostream>

using namespace std;

const int MaxSize = 10; //定义最大长度

/*类模板 */

template <class T> //类模板的定义
class SeqList
{
private:
	int length; //顺序表的长度
	T data[MaxSize];
public:
	SeqList(){length = 0;} //构造函数
	SeqList(T a[], int n);
	~SeqList(){} //析构函数
	//按位插入
	void Insert(int locate,T x);
	//按值插入
	void Insert(T x);
	//删除（带条件）
	//查找（按值查找）
	void FindX(T x);
	//按位查找
	void Find(int l);
	//删除
	void Delete(int l);
	void Print(); //输出顺序表

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
	//从最后一个元素开始到第locate个元素依次向后移动
	for(int k = length; k > locate; k--)
		data[k] = data[k-1];
	data[locate] = x;
	length++;
} //插入元素

template<class T>
void SeqList<T>::Insert(T x)
{
	if (length == MaxSize)
	{
		cout << "上溢" << endl;
		return;
	}
	data[length] = x;
	length++;
} //插入元素

template<class T>
void SeqList<T>::FindX(T x)
{
	int k = 0;
	while(k < length && data[k] != x)
		k++;
	if(k == length)
		cout << "没有找到" << endl;
	else
		cout << "找到了" << endl;
} //查找元素

template<class T>
void SeqList<T>::Find(int locate)
{
	if (locate < 0 || locate >= length)
	{
		cout << "位置不合法" << endl;
		return;
	}
	cout << "第" << locate << "个元素为：" << data[locate] << endl;
} //查找元素

template<class T>
void SeqList<T>::Delete(int locate)
{
	if (locate < 0 || locate >= length)
	{
		cout << "位置不合法" << endl;
		return;
	}
	for(int k = locate; k < length-1; k++)
		data[k] = data[k+1];
	length--;
} //删除元素

template <class T>
void SeqList<T>::Print() 
{
	cout << "顺序表的元素为：";
	for(int k = 0; k < length; k++)
		cout << data[k] << " ";
	cout << endl;
} //输出顺序表

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
	cout << "当前数组" ;
	s1.Print();
	cout << "输入想要插入的位置和数值" << endl;
	int locate1;
	int x1;
	cin >> locate1 >> x1;
	s1.Insert(locate1,x1);
	cout << "插入后的数组" ;
	s1.Print();
	cout << "输入想要删除的位置"<<endl;
	int locate;
	cin >> locate;
	s1.Delete(locate);
	cout << "操作后的数组" ;
	s1.Print();
	return 0;
}
