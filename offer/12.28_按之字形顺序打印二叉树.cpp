/**
有点绕，不好用递归写，还是要熟练运用数组啊
另外画个图应该有助于理解，今天懒没动脑子，想了好久
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        //如何分分层到vector当中？加一个参数好了 向下就+1
        vector<vector<int> > result;
        vector<vector<TreeNode*>> que;
        if(pRoot!=NULL){
                vector<TreeNode*> lev;
                lev.push_back(pRoot);
                que.push_back(lev);
                printbylevel(que,2);//从2层开始
        }
        for(int i=0;i<que.size();i++){
            vector<int> levre;
            for(int j=0;j<que[i].size();j++){
                //if(que[i][j]!=NULL)
                levre.push_back(que[i][j]->val);
            }
            result.push_back(levre);
        }
        return result;
    }
    //递归好像不太好用，还是用一层一层的while循环吧
    void printbylevel(vector<vector<TreeNode*> > &que,int depth){
        if(depth%2==0){//偶数层 从右往左即可
            for(int i=que[depth-2].size()-1;i>=0;i--){
                //从上层右往左遍历并且 push
                if(que.size()<depth){//首次进入该层
                    vector<TreeNode*> lev;
                    if(que[depth-2][i]->right!=NULL) lev.push_back(que[depth-2][i]->right);
                    if(que[depth-2][i]->left!=NULL) lev.push_back(que[depth-2][i]->left);
                    if(lev.size()) que.push_back(lev);
                }
                else{//已有该层
                    if(que[depth-2][i]->right!=NULL) que[depth-1].push_back(que[depth-2][i]->right);
                    if(que[depth-2][i]->left!=NULL) que[depth-1].push_back(que[depth-2][i]->left);
                }
            }
        }
        else{//奇数层 从左往右
            for(int i=que[depth-2].size()-1;i>=0;i--){
                //从上层右往左遍历并且 push
                if(que.size()<depth){
                    vector<TreeNode*> lev;
                    if(que[depth-2][i]->left!=NULL) lev.push_back(que[depth-2][i]->left);
                    if(que[depth-2][i]->right!=NULL) lev.push_back(que[depth-2][i]->right);
                    if(lev.size()) que.push_back(lev);
                }
                else{
                    if(que[depth-2][i]->left!=NULL) que[depth-1].push_back(que[depth-2][i]->left);
                    if(que[depth-2][i]->right!=NULL) que[depth-1].push_back(que[depth-2][i]->right);
                }
            }
        }
        //如果新增了元素
        if(depth==que.size()) printbylevel(que,depth+1);
    }
    /*
    if(p!=NULL){
        if(que.size()<depth){
            vector<TreeNode*> lev;
            lev.push_back(p);
            que.push_back(lev);
        }
        else que[depth-1].push_back(p);
        if(depth%2==0)//偶数层的下一层为奇数 从左到右
            printbylevel(que,p->left,depth+1),printbylevel(que,p->right,depth+1);
        else   //奇数层的下一层 右往左
            printbylevel(que,p->right,depth+1),printbylevel(que,p->left,depth+1);

    }*/
};
