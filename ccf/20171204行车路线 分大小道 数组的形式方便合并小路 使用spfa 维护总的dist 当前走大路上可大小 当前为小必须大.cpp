#include <iostream>
#include <vector>

using namespace std;

#define NUM 510
typedef long long ll;

//�����⣺��ʱ �����滻inf֮��Ҳ���ǿ����еĵط�������inf�ĳ˷�

const ll inf= 1e18;//7fffff����ff�������֮���ɸ�������
//��С·��
long long big[NUM][NUM];
long long small[NUM][NUM];
int n,m;
//�Ƿ����
bool vis[NUM];
//ǰ��Ϊ��/С·����µ�·������
ll dist[NUM],dist0[NUM];//��start��ĳ����ľ���

void spfa(int start){//���ö��еķ�ʽ �Ż�һ��֮��ͷŶ��У�������Ϊ���Ż����
	ll u,v,i,w;//����w���˸ĳ�longlogn��
	dist[start]=dist0[start]=0;
	vis[start]=1;//�Ѿ��������
	vector<int> que;
	que.push_back(start);
	while(!que.empty()){
		u=que[0];//ȡͷ
		que.erase(que.begin());
		vis[u]=0;
		for(v=1;v<n+1;v++){
			if (v == u) continue;
			w=big[u][v];//u��v�Ĵ�·
			//��ǰ�ߴ�·��ô��һ��������С·�����Ǵ�·
			if(dist[v]>w+dist[u]){
				dist[v]=w+dist[u];
				if(vis[v]==0){//��δ���
					vis[v]=1;
					que.push_back(v);
				}
				//�Ѿ���ӾͲ���Ҫ���·�����
			}
			if(dist[v]>w+dist0[u]){
				dist[v]=w+dist0[u];
				if(vis[v]==0){
					vis[v]=1;
					que.push_back(v);
				}
			}

			w=small[u][v];//��С·
			//ǰ�������Ǵ�·
			if(w==inf) continue;//������Inf�ĳ˷�
			w = w * w;
			//�����۾����ˣ�������dist0��д��dist��
			if(dist0[v]>w+dist[u]){
				dist0[v]=w+dist[u];
				if(vis[v]==0){
					vis[v]=1;
					que.push_back(v);
				}
			}
		}
	}
}

int main(){//����ʹ��memset���� ��չ�ɸ�����
    ll a,b,c,t=1,tmp;

	cin >> n >> m;
	//����memset�����ã�
	for (a = 1; a < n + 1; a++) {
		vis[a] = 0;
		dist[a] = dist0[a] = inf;
		for (b = 1; b < n + 1; b++) {
			small[a][b]=big[a][b] = inf;
		}
		//small[a][a] = big[a][a] = 0; ������������Ҫ��
	}

	//memset(big, inf, sizeof(big));
	tmp=m;
    //��κϲ�С·����ν���ѡ·
	//��Ҫʹ�����飬�������±��������
    while(tmp--){
        cin>>t>>a>>b>>c;
        if(t==0){//��
			if(c<big[a][b])//���⸲�Ǹ����ֵ
				big[a][b]=big[b][a]=c;
        }
        else if(c<small[a][b])
			small[a][b]=small[b][a]=c;
		///����������󣺸��Ƶ�ʱ��Ҫ������������ִ��
    }
    //�ϲ�С·��
	for(a=1;a<n+1;a++){
		for(b=a+1;b<n+1;b++){//�ϲ�a��b��·  �Ż��ɰ����Ǽ���
			for(c=1;c<n+1;c++){
				if (c == a || c == b) continue;//�м��c
				if(small[a][b]>small[a][c]+small[c][b]){
					small[a][b]=small[b][a]=small[a][c]+small[c][b];
				}
			}
		}
	}

	spfa(1);
	cout<<min(dist[n],dist0[n])<<endl;

    return 0;
}

