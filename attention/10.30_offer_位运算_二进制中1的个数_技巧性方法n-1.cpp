#include <iostream>
#include <cstdlib>
#include <cstdio>
//����
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
	int NumberOf1_2(int n){
	    int count=0;
	    while n{
	        ++count;
	        n=(n-1)&n;
	    }
	    /**
	    �з�����������
	    n-1�൱��+ff����
	    �����Ǵ������󣬵�һ��1��Ϊ0����һ��1�Ժ������0�����1����һ��1��ǰ���仯
	    ����������ôǰ�治�䣬��һ�����Ժ�ȫ��Ϊ0�����������һ��1
	    ǰ 1 00000
	    ǰ 0 11111
	    ----------
	    ǰ 0 00000
	    ���������
	    ֱ�����Ϊ1000 1000-1=0111�����
	    1000&0111=0���˳�ѭ��
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

