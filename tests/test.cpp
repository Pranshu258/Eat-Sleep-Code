#include "../src/header.h"
#include "../src/bst.h"
#include "../src/random.h"
#include "../src/graph.h"

// Test for BST Implementation
void bsttest() {
    int N;
    cout << "Enter the number of nodes: ";
    cin >> N;
    list<int> num = gen_unirandint(N, 1, 100);
    BST T(NULL);
    for (list<int>::iterator i = num.begin(); i != num.end(); i++) {
        T.ROOT = T.insert(T.ROOT, NULL, *i);
    }
    T.inorder(T.ROOT);
    cout << endl;
    // T.preorder(T.ROOT);
    // cout << endl;
    NODE* node = T.search(T.ROOT, 10);
    if (node != NULL) {
        cout << "10 found at " << node << endl;
        NODE* n = T.predecessor(node);
        if (n != NULL) {
            cout << "Pred: " << n->value << endl;
        } else {
            cout << "No predecessor" << endl;
        }
    }
    else
        cout << "10 not found" << endl;
    cout << (T.max(T.ROOT))->value << endl; 
    // T.ROOT = T.mirror(T.ROOT);
    T.inorder(T.ROOT);
    cout << endl;
}

int main () {
    bsttest();
    return 0;
}