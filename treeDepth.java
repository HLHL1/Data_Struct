/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
  
        public static int ans=0;
        public int TreeDepth(TreeNode root) {
            if(root==null){
                return 0;
            }
            int left=TreeDepth(root.left)+1;
            int right=TreeDepth(root.right)+1;
           return ans=Math.max(left,right);
        }
    
}