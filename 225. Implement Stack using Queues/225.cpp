#include <iostream>
#include <queue>
class MyStack
{
public:
    std::queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        int shit = q.back();
        q.pop();
        return shit;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        if (q.size() == 0)
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
    int param_3 = obj->pop();
    int param_2 = obj->top();
}