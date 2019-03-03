class Solution {
public:
    vector<int> res;
    vector<int> mins;//当过最小值的元素
    void push(int value) {
        res.push_back(value);
        if(mins.empty())
        {
            mins.push_back(value);
        }
        else if(value <= mins.back())
        {
            mins.push_back(value);
        }
    }
    void pop() {
        if(res.back() == mins.back())
            mins.erase(mins.end() - 1);
        res.erase(res.end() - 1);
    }
    int top() {
        int t = res.back();
        pop();
        return t;
    }
    int min() {
        return mins.back();
    }
};