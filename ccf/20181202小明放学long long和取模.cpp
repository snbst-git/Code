///201812_02ע��������Ȼ�Ĺ���
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
///1.Ҫʹ��long long��ֹը��
long long r,y,g,n,k,t,sum=0;

void caltime(long long &k,long long &t){//���ݳ�����ʱ��������ڵ�ʱ��
    if(k==0) return;//��·�������
    t-=sum;
    ///2.���ʵ��ĸ߼��������������ѭ��
    t=-((-t)%(r+g+y));
    while(t<=0){//?С�ڻ���С�ڵ���0
        switch(k){//1 3 2
            case 1://��ʼ�Ǻ�ƣ���ʣ��ts�����˲��������Ե����̵Ƶ�
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
    //��ô��ʾ������������ˣ����ﲻ��Ҫ
    ///ʹ��scanf����ֵΪ-1
    while(n-->0){
        cin>>k>>t;
        caltime(k,t);
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
