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
        std::string a[9999];
        std::string refers[9999];
        std::cout << std::endl;
        std::cout << std::endl;
        for (int i = 0; i < elem.size(); i++)
        {
            std::cout << elem[i] << " " << i;
        }
        Solution::TreeNode *tree = new Solution::TreeNode();
        Solution::TreeNode *headOfTree = tree;
        int i = 0;
        int counter;
        while (i < elem.size())
        {
            if (i == 0)
            {
                tree->val = stoi(elem[i]);
                putToDeque(tree);
            }
            counter = 0;
            int j = i + 1;
            while (counter != 2)
            {
                if (counter == 0 && elem[j] != "null")
                {
                    tree->left = new TreeNode(stoi(elem[j]));
                    putToDeque(tree->left);
                }
                if (counter == 1 && elem[j] != "null")
                {
                    tree->right = new TreeNode(stoi(elem[j]));
                    putToDeque(tree->right);
                    i = j;
                }
                j++;
            }
            tree = tree->left;
        }
    }
    void putToDeque(Solution::TreeNode *x)
    {
        pos += 1;
        a[pos] = x;
    }
    Solution::TreeNode *popFromDeque()
    {
        try
        {
            if (pos <= temp_pos)
                throw "EMPTY!";
            Solution::TreeNode *temp = a[pos];
            pos -= 1;
            return temp;
        }
        catch (...)
        {
            std::cout << "There are no elements here!" << std::endl;
        }
    }
    Solution::TreeNode *popFrontFromDeque()
    {
        try
        {
            if (temp_pos > pos)
                throw "EMPTY!";
            Solution::TreeNode *temp_pos_elem = a[temp_pos];
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
    int temp_pos = -1;
    Solution::TreeNode *a[9999];
};
int main()
{
    Solution *o = new Solution;
    std::vector<std::string> elem = {"1", "2", "3", "4", "5", "null", "8", "null", "null", "6", "7", "9"};
    Solution::TreeNode *tree = o->treeNodeMaker(elem);
    // for (int i = 0; i < elem.size(); i++)
    // {
    //     o->putToDeque(elem[i]);
    // }
    // o->showDequeValues();
    // std::cout << std::endl;
    // std::cout << o->pop_front() << std::endl;
    // std::cout << o->pop_front() << std::endl;

    return 0;
}
