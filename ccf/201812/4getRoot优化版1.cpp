///201812_03
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <time.h>

using namespace std;
int n,m,root,u,v,t,ans;
const int inf=0x7fffffff;

struct edge{
    int u,v,t;
    edge(int inu,int inv,int tin){
        u=inu,v=inv,t=tin;
    }
};

bool edgecmp(edge a,edge b){
    return a.t<b.t;//С����ǰ
}


int getRoot(int v[], int x)
{
	while (v[x] != x)
	{
		x = v[x];
	}
	return x;
}


int main(){

    cin>>n>>m>>root;
    //����Ҫ��¼node ֻ��Ҫ��¼�߼��ɣ�node��ͨ����ת�ɶ�ά�����¼
    vector<edge> edges,result;
    int j,i;

	int *src=new int[n+1];
	for (i = 1; i <= n; i++)
	{
		src[i] = i;
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
		if (getRoot(src,u) != getRoot(src,v)) {
			src[getRoot(src, u)] = getRoot(src, v);//���ϳ�ͬһ��  ����src[u]=v
			result.push_back(edges[i]);
		}
    }
    ans=0;
    for(i=0;i<result.size();i++){
        if(result[i].t>ans) ans=result[i].t;
    }
    cout<<ans<<endl;
    delete src;
    return 0;
}
