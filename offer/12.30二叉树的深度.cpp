/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
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
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        return max(Depth(1,pRoot->left),Depth(1,pRoot->right)); 
    }
};