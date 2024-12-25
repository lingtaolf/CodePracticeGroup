#include "tree.cpp"

TreeNode* search_tree(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr; 
    }

    TreeNode * currentNode = root;

    while (currentNode != nullptr) {
        if (currentNode->value == val) {
            return currentNode;
        }

        if (currentNode->value < val)  { 
            currentNode = currentNode->right

        }
    }


}
