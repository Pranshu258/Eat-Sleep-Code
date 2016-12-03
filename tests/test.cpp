#include "../src/header.h"
#include "../src/bst.h"

// Test for BST Implementation
void bsttest() {
    int N;
    cout << "Enter the number of nodes: ";
    cin >> N;
    cout << "Enter the " << N << " keys: ";
    BST T(NULL);
    for (int i = 0; i < N; i++) {
        double v;
        cin >> v;
        T.ROOT = T.insert(T.ROOT, v);
        //cout << "inserted " << v << endl;
    }
    T.inorder(T.ROOT);
    cout << endl;
    T.postorder(T.ROOT);
    cout << endl;
    T.ROOT = T.mirror(T.ROOT);
    T.inorder(T.ROOT);
    cout << endl;
}

int main () {
    bsttest();
    return 0;
}