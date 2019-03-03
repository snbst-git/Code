/**
1.第一反应就是用map，还在想有没有一点作弊
2.想太麻烦了 一个数组记录出现顺序 一个数组记录出现次数
其实可以再遍历一次，就避免记录顺序了
而且记录顺序也不必要用map来做，vector其实就可做而且排序相对方便
3.还不够熟悉map、vector，多熟悉熟悉
*/
class Solution {
public:

    int FirstNotRepeatingChar(string str) {
        //只出现一次肯定是要遍历一次的
        //记录位置
        if(str.size()==0) return -1;
        map<char,int> rec;
        ///咋就没想到再遍历一遍呢
        for(int i=0;i<str.size();i++){
            rec[str[i]]++;
        }
        for(int i=0;i<str.size();i++){
            if(rec[str[i]]==1) return i;
        }
        return -1;
        /*
        int order;
        int cnt[52];//初始为0
        for(order=0;order<52;order++) cnt[order]=0;
        for(int i=0;i<str.size();i++){
            if(str[i]>='a') order=26+str[i]-'a';
            else order=str[i]-'A';
            cnt[order]++;
            if(rec.find(str[i])==rec.end()) rec[str[i]]=i;
        }
        map<char,int>::iterator mit;
        sort(rec.begin(), rec.end(), cmp);
        for(mit=rec.begin();mit!=rec.end();mit++){
            if(mit->first>='a') order=26+mit->first-'a';
            else order=mit->first-'A';
            if(cnt[order]==1) return mit->second;
        }
        return -1;*/
    }

};
