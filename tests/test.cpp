#include "../src/header.h"
#include "../src/bst.h"
#include "../src/random.h"

// Test for BST Implementation
void bsttest() {
    int N;
    cout << "Enter the number of nodes: ";
    cin >> N;
    list<double> num = gen_unirandreal(N, 1, 100);
    BST T(NULL);
    for (list<double>::iterator i = num.begin(); i != num.end(); i++) {
        T.ROOT = T.insert(T.ROOT, *i);
    }
    T.inorder(T.ROOT);
    cout << endl;
    T.preorder(T.ROOT);
    cout << endl;
    // T.ROOT = T.mirror(T.ROOT);
    // T.inorder(T.ROOT);
    // cout << endl;
}

int main () {
    bsttest();
    return 0;
}