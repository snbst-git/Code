class Solution {
public:
    int Sum_Solution(int n) {
        return (n>0?(n+Sum_Solution(n-1)):0);
    }
};
