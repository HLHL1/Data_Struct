import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

class TreeNode {
     int val = 0;
     TreeNode left = null;
     TreeNode right = null;

     public TreeNode(int val) {
         this.val = val;

     }

 }

  class Solution {
    private boolean ifSubTree(TreeNode root1,TreeNode root2){
        //??????
        if(root2==null){
            return true;
        }
        //??????,??????????
        if(root1==null){
            return false;
        }
       //????????????????
        if(root1.val!=root2.val){
            return false;
        }
        return ifSubTree(root1.left,root2.left)&&ifSubTree(root1.right,root2.right);
    }
    public boolean HasSubtree(TreeNode root1, TreeNode root2) {
        if(root1==null||root2==null){
            return false;
        }
        Queue<TreeNode> queue=new LinkedList<>();
        queue.offer(root1);
        boolean result=false;
        while(!queue.isEmpty()){
            TreeNode top=queue.poll();
            if(top.val==root2.val){
                result=ifSubTree(top,root2);
            }
            if(top.left!=null)queue.offer(top.left);
            if(top.right!=null)queue.offer(top.right);
        }
        return result;
    }
}
public class test{
    public static void main(String[] args) {
        TreeNode root1=new TreeNode(1);
        root1.left=new TreeNode(2);
        root1.right=new TreeNode(3);
        root1.left.left=new TreeNode(4);
        root1.left.right=new TreeNode(5);

        TreeNode root2=new TreeNode(1);
        root2.left=new TreeNode(7);
        root2.right=new TreeNode(3);
        root2.left.left=new TreeNode(4);
        root2.left.right=new TreeNode(5);

       Solution solution=new Solution();
       boolean ans=solution.HasSubtree(root1,root2);
        System.out.println(ans);
    }
}