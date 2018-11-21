/**
真的O(1)了吗，，，好像是O(n)啊，但是什么都不知道最多只能这个样子了吧？
另外不让用throw new exception……
**/

class Solution {
public:
    int pos;
    int max;
    int *stack;
    void push(int value) {
        if(pos>=max){
            int *newstack=new int[max+100];
            for(int i=0;i<max;i++){
                newstack[i]=stack[i];
            }
            int *temp=stack;
            stack=newstack;
            delete[] temp;
            max+=100;
        }
        stack[pos++]=value;
    }
    void pop() {
        if(pos>0) pos--;
    }
    int top() {
        if(pos>0) return stack[pos-1];
        else return -1;
        //else{throw new std::exception("Stack is empty."); }
    }
    int min() {
        int min=0xfffffff;
        for(int i=0;i<pos;i++){
            if(min>stack[i]) min=stack[i];
        }
        return min;
    }
    Solution(int init=10){stack=new int[init];max=100,pos=0;}
    ~Solution(){delete[] stack;}

};
