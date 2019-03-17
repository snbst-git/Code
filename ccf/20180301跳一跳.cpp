#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;

int main(){
    int i=1,sum=0,sco=1;
    while(i!=0){
        scanf("%d",&i);
        switch(i){
            case 0:
                break;
            case 1:
                sco=1;
                sum+=sco;
                break;
            case 2:
                if(sco==1) sco=2;
                else sco+=2;
                sum+=sco;
                break;
        }
        //1非中心 2中心 0结束
    }
    cout<<sum<<endl;
    return 0;
}

