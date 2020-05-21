#include <iostream>
#define null NULL
using namespace std;

class Tree;
class TreeNode {
    friend class Tree;
public:
    int data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int data = 0, TreeNode* left = null, TreeNode* right = null) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Tree {
private:
    TreeNode* root;
public:
    Tree(int data = 0) {
        root = new TreeNode(data);
    }
    
    TreeNode *getRoot() {
        return root;
    }
    void preorder(TreeNode *root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void insertNode(TreeNode* node) {
        // 중복이 없을 때 실행
        if (searchNode(root, node->data) == null) {
            TreeNode* parent = null;
            TreeNode* current = root;
            while(current != null) {
                parent = current;
                if (current->data > node->data) {
                    current = current->left;
                } else {
                    current = current-> right;
                }
            }
            if (node->data < parent->data) {
                parent->left = node;
            } else {
                parent->right = node;
            }
        }
    }
    void deleteNode(int data) {
        // 탐색 먼저
        TreeNode *parent = null, *current = root, *child;
        while(current != null && current->data != data) {
            parent = current;
            current = (current->data > data) ? current->left: current->right;
        }
        if (current) {
            if (current->left == null && current->right == null) {
                if (parent) {
                    if (parent->left == current) {
                        parent->left = null;
                    } else {
                        parent->right = null;
                    }
                } else {
                    // 루트 노드 삭제
                }
            } else if ((current->left == null) || (current->right == null)) {
                child = (current->left != null) ? current->left:current->right;
                if (parent) {
                    if (parent->left == current) {
                        parent->left = child;
                    } else {
                        parent->right = child;
                    }
                } else {
                    // 루트 노드 삭제
                }
            } else {
                TreeNode *suc_p = current, *suc = current->right;
                while(suc->left != null) {
                    suc_p = suc;
                    suc = suc->left;
                }
                if (suc_p->left == suc) {
                    suc_p->left = suc->right;
                } else {
                    // ?
                }
                current->data = suc->data;
                current = suc;
            }
        }
        free(current);
    }
    TreeNode* searchMin(TreeNode *current) {
        while(current->left != null) {
            current = current->left;
        }
        return current;
    }
    
    TreeNode* searchMax(TreeNode *current) {
        while(current->right != null) {
            current = current->right;
        }
        return current;
    }
    
    TreeNode* searchNode(TreeNode* current, int data) {
        while (current != null && current->data !=  data) {
            current = (current->data < data) ? current->left: current->right;
        }
        return current;
    }
    
    TreeNode* successor(TreeNode *current) {
        if (current->right != null) {
            return searchMin(current->right);
        }
        // 왼쪽으로 계속 올라가다 맥스일때 오른쪽부모
        return null;
    }
};
 
int main(void) {
    
    Tree tree(6);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(4);
    tree.insertNode(node1);
    tree.insertNode(node2);
    tree.preorder(tree.getRoot());
    return 0;
}
