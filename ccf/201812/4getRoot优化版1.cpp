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
    return a.t<b.t;//小的在前
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
    //不需要记录node 只需要记录边即可，node连通问题转由二维数组记录
    vector<edge> edges,result;
    int j,i;

	int *src=new int[n+1];
	for (i = 1; i <= n; i++)
	{
		src[i] = i;
	}

    while(m-->0){//接下来录入各条边
        cin>>u>>v>>t;
        ///要不要加一个补充，如果已经有了，而且比现在的更小就不放进去了
        //忘了是怎么处理的了，好像用的是二维数组
        //if(trec[u][v]>t){
            //trec[u][v]=trec[v][u]=t;
            edges.push_back(edge(u,v,t));
            ///暂时没有边，都看成独立的
            //connect[u][v]=connect[v][u]=1;//已经连通
        //}
    }
    sort(edges.begin(),edges.end(),edgecmp);//排序后方便使用
    //普及连通情况，每次都要遍历感觉效率太低了，不过这里也不能只看和root的连通情况
    //reconnect();
    //排序之后遍历edges
    for(i=0;i<edges.size();i++){
        //某两个顶点是否已经连通了，怕要用数组，，，，
        u=edges[i].u,v=edges[i].v;
		if (getRoot(src,u) != getRoot(src,v)) {
			src[getRoot(src, u)] = getRoot(src, v);//整合成同一个  不是src[u]=v
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
