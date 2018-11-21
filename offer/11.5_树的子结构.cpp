/**
都犯的啥错啊，心急了写个
if(result==false){
   HasSubtree(p->right, q);
}
result=都不写，，，，
result=TreeEqual(p,q);也直接写个result=TreeEqual(p->left,q)

******重点
另外这个判断是自己已开始写的，有问题
if(p==NULL&&q==NULL)
    return true;
if(p==NULL||q==NULL)
    return false;
对于q，可能只是p的一部分，也可以算作
如  8
   / \
  2   3
 /     \
1       4

  8
 /
2
应该算作其一颗子树

由于先判断q==NULL?
所以如果没有返回而进行p==NULL?的判断，则表示q!=NULL，那么如果p==NULL肯定就不行了

***/
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {

        if(pRoot1==NULL||pRoot2==NULL) return false;//有任意一个为NULL都不对
        bool result=false;
        TreeNode *p=pRoot1,*q=pRoot2;
        if(p->val==q->val){
            result=TreeEqual(p,q);//值相等
        }
        if(result==false){//值不相等，对左右子树找
            result=HasSubtree(p->left, q);
        }
        if(result==false){
           result=HasSubtree(p->right, q);//少写了个result=……？？？？？？？
        }
        return result;
    }

    bool TreeEqual(TreeNode* p, TreeNode* q){
        /*if(p==NULL&&q==NULL)
            return true;
        if(p==NULL||q==NULL)
            return false;*/
        if(q==NULL) return true;//至此匹配的点val都相符
        if(p==NULL) return false;
        if(p->val==q->val){
            return TreeEqual(p->left,q->left)&&TreeEqual(p->right,q->right);
        }
        return false;
    }

};
