using Eat_Sleep_Code.Trees;
using System;

namespace Eat_Sleep_Code.Test
{
    public class MainTest
    {
        public static void Main(string[] args)
        {
            BinaryTreetest();

            Console.ReadKey();
        }

        #region Binary Tree Test
        private static void BinaryTreetest()
        {
            var tree = new BinaryTree();
            var rnd = new Random();
            for (int i = 0; i < 10; i++)
            {
                tree.root = tree.insert(i, tree.root);
            }
            tree.inorderTraversal(tree.root);
            Console.WriteLine(tree.search(7, tree.root) != null);
        }
        #endregion
    }
}
