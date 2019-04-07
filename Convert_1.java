package hhh.Test;


import java.util.*;
import java.util.Scanner;
class TreeNode {
     int val = 0;
     TreeNode left = null;
     TreeNode right = null;

     public TreeNode(int val) {
         this.val = val;

     }
 }
class Solution {
    public TreeNode Convert(TreeNode pRootOfTree) {

        if (pRootOfTree == null) return null;

        if (pRootOfTree.left != null) {
            if (pRootOfTree.left.left == null && pRootOfTree.left.right == null)
                pRootOfTree.left.right = pRootOfTree;
            else {
                Convert(pRootOfTree.left);
                if (pRootOfTree.left.right != null)
                    pRootOfTree.left = pRootOfTree.left.right;
                pRootOfTree.left.right = pRootOfTree;
            }
        }
        if (pRootOfTree.right != null) {
            if (pRootOfTree.right.left == null && pRootOfTree.right.right == null)
                pRootOfTree.right.left = pRootOfTree;
            else {
                Convert(pRootOfTree.right);
                if (pRootOfTree.right.left != null)
                    pRootOfTree.right = pRootOfTree.right.left;
                pRootOfTree.right.left = pRootOfTree;
            }
        }

        return findLeft(pRootOfTree);
    }

    //??????????
    private TreeNode findLeft(TreeNode root) {
        while (root.left != null)
            root = root.left;
        return root;
    }
}
public class test{
    public static void main(String[] args)  {

        TreeNode treeNode=new TreeNode(4);
        treeNode.left=new TreeNode(2);
        treeNode.right=new TreeNode(6);
        treeNode.left.left=new TreeNode(1);
        treeNode.right.left=new TreeNode(5);
        Solution solution=new Solution();
        solution.Convert(treeNode);
    }
}
