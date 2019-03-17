#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
#define MAX 1001
int v[MAX];
int deg[MAX];

int getroot(int x){
    int start=x,tmp;
    while(v[x]!=x){
        x=v[x];
    }
    while(v[start]!=x){
        tmp=v[start];
        v[start]=x;
        start=tmp;
    }
    return x;
}


int main(){
    int N,P,Q,i,j,a,b;
    cin>>N;
    memset(deg,0,sizeof(deg));
    while(N-->0){
        cin>>P>>Q;
        //初始化跟为自己
        for(i=1;i<=P;i++) v[i]=i;
        while(Q-->0){
            cin>>i>>j;
            a=getroot(i),b=getroot(j);
			if (a < b) {//之前的应用中，只需要判定是否连通，不需要统一为一个共同的root
				//而这里为了之后不需要每次都getroot来判断一次，就还是统一为共同的root（最小），不然其实都是连通的但是赋值会不一致
				v[b] = a;
			} 
			else v[a] = b;
            deg[a]++,deg[b]++;
        }
        //合并完成,可以判定是否连通
		//关键！不是直接取出v，而是应该getroot
        j=getroot(1);//root应该都是同一个
        a=0;//标记不连通
        b=0;//统计奇数
        for(i=1;i<=P;i++){
            if(getroot(i)!=j){
                a=1;
                break;
            }
            if(deg[i]%2==1) b++;
        }
        if(a==0&&(b==0||b==2)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}

