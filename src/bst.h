////////////////////////////////////////////////////////////////////////////////////
// BINARY SEARCH TREE
// Author: Pranshu Gupta

class BST {
    public:
        NODE* ROOT;
        BST(NODE* N);
        // crud operations
        NODE* insert (NODE* R, double key);
        NODE* mirror(NODE* node);
        // traversal
        void inorder (NODE* N);
        void postorder (NODE* N);
};

BST::BST (NODE * N) {
    ROOT = N; 
}

NODE* BST::insert (NODE* R, double key) {    
    if (R == NULL) {
        // create and return the node here
        NODE* node = new NODE;
        node->value = key;
        node->left = NULL;
        node->right = NULL;        
        return node;
    }

    if (R->value <= key) {
        R->right = insert(R->right, key);
    } else {
        R->left = insert(R->left, key);
    }

    return R;
}

void BST::inorder (NODE* N) {
    if (N != NULL) {
        if (N->left != NULL)
            inorder(N->left);
        cout << N->value << " ";
        if (N->right != NULL)
            inorder(N->right);
    }
    return;
}

void BST::postorder (NODE* N) {
    if (N != NULL) {
        if (N->left != NULL)
            postorder(N->left);
        if (N->right != NULL)
            postorder(N->right);
        cout << N->value << " ";
    }
    return;
}

NODE* BST::mirror(NODE* node) {
    if (node != NULL) {
        NODE* temp = node->left;
        node->left = mirror(node->right);
        node->right = mirror(temp);
    }
    return node;
}