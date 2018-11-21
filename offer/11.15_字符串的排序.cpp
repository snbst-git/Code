/**
坑多
1.string &str
导致有组合被吞了
2.字典顺序，sort一下
3.用一个表记录已经交换的
***/
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if (str.size() == 0) return result;
        add(str, 0, result);
        return result;
    }
    //1.不要用string &str
    void add(string str, int n, vector<string> &result) {
        if (n == str.size() - 1) result.push_back(str);
        else {
            vector<char> swaped;
            sort(str.begin() + n, str.end());//2.字典顺序
            for (int i = n ; i<str.size(); i++) {
                //3.不要用str[i]和str[n]比，而是建立一个已经交换过的表
                if (find(swaped.begin(), swaped.end(), str[i]) == swaped.end()) {
                    swaped.push_back(str[i]);
                    swap(str[n], str[i]);
                    add(str, n + 1, result);
                    swap(str[n], str[i]);
                }
            }
        }
    }
};
