#include <iostream>
#include <cstdlib>
#include <cstdio>
//测试
using namespace std;
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for (int i = 0; i<32; i++) {
			if (n & 1) count++;//不要用成&&了
			n = n >> 1;//不是直接n>>1
		}
		return count;
	}
	int NumberOf1_2(int n){
	    int count=0;
	    while n{
	        ++count;
	        n=(n-1)&n;
	    }
	    /**
	    有符号数的特性
	    n-1相当于+ff……
	    其结果是从右往左，第一个1变为0，第一个1以后的所有0都变成1，第一个1以前不变化
	    现在相与那么前面不变，第一个即以后全部为0，总体就少了一个1
	    前 1 00000
	    前 0 11111
	    ----------
	    前 0 00000
	    就这个画风
	    直到最后为1000 1000-1=0111（溢出
	    1000&0111=0，退出循环
	    */
	    return count;
	}
};

int main()
{
	int n;
	Solution a;
	while (1) {
		cin >> n;
		cout << a.NumberOf1(n) << endl;
	}
	return 0;
}

