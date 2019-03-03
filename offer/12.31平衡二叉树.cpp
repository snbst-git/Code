class Solution {
public:
   	//d代表深度
    int Depth(int d,TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return d;
        d++;
        return max(Depth(d,pRoot->left),Depth(d,pRoot->right)); 
    }
    
    bool judge_depth(TreeNode* pRoot)
    {
        if(abs(Depth(1,pRoot->left)- Depth(1,pRoot->right)) <= 1)
            return true;
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        return judge_depth(pRoot);
    }
};