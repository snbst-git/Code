class Solution {
public:
    long long res = 0;
    void merge(vector<int> &data,int left,int right)
    {
        int mid = (right-left)/2 + left;
        int i = mid;
        int j = right;
        int *temp = new int[right - left + 1];
        int end = right - left;
        while(i>=left && j>=mid+1)
        {
            if(data[i] > data[j])
            {
                res += (j - mid);
                temp[end--] = data[i--];
            }
            else
                temp[end--] = data[j--];
        }
        while(i >= left)
            temp[end--] = data[i--];
        while(j >= mid+1)
            temp[end--] = data[j--];
        for(int l = left,k = 0;l<=right;l++)
            data[l] = temp[k++];
    }
    void divide(vector<int> &data,int left,int right)
    {
        if(left == right)
            return;
        int mid = (right-left)/2 + left;
        divide(data,left,mid);
        divide(data,mid+1,right);
        merge(data,left,right);
    }
	//mergeSort to caculate InversePairs
	//BubbleSort and InsertSort Time Complexity are O(n*n),so time limit exceed
    int InversePairs(vector<int> data) {
        if(data.empty())
            return 0;
        divide(data,0,data.size()-1);
        return res % 1000000007;
    }
};