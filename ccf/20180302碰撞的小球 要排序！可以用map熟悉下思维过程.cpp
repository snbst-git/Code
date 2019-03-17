#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;

struct order {
	int x, y;
	order(int a, int b) {
		x = a, y = b;
	}
};

bool cmpbyy(order a, order b) {
	return a.y < b.y;//小于就在前面
}

int main(){
    int n,L,t,i;
    cin>>n>>L>>t;
	vector<int> a, v;
	vector<order> out;
	map<int, int> loc;
	a.resize(n), v.resize(n);
    for(i=0;i<n;i++) cin>>a[i],v[i]=1,loc[a[i]]=i;//位置为a[i]的序号为i
	//排序，并且记录顺序 0~9 按照其大小排序分别排多少，最后反着映射就是了
	sort(a.begin(), a.end());

	//错误2 没有说小球都是顺序的！要sort
    while(t-->0){
        //初始万一就在L处，那立即掉头？还是先跑一秒
        for(i=0;i<n;i++){
			//问题1 没有考虑方向就合并会导致错误
            if(a[i]==0&&v[i]==-1) v[i]=1;
            if(a[i]==L&&v[i]==1) v[i]=-1;
            a[i]+=v[i];
        }
        for(i=0;i<n-1;i++){
            //碰撞检测
            if(a[i]==a[i+1]){//应该不需要强调方向相反，否则碰不到一起的应该
                v[i]*=-1,v[i+1]*=-1;
            }
        }
    }
	map<int, int>::iterator mit;
	//mit就是按照位置的顺序 现在需要按照原来的顺序输出
    for(mit=loc.begin(),i=0;mit!=loc.end();mit++,i++){//mit->first是位置按照从小到大排序的 second就是下标，数组a中的位置
		out.push_back(order(a[i], mit->second));
    }
	sort(out.begin(), out.end(), cmpbyy);
	for (i = 0; i < out.size() - 1; i++) cout << out[i].x << " ";
	cout << out[i].x << endl;
    return 0;
}

