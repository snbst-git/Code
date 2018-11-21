class Solution {
public:
	//当exponent是偶数时，res = base ^ (exponent/2) * base ^ (exponent/2)
	//当exponent是奇数时，res = base ^ (exponent - 1/2) * base ^ (exponent - 1/2) * base
	//然后递归使exponent缩小，使得时间复杂度是O(logn)
    double Power(double base, int exponent) {
        int t = abs(exponent);
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        double res = Power(base,t >> 1);
        res *= res;
        if(exponent & 0x1 == 1)
            res *= base;
        if(exponent < 0)
            res = 1/res;
        return res;
    }
};