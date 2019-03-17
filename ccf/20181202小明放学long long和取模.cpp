///201812_02注意这种显然的规律
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
///1.要使用long long防止炸掉
long long r,y,g,n,k,t,sum=0;

void caltime(long long &k,long long &t){//根据出发的时间计算现在的时间
    if(k==0) return;//道路无需操作
    t-=sum;
    ///2.用适当的高级计算来避免过度循环
    t=-((-t)%(r+g+y));
    while(t<=0){//?小于还是小于等于0
        switch(k){//1 3 2
            case 1://开始是红灯，还剩余ts，减了不够用所以调用绿灯的
                k=3;
                t+=g;
                break;
            case 2:
                k=1;
                t+=r;
                break;
            case 3:
                k=2;
                t+=y;
                break;
            default:
                break;
        }
    }
}

int main(){
    cin>>r>>y>>g>>n;
    //怎么表示输入结束结束了？这里不需要
    ///使用scanf返回值为-1
    while(n-->0){
        cin>>k>>t;
        caltime(k,t);
        switch(k){
            case 0:
                sum+=t;
                break;
            case 1://红灯 下一个是绿灯
                sum+=t;
                break;
            case 2://黄灯，下一个是红灯
                sum+=(t+r);
                break;
            //case 3://绿灯 直接通行
                //break;
            default:
                break;
        }
    }
    cout<<sum<<endl;
    return 0;
}
