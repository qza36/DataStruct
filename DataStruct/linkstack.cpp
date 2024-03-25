#include <iostream>

using namespace std;

const int MaxSize = 10;

template <class T>
class qzaLinkStack
{
private:
	T data[MaxSize];
	int top; //ջ��Ԫ���±�
public:
	qzaLinkStack();//��ջ����
	~qzaLinkStack();
	void push(T x);//ѹջ
	T pop();//��ջ
	void print();//��ӡջ
	T getTop();//ȡջ��Ԫ��
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
	if (top >= MaxSize - 1) throw "ջ��";
	top++;
	data[top] = x;
}

template<class T>
void qzaLinkStack<T>::print()
{
	cout << "ջ��Ԫ�أ�";
	for (int i = 0; i <= top; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

template<class T>
T qzaLinkStack<T>::pop()
{
	if (top == -1) throw "ջ��";
	T x =  data[top];
	top--;
	return x;
}
 template<class T>
 T qzaLinkStack<T>::getTop() {
	if (top == -1) throw "ջ��";
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
	cout << "��ջ��Ԫ��Ϊ��" << x << endl;
	s.print();
	x = s.getTop();
	cout << "ջ��Ԫ��Ϊ��" << x << endl;	
	s.print();
	bool flag = s.Empty();
	if(flag == 1)
		cout << "ջΪ��" << endl;
	else 
		cout << "ջ��Ϊ��" << endl;
	return 0;
}
