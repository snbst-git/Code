#include <iostream>
#include <vector>

using namespace std;

#define NUM 510
typedef long long ll;

//大问题：超时 是在替换inf之后，也就是可能有的地方进行了inf的乘法

const ll inf= 1e18;//7fffff……ff会在相加之后变成负数，爆
//大小路径
long long big[NUM][NUM];
long long small[NUM][NUM];
int n,m;
//是否入队
bool vis[NUM];
//前驱为大/小路情况下的路径长度
ll dist[NUM],dist0[NUM];//从start到某个点的距离

void spfa(int start){//采用队列的方式 优化一个之后就放队列，最后队列为空优化完成
	ll u,v,i,w;//错误w忘了改成longlogn了
	dist[start]=dist0[start]=0;
	vis[start]=1;//已经放入队列
	vector<int> que;
	que.push_back(start);
	while(!que.empty()){
		u=que[0];//取头
		que.erase(que.begin());
		vis[u]=0;
		for(v=1;v<n+1;v++){
			if (v == u) continue;
			w=big[u][v];//u到v的大路
			//当前走大路那么上一个可以是小路可以是大路
			if(dist[v]>w+dist[u]){
				dist[v]=w+dist[u];
				if(vis[v]==0){//还未入队
					vis[v]=1;
					que.push_back(v);
				}
				//已经入队就不需要重新放入了
			}
			if(dist[v]>w+dist0[u]){
				dist[v]=w+dist0[u];
				if(vis[v]==0){
					vis[v]=1;
					que.push_back(v);
				}
			}

			w=small[u][v];//走小路
			//前驱必须是大路
			if(w==inf) continue;//避免做Inf的乘法
			w = w * w;
			//错误：眼睛捐了，这里是dist0，写成dist了
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

int main(){//不能使用memset…… 拓展成负数了
    ll a,b,c,t=1,tmp;

	cin >> n >> m;
	//错误memset不可用！
	for (a = 1; a < n + 1; a++) {
		vis[a] = 0;
		dist[a] = dist0[a] = inf;
		for (b = 1; b < n + 1; b++) {
			small[a][b]=big[a][b] = inf;
		}
		//small[a][a] = big[a][a] = 0; 会跳过，不需要吧
	}

	//memset(big, inf, sizeof(big));
	tmp=m;
    //如何合并小路，如何交叉选路
	//需要使用数组，方便用下标随机访问
    while(tmp--){
        cin>>t>>a>>b>>c;
        if(t==0){//大
			if(c<big[a][b])//避免覆盖更大的值
				big[a][b]=big[b][a]=c;
        }
        else if(c<small[a][b])
			small[a][b]=small[b][a]=c;
		///……错误错误：复制的时候要看清楚，还是手打吧
    }
    //合并小路！
	for(a=1;a<n+1;a++){
		for(b=a+1;b<n+1;b++){//合并a到b的路  优化成半三角即可
			for(c=1;c<n+1;c++){
				if (c == a || c == b) continue;//中间点c
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

