#include <iostream>
#include <string>

class TreeNode
{
public:
    std::string data;
    int count;
    TreeNode *left, *right;
    TreeNode(std::string s, TreeNode *l = nullptr, TreeNode *r = nullptr) : data{s}, left{l}, right{r}, count{1} {}
};

/*
Insert a string into the tree. If the string does not extist in the binary search tree
then create a new entry, else increment the count of the existing entry.
*/
TreeNode *insert(TreeNode *tree, std::string s)
{
    if (tree->data == s)
    {
        tree->count++;
    }
    else
    {
        TreeNode *new_tree = new TreeNode(s);

        if (tree->left == nullptr)
        {
            tree->left = new_tree;
        }
        else if (tree->right == nullptr)
        {
            tree->right = new_tree;
        }
        else
        {
            if (tree->count > new_tree->count)
            {
                insert(tree->left, s);
            }
            else
            {
                insert(tree->right, s);
            }
        }
    }

    return tree;
}

/*
Return the number of times the string has been inserted.
*/
int count(TreeNode *tree, std::string s)
{
    if (tree == nullptr)
    {
        return 0;
    }
    else if (tree->data == s)
    {
        return tree->count;
    }
    else if (tree->left == nullptr && tree->right == nullptr)
    {
        return 0;
    }

    if (tree->left == nullptr)
    {
        return count(tree->right, s);
    }
    else if (tree->right == nullptr)
    {
        return count(tree->left, s);
    }

    return count(tree->left, s) + count(tree->right, s);
}

int main()
{
    TreeNode *the_tree = new TreeNode(""); // The root of the tree will be the empty string.
    the_tree = insert(the_tree, "middle");
    the_tree = insert(the_tree, "ant");
    the_tree = insert(the_tree, "dog");
    the_tree = insert(the_tree, "greetings");
    the_tree = insert(the_tree, "cat");
    the_tree = insert(the_tree, "dog");
    the_tree = insert(the_tree, "rhinoceros");
    the_tree = insert(the_tree, "dog");

    std::cout << "dog appears " << count(the_tree, "dog") << " times (should be 3)" << std::endl;
    std::cout << "cat appears " << count(the_tree, "cat") << " times (should be 1)" << std::endl;
    std::cout << "AHeta5h535q!# appears " << count(the_tree, "AHeta5h535q!#") << " times (should be 0)" << std::endl;

    return 0;
}