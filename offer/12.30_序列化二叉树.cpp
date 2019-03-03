/**
忘了加引用可还行
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
    char* Serialize(TreeNode *root) {
        string result;
        front(result,root);
        //去掉最后的， 为空也至少为#
        char *s=new char[result.size()+1];
        strcpy(s,result.c_str());
        return s;
    }
    TreeNode* Deserialize(char *str) {
        int i=0;
        TreeNode *root=NULL;
        formtree(str,i,root);
        return root;
    }

    void formtree(char *s,int &i,TreeNode *&p){
        if(s[i]=='#'){
            i++;
            //p=NULL; 默认初始化为NULL 无需操作
        }
        /*
        int num=0;
        while(s[i]!=','&&s[i]!=0){
            num=num*10+s[i++]-'0';
        }
        p=new TreeNode(num);
        if(s[i]==0) return;
        else i++;//为，肯定左右都有
        formtree(s,i,p->left);
        formtree(s,i,p->right);
        */
        else if(s[i]>='0'&&s[i]<='9'){
            string nums;
            while(s[i]>='0'&&s[i]<='9') nums+=s[i++];
            p=new TreeNode(atoi(nums.c_str()));
            if(s[i]==',') i++;
            formtree(s,i,p->left);
            formtree(s,i,p->right);
        }
        //else if(s[i]==',') i++;
        else if(s[i]==0) return;//结束

    }

    void front(string &r,TreeNode *p){
        if(p!=NULL){
            //前序是中左右 左根右是中序
            r+=std::to_string(p->val);
            r+=',';
            front(r,p->left);
            front(r,p->right);
        }
        else{
            r+="#";
            //最后肯定是以#结束的
        }
    }
};
