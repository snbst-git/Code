/**
改一下遍历就是了
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
