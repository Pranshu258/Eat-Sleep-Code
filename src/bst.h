////////////////////////////////////////////////////////////////////////////////////
// BINARY SEARCH TREE
// Author: Pranshu Gupta

struct NODE {
    double value;
    NODE* left;
    NODE* right;
    NODE* parent;
};

class BST {
    public:
        NODE* ROOT;
        BST(NODE* N);
        // crud operations
        NODE* max(NODE* R);
        NODE* min(NODE* R);
        NODE* predecessor (NODE* R);
        NODE* successor (NODE* R);
        NODE* insert (NODE* R, NODE* P, double key);
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

NODE* BST::insert (NODE* R, NODE* P, double key) {    
    if (R == NULL) {
        // create and return the node here
        NODE* node = new NODE;
        node->value = key;
        node->left = NULL;
        node->right = NULL;
        node->parent = P;        
        return node;
    }

    if (R->value <= key) {
        R->right = insert(R->right, R, key);
    } else {
        R->left = insert(R->left, R, key);
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

NODE* BST::max (NODE* R) {
    NODE* n = R;
    while (n->right != NULL) {
        n = n->right;
    }
    return n;
}

NODE* BST::min (NODE* R) {
    NODE* n = R;
    while (n->left != NULL) {
        n = n->left;
    }
    return n;
}

NODE* BST::predecessor (NODE* R) {
    NODE* n = R;
    if (n == NULL) {
        return NULL;
    }
    if (n->left != NULL) {
        return max(n->left);
    } else {
        if (n->parent != NULL) {
            while (n != (n->parent)->right) {
                n = n->parent;
                if (n->parent == NULL) {
                    break;
                }
            }
        }
        return n->parent;
    }
}

NODE* BST::successor (NODE* R) {
    NODE* n = R;
    if (n == NULL) {
        return NULL;
    }
    if (n->right != NULL) {
        return min(n->right);
    } else {
        if (n->parent != NULL) {
            while (n != (n->parent)->left) {
                n = n->parent;
                if (n->parent == NULL) {
                    break;
                }
            }
        }
        return n->parent;
    }
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

