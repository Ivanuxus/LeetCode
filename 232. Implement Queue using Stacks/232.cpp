#include <list>
class MyQueue
{
public:
    std::list<int> l1 = {};

    MyQueue()
    {
    }

    void push(int x)
    {
        l1.push_back(x);
    }

    int pop()
    {
        std::list<int>::iterator it = l1.begin();
        int temp = *it;
        l1.pop_front();
        return temp;
    }

    int peek()
    {
        std::list<int>::iterator it = l1.begin();
        int temp = *it;
        return temp;
    }

    bool empty()
    {
        if (l1.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    MyQueue *obj = new MyQueue;
    obj->push(1);
    obj->push(2);
    int param_3 = obj->peek();
    int param_2 = obj->pop();
    bool param_4 = obj->empty();
    return 0;
}
