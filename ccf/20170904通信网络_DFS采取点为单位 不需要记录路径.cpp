#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>


using namespace std;

typedef vector<string> strvec;
typedef map<strvec,string> rules;
typedef map<string, int> weekmap;


void visit(int nid, int start);

bool reach[1001][1001];
bool vis[1001];//一次遍历的情况
vector< vector<int> > nodes;
int cnt;

int main(){//不能使用memset…… 拓展成负数了
	int n, m, i, a, b;
	cin >> n >> m;
	cnt = 0;
	nodes.resize(n+1);//1~n下标
	//清空
	memset(vis, 0, sizeof(vis));
	memset(reach, 0, sizeof(reach));
	i = m;
	while (i-- > 0) {//录入边
		cin >> a >> b;//a到b的边
		nodes[a].push_back(b);
	}
	vector<int> path;
	for (i = 1; i <= n; i++) {
		//问题：不能限制每个点只宏观visit一次
		//相应地 也不需要记录路径了，只需要记录是从哪个点开始的
        ///为什么不用路径：因为路径有太多重复的标记，所以会超时
        //另外为什么加上oncevis[]==0的限制会导致错误？
		memset(vis, 0, sizeof(vis));
		visit(i, i);
	}
	cnt = 0;
	for (i = 1; i <= n; i++) {
		b = 0;
		for (a = 1; a <= n; a++) {
			if (reach[i][a] == 1) b++;
			else break;//优化：否则凑不齐，直接退出
		}
		if (b == n) cnt++;
	}
	cout << cnt << endl;
	return 0;
}

//vis避免重复调用
void visit(int nid, int start) {//从start开始的一条路径 中间的全部标记 开始的就是自己，所以不需要单独标记start
	//只记录起点 不记录路径
	vis[nid] = 1;

	//标记互相知道存在
	//不需要把路上的都挨个标记一遍
	reach[start][nid] = reach[nid][start] = 1;//标记知道
	//逐个访问邻接点 vis为本次的标识 nodes[nid]为邻接点

	for (int i = 0; i < nodes[nid].size(); i++) {
		if (vis[nodes[nid][i]] == 0) {
			vis[nodes[nid][i]] = 1;
			//递归遍历
			visit(nodes[nid][i], start);
		}
	}
	///vis[nid] = 0; 优化这个也可以删掉，因为遍历起点所以反正待会儿会补上的
}
