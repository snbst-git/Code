#include <stdio.h>
#include <iostream>

using namespace std;

class A {
public:
	void afunc()const;
	void afunc();
	///��const���κͲ���const���κ�������������������⣬���Ƴ�����ʹ��
	void cfunc(const int a);
	//void cfunc(int a);

};

void A::cfunc(const int a) {
	cout << "const " << a << endl;
}
/**�����ǲ�����const���ܹ��������� ����ʾ����ʵ��
void A::cfunc(int a) {
	cout << "not const " << a << endl;
}*/


void A::afunc() {
	cout << "not const\n";
}

void A::afunc()const {
	cout << "const\n";
	///inline����ֻ��������д������const�������嶼Ҫ��
}



int main()
{
	A a1;
	int i1=0, const i2=1;
	a1.afunc();//����ʹ���˷�const��
	A const a2;
	a2.afunc();

	a1.cfunc(i1);
	a1.cfunc(i2);

	getchar();
	return 0;
}
