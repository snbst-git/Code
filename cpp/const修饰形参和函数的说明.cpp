#include <stdio.h>
#include <iostream>

using namespace std;

class A {
public:
	void afunc()const;
	void afunc();
	///仅const修饰和不用const修饰函数不会产生二义性问题，估计常对象使用
	void cfunc(const int a);
	//void cfunc(int a);

};

void A::cfunc(const int a) {
	cout << "const " << a << endl;
}
/**仅仅是参数的const不能够进行区分 会提示已有实体
void A::cfunc(int a) {
	cout << "not const " << a << endl;
}*/


void A::afunc() {
	cout << "not const\n";
}

void A::afunc()const {
	cout << "const\n";
	///inline可以只有声明处写，但是const声明定义都要有
}



int main()
{
	A a1;
	int i1=0, const i2=1;
	a1.afunc();//优先使用了非const的
	A const a2;
	a2.afunc();

	a1.cfunc(i1);
	a1.cfunc(i2);

	getchar();
	return 0;
}
