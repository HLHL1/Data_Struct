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
    private TreeNode leftNode=null;
    private TreeNode rightNode=null;
    public TreeNode Convert(TreeNode pRootOfTree) {
        if(pRootOfTree==null){
            return null;
        }
        Convert(pRootOfTree.left);
        if(leftNode==null&&rightNode==null){
            leftNode=pRootOfTree;
            rightNode=pRootOfTree;
        }else{
            rightNode.right=pRootOfTree;
            pRootOfTree.left=rightNode;
            rightNode=pRootOfTree;
        }
        Convert(pRootOfTree.right);
        return leftNode;
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
