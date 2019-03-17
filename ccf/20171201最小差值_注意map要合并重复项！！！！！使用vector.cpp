#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

//#define MAP

using namespace std;

typedef map<int,int> mymap;

int main(){
    int n,a;
    cin>>n;

    #ifdef MAP
    mymap imap;
    mymap::iterator mit,last;
    while(n--){
        cin>>a;
        if(imap.find(a)!=imap.end()){
            cout<<"0"<<endl;
            return 0;
        }
        imap[a]=n;//n无用，主要使用a
    }
    mit=imap.begin(),last=mit;
    mit++;
    ///没有考虑多个相同的情况！
    a=0x7fffffff;
    for(;mit!=imap.end();mit++,last++){
        a=min(a,mit->first-last->first);
    }
    cout<<a<<endl;
    #else
    vector<int> ivec;
    while(n--){
        cin>>a;
        ivec.push_back(a);
    }
    sort(ivec.begin(),ivec.end());
    a=0x7fffffff;
    for(n=1;n<ivec.size();n++){
        a=min(a,ivec[n]-ivec[n-1]);
    }
    cout<<a<<endl;
    #endif
    return 0;
}

