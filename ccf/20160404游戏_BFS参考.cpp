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
int dire[4][2] = { 1,0,0,1,-1,0,0,-1 };//�� �� �� ��
bool flag[MAX][MAX][9999];

typedef struct node {//��time��ʱ���ߵ�x y�����ǲ������ظ�����ͬtime����
	int x, y, time;
	node(int a=0, int b=0, int c=0) :x(a), y(b), time(c) {  }
};
queue<node> q;

typedef struct typedead {
	int start, end;
	typedead(int a=0,int b=0):start(a),end(b){}
};//�������е�
typedead dead[MAX][MAX];

//�����жϿɲ�������ĳ���� node ��time ��dead�ж�   ****����Ҫ�����Ƿ��Ѿ��ڶ����е��ж�
bool judge(node &no) {//x���� y����
	//�ƺ�����Ҫ���300������
	if (no.x <= n && no.x >= 1 && no.y <= m && no.y >= 1 &&no.time<300&&flag[no.x][no.y][no.time]==0&& (dead[no.x][no.y].start > no.time || dead[no.x][no.y].end < no.time)) return 1;
	return 0;
}

int main() {
	memset(flag, 0, sizeof(flag));
	cin >> n >> m >> t;
	mintime = n * m;
	//n��m�� t��ʱ���
	int i, a, b, c,d;
	for (i = 0; i < t; i++) {
		cin >> a >> b >> c >> d;
		dead[a][b].start = c;
		dead[a][b].end = d;//c~dΣ��
	}
	q.push(node(1, 1, 0));
	flag[1][1][0] = 1;//���Ҳ���Ҫ�ָ�����Ϊʱ����һֱ�������ߵ�
	node now;
	while (!q.empty()) {
		now = q.front();//Ӧ����front�ɣ���vectorҲ����
		q.pop();
		if (now.x == n && now.y == m) {
			break;
			//������ȿ϶������絽�����
		}
		for (int i = 0; i < 4; i++) {
			node next(now.x + dire[i][0], now.y + dire[i][1], now.time + 1);
			if (judge(next)) q.push(next),flag[next.x][next.y][next.time]=1;
			//����Σ�գ���������
			//ע���һ����ͱ��һ��flag
		}
	}
	cout << now.time << endl;
	return 0;
}
