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
    //��ô��ʾ������������ˣ����ﲻ��Ҫ
    ///ʹ��scanf����ֵΪ-1
    while(n-->0){
        cin>>k>>t;
        switch(k){
            case 0:
                sum+=t;
                break;
            case 1://��� ��һ�����̵�
                sum+=t;
                break;
            case 2://�Ƶƣ���һ���Ǻ��
                sum+=(t+r);
                break;
            //case 3://�̵� ֱ��ͨ��
                //break;
            default:
                break;
        }
    }
    cout<<sum<<endl;
    return 0;
}
