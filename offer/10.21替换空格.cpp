class Solution {
public:
	void replaceSpace(char *str,int length) {
//申请一个O(3 * length)的空间，存储替换后的字符串，然后再赋值回去。
//时间复杂度O(N)
//		char* t = new char[length * 3]; 
//		int len = 0;
//		for(int i = 0;i<length;i++,len++)
//		{
//			if(str[i] == ' ')
//			{
//				t[len++] = '%';
//				t[len++] = '2';
//				t[len] = '0'; 
//			} 
//			else
//				t[len] = str[i];
//		} 
//		for(int i = 0;i<len;i++)
//		{
//			str[i] = t[i];
//		}

//表达先从前往后扫描，在从后往前复制,时间复杂度O(n)
		int len = 0;
		int count = 0;
		for(int i = 0;i<length;i++)
		{
			if(str[i] == ' ')
				count++;			
		} 
		len = length + count * 2;
		for(int i = length;i != len;i--,len--)
		{
			if(str[i] == ' ')
			{
				str[len--] = '0';
				str[len--] = '2';
				str[len] = '%';
			}
			else
				str[len] = str[i];
		}
	}
};