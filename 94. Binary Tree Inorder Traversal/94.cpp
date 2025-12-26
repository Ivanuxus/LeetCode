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
        // for (int i = 0; i <= elem.size(); i++)
        // {
        //     std::cout << elem[i] << " " << i;
        // }
        Solution::TreeNode *tree = new Solution::TreeNode();
        int i = 0;
        int counter;
        while (i < elem.size())
        {
            TreeNode *head = tree;
            int counter = 0;
            int j = i;
            while (counter != 3 && j <= elem.size())
            {
                putToDeque(elem[j], a);
                counter += 1;
                j++;
            }
            showDequeValues();
            if(counter == 3)
            {
                tree->val = stoi(elem[j-2]);
                tree->left = new Solution::TreeNode(stoi(elem[j-1]));
                tree->right = new Solution::TreeNode(stoi(elem[j]));
                popFrontFromDeque(a);
                i += 3;
                counter = 0;
            }
            showDequeValues();
        }
    }
    void putToDeque(std::string x, std::string a[9999])
    {
        pos += 1;
        a[pos] = x;
    }
    std::string popFromDeque(std::string a[9999])
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
    std::string popFrontFromDeque(std::string a[9999])
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
