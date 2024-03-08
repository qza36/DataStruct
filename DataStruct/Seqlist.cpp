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
	for(knt k = length; k > locate; k--)
		data[k] = data[k-1];
	data[locate] = x;
	length++;
} //插入元素

template <class T>
void SeqList<T>::Print() 
{
	cout << "顺序表的元素为：";
	for(int k = 0; k < length; k++)
		cout << data[k] << " ";
	cout << endl;
} //输出顺序表

int main() {
	int a[5] = {1,2,3,4,5};
	SeqList<int> s1(a,5);
	s1.Print();
	return 0;
}
