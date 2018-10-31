/**有两点没有考虑到
1.指数为负数的情况
2.指数为负数的情况下base==0那么就会导致错误

开始写的时候觉得模重复平方法还是有点朴素了，会不会有更好的方法
*/


class Solution {
public:
    double Power(double base, int exponent) {
    //模重复平方法
        int i,flag;
        double result=1;
        int *expbit=new int[32];
        if(exponent==0){
            if(base==0) return 0;
            else return 1;
        }
        if(exponent>0) flag=0;
        else{//******没有考虑负数的情况
            flag=1,exponent*=-1;
            if(base==0) throw new std::exception("Base==0 cannot be the denominator.");
            //exit(1);//*****分母为0应该进行报错 没考虑这点
        }
        for(i=0;i<32;i++){
            expbit[i]=exponent&1;//0~32记录了从低到高，最后循环的时候从高到低
            exponent=exponent>>1;
        }
        for(i=31;i>=0;i--){
            if(expbit[i]) result*=base;
            if(i) result=result*result;//最后一次不需要平方
        }
        delete[] expbit;
        if(flag) result=1.0/result;
        return result;
    }
};
