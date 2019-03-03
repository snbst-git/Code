/**
递归好骚啊！
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL) return true;
        //根不为空
        //镜像
        else return cmp(pRoot->left,pRoot->right);
    }

    bool cmp(TreeNode* p,TreeNode* q){
        if(p==NULL&&q==NULL) return true;
        else if(p==NULL||q==NULL) return false;
        else if(p->val!=q->val) return false;
        else return cmp(p->left,q->right)&&cmp(p->right,q->left);
    }

};
