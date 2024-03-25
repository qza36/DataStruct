#include <iostream>

using namespace std;

const int MaxSize = 10;

template <class T>
class qzaLinkStack
{
private:
	T data[MaxSize];
	int top; //栈顶元素下标
public:
	qzaLinkStack();//空栈构造
	~qzaLinkStack();
	void push(T x);//压栈
	T pop();//弹栈
	void print();//打印栈
	T getTop();//取栈顶元素
	bool Empty();
};

template<class T>
qzaLinkStack<T>::qzaLinkStack()
{
	top = -1;
}

template<class T>
qzaLinkStack<T>::~qzaLinkStack()
{
}

template<class T>
void qzaLinkStack<T>::push(T x)
{
	if (top >= MaxSize - 1) throw "栈满";
	top++;
	data[top] = x;
}

template<class T>
void qzaLinkStack<T>::print()
{
	cout << "栈内元素：";
	for (int i = 0; i <= top; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

template<class T>
T qzaLinkStack<T>::pop()
{
	if (top == -1) throw "栈空";
	T x =  data[top];
	top--;
	return x;
}
 template<class T>
 T qzaLinkStack<T>::getTop() {
	if (top == -1) throw "栈空";
	return data[top];
}
 template<class T> 
 bool qzaLinkStack<T>::Empty() {
	 if(top==-1) return true;
	 else return false;
 }
int main() {
	qzaLinkStack<int> s;
	int x;
	cin >> x;
	while (x != 0)
	{
		s.push(x);
		cin >> x;
	}
	s.print();
	x = s.pop();
	cout << "弹栈的元素为：" << x << endl;
	s.print();
	x = s.getTop();
	cout << "栈顶元素为：" << x << endl;	
	s.print();
	bool flag = s.Empty();
	if(flag == 1)
		cout << "栈为空" << endl;
	else 
		cout << "栈不为空" << endl;
	return 0;
}
