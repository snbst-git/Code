/**
1.等差数列啊！
2.分情况讨论蠢死了
*/
class Solution {
public:
    //等差数列直接用公式就好了
    vector<vector<int> > FindContinuousSequence(int sum) {
        int low=1,high=2;
        vector<vector<int>> result;
        while(low<high){
            int temp=(high+low)*(high-low+1)/2;
            if(temp<sum) high++;
            else if(temp==sum){
                vector<int> ans;
                for(int i=low;i<=high;i++){
                    ans.push_back(i);
                }
                result.push_back(ans);
                low++;//不然死循环到这里了
            }
            else{//>
                low++;//偏大，少一个低的 high要不要移动？
                //不用，因为原来相当于2~4不够 故2~5超了，那么现在3~5是大于2~4而小于3~5的
                //由于是连续的所以不需要考虑
            }
        }
        return result;
    }

    /*
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        int i, j, k;
        vector<vector<int>> result;
        if (sum % 2) {//奇数
            for (i = 2; i <= sum; i++) {
                if (i % 2) {//奇数个 需要整除
                    j = sum % i;
                    if (j == 0) {
                        vector<int> ans;
                        j = sum / i;
                        if (j - i / 2 <= 0) break;
                        ans.push_back(j);
                        for (k = 1; k <= i / 2; k++) {
                            ans.insert(ans.begin(), j - k);
                            ans.push_back(j + k);
                        }
                        result.push_back(ans);
                    }
                    //否则不整除，无需处理
                }
                else {//偶数个
                    if ((i / 2) % 2) {//(i/2)为奇数才能凑成奇数个奇数对
                        vector<int> ans;
                        j = sum / i;
                        if (j - i / 2 + 1 <= 0) break;
                        for (k = 1; k <= i / 2; k++) {
                            ans.insert(ans.begin(), j - k + 1);//0 -1 -2
                            ans.push_back(j + k);//+1 +2 +3
                        }
                        result.push_back(ans);
                    }
                }

            }
        }
        else {//偶数
            for (i = 3; i <= sum; i++ ) {//只考虑奇数
                if (i % 2) {
                    j = sum % i;
                    if (j == 0) {
                        vector<int> ans;
                        j = sum / i;
                        if (j - i / 2 <= 0) break;
                        ans.push_back(j);
                        for (k = 1; k <= i / 2; k++) {
                            ans.insert(ans.begin(), j - k);
                            ans.push_back(j + k);
                        }
                        result.push_back(ans);
                    }
                    //否则不整除，无需处理
                }
                else {//i为偶数 偶数个数字加得到偶数 必须有偶数对 如8 =4*2
				    if ((i / 2) % 2 == 0) {//偶数配对
                        if (sum%(i/2) == 0&&(sum/(i/2))%2==1) {
                            vector<int> ans;
                            j = sum / i;//100/8=12.5=12 中间偏左
                            if (j - i / 2 + 1 <= 0) break;
                            for (k = 1; k <= i / 2; k++) {
                                ans.insert(ans.begin(), j - k + 1);//0 -1 -2 -3
                                ans.push_back(j + k);//+1 +2 +3 +4
                            }
                            result.push_back(ans);
                        }
                    }
                }
	    	}
        }
        sort(result.begin(),result.end(),cmp);
        return result;
    }
    */
};
