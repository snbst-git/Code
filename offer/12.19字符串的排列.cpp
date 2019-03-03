class Solution {
public:
    void f1(vector<string> &res,string str,string now)
    {
        if(str.empty())
        {
            res.push_back(now);
            return;
        }
        for(int i = 0;i<str.size();i++)
        {
			//去重
        	if(i>0 && str[i] == str[i-1])
				continue; 
            now = now + str.at(i);
            string temp =  str.substr(0,i)+str.substr(i+1);
            f1(res,temp,now);	//递归
            now.erase(now.end() - 1);
        }
    }
    
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty())
            return res;
        sort(str.begin(),str.end());
        string empty;
        f1(res,str,empty);
        return res;
    }
};