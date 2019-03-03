class Solution {
public:
     int Add(int num1, int num2)
    {
        //位运算 不熟悉二进制的特点
         while(num2!=0){
             int temp=num1^num2;//计算和
             num2=(num1&num2)<<1;//计算进位
             //和与进位应该是错开的求或即可
             num1=temp;//留到下一步加
         }
         return num1;
         /*这个做法对于负数有很大问题，回忆一下逻辑 考虑一下补码怎么加
        int result = 0, carry = 0, sum, i = 0;
        while (num1!=0||num2!=0) {
            //和即取异或
            sum = (carry ^ num1 ^ num2) & 1;
            //carry有两个1即可
            carry = carry & (num1 & 1) || carry & (num2 & 1) || ((num1 & num2) & 1);
            result = result | (sum << i);
            num1 = num1 >> 1;
            num2 = num2 >> 1;
            i++;
        }
        result = result | (carry << i);
        return result;*/
    }
};
