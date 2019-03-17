#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

#define MAX 100001

typedef struct edge {
	int u, v, k;
	edge(int a, int b, int c) {
		u = a, v = b, k = c;
	}
};

vector< edge > nodes;
int v[MAX];
int n, m;

//卧槽原来是最小生成树
int getroot(int x) {
	int start = x,nxt;
	while (x != v[x]) {
		x = v[x];
	}
	//1可能优化 边走边改
	while (v[start] != x) {
		nxt = v[start];
		v[start] = x;
		start = nxt;
	}
	return x;
}

bool cmp(edge a, edge b) {
	return a.k < b.k;
}

int main() {
	int a, b, c,maxlen;
	cin >> n >> m;//n个点 m个公司
	
	for (a = 1; a <= n; a++) v[a] = a;
	//输入边
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		//a--b b--a 长为c的边
		nodes.push_back(edge(a, b, c));
		//nodes.push_back(edge(b, a, sc));
	}
	sort(nodes.begin(), nodes.end(), cmp);
	for (a = 0; a < m; a++) {
		b = getroot(nodes[a].u), c = getroot(nodes[a].v);
		if (b != c) {
			//2优化 这里边走边标记可以减少用时
			if(b>c)	v[b] = c;
			else v[c] = b;
			maxlen = nodes[a].k;//肯定是最大的
		}
		//必须要提前跳出 3优化 可以直接是1 而不是getroot(1)
		if (getroot(n) == getroot(1)) break;
	}
	cout << maxlen << endl;
	return 0;
}
