/**
实践了一下select partition(random) 函数
1.本日最坑的是swap函数，弄了个浮点错误出来……什么鬼
另外注意只修改了部分swap为recswap导致程序执行错误……不要急啊挨个改好啊
2.特别注意之前一个地方
k是相对的下标 而partition返回的是绝对的下标
所以需要rei=i-p这一转换，这个没有注意到
*/
class Solution {
public:
    vector<int> rec;
    void Insert(int num)
    {
        rec.push_back(num);
    }

    void recswap(int i, int j) {
        int temp = rec[i];
        rec[i] = rec[j];
        rec[j] = temp;
    }

    double GetMedian()
    {
        //中位数
        int size=rec.size();
        if(size==0) return 0;
        if(size%2){//奇数
            return select(0,size-1,size/2);//5 取3 下标2
        }
        else{//万一是0个？//if(size==0) return 0;
            double sum=select(0,size-1,size/2)+select(0,size-1,size/2-1);
            //sum/=2;//浮点运算错误？除以0了？
            return sum/2.0;//4 取2 3 下标1 2
        }
    }
    //k是相对下标 i是绝对下标
    int select(int p,int q,int k){//这里选从0开始的下标
        if(p==q) return rec[p];
        int i=randpartition(p,q);//下标
        int rei=i-p;//相对下标
        if(rei==k) return rec[i];
        else if(k<rei) return select(p,i-1,k);
        else return select(i+1,q,k-rei-1);///写成+1了
    }

    int randpartition(int p,int q){
        srand((int)time(0));
        //随机一个数放到最后去
        recswap(p+rand()%(q-p+1),q);
        int i=p-1,j=p;
        int u=rec[q];
        //选用尾巴为划分元素
        while(j<q){//只取到q-1
            if(rec[j]<=u) recswap(j,++i);//交换i和j的内容
            j++;
        }
        recswap(++i,q);
        return i;//现在的下标
    }

};
