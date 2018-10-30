class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int x = n;	//如果要使用右移操作，转化成无符号数可以避免负数补1
         int res = 0;
         while(x != 0)
         {
			 //可以消除最左边的1
             x = x & (x - 1);
             res++;
         }
         return res;
     }
};