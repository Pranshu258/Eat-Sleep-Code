using System;

namespace Eat_Sleep_Code.Trees
{
    class BinaryTree: Tree
    {
        public Node insert (double key, Node node)
        {
            if (node != null)
            {
                if (key <= node.key)
                {
                    node.left = insert(key, node.left);
                    node.size = node.size + 1;
                } 
                else
                {
                    node.right = insert(key, node.right);
                    node.size = node.size + 1;
                }
            }
            else
            {
                node = new Node();
                node.key = key;
                node.left = null;
                node.right = null;
                node.size = 1;
            }
            return node;
        }

        public Node search(double key, Node node)
        {
            if (node != null )
            {
                if (key == node.key)
                {
                    return node;
                }
                else if (key < node.key)
                {
                    return search(key, node.left);
                }
                else
                {
                    return search(key, node.right);
                }
            }
            else
            {
                return null;
            }

        }

        public void inorderTraversal (Node node)
        {
            if (node.left != null)
            {
                inorderTraversal(node.left);
            }
            Console.WriteLine(string.Format("Value: {0}", node.key));
            if (node.right != null)
            {
                inorderTraversal(node.right);
            }
        }

        public Node minimum(Node node)
        {
            if (node != null)
            {
                if (node.left != null)
                {
                    return minimum(node.left);
                }
                else
                {
                    return node;
                }
            }
            return null;
        }

        public Node maximum(Node node)
        {
            if (node != null)
            {
                if (node.right != null)
                {
                    return maximum(node.right);
                }
                else
                {
                    return node;
                }
            }
            return null;
        }

    }
}
