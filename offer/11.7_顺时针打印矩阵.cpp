#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector <int> result;
		int start=0;
		while(matrix.size()>2*start||matrix[0].size()>2*start){
			circletovector(result,start,matrix);//只打印一圈
			start++;
		}
		return result;
	}
	void circletovector(vector<int> &result,int start,vector<vector<int> > &matrix){
		int i,j;
		i=j=start;		
		//右界 matrix[0].size()-1-start
		//→ 打印start~matrix[0].size-1-start
		//下界 matrix.size()-1-start
		//左界 start
		//上界 start
		while(j<matrix[0].size()-start){//只有一列也需要打印
			result.push_back(matrix[i][j]);
			j++;
		}
		j--;
		//行 避免重复打印，下面的行要高于上面的行  至少有两行
		//上为start 下为matrix[0].size()-1-start
		if (matrix.size() > 2 * start+1) {
			i++;//已经打印了最开始一行
			while (i < matrix.size() - start-1) {
				result.push_back(matrix[i][j]);
				i++;
			}
			i--;
		}
		//列 避免重复打印
		if (matrix[0].size() > 2 * start+1) {
			--j;
			while (j >= start) {
				result.push_back(matrix[i][j]);
				j--;
			}
			j++;
		}
		if (matrix[0].size() > 2 * start + 1 && matrix.size() > 2 * start + 1) {
			i--;
			while (i > start) {//第一个不用打印了，已经解决了
				result.push_back(matrix[i][j]);
				i--;
			}
			i++;
		}	
	}
	/*
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector <int> result;
		int m = matrix.size();
		int n = matrix[0].size();
		int direct = 1;
		//1→ 2↓ 3← 4↑
		int up = 1, down = m - 1, left = 0, right = n - 1;
		int i = 0, j = -1;//j++所以=-1开始
		while (up <= down || left <= right) {
			switch (direct) {//1→ 2↓ 3← 4↑
			case 1:
				direct = 2;
				if (left > right) return result;
				j++;
				while (j <= right) {
					result.push_back(matrix[i][j]);
					j++;
				}
				j--;
				right--;
				break;
			case 2:
				direct = 3;
				if (up > down) return result;
				i++;
				while (i <= down) {
					result.push_back(matrix[i][j]);
					i++;
				}
				i--;
				down--;
				break;
			case 3:
				direct = 4;
				if (left > right) return result;
				j--;
				while (j >= left) {
					result.push_back(matrix[i][j]);
					j--;
				}
				j++;
				left++;
				break;
			case 4:
				direct = 1;
				if (up > down) return result;
				i--;
				while (i >= up) {
					result.push_back(matrix[i][j]);
					i--;
				}
				i++;
				up++;
				break;
			default:
				break;
			}
		}
		return result;
	}
	*/
};

int main() {
	vector<vector<int>> matrix(1);

	int i;
	for (i = 1; i <= 5; i++) matrix[0].push_back( i);

	Solution a;
	a.printMatrix(matrix);

	return 0;
}

