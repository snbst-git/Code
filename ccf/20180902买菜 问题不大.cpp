#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <memory.h>

using namespace std;

int main(){
    int n,i;
    int *in,*out;
    cin>>n;
    in=new int[n];
    out=new int[n];
    for(i=0;i<n;i++) cin>>in[i];
    //感觉正常计算可能会超时
    cout<<(in[0]+in[1])/2<<' ';
    for(i=1;i<n-1;i++){
        cout<<(in[i-1]+in[i]+in[i+1])/3<<" ";
    }
    cout<<(in[n-1]+in[n-2])/2<<endl;
    delete in;
    delete out;
    return 0;
}
