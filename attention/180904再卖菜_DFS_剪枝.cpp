///关于这道题spfa方法的参考 https://blog.csdn.net/wl16wzl/article/details/83652703
///关于差分约束 https://blog.csdn.net/c79801496/article/details/46862269

//8 2 2 1 3 4 9 10 13
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//考虑剪枝后解决超时问题 总体采用深度优先搜索
//https://blog.csdn.net/wl16wzl/article/details/83652703
//https://blog.csdn.net/imotolove/article/details/82777819#commentsedit
bool state[301][301][301];//剪枝

int getprice(vector<int>&result, int loc, vector<int>&price) {
	if (loc > 0) {
		///注意要考虑上一家的价格！result[loc-1]
		if (state[loc][result[loc - 1]][result[loc]]) return 0;///已经考虑过的失败值 也要考虑头一家不同这一家相同的情况
		else state[loc][result[loc - 1]][result[loc]] = 1;
	}
	int temp, k;
	if (loc == 0) {
		temp = price[0] * 2;
		for (k = 1; k < temp; k++) {//k最大temp-1
			result[0] = k, result[1] = temp - k;
			if (getprice(result, loc + 1, price)) return 1;//结束信号
		}
		temp++;
		for (k = 1; k < temp; k++) {//k最大temp-1
			result[0] = k, result[1] = temp - k;
			if (getprice(result, loc + 1, price)) return 1;//结束信号
		}
	}
	else if (loc < price.size() - 1) {
		temp = price[loc] * 3;
		result[loc + 1] = temp - result[loc] - result[loc - 1];
		if (result[loc + 1] < -2) return 0;//至少是-2+3=1才救得回来
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		result[loc + 1]++;//++仅仅是为了为负的时候补救，但是如果已经为+说明是偏大了，不需要继续 好像漏掉了一些情况，不行
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		result[loc + 1]++;
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		return 0;
	}
	else if (loc == price.size() - 1) {//求的是n-1位置的值
		if ((result[loc] + result[loc - 1]) / 2 == price[loc]) return 1;
		return 0;
	}
}
/***
//普通算法，超时问题
int getprice(vector<int>&result, int loc,vector<int>&price) {
	int temp, k;
	if (loc == 0) {
		temp = price[0] * 2;
		for (k = 1; k < temp; k++) {//k最大temp-1
			result[0] = k, result[1] = temp - k;
			if (getprice(result, loc+1, price)) return 1;//结束信号
		}
		temp++;
		for (k = 1; k < temp; k++) {//k最大temp-1
			result[0] = k, result[1] = temp - k;
			if (getprice(result, loc+1, price)) return 1;//结束信号
		}
	}
	else if (loc < price.size() - 1) {
		temp = price[loc] * 3;
		result[loc + 1] = temp - result[loc] - result[loc - 1];
		if (result[loc + 1] < -2) return 0;//至少是-2+3=1才救得回来
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		result[loc + 1]++;//++仅仅是为了为负的时候补救，但是如果已经为+说明是偏大了，不需要继续 好像漏掉了一些情况，不行
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		result[loc + 1]++;
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		return 0;
	}
	else if (loc == price.size() - 1) {//求的是n-1位置的值
		if ((result[loc] + result[loc - 1]) / 2 == price[loc]) return 1;
		return 0;
	}
}*/

int main() {
	int n,i,j,k,temp;
	cin >> n;
	vector<int> price(n),result(n);
	for (i = 0; i < n; i++) cin >> price[i];//录入价格
	if (n == 2) {
		cout << price[0]<<" "<<price[1];//两个价值肯定要相等
		return 0;
	}
	getprice(result, 0, price);
	for (i = 0; i < n - 1; i++) cout << result[i] << " ";
	cout << result[i];

	return 0;

}
