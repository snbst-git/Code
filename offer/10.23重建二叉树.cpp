/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//递归关系式T(n) = 2T(n/2) + O(n) 时间复杂度O(nlogn) 
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* head = new TreeNode(pre[0]);
        int root = pre[0];
        int left = 0;			//左子树元素个数
        int right = 0;			//右子树元素个数
        vector<int> lpre,lvin;	//左子树的前序遍历和中序遍历
        vector<int> rpre,rvin;	//右子树的前序遍历和中序遍历
        for(left = 0;vin[left]!=root;left++)
        {
            lpre.push_back(pre[left+1]);
            lvin.push_back(vin[left]);
        }
        for(int i = left+1;i < vin.size();i++)
        {
            right++;
            rpre.push_back(pre[i]);
            rvin.push_back(vin[i]);
        }
        if(left != 0)
        {
            head->left = reConstructBinaryTree(lpre,lvin);
        }
        if(right != 0)
        {
            head->right = reConstructBinaryTree(rpre,rvin);
        }
        return head;
    }
};