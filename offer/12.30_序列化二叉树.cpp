/**
���˼����ÿɻ���
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
        //ȥ�����ģ� Ϊ��Ҳ����Ϊ#
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
            //p=NULL; Ĭ�ϳ�ʼ��ΪNULL �������
        }
        /*
        int num=0;
        while(s[i]!=','&&s[i]!=0){
            num=num*10+s[i++]-'0';
        }
        p=new TreeNode(num);
        if(s[i]==0) return;
        else i++;//Ϊ���϶����Ҷ���
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
        else if(s[i]==0) return;//����

    }

    void front(string &r,TreeNode *p){
        if(p!=NULL){
            //ǰ���������� �����������
            r+=std::to_string(p->val);
            r+=',';
            front(r,p->left);
            front(r,p->right);
        }
        else{
            r+="#";
            //���϶�����#������
        }
    }
};
