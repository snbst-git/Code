/**
1.二叉搜索树挺磨人啊……
2.没想清楚逻辑
自己的程序为什么不能用，画图和理一下逻辑
3.网上的方法直接每次处理相邻一前一后结点，其实right和left的处理都是一致的，要看到这一点
***/
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return NULL;
        TreeNode *p=pRootOfTree,*pre=NULL;
        both(p,pre);
        while(p->left!=NULL) p=p->left;
        return p;
    }
    void both(TreeNode *p,TreeNode *&pre){
        if(p){
            both(p->left,pre);
            p->left=pre;
            if(pre) pre->right=p;
            pre=p;
            both(p->right,pre);
        }
    }

    void left(TreeNode *p){
        if(p!=NULL){
            if(p->left!=NULL){
                TreeNode *temp=p->left;//temp=原p->left
                if(temp->right!=NULL){
                    p->left=temp->right;//p->left更新为temp的右子树
                    TreeNode *temp2=p->left;//搜索到最左边的结点
                    while(temp2->left!=NULL){
                        temp2=temp2->left;
                    }
                    temp2->left=temp;//temp的左子树某一个结点更新为temp
                    temp->right=NULL;
                }
                //left(p->left);//如果left为空也没必要再排了
            }
        }
    }

    void right(TreeNode *p){
        if(p!=NULL){
            if(p->right!=NULL){
                TreeNode *temp=p->right;
                if(temp->left!=NULL){
                    p->right=temp->left;
                    TreeNode *temp2=p->right;
                    while(temp2->right!=NULL){//找最大的，最右边的结点
                        temp2=temp2->right;
                    }
                    temp2->right=temp;
                    temp->left=NULL;
                }
                //right(p->right);
            }
        }
    }
};
