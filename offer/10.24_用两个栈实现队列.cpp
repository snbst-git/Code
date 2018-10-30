class Solution
{
public://似乎没考虑满队的情况 但是需要考虑队列为空出队列的情况
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        /*
        if(stack1.empty()&&stack2.empty()){
          return -0xffff;//报错信息之类的
        }*/
        if(stack2.empty())
        {
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int i=stack2.top();
        stack2.pop();
        return i;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
