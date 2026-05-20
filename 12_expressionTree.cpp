#include <iostream>
#include <stack>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* newNode(char val) {
    Node* temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool isOperator(char ch){
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

Node* constructTree(string postfix){
    stack<Node*> s;

    for(int i = 0; i<postfix.length(); i++){
        char ch = postfix[i];

        Node* temp = newNode(ch);

        if(!isOperator(ch)){
            s.push(temp);
        }
        else{
            temp->right = s.top();
            s.pop();
            temp->left = s.top();
            s.pop();

            s.push(temp);
        }
    }
    return s.top();
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    string postfix;
    cout << "Enter the postfix expression : ";
    cin >> postfix;

    Node* root = constructTree(postfix);

    cout << "Inorder Traversal of Postfix is : " ;
    inorder(root);

    return 0;
}