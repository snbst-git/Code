class Solution {
public:
	//两个数拼起来，如果a+b < b+a那么a就小于b
	//基于上述原理排序
    static bool compare(const string &a ,const string &b)
    {
        string r1,r2;
        r1 = a + b;
        r2 = b + a;
        if(r1 < r2)
            return true;
        else
            return false;
    }
    string PrintMinNumber(vector<int> numbers) {
        vector<string> temp;
        for(auto &i : numbers)
        {
            temp.push_back(to_string(i));
        }
        sort(temp.begin(),temp.end(),compare);
        string res;
        for(auto &i : temp)
            res += i;
        return res;
    }
};