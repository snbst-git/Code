#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

typedef struct typedead;
typedef struct node;

#define MAX 101
int n, m, t,mintime;
int dire[4][2] = { 1,0,0,1,-1,0,0,-1 };//右 上 左 下
bool flag[MAX][MAX][9999];

typedef struct node {//在time的时候走到x y，但是不允许重复把相同time放入
	int x, y, time;
	node(int a=0, int b=0, int c=0) :x(a), y(b), time(c) {  }
};
queue<node> q;

typedef struct typedead {
	int start, end;
	typedead(int a=0,int b=0):start(a),end(b){}
};//覆盖所有点
typedead dead[MAX][MAX];

//函数判断可不可以走某个点 node 连time 用dead判断   ****还需要加上是否已经在队列中的判断
bool judge(node &no) {//x是行 y是列
	//似乎不需要这个300的限制
	if (no.x <= n && no.x >= 1 && no.y <= m && no.y >= 1 &&no.time<300&&flag[no.x][no.y][no.time]==0&& (dead[no.x][no.y].start > no.time || dead[no.x][no.y].end < no.time)) return 1;
	return 0;
}

int main() {
	memset(flag, 0, sizeof(flag));
	cin >> n >> m >> t;
	mintime = n * m;
	//n行m列 t个时间点
	int i, a, b, c,d;
	for (i = 0; i < t; i++) {
		cin >> a >> b >> c >> d;
		dead[a][b].start = c;
		dead[a][b].end = d;//c~d危险
	}
	q.push(node(1, 1, 0));
	flag[1][1][0] = 1;//而且不需要恢复，因为时间是一直往后面走的
	node now;
	while (!q.empty()) {
		now = q.front();//应该是front吧，用vector也可以
		q.pop();
		if (now.x == n && now.y == m) {
			break;
			//宽度优先肯定是最早到的最快
		}
		for (int i = 0; i < 4; i++) {
			node next(now.x + dire[i][0], now.y + dire[i][1], now.time + 1);
			if (judge(next)) q.push(next),flag[next.x][next.y][next.time]=1;
			//否则危险，不可以走
			//注意加一个点就标记一个flag
		}
	}
	cout << now.time << endl;
	return 0;
}
