class Solution {
public:
    bool judge(vector<int> sequence) 
    {
        if(sequence.empty())
            return true;
        int root = sequence.back();
        vector<int> left,right;
        int i = 0;
		//左子树
        for(;i<sequence.size() - 1;i++)
        {
            left.push_back(sequence[i]);
            if(sequence[i] > root)
                break;
        }
        for(;i<sequence.size() - 1;i++)
        {
			//如果右子树有比根节点小的数
            if(sequence[i] < root)
                return false;
            right.push_back(sequence[i]);
        }
        bool bleft = true,bright = true;
        if(!left.empty())
            bleft = judge(left);
        if(!right.empty())
            bright = judge(right);
        return bleft & bright;
    }

    bool VerifySquenceOfBST(vector<int> sequence) 
    {
        if(sequence.empty())
            return false;
        else 
            return judge(sequence);
    }
};