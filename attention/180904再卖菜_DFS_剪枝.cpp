///���������spfa�����Ĳο� https://blog.csdn.net/wl16wzl/article/details/83652703
///���ڲ��Լ�� https://blog.csdn.net/c79801496/article/details/46862269

//8 2 2 1 3 4 9 10 13
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//���Ǽ�֦������ʱ���� ������������������
//https://blog.csdn.net/wl16wzl/article/details/83652703
//https://blog.csdn.net/imotolove/article/details/82777819#commentsedit
bool state[301][301][301];//��֦

int getprice(vector<int>&result, int loc, vector<int>&price) {
	if (loc > 0) {
		///ע��Ҫ������һ�ҵļ۸�result[loc-1]
		if (state[loc][result[loc - 1]][result[loc]]) return 0;///�Ѿ����ǹ���ʧ��ֵ ҲҪ����ͷһ�Ҳ�ͬ��һ����ͬ�����
		else state[loc][result[loc - 1]][result[loc]] = 1;
	}
	int temp, k;
	if (loc == 0) {
		temp = price[0] * 2;
		for (k = 1; k < temp; k++) {//k���temp-1
			result[0] = k, result[1] = temp - k;
			if (getprice(result, loc + 1, price)) return 1;//�����ź�
		}
		temp++;
		for (k = 1; k < temp; k++) {//k���temp-1
			result[0] = k, result[1] = temp - k;
			if (getprice(result, loc + 1, price)) return 1;//�����ź�
		}
	}
	else if (loc < price.size() - 1) {
		temp = price[loc] * 3;
		result[loc + 1] = temp - result[loc] - result[loc - 1];
		if (result[loc + 1] < -2) return 0;//������-2+3=1�žȵû���
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		result[loc + 1]++;//++������Ϊ��Ϊ����ʱ�򲹾ȣ���������Ѿ�Ϊ+˵����ƫ���ˣ�����Ҫ���� ����©����һЩ���������
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		result[loc + 1]++;
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		return 0;
	}
	else if (loc == price.size() - 1) {//�����n-1λ�õ�ֵ
		if ((result[loc] + result[loc - 1]) / 2 == price[loc]) return 1;
		return 0;
	}
}
/***
//��ͨ�㷨����ʱ����
int getprice(vector<int>&result, int loc,vector<int>&price) {
	int temp, k;
	if (loc == 0) {
		temp = price[0] * 2;
		for (k = 1; k < temp; k++) {//k���temp-1
			result[0] = k, result[1] = temp - k;
			if (getprice(result, loc+1, price)) return 1;//�����ź�
		}
		temp++;
		for (k = 1; k < temp; k++) {//k���temp-1
			result[0] = k, result[1] = temp - k;
			if (getprice(result, loc+1, price)) return 1;//�����ź�
		}
	}
	else if (loc < price.size() - 1) {
		temp = price[loc] * 3;
		result[loc + 1] = temp - result[loc] - result[loc - 1];
		if (result[loc + 1] < -2) return 0;//������-2+3=1�žȵû���
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		result[loc + 1]++;//++������Ϊ��Ϊ����ʱ�򲹾ȣ���������Ѿ�Ϊ+˵����ƫ���ˣ�����Ҫ���� ����©����һЩ���������
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		result[loc + 1]++;
		if (result[loc + 1] > 0) {
			if (getprice(result, loc + 1, price)) return 1;
		}
		return 0;
	}
	else if (loc == price.size() - 1) {//�����n-1λ�õ�ֵ
		if ((result[loc] + result[loc - 1]) / 2 == price[loc]) return 1;
		return 0;
	}
}*/

int main() {
	int n,i,j,k,temp;
	cin >> n;
	vector<int> price(n),result(n);
	for (i = 0; i < n; i++) cin >> price[i];//¼��۸�
	if (n == 2) {
		cout << price[0]<<" "<<price[1];//������ֵ�϶�Ҫ���
		return 0;
	}
	getprice(result, 0, price);
	for (i = 0; i < n - 1; i++) cout << result[i] << " ";
	cout << result[i];

	return 0;

}
