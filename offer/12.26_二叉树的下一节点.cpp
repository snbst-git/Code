/**
还以为思路上会有错……结果都是访问越界
结果把NULL判断加上去就没问题了……
*/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL) return NULL;
        //如果没有那么就回父节点 如果是左子树那么就访问父节点
        //如果是右那么就回退到父节点一直等到为一个的左子
        if(pNode->right!=NULL){
            //中序遍历下一个结点，如果对右边中序遍历
            return mid(pNode->right);
        }
        return func(pNode->next,pNode);
    }
    TreeLinkNode* func(TreeLinkNode*p,TreeLinkNode *last){
        if(p==NULL) return NULL;
        if(last==p->left) return p;//如果是左子树正好访问根节点
        //如果是右子树的话那么就继续往上
        else return func(p->next,p);
    }

    TreeLinkNode* mid(TreeLinkNode* p){
        //中序遍历返回第一个
        if(p->left!=NULL) return mid(p->left);//如果左不为空那么就访问左
        return p;//否则访问本身
    }
};
