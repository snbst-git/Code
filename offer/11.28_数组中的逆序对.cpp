/**
1.long long
注意数据量的一般都有这个问题……
2.比较的时候不能打乱顺序
但是比较之后就可以排序这一块了
归并的思想
不够熟悉归并排序
*/
class Solution {
public:
    //比较完了之后就可以拍成有序的了
    //归并排序都要搞忘了……
    int InversePairs(vector<int> data) {
        int length  = data.size();
        if(length<=1) return 0;
        vector<int> copy(data); //构建副本？用于比较，data则应用排序
        //for(int i=0;i<length;i++) copy[i]==data[i];
        return mergeSort(data,copy, 0, length-1);
    }
    long long mergeSort(vector<int> &data,vector<int> &copy,int l,int r){
        if(l>=r) return 0;
        int mid=(l+r)>>1;
        long long lcount=mergeSort(copy,data,l,mid);
        long long rcount=mergeSort(copy,data,mid+1,r);
        long long count=0;
        int lp=mid,rp=r,copyp=r;
        while(lp>=l&&rp>mid){
            if(data[lp]>data[rp]){
                copy[copyp--]=data[lp--];//取大的
                //相当于升序排序
                count+=rp-mid;//rp-(mid+1)+1
                //已经升序，所以mid+1~rp都小于
            }
            else copy[copyp--]=data[rp--];//取大的
        }
        //处理余下的
        while(lp>=l) copy[copyp--]=data[lp--];
        while(rp>mid) copy[copyp--]=data[rp--];
        return (lcount+rcount+count)%1000000007;
    }

    /*
    struct record{
            int x,y;
            record():x(0),y(0){}
            bool operator>(const record &b){return y>b.y;}
        };
    static bool cmp(record &a,record &b){return a>b;}
    int InversePairs(vector<int> data) {
        int count=0;
        int size=data.size(),i,j;
        if(size<=1) return 0;

        record *rec=new record[size];
        //record rec[size];
        //这个应该是有继承的，如果前面一个数字大于后面某一个数字那么就大于其后面所有的数字
        //从这个数字开始往右边搜索
        //只需要找左边大于等于右边某一个数，然后=？+1即可，从倒数第二个数字开始
        rec[size-1].x=data[size-1];
        //右边有0个数字 无需比较
        for(i=size-2;i>=0;i--){//从倒数第二个开始
            sort(rec+i+1,rec+size,cmp);
            rec[i].x=data[i];
            for(j=i+1;j<size;j++){
                if(data[i]>rec[j].x){
                    rec[i].y=1+rec[j].y;
                    count+=rec[i].y%1000000007;
                    break;//退出循环
                }
            }
        }
        delete[] rec;
        return count%1000000007;
    }*/
};
/***超时分析
1.每次都要构造一个copy
2.copy复制回data用时长
class Solution {
public:
    //比较完了之后就可以拍成有序的了
    //归并排序都要搞忘了……
    int InversePairs(vector<int> data) {
        int length  = data.size();
        if(length<=1) return 0;
        //for(int i=0;i<length;i++) copy[i]==data[i];
        return mergeSort(data, 0, length-1);
    }
    long long mergeSort(vector<int> &data,int l,int r){
        if(l>=r) return 0;
        int mid=(l+r)>>1;
        long long lcount=mergeSort(data,l,mid);
        long long rcount=mergeSort(data,mid+1,r);
        long long count=0;
        int lp=mid,rp=r,copyp=r;
        vector<int> copy(data.size()); //构建副本？用于比较，data则应用排序
        while(lp>=l&&rp>mid){
            if(data[lp]>data[rp]){
                copy[copyp--]=data[lp--];//取大的
                //相当于升序排序
                count+=rp-mid;//rp-(mid+1)+1
                //已经升序，所以mid+1~rp都小于
            }
            else copy[copyp--]=data[rp--];//取大的
        }
        //处理余下的
        while(lp>=l) copy[copyp--]=data[lp--];
        while(rp>mid) copy[copyp--]=data[rp--];
        for(int i=l;i<=r;i++) data[i]=copy[i];
        return (lcount+rcount+count)%1000000007;
    }

};

**/
