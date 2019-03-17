package hhh.Test;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;


class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }

class Solution {
    public TreeNode reConstructBinaryTree(int[] pre, int[] in) {

        return createTree(pre,0,pre.length-1,in,0,in.length-1);

    }

    public TreeNode createTree(int[] pre, int preStart, int preEnd, int[] in, int inStart, int inEnd) {

        //????????
        if(preStart>preEnd||inStart>inEnd)return null;
        //???????
        TreeNode treeNode=new TreeNode(pre[preStart]);
        treeNode.right=null;
        treeNode.left=null;
        //?????????????i???
        for(int i=0;i<=inEnd;i++){
            if(in[i]==pre[preStart]){
                treeNode.left=createTree(pre,preStart+1,preStart+i-inStart,in,inStart,i-1);
                treeNode.right=createTree(pre,preStart+i-inStart+1,preEnd,in,i+1,inEnd);
            }
        }
        return treeNode;
    }

    public void printTree(TreeNode root){
        if(root==null)return;
        System.out.println(root.val);
        printTree(root.left);
        printTree(root.right);
    }
}
 public class test {

    public static void main(String[] args) {
        int[] pre={1,2,4,7,3,5,6,8};
        int[] in={4,7,2,1,5,3,8,6};
        Solution solution=new Solution();
        solution.printTree(solution.reConstructBinaryTree(pre,in));
    }
}

