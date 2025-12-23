#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    std::vector<int> inorderTraversal(TreeNode *root)
    {
    }

    TreeNode *treeNodeMaker(std::vector<std::string> elem)
    {
    }
    void putToDeque(std::string x)
    {
        pos += 1;
        a[pos] = x;
    }
    std::string popFromDeque()
    {
        try
        {
            if (pos <= temp_pos)
                throw "EMPTY!";
            std::string temp = a[pos];
            pos -= 1;
            return temp;
        }
        catch (...)
        {
            std::cout << "There are no elements here!" << std::endl;
        }
    }
    std::string popFrontFromDeque()
    {
        try
        {
            if (temp_pos > pos)
                throw "EMPTY!";
            std::string temp_pos_elem = a[temp_pos];
            temp_pos += 1;
            return temp_pos_elem;
        }
        catch (...)
        {
            std::cout << "There are no elements here!" << std::endl;
        }
    }
    void showDequeValues()
    {
        std::cout << std::endl;
        for (int i = temp_pos; i <= pos; i++)
        {
            std::cout << a[i] << " ";
        }
    }

private:
    int pos = -1;
    int temp_pos = 0;
    std::string a[9999];
};
int main()
{
    Solution *o = new Solution;
    std::vector<std::string> elem = {"1", "2", "3", "4", "5", "null", "8", "null", "null", "6", "7", "9"};
    // for (int i = 0; i < elem.size(); i++)
    // {
    //     o->putToDeque(elem[i]);
    // }
    // o->showDequeValues();
    Solution::TreeNode* tree = new Solution::TreeNode();
    // std::cout << std::endl;
    // std::cout << o->pop_front() << std::endl;
    // std::cout << o->pop_front() << std::endl;

    return 0;
}