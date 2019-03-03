class A {
public:
    void afunc()const;

};

void A::afunc()const {
	///1.inline可以只有声明处写，但是const声明定义都要有，否则提示不兼容
}

//2.至于inline可否只在定义处写不不清楚
//3.另外inline的函数定义必须先于其调用，否则会内联失败，只进行普通的函数调用