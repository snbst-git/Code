#include <vector>
#include <iostream>

using namespace std;
//得益于本题的特殊性，可以采取对角搜索O(m+n)
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int i = array.size() - 1, j = 0;
		while (i >= 0 && j<array[0].size()) {
			if (array[i][j] == target) return true;
			else if (array[i][j]>target) i--;
			else j++;
		}
		return false;
	}
};
//常规方法O(lgm*lgn)
class Solution2 {
public:
	bool Find(int target, vector<vector<int> > array) {
		int xlow = 0, xhigh, ylow = 0, yhigh, xmid, ymid;
		xhigh = array.size()-1;//行数
		xmid = (xlow + xhigh) >> 1;
		//注意low high应该是size-1的问题 避免low=mid+1之后==high进而越界访问
		while (xlow<xhigh) {		
			ylow = 0, yhigh = array[xmid].size()-1;//列数
			ymid = (ylow + yhigh) >> 1;
			while (ylow<yhigh) {
				if (array[xmid][ymid] == target) return 1;
				else if (array[xmid][ymid]>target) {
					yhigh = ymid;
				}
				else if (array[xmid][ymid]<target) {
					ylow = ymid+1;
				}
				ymid = (ylow + yhigh) >> 1;
			}
			if (array[xmid][ymid] == target) return 1;
			else if (array[xmid][ymid]>target) {
				xhigh = xmid;
			}
			else if (array[xmid][ymid]<target) {
				xlow = xmid+1;
			}
			xmid = (xlow + xhigh) >> 1;
		}
		//****注意：由于是二维数组，这里low=high的情况还需要搜索这一行
		ylow = 0, yhigh = array[xmid].size() - 1;//列数
		ymid = (ylow + yhigh) >> 1;
		while (ylow<yhigh) {
			if (array[xmid][ymid] == target) return 1;
			else if (array[xmid][ymid]>target) {
				yhigh = ymid;
			}
			else if (array[xmid][ymid]<target) {
				ylow = ymid + 1;
			}
			ymid = (ylow + yhigh) >> 1;
		}
		if (array[xmid][ymid] == target) return 1;
		else return 0;
	}
};


int main() {
	vector<vector<int> > test(5);
	for (int i = 0; i < 5; i++) {
		test[i].resize(5);
		for (int j = 0; j < 5; j++) {
			test[i][j] = i * 5 + j;
		}
	}
	Solution a;
	cout<<a.Find(26, test);
	cout << a.Find(24, test);
	cout << a.Find(0, test);
	cout << a.Find(-1, test);
	Solution2 b;
	cout<<b.Find(26, test);
	cout << b.Find(24, test);
	cout << b.Find(0, test);
	cout << b.Find(-1, test);
	return 0;
}
