/**
没有考虑太多
*/
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
    void Mirror(TreeNode *pRoot) {
        //递归交换左右
        if(pRoot!=NULL){
            Mirror(pRoot->left);
            Mirror(pRoot->right);
            TreeNode *ptr=pRoot->left;
            pRoot->left=pRoot->right;
            pRoot->right=ptr;
        }
    }
};
