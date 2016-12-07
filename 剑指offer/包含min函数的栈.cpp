// 题目描述
// 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

// 思路：
// 使用一个辅助的栈，存储每个主栈中每个操作之后对应的最小值

class Solution {
    stack<int> valueStack;
    stack<int> minStack;
public:


    void push(int value) {
        if (minStack.empty())
        {
        	minStack.push(value);
        }
        else
        {
        	if (value > minStack.top())
            {
            	minStack.push(minStack.top());
            }
            else
            {
            	minStack.push(value);
            }
        }
        valueStack.push(value);
    }

    void pop() {
        valueStack.pop();
        minStack.pop();
    }

    int top() {
        return valueStack.top();
    }

    int min() {
        return minStack.top();
    }
};