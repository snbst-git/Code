#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <memory.h>

using namespace std;
struct node;
struct edge;

const int inf=-1;
vector<edge> edges;
vector<node> nodes;

struct node{
    int u;
    int key;
    node(int a,int b=inf){
        u=a,key=b;
    }
};

struct edge{
    int u,v;
    int w;
    edge(int a,int b,int c){
        u=a,v=b,w=c;
    }
};

int relax(edge &e){
    if(nodes[e.v].key<nodes[e.u].key+e.w){
        nodes[e.v].key=nodes[e.u].key+e.w;
        return 1;
    }
    return 0;
}

int main(){
    int n,i,j,sum=0,t;
    int *in;
    cin>>n;
    in=new int[n+1];
    for(i=1;i<=n;i++) cin>>in[i],nodes.push_back(node(i));
    nodes.push_back(node(0,0));//前0家，累积为0
    //头两家 1
    edges.push_back(edge(0,2,2*in[1]));
    edges.push_back(edge(2,0,-2*in[1]-1));
    //最后两家 n
    edges.push_back(edge(n-2,n,2*in[n]));
    edges.push_back(edge(n,n-2,-2*in[n]-1));
    edges.push_back(edge(0,1,1));
    for(i=2;i<=n-1;i++){//2~n-1
        edges.push_back(edge(i-1,i,1));//价格要>0
        edges.push_back(edge(i-2,i+1,3*in[i]));
        edges.push_back(edge(i+1,i-2,-3*in[i]-2));
    }
    edges.push_back(edge(i-1,i,1));//价格要>0
    //自闭了，先忘了写外面的n次循环
    for(j=0;j<n;j++) for(i=0;i<edges.size();i++)  relax(edges[i]);
    for(i=1;i<n;i++){
        cout<<nodes[i].key-nodes[i-1].key<<" ";
    }
    cout<<nodes[i].key-nodes[i-1].key<<endl;

    delete in;
    return 0;
}
