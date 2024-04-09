#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class AckermannTree {
private:
    unordered_map<int, TreeNode*> memo;

public:
    AckermannTree() {}

    TreeNode* createNode(int m, int n) {
        int key = (m << 16) | n;
        if (memo.find(key) != memo.end())
            return memo[key];

        TreeNode* newNode = new TreeNode(0);
        if (m == 0)
            newNode->value = n + 1;
        else if (n == 0)
            newNode->value = createNode(m - 1, 1)->value;
        else {
            TreeNode* leftNode = createNode(m, n - 1);
            TreeNode* rightNode = createNode(m - 1, leftNode->value);
            newNode->value = rightNode->value;
            newNode->left = leftNode;
            newNode->right = rightNode;
        }
        memo[key] = newNode;
        return newNode;
    }

    void printEdges(TreeNode* root) {
        if (root == nullptr)
            return;
        vector<TreeNode*> path;
        getPath(root, path);
        for (int i = 0; i < path.size() - 1; ++i) {
            cout << path[i]->value << " -> " << path[i + 1]->value << endl;
        }
    }

    void getPath(TreeNode* node, vector<TreeNode*>& path) {
        if (node == nullptr)
            return;
        path.push_back(node);
        if (node->left != nullptr)
            getPath(node->left, path);
        if (node->right != nullptr)
            getPath(node->right, path);
    }

    void deleteTree(TreeNode* root) {
        if (root == nullptr)
            return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    ~AckermannTree() {
        for (auto it = memo.begin(); it != memo.end(); ++it) {
            deleteTree(it->second);
        }
    }
};

int main() {
    AckermannTree tree;
    int m, n;
    cout << "Enter values for m and n: ";
    cin >> m >> n;
    TreeNode* root = tree.createNode(m, n);
    cout << "Edges of the Ackermann tree:" << endl;
    tree.printEdges(root);

    return 0;
}
