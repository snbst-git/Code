class Solution {
public:
	//可以不使用O(n)遍历，因为数组局部有序，可用二分查找
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
		else
		{
			int first = 0;
			int last = rotateArray.size() - 1;
			int mid = first;
			//当第一个元素大于等于最后一个元素是循环
			while(rotateArray[first] >= rotateArray[last])
			{
				if(last - first == 1)
					return rotateArray[last];	//循环结束信号，当两个指针相差一时返回后一个值
				mid = first + ((last - first)>>1);
				//如果first,mid,last的三个值相等，则无法判断例如{1,0,1,1,1)与{1,1,1,0,1}无法判断0处于哪一个局部，只能遍历求解
                if(rotateArray[first] == rotateArray[mid] && rotateArray[mid] == rotateArray[last])
                    return Traversal(rotateArray);
				//当mid值小于等于last时，说明mid在旋转后的序列里
				else if(rotateArray[mid] <= rotateArray[last])
					last = mid;
				//当mid值大于等于first时，说明mid在未旋转的序列里
				else if(rotateArray[mid] >= rotateArray[first])
					first = mid;
			}
			return rotateArray[mid];
		}
	}
	//遍历求解
    int Traversal(vector<int>& array) 
    {
        int i = 0;
        int res = array[i];
        for(i = 0;i<array.size();i++)
        {
            if(res > array[i])
                res = array[i];
        }
        return res;
    }   
};