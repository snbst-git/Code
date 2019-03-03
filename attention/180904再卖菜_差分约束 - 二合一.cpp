#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
///其中max项与所学的相同，xj-xi≤bk 对应w(i,j)=bk relax为> 所以无边为无穷，可以松弛到有边
///算法为求最短路径，求到的为最大值


///而min与所学的反着来，  xj-xi≥bk 对应w(i,j)=bk relax为< 所以无边为-1(最小，可以松弛到有边
///算法为求最长路径，求到的为最小值


#define MIN
//注意转换方式  aj-ai<=bk 则 w(i,j)=bk
const int inf = 0xfffffff;
///20180904 80分超时 尝试使用差分约束优化

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

//edge (u,v) 则比较v.d和u.d+w(u,v)
int relax(edge &e, node *V) {
#ifdef MIN
///初始化为-1 代表没有边，逐渐放大放大到至少要达到的MIN
	if (V[e.v].d<V[e.u].d + e.w) {
		V[e.v].d = V[e.u].d + e.w;
		V[e.v].ex = e.u;//前驱结点更新为u
		return 1;//1表示进行了修改之后只需要+=relax就可以判断是否修改了
	}
	return 0;//0表示没有进行修改
#else
///初始为正无穷，代表没有边，逐渐缩小缩小为最大能达到的MAX
	if (V[e.v].d>V[e.u].d + e.w) {
		V[e.v].d = V[e.u].d + e.w;
		V[e.v].ex = e.u;//前驱结点更新为u
		return 1;//1表示进行了修改之后只需要+=relax就可以判断是否修改了
	}
	return 0;//0表示没有进行修改
#endif // MIN
}

//8 2 2 1 3 4 9 10 13


int main() {
	int n,i,flag=0;
	int A, B, D;
	cin >> n;
	vector<int> price(n+1);
	for (i = 1; i <= n; i++) cin >> price[i];
	//1~n下标
	node *V = new node[n + 1];//1~n使用，便于逻辑理解
	V[0].d = 0;//修改 不是从V[1]出发，所以从V[0]出发
	vector<edge> E;
	vector<edge>::iterator vit;
	//S2-S0=price1+price2 +price0-price0
	//注意转换方式  aj-ai<=bk 则 w(i,j)=bk
#ifdef  MIN
	//最小值求法 前面尽可能小
	E.push_back(edge(0, 2, 2 * price[1]));//>=
	E.push_back(edge(2, 0, -2 * price[1] - 1));//<=
											   //price[n-1]+price[n]
	E.push_back(edge(n - 2, n, 2 * price[n]));
	E.push_back(edge(n, n - 2, -2 * price[n] - 1));
	//后面的要大于前面的 至少为1
	for (i = 0; i < n; i++) {
		//0~n-1都有
		E.push_back(edge(i, i + 1, 1));//si-s[i+1]<=-1 也即 s[i+1]-s[i]>=1
		if (i > 1) {//2~n-1 price才有
			E.push_back(edge(i - 2, i + 1, 3 * price[i]));//eg price 2   1 2 3 S3-S0
			E.push_back(edge(i + 1, i - 2, -3 * price[i] - 2));
		}
	}
#else
	//最大值求法 前面尽可能大
	E.push_back(edge(2, 0, -2 * price[1]));//>=
	E.push_back(edge(0, 2, 2 * price[1] + 1));//<=
											  //price[n-1]+price[n]
	E.push_back(edge(n, n - 2, -2 * price[n]));
	E.push_back(edge(n - 2, n, 2 * price[n] + 1));
	//后面的要大于前面的 至少为1
	for (i = 0; i < n; i++) {
		//0~n-1都有
		E.push_back(edge(i + 1, i, -1));//si-s[i+1]<=-1 也即 s[i+1]-s[i]>=1
		if (i > 1) {//2~n-1 price才有
			E.push_back(edge(i + 1, i - 2, -3 * price[i]));//eg price 2   1 2 3 S3-S0
			E.push_back(edge(i - 2, i + 1, 3 * price[i] + 2));
		}
	}
#endif //  MIN
	//构建与初始化图完成
	//下面使用Bellman-ford法，求最短路径
	//求最小值？-4 -1 -1 -3 -5 -4 -20 -6 但是-4的问题还是没有解决
	//for (vit = E.begin(); vit != E.end(); vit++) (*vit).w *= -1;//边求反感觉一眼
	for (i = 0; i <= n; i++) {//i=1 to |V|-1
	//修改：从V0开始						   //需要注意的是这里没有v0 只有v1234
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
	//注意这里的V.d的含义是累计，注意还像有负环的存在
	for (i = 1; i < n; i++) cout << V[i].d-V[i-1].d << " ";
	cout << V[i].d - V[i - 1].d;
	//求出来的是普通解不是最优解
	delete[] V;
	return 0;
}
