#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
};

Node* newNode(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int val) {
    if(root == NULL){
        return newNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(Node* root) {

    stack<Node*> st;
    Node* temp = root;

    while (temp != NULL || !st.empty()) {

        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }

        temp = st.top();
        st.pop();

        cout << temp->data << " ";

        temp = temp->right;
    }
}

// Iterative Preorder
void preorder(Node* root) {

    if (root == NULL)
        return;

    stack<Node*> st;

    st.push(root);

    while (!st.empty()) {

        Node* temp = st.top();
        st.pop();

        cout << temp->data << " ";

        if (temp->right)
            st.push(temp->right);

        if (temp->left)
            st.push(temp->left);
    }
}

// Iterative Postorder
void postorder(Node* root) {

    if (root == NULL)
        return;

    stack<Node*> st1, st2;

    st1.push(root);

    while (!st1.empty()) {

        Node* temp = st1.top();
        st1.pop();

        st2.push(temp);

        if (temp->left)
            st1.push(temp->left);

        if (temp->right)
            st1.push(temp->right);
    }

    while (!st2.empty()) {

        cout << st2.top()->data << " ";

        st2.pop();
    }
}

int main() {
    Node* root = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++){

        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nIterative Inorder Traversal: ";
    inorder(root);

    cout << "\nIterative Preorder Traversal: ";
    preorder(root);

    cout << "\nIterative Postorder Traversal: ";
    postorder(root);

    return 0;
}