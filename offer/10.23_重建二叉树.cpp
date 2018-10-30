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
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0||vin.size()==0||(pre.size()!=vin.size())) 
            return NULL;
        TreeNode* root=new TreeNode(pre[0]);
        if(pre.size()==1){
            root->left=NULL,root->right=NULL;
            return root;
        }
        int rootloc=0;//在vin中的位置
        while(rootloc<vin.size()&&vin[rootloc]!=pre[0]) rootloc++;//最好加一个判定
        vector <int> lpre,rpre,lvin,rvin;
        int j=1;
        for(int i=0;i<rootloc;i++,j++) lvin.push_back(vin[i]),lpre.push_back(pre[j]);
        for(int i=rootloc+1;i<vin.size();i++,j++) rvin.push_back(vin[i]),rpre.push_back(pre[j]);
        root->left=reConstructBinaryTree(lpre,lvin);
        root->right=reConstructBinaryTree(rpre,rvin);
        return root;
    }
};
