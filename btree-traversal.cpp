#include <iostream>
#include <vector>

struct BTreeNode {
    std::vector<int> keys;
    std::vector<const BTreeNode*> children;
};

void traverseBTree(const BTreeNode* node) {
    if (node == nullptr) {
        return;
    }

    for (std::size_t i = 0; i < node->keys.size(); ++i) {
        if (i < node->children.size()) {
            traverseBTree(node->children[i]);
        }
        std::cout << node->keys[i] << ' ';
    }

    if (node->children.size() > node->keys.size()) {
        traverseBTree(node->children.back());
    }
}

int main() {
    BTreeNode left{{5, 7}, {}};
    BTreeNode *leftPtr = &left;

    BTreeNode middle{{12, 15}, {}};
    BTreeNode *middlePtr = &middle;

    BTreeNode right{{25, 30}, {}};
    BTreeNode *rightPtr = &right;

    BTreeNode root{{10, 20}, {leftPtr, middlePtr, rightPtr}};
    BTreeNode *rootPtr = &root;

    std::cout << "B-tree in-order traversal: ";
    traverseBTree(rootPtr);
    std::cout << '\n';

    delete leftPtr;
    delete middlePtr;
    delete rightPtr;
    delete rootPtr;

    return 0;
}
