class Solution {
public:
    int StrToInt(string str) {
        int flag = 0, result = 0, i=0;///记得初始化下标
        if (str.empty()) return 0;
        if (str[0] == '-') flag = 1, i++;
        else if (str[0] == '+') i++;
        while (i<str.size()) {
            result *= 10;
            if (str[i] >= '0'&&str[i] <= '9') result += (str[i] - '0');
            else return 0;//不规范
            i++;
        }
        if (flag) result *= -1;
        return result;
    }
};
