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
	//层序遍历
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> BFS;
        BFS.push(root);
        while(!BFS.empty())
        {
            res.push_back(BFS.front()->val);
            if(BFS.front()->left)
                BFS.push(BFS.front()->left);
            if(BFS.front()->right)
                BFS.push(BFS.front()->right);
            BFS.pop();
        }
        return res;
    }
};