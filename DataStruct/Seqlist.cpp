#include <iostream>

using namespace std;

const int MaxSize = 10; //定义最大长度

/*类模板 */

template <class T> //类模板的定义
class qzaSeqList
{
private:
	int length; //顺序表的长度
	T data[MaxSize];
public:
	qzaSeqList(){length = 0;} //构造函数
	qzaSeqList(T a[], int n);
	~qzaSeqList(){} //析构函数
	//按位插入
	void Insert(int locate,T x);
	//插入数据，然后排序
	void sortInsert(T x);
	//删除（按下标删除)
	void Delete(int locate);
	//查找（按值查找）符合条件的元素
	void FindX(T x);
	//按位查找
	void Find(int l);
	void Print(); //输出顺序表
	void getlength() {cout << "顺序表的长度为：" << length << endl;}
};
template <class T>
qzaSeqList<T>::qzaSeqList(T a[], int n)
{
	length = n;
	for(int k =0 ; k < length; k++)
		data[k] = a[k];
}

template <class T>
void qzaSeqList<T>::Insert(int locate, T x)
{
	//从最后一个元素开始到第locate个元素依次向后移动
	for(int k = length; k > locate; k--)
		data[k] = data[k-1];
	data[locate] = x;
	length++;
	} //插入元素


template<class T>
void qzaSeqList<T>::FindX(T x)
{
	int i;
	for(i = 0; i < length; i++)
		if (data[i] == x)
		{
			cout << "第" << i << "个元素为：" << x << endl;
			break;
		}
	if (i == length)
		cout << "没有找到" << x << endl;
} //查找元素

template<class T>
void qzaSeqList<T>::Find(int locate)
{
	if (locate < 0 || locate >= length)
	{
		cout << "位置不合法" << endl;
		return;
	}
	cout << "第" << locate << "个元素为：" << data[locate] << endl;
} //查找元素

template<class T>
void qzaSeqList<T>::Delete(int locate)
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
void qzaSeqList<T>::Print() 
{
	cout << "顺序表的元素为：";
	for(int k = 0; k < length; k++)
		cout << data[k] << " ";
	cout << endl;
} //输出顺序表

template <class T>
void qzaSeqList<T>::sortInsert(T x)
{//插入，然后冒泡排序
	data[length] = x;
	length++;
	for(int i = 0; i < length; i++)
		for(int j = 0; j < length - i - 1; j++)
			if (data[j] > data[j + 1])
			{
				T temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
} //插入元素

int main() {
	int x=1;
	int i = 0;
	int a[10] = {0};
	cout << "输入数据：" << endl;
	while (x != 0) {
		cin >> x;
		a[i] = x;
		i++;
	}
	qzaSeqList<int> s1(a,i-1);
	cout << "当前数组" ;
	s1.Print();
	 s1.getlength();
	cout <<"输入插入位置和插入元素" << endl;
	int locate;
	cin >> locate >> x;
	s1.Insert(locate,x);
	cout << "插入后的数组" ;
	s1.Print();
	cout << "输入插入的数据" << endl;
	cin >> x;
	s1.sortInsert(x);
	cout << "排序后的数组" << endl;
	s1.Print();
	cout << "输入删除的位置" << endl;
	cin >> locate;
	s1.Delete(locate);
	cout << "删除后的数组" << endl;
	s1.Print();
	cout << "输入查找的元素" << endl;
	cin >> x;
	s1.FindX(x);
	cout << "输入查找的位置" << endl;
	cin >> locate;
	s1.Find(locate);

	return 0;
}
