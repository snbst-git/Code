/**
1.很巧妙地将非最大的排除了
一个是从后面把比当前数字小的都剔除掉，意味着队列中只会剩下比当前大的还在前面优先级更高
而队头如果没有被删掉说明就是更大的，所以每次只需要输出队头
2.注意size是unsigned，所以有符号溢出比较的时候可以用i-front+1>size的方式
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        //最好不要每次都从头到尾来一次，如何利用前面的结果？
        int i=0;
        list<int> rec;//用于保存下标 无需保存原值
        vector<int> result;
        if(size<=0) return result;
        while(i<num.size()){
            //对于新来的元素，如果比当前最大值大，那么丢弃前面比这个小的
            //如果比当前元素小可以保存，但是不会最先使用，万一有多个小于？
            //多个小于那么在较大的放进来的时候已经把前面的删除，或者是放在前面那么大的就先作为头
            while(rec.size()&&num[rec.back()]<=num[i]){
                rec.pop_back();
            }
            //pop超出下标范围的部分
            while(rec.size()&&i>=size-1&&rec.front()<i-size+1){//i-0第一个 i-(size-1)第size个
                rec.pop_front();
            }
            rec.push_back(i);
            if(i>=size-1)//至少等第一个窗口放入完毕 此时下标为size-1
            result.push_back(num[rec.front()]);
            i++;
        }
        return result;
    }
};
