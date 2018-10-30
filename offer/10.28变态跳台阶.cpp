class Solution {
public:
	//用排列组合的插空法思想，N个台阶有n-1个空，所以答案是2的n-1次方
	//改用位运算效率更高
    int jumpFloorII(int number) {
        if(number <= 0)
            return 0;
        return 1 << (number - 1);
    }
};