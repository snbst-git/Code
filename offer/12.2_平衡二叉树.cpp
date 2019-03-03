/**
应该不是比较好的解法
有冗余操作
看一下推荐解答
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL) return true;
        if(IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right)){
            int a,b;
            a=TreeDepth(pRoot->left),b=TreeDepth(pRoot->right);
            a-=b;
            if(a>=-1&&a<=1) return true;
            return false;
        }
        return false;

    }
    int TreeDepth(TreeNode* pRoot)
    {
        return  depth(pRoot,0);
    }
    int depth(TreeNode *p,int a){
        if(p!=NULL){
            //已有a p多1
            return max(depth(p->left,a+1),depth(p->right,a+1));
        }
        else return a;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
};
