#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector <int> result;
		int start=0;
		while(matrix.size()>2*start||matrix[0].size()>2*start){
			circletovector(result,start,matrix);//ֻ��ӡһȦ
			start++;
		}
		return result;
	}
	void circletovector(vector<int> &result,int start,vector<vector<int> > &matrix){
		int i,j;
		i=j=start;		
		//�ҽ� matrix[0].size()-1-start
		//�� ��ӡstart~matrix[0].size-1-start
		//�½� matrix.size()-1-start
		//��� start
		//�Ͻ� start
		while(j<matrix[0].size()-start){//ֻ��һ��Ҳ��Ҫ��ӡ
			result.push_back(matrix[i][j]);
			j++;
		}
		j--;
		//�� �����ظ���ӡ���������Ҫ�����������  ����������
		//��Ϊstart ��Ϊmatrix[0].size()-1-start
		if (matrix.size() > 2 * start+1) {
			i++;//�Ѿ���ӡ���ʼһ��
			while (i < matrix.size() - start-1) {
				result.push_back(matrix[i][j]);
				i++;
			}
			i--;
		}
		//�� �����ظ���ӡ
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
			while (i > start) {//��һ�����ô�ӡ�ˣ��Ѿ������
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
		//1�� 2�� 3�� 4��
		int up = 1, down = m - 1, left = 0, right = n - 1;
		int i = 0, j = -1;//j++����=-1��ʼ
		while (up <= down || left <= right) {
			switch (direct) {//1�� 2�� 3�� 4��
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

