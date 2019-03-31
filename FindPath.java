import java.util.ArrayList;
 class TreeNode {
     int val = 0;
     TreeNode left = null;
     TreeNode right = null;

     public TreeNode(int val) {
         this.val = val;

     }

 }

 class Solution {
     ArrayList<ArrayList<Integer>> arrayLists=new ArrayList<>();
     ArrayList<Integer> a=new ArrayList<>();
     public void FindPathTmp(TreeNode root,int target,int sum){
         int Sum=sum+root.val;
         a.add(root.val);
        if(Sum==target&&root.left==null&&root.right==null){
           arrayLists.add(new ArrayList<>(a));
        }
        if(root.left!=null) {
            FindPathTmp(root.left, target, Sum);
        }
        if(root.right!=null) {
            FindPathTmp(root.right, target, Sum);
        }
        a.remove(a.size()-1);
     }
    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {

        if(root==null){
            return null;
        }
       FindPathTmp(root,target,0);
       return arrayLists;
    }
}
public class test{
    public static void main(String[] args) {

        TreeNode root=new TreeNode(10);
        root.left=new TreeNode(5);
        root.right=new TreeNode(12);
        root.left.left=new TreeNode(4);
        root.left.right=new TreeNode(7);
        Solution solution=new Solution();
        for(ArrayList<Integer> tmp:solution.FindPath(root,22)){
            for(int i=0;i<tmp.size();i++){
                System.out.print(tmp.get(i)+" ");
            }
            System.out.println();
        }
    }
}