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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> nodes;
        if(root!=NULL){
            //递归的话应该左右就有问题
            nodes.push_back(root);
        }
        while(nodes.size()>0){
            /**先写成root->left root->right了丢人***/
            if((nodes.front())->left!=NULL) nodes.push_back((nodes.front())->left);
            if((nodes.front())->right!=NULL) nodes.push_back((nodes.front())->right);
            result.push_back((nodes.front())->val);//元素
            nodes.erase(nodes.begin());//迭代器
        }
        return result;
    }
};
