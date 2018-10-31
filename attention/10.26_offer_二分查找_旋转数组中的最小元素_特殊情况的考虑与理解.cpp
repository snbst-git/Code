/**
书P69
原题链接：https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
自己问题：
1.没有考虑中间一堆数字相同的旋转数组
2.开始没有很能明白p=q=mid作为判断需要遍历的原因
因为如果p!=q那么肯定是有p>q，而mid>=p，由p==mid就知道前面这一堆都是一样的值，所以就在后面
如果是p==q那么这里翻转的结果min可在前也可以在后，不能判断
3.在往后移动时候一开始p=mid+1，这里忽视了mid恰好为min的情况，这样p=mid+1就略过了min
*/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray);

int main(){
	int n;
	cin >> n;
    vector<int> num(n);
    for(int i=0;i<n;i++){
		cin >> num[i];
    }
    cout<<minNumberInRotateArray(num);

	//cout << minNumberInRotateArray(num);
    getchar();

    return 0;
}

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size()<=0) return 0;
    int p=0,q=rotateArray.size()-1;
	if (rotateArray[p] < rotateArray[q]) return rotateArray[p];//如果没有进行翻转   特殊情况翻转元素数0
    while(q-p>=2){//(0+2)/2=1 还有中间
        int mid=p+(q-p)/2;//这里如果用>>，注意优先级太低了，会导致计算结果不一致，就得加括号，所以直接/2也可以
        if(rotateArray[p]>rotateArray[mid]){
            q=mid;//可能是最小值
        }
        else if(rotateArray[p]<rotateArray[mid]) {
            p=mid;//这里=mid+1会不会略过？因为是<mid那么说明mid是大值
			/*****应该p=mid;而不是mid+1
			主要应用情况：在一次移动之后mid+1恰好就是最小值
			那么下一轮就也因为小于略过了，其实这里开始已经没有前面的大数序列了，不应该跳，这样就错过了最小值
			所以应该把mid留下，作为一个大数，使得之后不断把q前移
			*/
        }
		else {//==的情况 前面等于中间 可能在前面可能在后面
			p++;
			/*这里可以进一步具体化
			如果[p]!=[q]
			那么说明虽然[p]==[mid]，既然p到mid是非递减，说明都是==p，那么q自然只能<p，所以往后移动即可
			仍然可以p=mid

			如果[p]==[q]那么说明可能最小值在p~mid也可能在mid~q不能判定，此时需要遍历！
			*/
		}
    }
    if(p==q) return rotateArray[p];
    else return rotateArray[p]<rotateArray[q]?rotateArray[p]:rotateArray[q];
}
