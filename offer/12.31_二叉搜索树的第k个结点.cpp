/**
二叉搜索树特性，中序遍历为序号
注意return NULL可以作为继续查找信号，所以单独保存返回结果到ret
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int count=1;
        return mid(pRoot,count,k);
    }

    TreeNode *mid(TreeNode* p,int &c,int k){
        if(p!=NULL){
            TreeNode *ret;
            if(p->left!=NULL){
                ret=mid(p->left,c,k);
                if(ret!=NULL) return ret;//分开，否则无法区分是序号不符合继续找，还是失败信号
            }
            if(c==k)  return p;
            c++;
            if(p->right!=NULL){
                ret=mid(p->right,c,k);
                if(ret!=NULL) return ret;
            }
        }
        return NULL;
        //当前结点序号不符合 或者是结点为空
    }

};
