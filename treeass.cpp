#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void iterative_preorder(TreeNode* root) {
    if (root == NULL) return;

    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        TreeNode* node = nodeStack.top();
        cout << node->data << " ";
        nodeStack.pop();
        if (node->right) nodeStack.push(node->right);
        if (node->left) nodeStack.push(node->left);
    }
    cout << endl;
}

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void iterative_inorder(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

void postorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void iterative_postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode*> stk1, stk2;
    stk1.push(root);
    while (!stk1.empty()) {
        TreeNode* curr = stk1.top();
        stk1.pop();
        stk2.push(curr);
        if (curr->left) stk1.push(curr->left);
        if (curr->right) stk1.push(curr->right);
    }
    while (!stk2.empty()) {
        cout << stk2.top()->data << " ";
        stk2.pop();
    }
    cout << endl;
}

void levelorder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* front = q.front();
            q.pop();
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
            cout << front->data << " ";
        }
        cout << endl;
    }
}

int height(TreeNode* root) {
    if (root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

TreeNode* mirror(TreeNode* root) {
    if (root == NULL) return NULL;
    TreeNode* newNode = new TreeNode(root->data);
    newNode->left = mirror(root->right);
    newNode->right = mirror(root->left);
    return newNode;
}

bool checkequal(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL || root1->data != root2->data) return false;
    return checkequal(root1->left, root2->left) && checkequal(root1->right, root2->right);
}

TreeNode* clone(TreeNode* root) {
    if (root == NULL) return NULL;
    TreeNode* newNode = new TreeNode(root->data);
    newNode->left = clone(root->left);
    newNode->right = clone(root->right);
    return newNode;
}

TreeNode* createtree() {
    int value;
    cin >> value;
    if (value == -1) return NULL;
    TreeNode* newNode = new TreeNode(value);
    cout << "Left of Node (-1 if NULL) " << newNode->data << ": ";
    newNode->left = createtree();
    cout << "Right of Node (-1 if NULL) " << newNode->data << ": ";
    newNode->right = createtree();
    return newNode;
}

TreeNode* insertinBST(TreeNode* node, int key) {
    if (node == NULL) return new TreeNode(key);
    if (node->data == key) return node;
    if (node->data < key) node->right = insertinBST(node->right, key);
    else node->left = insertinBST(node->left, key);
    return node;
}

TreeNode* iterative_insertinBST(TreeNode* node, int key) {
    if (node == NULL) return new TreeNode(key);
    TreeNode* temp = node;
    TreeNode* prev = NULL;
    while (temp != NULL) {
        prev = temp;
        if (temp->data < key) temp = temp->right;
        else if (temp->data > key) temp = temp->left;
        else return node;
    }
    if (prev->data < key) prev->right = new TreeNode(key);
    else prev->left = new TreeNode(key);
    return node;
}

TreeNode* createBST() {
    cout << "Enter Root Value: ";
    int val;
    cin >> val;
    TreeNode* root = new TreeNode(val);
    while (true) {
        int x;
        cout << "Enter value to be inserted in BST (-1 if NULL): ";
        cin >> x;
        if (x == -1) break;
        insertinBST(root, x);
    }
    return root;
}

bool searchinBST(TreeNode* root, int key) {
    TreeNode* temp = root;
    while (temp != NULL) {
        if (key == temp->data) return true;
        if (key < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return false;
}

TreeNode* getSuccessor(TreeNode* curr) {
    curr = curr->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

TreeNode* deleteinBST(TreeNode* root, int x) {
    if (root == nullptr) return root;
    if (root->data > x) root->left = deleteinBST(root->left, x);
    else if (root->data < x) root->right = deleteinBST(root->right, x);
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* succ = getSuccessor(root);
        root->data = succ->data;
        root->right = deleteinBST(root->right, succ->data);
    }
    return root;
}

int search(vector<int>& inor, int value, int left, int right) {
    for (int i = left; i <= right; i++) {
        if (inor[i] == value) {
            return i;
        }
    }
    return -1;
}

TreeNode* buildtree(vector<int>& inor, vector<int>& preor, int& preindex, int left, int right) {
    if (left > right) return nullptr;
    int rootvalue = preor[preindex];
    preindex++;
    TreeNode* newnode = new TreeNode(rootvalue);
    int index = search(inor, rootvalue, left, right);
    newnode->left = buildtree(inor, preor, preindex, left, index - 1);
    newnode->right = buildtree(inor, preor, preindex, index + 1, right);
    return newnode;
}

TreeNode* createtreefrominandpost(vector<int>& inor, vector<int>& preor) {
    int preindex = 0;
    return buildtree(inor, preor, preindex, 0, preor.size() - 1);
}

int main() {
    bool flag = true;
    while (flag) {
        cout << "1-> Create a Tree     2-> Create a BST (Insert, Delete, Search)      3-> Create Binary Tree from inorder and preorder     4-> Exit" << endl << endl;
        int op;
        cout << "Enter option: ";
        cin >> op;
        if (op == 1) {
            cout << "Enter value: ";
            TreeNode* root = createtree();
            cout << endl;
            bool flag2 = true;
            while (flag2) {
                cout << "1-> Tree Traversal    2-> Cloning tree    3-> Check if two trees are equal     4-> Mirror     5-> Find Height    6-> Exit" << endl;
                int op2;
                cout << "Enter option: ";
                cin >> op2;
                if (op2 == 1) {
                    cout << "Preorder: ";
                    preorder(root);
                    cout << endl << endl;
                    cout << "Iterative Preorder: ";
                    iterative_preorder(root);
                    cout << endl << endl;
                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl << endl;
                    cout << "Iterative Inorder: ";
                    iterative_inorder(root);
                    cout << endl << endl;
                    cout << "Postorder: ";
                    postorder(root);
                    cout << endl << endl;
                    cout << "Iterative Postorder: ";
                    iterative_postorder(root);
                    cout << endl << endl;
                    cout << "Levelorder" << endl;
                    levelorder(root);
                    cout << endl << endl;
                }
                else if (op2 == 3) {
                    cout << "Enter value of root 2: ";
                    TreeNode* root2 = createtree();
                    cout << endl;
                    if (checkequal(root, root2)) {
                        cout << "TRUE" << endl;
                    } else {
                        cout << "FALSE" << endl;
                    }
                }
                else if (op2 == 2) {
                    TreeNode* root2 = clone(root);
                    cout << endl << endl;
                    cout << "Levelorder of Tree1:" << endl;
                    levelorder(root);
                    cout << endl << endl;
                    cout << "Levelorder of Tree2:" << endl;
                    levelorder(root2);
                    cout << endl << endl;
                }
                else if (op2 == 4) {
                    TreeNode* root2 = mirror(root);
                    cout << endl << endl;
                    cout << "Levelorder of Tree:" << endl;
                    levelorder(root);
                    cout << endl << endl;
                    cout << "Levelorder of mirror of Tree:" << endl;
                    levelorder(root2);
                    cout << endl << endl;
                }
                else if (op2 == 5) {
                    cout << height(root) << endl;
                }
                else if (op2 == 6) {
                    flag2 = false;
                }
            }
        }
        else if (op == 2) {
            TreeNode* root = createBST();
            bool flag3 = true;
            cout << endl << endl;
            cout << "Levelorder of Tree:" << endl;
            levelorder(root);
            cout << endl << endl;
            while (flag3) {
                cout << "1-> Insert node    2-> Delete node   3-> Search node    4-> Exit" << endl;
                int op3;
                cout << "Enter option: ";
                cin >> op3;
                if (op3 == 1) {
                    int key;
                    cout << "Enter value to insert: ";
                    cin >> key;
                    root = insertinBST(root, key);
                    cout << endl << endl;
                    cout << "Levelorder of Tree:" << endl;
                    levelorder(root);
                    cout << endl << endl;
                }
                else if (op3 == 2) {
                    int key;
                    cout << "Enter value to delete: ";
                    cin >> key;
                    root = deleteinBST(root, key);
                    cout << endl << endl;
                    cout << "Levelorder of Tree:" << endl;
                    levelorder(root);
                    cout << endl << endl;
                }
                else if (op3 == 3) {
                    int key;
                    cout << "Enter value to search: ";
                    cin >> key;
                    if (searchinBST(root, key)) {
                        cout << "Key found" << endl;
                    }
                    else {
                        cout << "Key not found" << endl;
                    }
                }
                else if (op3 == 4) {
                    flag3 = false;
                }
            }
        }
        else if (op == 3) {
            cout << "Enter number of elements in tree: ";
            int n;
            cin >> n;
            vector<int> inor(n);
            vector<int> preor(n);
            for (int i = 0; i < n; i++) {
                cout << "Enter element in inorder: ";
                cin >> inor[i];
            }
            for (int i = 0; i < n; i++) {
                cout << "Enter element in preorder: ";
                cin >> preor[i];
            }
            TreeNode* root2 = createtreefrominandpost(inor, preor);
            cout << "Levelorder of Tree:" << endl;
            levelorder(root2);
            cout << endl << endl;
        }
        else if (op == 4) {
            flag = false;
        }
    }
}