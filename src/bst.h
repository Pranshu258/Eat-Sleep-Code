////////////////////////////////////////////////////////////////////////////////////
// BINARY SEARCH TREE
// Author: Pranshu Gupta

struct NODE {
    double value;
    NODE* left;
    NODE* right;
};

class BST {
    public:
        NODE* ROOT;
        BST(NODE* N);
        // crud operations
        NODE* max(NODE* R);
        NODE* min(NODE* R);
        NODE* insert (NODE* R, double key);
        NODE* search(NODE* R, double key);
        NODE* mirror(NODE* node);
        // traversal
        void inorder (NODE* N);
        void postorder (NODE* N);
        void preorder (NODE* N);
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

NODE* BST::search(NODE* R, double key) {
    if (R != NULL) {
        if (R->value == key) {      
            return R;
        } else if (R->value < key) {
            return search(R->right, key);
        } else {
            return search(R->left, key);
        } 
    } else {
        return R;
    } 
}

NODE* BST::max(NODE* R) {
    NODE* n = R;
    while (n->right != NULL) {
        n = n->right;
    }
    return n;
}

NODE* BST::min(NODE* R) {
    NODE* n = R;
    while (n->left != NULL) {
        n = n->left;
    }
    return n;
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

void BST::preorder (NODE* N) {
    if (N != NULL) {
        cout << N->value << " ";
        if (N->left != NULL)
            preorder(N->left);
        if (N->right != NULL)
            preorder(N->right);
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

