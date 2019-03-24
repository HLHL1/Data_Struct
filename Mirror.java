class TreeNode {
     int val = 0;
     TreeNode left = null;
     TreeNode right = null;

     public TreeNode(int val) {
         this.val = val;

     }
 }
class Solution {
    public void Mirror(TreeNode root) {

        if(root==null){
            return ;
        }
        if(root.left!=null||root.right!=null){
            TreeNode tmp=root.left;
            root.left=root.right;
            root.right=tmp;
        }
        Mirror(root.left);
        Mirror(root.right);
    }
    public void print(TreeNode root){
        if(root==null){
            return ;
        }
        System.out.println(root.val);
        print(root.left);
        print(root.right);
    }
}
public class test{
    public static void main(String[] args) {
        TreeNode root1=new TreeNode(1);
        root1.left=new TreeNode(2);
        root1.right=new TreeNode(3);
        root1.left.left=new TreeNode(4);
        root1.left.right=new TreeNode(5);

       Solution solution=new Solution();
       solution.Mirror(root1);
       solution.print(root1);
        }
}