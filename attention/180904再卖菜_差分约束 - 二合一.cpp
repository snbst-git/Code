#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
///����max������ѧ����ͬ��xj-xi��bk ��Ӧw(i,j)=bk relaxΪ> �����ޱ�Ϊ��������ɳڵ��б�
///�㷨Ϊ�����·�����󵽵�Ϊ���ֵ


///��min����ѧ�ķ�������  xj-xi��bk ��Ӧw(i,j)=bk relaxΪ< �����ޱ�Ϊ-1(��С�������ɳڵ��б�
///�㷨Ϊ���·�����󵽵�Ϊ��Сֵ


#define MIN
//ע��ת����ʽ  aj-ai<=bk �� w(i,j)=bk
const int inf = 0xfffffff;
///20180904 80�ֳ�ʱ ����ʹ�ò��Լ���Ż�

struct node {
	int d;
	int ex;
	node() {
#ifdef MIN
	d = -1;
#else
	d = inf;//MAX
#endif // MIN
	 ex = 0;
	}
};

struct edge {
	int u;
	int v;
	int w;
	edge(int start, int end, int wnum) { u = start, v = end, w = wnum; }
};

//edge (u,v) ��Ƚ�v.d��u.d+w(u,v)
int relax(edge &e, node *V) {
#ifdef MIN
///��ʼ��Ϊ-1 ����û�бߣ��𽥷Ŵ�Ŵ�����Ҫ�ﵽ��MIN
	if (V[e.v].d<V[e.u].d + e.w) {
		V[e.v].d = V[e.u].d + e.w;
		V[e.v].ex = e.u;//ǰ��������Ϊu
		return 1;//1��ʾ�������޸�֮��ֻ��Ҫ+=relax�Ϳ����ж��Ƿ��޸���
	}
	return 0;//0��ʾû�н����޸�
#else
///��ʼΪ���������û�бߣ�����С��СΪ����ܴﵽ��MAX
	if (V[e.v].d>V[e.u].d + e.w) {
		V[e.v].d = V[e.u].d + e.w;
		V[e.v].ex = e.u;//ǰ��������Ϊu
		return 1;//1��ʾ�������޸�֮��ֻ��Ҫ+=relax�Ϳ����ж��Ƿ��޸���
	}
	return 0;//0��ʾû�н����޸�
#endif // MIN
}

//8 2 2 1 3 4 9 10 13


int main() {
	int n,i,flag=0;
	int A, B, D;
	cin >> n;
	vector<int> price(n+1);
	for (i = 1; i <= n; i++) cin >> price[i];
	//1~n�±�
	node *V = new node[n + 1];//1~nʹ�ã������߼����
	V[0].d = 0;//�޸� ���Ǵ�V[1]���������Դ�V[0]����
	vector<edge> E;
	vector<edge>::iterator vit;
	//S2-S0=price1+price2 +price0-price0
	//ע��ת����ʽ  aj-ai<=bk �� w(i,j)=bk
#ifdef  MIN
	//��Сֵ�� ǰ�澡����С
	E.push_back(edge(0, 2, 2 * price[1]));//>=
	E.push_back(edge(2, 0, -2 * price[1] - 1));//<=
											   //price[n-1]+price[n]
	E.push_back(edge(n - 2, n, 2 * price[n]));
	E.push_back(edge(n, n - 2, -2 * price[n] - 1));
	//�����Ҫ����ǰ��� ����Ϊ1
	for (i = 0; i < n; i++) {
		//0~n-1����
		E.push_back(edge(i, i + 1, 1));//si-s[i+1]<=-1 Ҳ�� s[i+1]-s[i]>=1
		if (i > 1) {//2~n-1 price����
			E.push_back(edge(i - 2, i + 1, 3 * price[i]));//eg price 2   1 2 3 S3-S0
			E.push_back(edge(i + 1, i - 2, -3 * price[i] - 2));
		}
	}
#else
	//���ֵ�� ǰ�澡���ܴ�
	E.push_back(edge(2, 0, -2 * price[1]));//>=
	E.push_back(edge(0, 2, 2 * price[1] + 1));//<=
											  //price[n-1]+price[n]
	E.push_back(edge(n, n - 2, -2 * price[n]));
	E.push_back(edge(n - 2, n, 2 * price[n] + 1));
	//�����Ҫ����ǰ��� ����Ϊ1
	for (i = 0; i < n; i++) {
		//0~n-1����
		E.push_back(edge(i + 1, i, -1));//si-s[i+1]<=-1 Ҳ�� s[i+1]-s[i]>=1
		if (i > 1) {//2~n-1 price����
			E.push_back(edge(i + 1, i - 2, -3 * price[i]));//eg price 2   1 2 3 S3-S0
			E.push_back(edge(i - 2, i + 1, 3 * price[i] + 2));
		}
	}
#endif //  MIN
	//�������ʼ��ͼ���
	//����ʹ��Bellman-ford���������·��
	//����Сֵ��-4 -1 -1 -3 -5 -4 -20 -6 ����-4�����⻹��û�н��
	//for (vit = E.begin(); vit != E.end(); vit++) (*vit).w *= -1;//���󷴸о�һ��
	for (i = 0; i <= n; i++) {//i=1 to |V|-1
	//�޸ģ���V0��ʼ						   //��Ҫע���������û��v0 ֻ��v1234
		for (vit = E.begin(); vit != E.end(); vit++) {
			relax(*vit, V);
		}
	}
	for (vit = E.begin(); vit != E.end(); vit++) {
		flag += relax(*vit, V);
	}
	if (flag>0) printf("-1");
	//else if (V[n].ex == 0) printf("-2");
	//else printf("%d", V[n].d);
	//ע�������V.d�ĺ������ۼƣ�ע�⻹���и����Ĵ���
	for (i = 1; i < n; i++) cout << V[i].d-V[i-1].d << " ";
	cout << V[i].d - V[i - 1].d;
	//�����������ͨ�ⲻ�����Ž�
	delete[] V;
	return 0;
}
