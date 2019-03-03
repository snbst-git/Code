#include <stdio.h>
#include <list>
#include <iostream>
#include <windows.h>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef list<int> LISTINT;
typedef list<string> STRLIST;
typedef map<string, string> MYMAP;
typedef map<string, STRLIST> FUNCCALLMAP;

static int func(){cout<<"test"<<endl;}//作用局限于本文件

class A {
	int num;
	const static int x=0;//正确
	//static int x=0;错误，应该在类体外完成初始化
	//const int y=1;错误，应该使用初始化列表完成初始化
	/**这里的get()相当于一个全局函数，不是A的成员
	所以首先不能直接return num因为没有this指针
	其次不能使用virtual和static修饰，因为不是类的成员函数没有意义
	*/
	//friend int get(){return num;}
	//friend static int get(A &a){return a.num;}
	friend int get(A &a){return a.num;}
public:
    A(int a=0):num(a){}

};

class B:public A{

};

int main(int argc, char *argv[])
{
    A b;
    func();
    cout<<get(b);


    getchar();
    getchar();

	return 0;
}
