#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for (int i = 0; i<32; i++) {
			if (n & 1) count++;//��Ҫ�ó�&&��
			n = n >> 1;//����ֱ��n>>1
		}
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

