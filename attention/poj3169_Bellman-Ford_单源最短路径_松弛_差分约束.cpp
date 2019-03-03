#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int inf=0xfffffff;

struct node{
	int d;
	int ex;
	node(){d=inf,ex=0;}
};

struct edge{
	int u;
	int v;
	int w;
	edge(int start,int end,int wnum){u=start,v=end,w=wnum;}
};

//edge (u,v) ��Ƚ�v.d��u.d+w(u,v)
int relax(edge &e,node *V){
	if(V[e.v].d>V[e.u].d+e.w){
		V[e.v].d=V[e.u].d+e.w;
		V[e.v].ex=e.u;//ǰ��������Ϊu
		return 1;//1��ʾ�������޸�֮��ֻ��Ҫ+=relax�Ϳ����ж��Ƿ��޸���
	}
	return 0;//0��ʾû�н����޸�
}

int main(){
	int n,ml,md,flag=0;
	int A,B,D;
	scanf("%d%d%d",&n,&ml,&md);
	node *V=new node[n+1];//1~nʹ�ã������߼����
	V[1].d=0;
	vector<edge> E;
	vector<edge>::iterator vit;
	while(ml-->0){
		scanf("%d%d%d",&A,&B,&D);//A<B
		E.push_back(edge(A,B,D));
	}
	while(md-->0){
		scanf("%d%d%d",&A,&B,&D);//A<B
		E.push_back(edge(B,A,-D));
	}
	for(int i=1;i<n;i++){
		//3-2>=0  2-3<=0
		E.push_back(edge(i+1,i,0));
	}
	//�������ʼ��ͼ���
	//����ʹ��Bellman-ford���������·��
	for(int i=0;i<n;i++){//i=1 to |V|-1
		//��Ҫע���������û��v0 ֻ��v1234
		for(vit=E.begin();vit!=E.end();vit++){
			relax(*vit,V);
		}
	}
	for(vit=E.begin();vit!=E.end();vit++){
			flag+=relax(*vit,V);
	}
	if(flag>0) printf("-1");
	else if(V[n].ex==0) printf("-2");
	else printf("%d",V[n].d);

	delete[] V; 
	return 0;
}
/*
4 2 1
1 3 10
2 4 20
2 3 3

*/