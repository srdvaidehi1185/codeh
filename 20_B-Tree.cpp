#include <iostream>
using namespace std;

#define T 2

struct BTreeNode {

    int keys[2 * T - 1];

    BTreeNode* child[2 * T];

    int n;

    bool leaf;

    BTreeNode(bool leaf) {

        this->leaf = leaf;

        n = 0;

        for(int i = 0; i < 2 * T; i++) {

            child[i] = NULL;
        }
    }
};

void splitChild(BTreeNode* parent, int i, BTreeNode* y) {

    cout << "\nNode Splitting Performed";

    cout << "\nKey Promoted : " << y->keys[T - 1] << endl;

    BTreeNode* z = new BTreeNode(y->leaf);

    z->n = T - 1;

    for(int j = 0; j < T - 1; j++) {

        z->keys[j] = y->keys[j + T];
    }

    if(!y->leaf) {

        for(int j = 0; j < T; j++) {

            z->child[j] = y->child[j + T];
        }
    }

    y->n = T - 1;

    for(int j = parent->n; j >= i + 1; j--) {

        parent->child[j + 1] = parent->child[j];
    }

    parent->child[i + 1] = z;

    for(int j = parent->n - 1; j >= i; j--) {

        parent->keys[j + 1] = parent->keys[j];
    }

    parent->keys[i] = y->keys[T - 1];

    parent->n++;
}

void insertNonFull(BTreeNode* node, int key) {

    int i = node->n - 1;

    if(node->leaf) {

        while(i >= 0 && key < node->keys[i]) {

            node->keys[i + 1] = node->keys[i];

            i--;
        }

        node->keys[i + 1] = key;

        node->n++;
    }

    else {

        while(i >= 0 && key < node->keys[i]) {

            i--;
        }

        i++;

        if(node->child[i]->n == 2 * T - 1) {

            splitChild(node, i, node->child[i]);

            if(key > node->keys[i]) {

                i++;
            }
        }

        insertNonFull(node->child[i], key);
    }
}

BTreeNode* insert(BTreeNode* root, int key) {

    if(root == NULL) {

        root = new BTreeNode(true);

        root->keys[0] = key;

        root->n = 1;

        return root;
    }

    if(root->n == 2 * T - 1) {

        BTreeNode* s = new BTreeNode(false);

        s->child[0] = root;

        splitChild(s, 0, root);

        int i = 0;

        if(key > s->keys[0]) {

            i++;
        }

        insertNonFull(s->child[i], key);

        return s;
    }

    insertNonFull(root, key);

    return root;
}

void traverse(BTreeNode* root) {

    if(root != NULL) {

        int i;

        for(i = 0; i < root->n; i++) {

            traverse(root->child[i]);

            cout << root->keys[i] << " ";
        }

        traverse(root->child[i]);
    }
}

int main() {

    BTreeNode* root = NULL;

    int n, value;

    cout << "Enter number of keys: ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        cout << "Enter key: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nB-Tree Traversal: ";

    traverse(root);

    return 0;
}