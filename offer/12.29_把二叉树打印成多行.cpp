/**
����������Ŀ�ļ򻯰濩~������һ�������죬ֱ�Ӹ��ƹ���
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
        //��ηֲַ㵽vector���У���һ���������� ���¾�+1
            vector<vector<int> > result;
            vector<vector<TreeNode*>> que;
            printbylevel(que,pRoot,1);
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
    //�ݹ��ʤ��
    void printbylevel(vector<vector<TreeNode*> > &que,TreeNode *p,int depth){
        if(p!=NULL){
            if(que.size()<depth){
                vector<TreeNode*> lev;
                lev.push_back(p);
                que.push_back(lev);
            }
            else que[depth-1].push_back(p);
            printbylevel(que,p->left,depth+1),printbylevel(que,p->right,depth+1);
        }
    }

};
