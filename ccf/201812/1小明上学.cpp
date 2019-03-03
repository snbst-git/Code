#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int r,c;

int main(){
    int r,y,g,n,k,t,sum=0;
    cin>>r>>y>>g>>n;
    //怎么表示输入结束结束了？这里不需要
    ///使用scanf返回值为-1
    while(n-->0){
        cin>>k>>t;
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
