class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //从右上角往左下角遍历
        //时间复杂度O(max(row,col))
        int row = 0,col = array[0].size() - 1;
		while(row < array.size() && col >= 0)
		{
			if(array[row][col] == target)
				return true;
			else if(array[row][col] < target)
				row++;
			else
				col--;
		}
		return false;
    }
};