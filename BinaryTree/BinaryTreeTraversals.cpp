#include <iostream>
#include <queue>
using namespace std;

// Definition of a Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree() {
    cout << "Enter the root node value: ";
    int rootVal;
    cin >> rootVal;
    if (rootVal == -1) return NULL; // Special value for NULL

    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        // Input for the left child
        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        int leftVal;
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        // Input for the right child
        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        int rightVal;
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

void printPreorder(Node* root) {
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostOrder(Node* root) {
   if(root == NULL){
        return;
    }
    printPreorder(root->left);
    printPreorder(root->right);
    cout<<root->data<<" ";
}

void printInOrder(Node* root) {
   if(root == NULL){
        return;
   }
   printInOrder(root->left);
   cout<<root->data<<" ";
   printInOrder(root->right);
}

void printLevelOrderTraversal(Node* root){
    if(root == NULL){
        cout<<"Loop is empty \n";
        return;
    }
    queue<Node*> q; // queue use korchi for dyanmic data type
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout<<current->data<<" ";
        // left er number push korbo jodi thaake
        if(current->left != NULL){
            q.push(current -> left);
        }
        // right er ta after left
        if(current->right != NULL){
            q.push(current -> right);
        }
    }
    cout<<"\n";
}

void IterativePreOrder(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* current = st.top();
        st.pop();
        cout<<current->data<<" ";
        // Push right child first, so left child is processed first
        if(current->right) st.push(current->right);
        if(current->left) st.push(current->left);
    }
} // similarly baaki iterative gulo kaaj korbe 
int main() {
    Node* root = buildTree(); // Build the tree dynamically
    cout << "PreOrder Traversal of the tree: ";
    printPreorder(root);
    cout<<endl;
    cout << "InOrder Traversal of the tree: ";
    printInOrder(root); 
    cout<<endl;
    cout << "PostOrder Traversal of the tree: ";
    printPostOrder(root); 
    cout<<endl;
    cout << "LevelOrder Traversal of the tree: ";
    printLevelOrderTraversal(root);
    cout<<endl;
    return 0;
}