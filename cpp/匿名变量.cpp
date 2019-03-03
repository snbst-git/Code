int inc(int &a) {
	return a++;
}

int testall = 0;

int j;
int i=0;
char c=0;
///i用全局 局部变量都可以，只是不能用某个函数体内返回引用的形式
///那个主要是空间会回收，但是对于main()函数体的局部变量，程序结束才会回收，可以使用
int main(int argc, char *argv[])
{

	j=inc(i);
	j=inc(++i);
	j=inc(i++);
	j=inc(i+5);

    ///char c部分全军覆没全是匿名变量，因为类型不符合
	j=inc(c);
	j=inc(++c);
	j=inc(c++);
	j=inc(c+5);
}
