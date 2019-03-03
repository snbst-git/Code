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
	//比较函数，数组长度大的靠前(事实上好像没要求这一点)
    bool static compare(const vector<int> a, const vector<int> b)
    {
        return a.size() > b.size();  
    }
	//深度搜索
    void DFS(int sum,int expectNumber,vector<vector<int> > &res,vector<int> &path,TreeNode* node)
    {
        sum += node->val;
        path.push_back(node->val);
        if(node->left == NULL && node->right==NULL)
        {
            if(sum == expectNumber)
                res.push_back(path);
        }
        if(node->left)
        {
            DFS(sum,expectNumber,res,path,node->left);
        }
        if(node->right)
        {
            DFS(sum,expectNumber,res,path,node->right);
        }
         path.erase(path.end() - 1);
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        vector<int> path;
        if(root)
            DFS(0,expectNumber,res,path,root);
        sort(res.begin(),res.end(),compare);
        return res;
    }
};