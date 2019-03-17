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
bool vis[1001];//һ�α��������
vector< vector<int> > nodes;
int cnt;

int main(){//����ʹ��memset���� ��չ�ɸ�����
	int n, m, i, a, b;
	cin >> n >> m;
	cnt = 0;
	nodes.resize(n+1);//1~n�±�
	//���
	memset(vis, 0, sizeof(vis));
	memset(reach, 0, sizeof(reach));
	i = m;
	while (i-- > 0) {//¼���
		cin >> a >> b;//a��b�ı�
		nodes[a].push_back(b);
	}
	vector<int> path;
	for (i = 1; i <= n; i++) {
		//���⣺��������ÿ����ֻ���visitһ��
		//��Ӧ�� Ҳ����Ҫ��¼·���ˣ�ֻ��Ҫ��¼�Ǵ��ĸ��㿪ʼ��
        ///Ϊʲô����·������Ϊ·����̫���ظ��ı�ǣ����Իᳬʱ
        //����Ϊʲô����oncevis[]==0�����ƻᵼ�´���
		memset(vis, 0, sizeof(vis));
		visit(i, i);
	}
	cnt = 0;
	for (i = 1; i <= n; i++) {
		b = 0;
		for (a = 1; a <= n; a++) {
			if (reach[i][a] == 1) b++;
			else break;//�Ż�������ղ��룬ֱ���˳�
		}
		if (b == n) cnt++;
	}
	cout << cnt << endl;
	return 0;
}

//vis�����ظ�����
void visit(int nid, int start) {//��start��ʼ��һ��·�� �м��ȫ����� ��ʼ�ľ����Լ������Բ���Ҫ�������start
	//ֻ��¼��� ����¼·��
	vis[nid] = 1;

	//��ǻ���֪������
	//����Ҫ��·�ϵĶ��������һ��
	reach[start][nid] = reach[nid][start] = 1;//���֪��
	//��������ڽӵ� visΪ���εı�ʶ nodes[nid]Ϊ�ڽӵ�

	for (int i = 0; i < nodes[nid].size(); i++) {
		if (vis[nodes[nid][i]] == 0) {
			vis[nodes[nid][i]] = 1;
			//�ݹ����
			visit(nodes[nid][i], start);
		}
	}
	///vis[nid] = 0; �Ż����Ҳ����ɾ������Ϊ����������Է���������Ჹ�ϵ�
}
