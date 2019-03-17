#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#define VECSORT

using namespace std;

typedef vector<string> strvec;
typedef map<strvec,string> rules;
typedef map<string, int> weekmap;

typedef struct operation {//1.time先后顺序 2.op=0借或者是op=1还 还优先级高 3.key顺序从小到大
	int op, key, time;
	operation(int a, int b,int c) {
		op = a, key = b, time = c;
	}
#ifdef VECSORT
	int operator >(operation &opp) {
		if (time == opp.time) {
			if (op == opp.op) {
				return key < opp.key;//钥匙号码小优先
			}
			else return op > opp.op;//同时还优先
		}
		else return time < opp.time;//时间前优先
	}
#endif
}operation;

/*
int cmp(operation a, operation b) {//直接用cmp函数降序
	return a > b;
	//最终结果是a>b的在前面
}*/

#ifdef VECSORT
//替代cmp函数，需要自定义< 最后排出来是升序
bool operator <(operation a, operation b) {
	if (a.time == b.time) {
		if (a.op == b.op) {
			return a.key < b.key;//钥匙号码小优先
		}
		else return a.op > b.op;//同时还优先
	}
	else return a.time < b.time;//时间前优先
}
int cmp(operation a, operation b) {//直接用cmp函数降序
	if (a.time == b.time) {
		if (a.op == b.op) {
			return a.key < b.key;//钥匙号码小优先
		}
		else return a.op > b.op;//同时还优先
	}
	else return a.time < b.time;//时间前优先
}
#else
//less大顶堆使用< 结果是a<b的 b在堆里较大在前
bool operator <(operation a, operation b) {
	if (a.time == b.time) {
		if (a.op == b.op) {
			return a.key > b.key;//钥匙号码小优先
		}
		else return a.op < b.op;//同时还优先
	}
	else return a.time > b.time;//时间前优先
}
//greater小顶堆定义> 结果是a>b的 b在堆里较小在前
bool operator >(operation a, operation b) {
	if (a.time == b.time) {
		if (a.op == b.op) {
			return a.key > b.key;//钥匙号码小优先
		}
		else return a.op < b.op;//同时还优先
	}
	else return a.time > b.time;//时间前优先
}
#endif

int main(){//不能使用memset…… 拓展成负数了
	int a,b,c,N,K,i;
	cin >> N >> K;
	#ifdef VECSORT
	vector<operation> ops;
	#else
	//priority_queue<operation, vector<operation>,less<operation> > ops;//less就是大顶堆了
	priority_queue<operation,vector<operation>,greater<operation> > ops;//greater返回的是小顶堆
	#endif
	vector<int> keys(N + 1);
	vector<int>::iterator vit;
	priority_queue<int, vector<int>, greater<int> > freepos;//greater实际小的在top 需要定义>
	for (i = 1; i <= N; i++) keys[i] = i;
	i = K;
	while (i-- > 0) {
		cin >> a >> b >> c;
		#ifdef VECSORT
		//b时刻借a钥匙
		ops.push_back(operation(0, a, b));
		//b+c时刻还a钥匙
		ops.push_back(operation(1, a, b+c));
		#else
		ops.push(operation(0, a, b));
		ops.push(operation(1, a, b+c));
		#endif
	}

#ifdef VECSORT
	//sort(ops.begin(), ops.end(),cmp);//使用时间排序
	sort(ops.begin(), ops.end());//使用时间排序
	for (i = 0; i < ops.size(); i++) {
		if (ops[i].op == 0) {//借钥匙
			//找到现在key在什么位置
			vit=find(keys.begin(), keys.end(), ops[i].key);
			if (vit == keys.end()) {
				printf("can't find %d\n", ops[i].key);
				return -1;
			}
			a = distance(keys.begin(), vit);//从0开始的但是begin是，所以不需要+1！
			freepos.push(a);//下标从1开始
			*vit = -1;//会作用到原来的下面，当然也可以用[]来修改
			//freepos.push(ops[i].key);//该位置空闲 错误，应该找位置
		}
		else {//还钥匙
			a = freepos.top();
			freepos.pop();
			keys[a] = ops[i].key;//a位置放入op.key
		}
	}
#else
	while (!ops.empty()) {
		if (ops.top().op == 0) {//借钥匙
							 //找到现在key在什么位置
			vit = find(keys.begin(), keys.end(), ops.top().key);
			if (vit == keys.end()) {
				printf("can't find %d\n", ops.top().key);
				return -1;
			}
			a = distance(keys.begin(), vit);//从0开始的但是begin是，所以不需要+1！
			freepos.push(a);//下标从1开始
			*vit = -1;//会作用到原来的下面，当然也可以用[]来修改
					  //freepos.push(ops[i].key);//该位置空闲 错误，应该找位置
		}
		else {//还钥匙
			a = freepos.top();
			freepos.pop();
			keys[a] = ops.top().key;//a位置放入op.key
		}
		ops.pop();
	}
#endif // VECSORT



	for (i = 1; i < N; i++) cout << keys[i] << " ";
	cout << keys[i] << endl;
	return 0;
}
