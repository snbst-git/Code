#include <iostream>

using namespace std;

int   x=2,  y=x+30;
struct A{
    static int  x;
    int  y;
public:
    operator int( ){ return x+y; }
    A operator ++(int){
         return A(x++, y++);
         /**
         ע��˳��
         1.����A(4,3)����
         2.x++,y++ a(5,4)
         3.����A(4,3)���캯��
         A::x=4
         a(4,4)
         Ҳ�������õ�x++����Ȼ�ȴ�����������Ǳȵ��ú�����
         */
         }
    A(int x=::x+2, int y=::y+3){
		cout << "new A(" << x << "," << y << ")\n";
		A::x = x;  A::y = y;
	}
    int &h(int &x);
    static int testx;
    int func(){return testx++;}
};
int &A::h(int &x)
{
for(int y=1; y!=1|| x<201; x+=11, y++)  if(x>200) { x-=21; y-=2;}
    return x-=10;
}
int A::x=23;
int A::testx=1;
int testall = 0;

void func(int a) {

	cout << "in test func " <<a<< endl;
}

int main( ){

	func(testall++);
    /**
     ע��˳��
     1.����func(0)����
     2.testall++ testall=1
     3.����func(0)����
     Ҳ�������õ�testall++����Ȼ�ȴ�����������Ǳȵ��ú�����
     */

    A  a(54, 3),  b(65),  c;
    int  i,  &z=i,  A::*p=&A::y;
    z=b.x;       i=a.x;    i=c.*p;
    cout<<a.x<<" "<<a.y<<endl;
	A *pt= &a;
    i=a++;
    cout<<a.x<<" "<<a.y<<endl;
    cout<<i<<endl;
    i=::x+c.y;
    i=a+b;
    //cout<<a.x<<" "<<a.y<<endl;
    //cout<<b.x<<" "<<b.y<<endl;
    //cout<<i<<endl;
    b.h(i)=7;
    return 0;
}
