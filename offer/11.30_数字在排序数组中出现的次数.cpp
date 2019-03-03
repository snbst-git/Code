/**
1.排序 二分
找一个起点，找一个终点
很神奇，用k-1/k+1 不仅有死循环的错误，还有数字统计有误的问题

换-0.5/+0.5一下子就可以了
首先不可能相等，所以s==e时，要么s++，要么e--,进而退出循环
正好s++说明是+0.5，data[s]偏小，找到上界k+?，比k+0.5大的一个整数；e--说明是-0.5,data[s]偏大，k本身作为下界

首先0.5排除了相等的可能性，不会死循环

2.对于k不在数组中的情况 应该返回0
比如 4 6 8
要找5 5本身 5.5 4.5的结果都是一样的
0+2=2/2=1
6>5 0 0
4<5 1 0
1

这里只是由于0.5的特殊性才构建了一个不完全的二分，自己的还是要弄完全一点
参照一下中位数那一章的程序

3.不应该直接找k，不过其实也可以定位到一个k后向前向后移动
4.也不应该找k+1 k-1万一k+1,k-1不存在，判定之类的就很复杂
关键是不存在的时候应该处理

*/
class Solution {
public:
    //二分法
    int GetNumberOfK(vector<int> data ,int k) {
        int size=data.size(),count;
        if(size==0) return 0;
        int s=0,e=size-1,mid;
        while(s<=e){
            mid=(s+e)/2;
            if(data[mid]>k+0.5) e=mid-1;//mid+1?
            else if(data[mid]<k+0.5) s=mid+1;
        }
        count=s;
        s=0,e=size-1;
        while(s<=e){
            mid=(s+e)/2;
            if(data[mid]>k-0.5) e=mid-1;//mid+1?
            else if(data[mid]<k-0.5) s=mid+1;
        }
        count-=s;
        return count;
    }
    /*
    int GetNumberOfK(vector<int> data ,int k) {
        int size=data.size(),count=0;
        if(size==0) return 0;
        for(int i=0;i<size;i++){
            if(data[i]<k);//有序可以二分
            else if(data[i]==k) count++;
            else break;
        }
        return count;
    }*/
};
