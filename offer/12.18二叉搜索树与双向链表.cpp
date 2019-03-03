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
	//中序遍历的顺序存储在一个队列里
    queue<TreeNode*> inorder;
	//中序遍历
    void traversal(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return;
        traversal(pRootOfTree->left);
        inorder.push(pRootOfTree);
        traversal(pRootOfTree->right);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        traversal(pRootOfTree);
        TreeNode* head = inorder.front();
        inorder.pop();
        TreeNode* pt = head;
        pt->left = NULL;
		//依次出队列，形成一个双向链表
        while(!inorder.empty())
        {
            TreeNode* temp = pt;
            pt->right = inorder.front();
            inorder.pop();
            pt = pt->right;
            pt->left = temp;
        }
        pt->right = NULL;
        return head;
    }
};