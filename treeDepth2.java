
import java.util.LinkedList;
import java.util.Queue;
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
  
        public  int ans=0;
        public int TreeDepth(TreeNode root) {
            if(root==null){
                return 0;
            }
            Queue<TreeNode> queue=new LinkedList<>();
            queue.offer(root);
            int start=0,end=1;
            while(!(queue.isEmpty())){
                TreeNode first=queue.poll();
                start++;
                if(first.left!=null)queue.offer(first.left);
                if(first.right!=null)queue.offer(first.right);
                if(start==end){
                    ans++;
                    start=0;
                    end=queue.size();
                }
            }
            return ans;
        }
    
}