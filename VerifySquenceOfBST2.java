
import java.util.*;


class Solution {
    private List<Integer> sequence=new Vector<>();

    public boolean VerifySquenceOfBST(Vector<Integer> sequence) {
        this.sequence = sequence;
        if(sequence.size()==0){
            return false;
        }
        return After(sequence,0,sequence.size()-1);
    }
    public boolean After(Vector sequence,int left,int right){
       int n=sequence.size();
       if(n==0||n==1){
           return true;
       }
       int root=sequence.indexOf(right);
       List<Integer> leftArr=new Vector<Integer>();
       List<Integer>rightArr=new Vector<Integer>();
       int i=0;
       for(i=left;i<right;i++){
           if(sequence.indexOf(i)<=root){
               leftArr.add(sequence.indexOf(i));
           }else{
               break;
           }
       }
       for(int j=i;j<right;j++){
           if(sequence.indexOf(i)>root){
               rightArr.add(sequence.indexOf(i));
           }else{
               return false;
           }
       }
       boolean l=After((Vector) leftArr,0,leftArr.size()-1);
       boolean r=After((Vector)rightArr,0,rightArr.size()-1);
       return l&&r;
    }
}
public class test{
    public static void main(String[] args) {

       Solution solution=new Solution();
       Vector<Integer> v=new Vector<>();
       v.add(5);
       v.add(7);
       v.add(6);
        v.add(9);
        v.add(11);
        v.add(10);
        v.add(8);
        System.out.println(solution.VerifySquenceOfBST(v));

    }
}