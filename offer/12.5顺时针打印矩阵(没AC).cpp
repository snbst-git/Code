class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int col = matrix[0].size(),row = matrix.size();
        int top = 0,bot = row-1,left = 0,right = col - 1; 
        vector<int> res;
     	while(left<=right && top<=bot)
     	{
     		//第一步 
            for(int i=left;i<=right;++i)                
            	res.push_back(matrix[top][i]);  
			//第二步
			if(bot > top)
				for(int i = top+1;i<=bot;i++)
				    res.push_back(matrix[i][right]);   
			//第三步
			if(bot > top && right > left)
			{
				for(int i = right - 1;i>=left;i--)
				res.push_back(matrix[bot][i]);   
			} 
            //第四步
			if(bot > top+ 1 && right > left)
			{
				for(int i = bot - 1;i>=top+1;i--)
					res.push_back(matrix[i][left]); 
			}
			left++;
			top++;
			right--;
			bot--;
		}
		return res;
    }
};