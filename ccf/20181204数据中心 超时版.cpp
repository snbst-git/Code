///201812_03
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <time.h>

using namespace std;
long long n,m,root,u,v,t,ans;
const long long inf=0x7fffffffffffffff;
bool ** connect;

struct edge{
    long long u,v,t;
    edge(long long inu,long long inv,long long tin){
        u=inu,v=inv,t=tin;
    }
};

bool edgecmp(edge a,edge b){
    return a.t<b.t;//С����ǰ
}

void reconnect(){
    long long i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){//��Ҫ�ظ���1��ʼ�������൱��Ūһ�������Ǿ͹���
			if (i == j) continue;
            if(connect[i][j]==1){
                for(k=1;k<=n;k++){
					if (i == k||j==k) continue;
                    if(connect[j][k]==1){
                        connect[i][k]=connect[k][i]=1;//��ͨ
                    }
                }
            }
        }
    }
}

int main(){

    cin>>n>>m>>root;
    //����Ҫ��¼node ֻ��Ҫ��¼�߼��ɣ�node��ͨ����ת�ɶ�ά�����¼
    vector<edge> edges,result;
    long long j,i;
    connect=new bool*[n+1];
    for(i=1;i<=n;i++){
        connect[i]=new bool[n+1];
		for (j = 1; j <= n; j++) connect[i][j] = 0;
        connect[i][i]=1;
    }
    while(m-->0){//������¼�������
        cin>>u>>v>>t;
        ///Ҫ��Ҫ��һ�����䣬����Ѿ����ˣ����ұ����ڵĸ�С�Ͳ��Ž�ȥ��
        //��������ô������ˣ������õ��Ƕ�ά����
        //if(trec[u][v]>t){
            //trec[u][v]=trec[v][u]=t;
            edges.push_back(edge(u,v,t));
            ///��ʱû�бߣ������ɶ�����
            //connect[u][v]=connect[v][u]=1;//�Ѿ���ͨ
        //}
    }
    sort(edges.begin(),edges.end(),edgecmp);//����󷽱�ʹ��
    //�ռ���ͨ�����ÿ�ζ�Ҫ�����о�Ч��̫���ˣ���������Ҳ����ֻ����root����ͨ���
    //reconnect();
    //����֮�����edges
    for(i=0;i<edges.size();i++){
        //ĳ���������Ƿ��Ѿ���ͨ�ˣ���Ҫ�����飬������
        u=edges[i].u,v=edges[i].v;
        if(connect[u][v]==0){//û�����ߵ�ʱ��û����ͨ
            result.push_back(edges[i]);
            connect[u][v]=connect[v][u]=1;//ѡ�������ߣ���ͨ
			reconnect();
        }
    }
    ans=0;
    for(i=0;i<result.size();i++){
        if(result[i].t>ans) ans=result[i].t;
    }
    cout<<ans<<endl;
    delete []connect;
    return 0;
}
