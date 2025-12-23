#include <iostream>
#include <queue>
#include <vector>
class MyStack
{
public:
    std::queue<int> q1;
    std::queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        while (q2.size() != 0)
        {
            q2.pop();
        }
        int tempPopped = 0;
        int initSize = q1.size();
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
            if (q1.size() == initSize - 1)
            {
                tempPopped = q2.back();
            }
        }
        q1.swap(q2);
        return q2.back();
    }

    int top()
    {
        while (q2.size() != 0)
        {
            q2.pop();
        }
        int tempPopped = 0;
        int initSize = q1.size();
        while (q1.size() != 0)
        {
            q2.push(q1.front());
            q1.pop();
            if (q1.size() == 1)
            {
                tempPopped = q1.back();
            }
        }
        tempPopped = q2.back();
        q1.swap(q2);
        while (q2.size() != 0)
        {
            q2.pop();
        }
        return tempPopped;
    }

    bool empty()
    {
        if (q1.size() == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    int x = 10;
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_3 = obj->top();
    int param_2 = obj->pop();
    int param_6 = obj->top();
    int param_92 = obj->pop();
    bool param_4 = obj->empty();
}