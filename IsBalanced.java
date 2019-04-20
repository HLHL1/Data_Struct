import java.util.*;
public class Solution {
    public int dethp(TreeNode root,int h){
        if(root==null){
            return h;
        }
        int left_h=dethp(root.left,h+1);
        int right_h=dethp(root.right,h+1);
        return Math.max(left_h,right_h);
    }
    public boolean IsBalanced_Solution(TreeNode root) {
        if(root==null){
            return true;
        }
        int d1=dethp(root.left,0);
        int d2=dethp(root.right,0);
        int d=d1-d2;
        if(d>1||d<-1){
            return false;
        }else{
            return IsBalanced_Solution(root.left)&&IsBalanced_Solution(root.right);
        }
    }
}