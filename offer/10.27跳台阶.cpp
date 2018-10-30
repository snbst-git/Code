class Solution {
public:
·//可以用递归，递归调用开销太大，专用迭代
    int jumpFloor(int number) {
        if(number == 1)
        	return 1;
        if(number == 2)
        	return 2;
        int first = 1;
        int second = 2;
        int third;
		//迭代
        for(int i = 3;i<=number;i++)
        {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};