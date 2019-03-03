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
    bool flag = false;
    bool Subtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		//树二等于NULL，则说明树二已经遍历匹配完成
        if(pRoot2 == NULL)
            return true;
        else if(pRoot1 == NULL)
            return false;
		//如果顶点相同，则判断子结构
        else if(pRoot1->val == pRoot2->val)
            return Subtree(pRoot1->left,pRoot2->left) && Subtree(pRoot1->right,pRoot2->right); 
        else
            return false;
    }
    //遍历树1
    void travel(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL)
            return;
        else if(pRoot1->val == pRoot2->val)	//如果两棵树的顶点值相同，则判断两棵树子树
           flag |= Subtree(pRoot1->left,pRoot2->left) && Subtree(pRoot1->right,pRoot2->right);
		//因为树一中有可能有多个结点的值和树二的顶点相同，所以或上flag
        travel(pRoot1->left,pRoot2);	
        travel(pRoot1->right,pRoot2);
    }
	
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        travel(pRoot1, pRoot2);
        return flag;
    }
};