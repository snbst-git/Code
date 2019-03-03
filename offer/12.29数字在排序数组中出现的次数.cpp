class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
    int low,high,l,r;
        //求下界
        for(l = 0,r = data.size();l<r;)
        {
            int mid = (r - l)/2 + l;
            if(data[mid] >= k)
            {
                r = mid ;
            }
            else
            {
                l = mid + 1;
            }
        }
        low = r;
        //求上界
        for(l = -1,r = data.size() - 1;l<r;)
        {
            int mid = (r - l + 1)/2 + l;
            if(data[mid] <= k)
            {
                l = mid ;
            }
            else
            {
                r = mid - 1;
            }
        }
        high = l;
        return high - low + 1;
    }
};