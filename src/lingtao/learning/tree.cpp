#include <iostream>
#include <queue>

class TreeNode {
public:
    TreeNode(int v) {
        value = v;
    }

    int value;
    TreeNode* left; 
    TreeNode* right;
};

void postOrder(TreeNode* node) {
    if (node->left != nullptr) {
        postOrder(node->left);
    }
    if (node->right != nullptr) {
        postOrder(node->right);
    }
    std::cout<<node->value<<std::endl;
}

void firstOrder(TreeNode* node) {
    if (node != nullptr) {
        std::cout<<node->value<<std::endl;
    }

    if (node->left != nullptr) {
        firstOrder(node->left);
    }

    if (node->right != nullptr) {
        firstOrder(node->right);
    }
}

void midOrder(TreeNode * node) {
    if (node->left != nullptr) {
        midOrder(node->left);
    }

    std::cout<<node->value<<std::endl;

    if (node->right != nullptr) {
        midOrder(node->right);
    }
}

void levelOrder(TreeNode* root) {
    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        std::cout<<node->value<<std::endl;
        if (node->left != nullptr) {
            queue.push(node->left);
        }
        if (node->right != nullptr) {
            queue.push(node->right);
        }
    }
}


int main() {
    TreeNode* root = new TreeNode(0);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    node3->left = node7;
    node3->right = node8;

    //levelOrder(root);
    //firstOrder(root);
    //midOrder(root);
    postOrder(root);
    return 0;

}