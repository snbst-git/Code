/**
�������������ԣ��������Ϊ���
ע��return NULL������Ϊ���������źţ����Ե������淵�ؽ����ret
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int count=1;
        return mid(pRoot,count,k);
    }

    TreeNode *mid(TreeNode* p,int &c,int k){
        if(p!=NULL){
            TreeNode *ret;
            if(p->left!=NULL){
                ret=mid(p->left,c,k);
                if(ret!=NULL) return ret;//�ֿ��������޷���������Ų����ϼ����ң�����ʧ���ź�
            }
            if(c==k)  return p;
            c++;
            if(p->right!=NULL){
                ret=mid(p->right,c,k);
                if(ret!=NULL) return ret;
            }
        }
        return NULL;
        //��ǰ�����Ų����� �����ǽ��Ϊ��
    }

};
