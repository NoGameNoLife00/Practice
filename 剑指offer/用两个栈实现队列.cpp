// 题目描述
// 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的成员为int类型。

思路：
队列的特点：先进先出
栈的特定： 先进后出
利用两个栈实现队列，stack1用于存储push进来的成员。
而当有pop操作时，判断stack2是否为空，如果为空就将stack1中的成员依次放入stack2中，
这时stack2的栈顶成员对应就是队列中需要弹出的成员

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty())
        {
        	while(!stack1.empty())
            {
            	stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty())
        {
            // 错误处理
			return -1;
        }
        int result = stack2.top();
        stack2.pop();
        return result;

    }

private:
    stack<int> stack1;
    stack<int> stack2;
};