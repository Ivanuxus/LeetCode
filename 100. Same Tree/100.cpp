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

    bool inorderTraversal(TreeNode *tree1, TreeNode *tree2)
    {
        if(tree1->val != tree2->val)
        {
            return false;
        }
        if(tree1->left ==  nullptr && tree2->left !=  nullptr)
        {
            return false;
        }
        if(tree1->left !=  nullptr && tree2->left ==  nullptr)
        {
            return false;
        }
        if(tree1->right ==  nullptr && tree2->right !=  nullptr)
        {
            return false;
        }
        if(tree1->right !=  nullptr && tree2->right ==  nullptr)
        {
            return false;
        }
        std::cout<< tree1->val<< " "<< tree2->val;
        int result1 = tree1->val;
        int result2 = tree2->val;
        inorderTraversal(tree1->left, tree2->left);
        inorderTraversal(tree1->right, tree2->right);
        return true;
    };

    TreeNode *treeMaker(std::vector<std::string> elem)
    {
        Solution::TreeNode *tree = new Solution::TreeNode();
        Solution::TreeNode *headOfTree = tree;
        int i = 0;
        int counter;
        resetDequeValues();

        std::cout << std::endl;
        for (int i = 0; i < elem.size(); i++)
        {
            std::cout << elem[i] << " have " << i << " as index" << std::endl;
        }
        std::cout << std::endl;

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
                if (j >= elem.size())
                {
                    return headOfTree;
                }
                if (counter == 0)
                {
                    if (elem[j] != "null")
                    {
                        tree->left = new TreeNode(stoi(elem[j]));
                        putToDeque(tree->left);
                    }
                    if (elem[j] == "null")
                    {
                    }
                }
                if (counter == 1)
                {
                    if (elem[j] != "null")
                    {
                        tree->right = new TreeNode(stoi(elem[j]));
                        putToDeque(tree->right);
                        if (i == 0)
                        {
                            popFrontFromDeque();
                        }
                    }

                    if (elem[j] == "null")
                    {
                    }
                    i = j;
                }
                j++;
                counter += 1;
            }
            tree = popFrontFromDeque();
        }
        resetDequeValues();
        return headOfTree;
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
            std::cout << std::endl
                      << "There are no elements here!" << std::endl;
        }
        return nullptr;
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
            std::cout << std::endl
                      << "There are no elements here!" << std::endl;
        }
        return nullptr;
    }
    Solution::TreeNode *showFrontFromDeque()
    {
        try
        {
            if (temp_pos > pos)
                throw "EMPTY!";
            Solution::TreeNode *temp_pos_elem = a[temp_pos];
            return temp_pos_elem;
        }
        catch (...)
        {
            std::cout << std::endl
                      << "There are no elements here!" << std::endl;
        }
        return nullptr;
    }
    void showDequeValues()
    {
        std::cout << std::endl;
        for (int i = temp_pos; i <= pos; i++)
        {
            std::cout << a[i] << " ";
        }
    }
    void resetDequeValues()
    {
        pos = -1;
        temp_pos = 0;
        for (int i = 0; i <= 9999; i++)
        {
            a[i] = nullptr;
        }
    }

private:
    int pos = -1;
    int temp_pos = 0;
    Solution::TreeNode *a[9999];
};
int main()
{
    std::vector<int> result;
    Solution *o = new Solution;
    std::vector<std::string> elem1 = {"1", "null", "2", "null", "3"};
    std::vector<std::string> elem2 = {"1", "null", "2", "null", "3"};
    Solution::TreeNode *tree1 = o->treeMaker(elem1);
    Solution::TreeNode *tree2 = o->treeMaker(elem2);
    o->inorderTraversal(tree1, tree2);
    return 0;
}
