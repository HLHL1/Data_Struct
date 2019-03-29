public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
        if(sequence.length==0){
            return false;
        }
        return After(sequence,0,sequence.length-1);
       
    }
    public boolean After(int [] sequence,int left,int right){
        if(left>=right){
            return true;
        }
        int root=sequence[right];
        int flag=0;
        int index=0;
        for(int i=left;i<right;i++){
            if(flag==0&&sequence[i]>root){
                flag=1;
                index=i;
            }
            if(flag==1&&sequence[i]<root){
                return false;
            }
        }
        boolean l=true,r=true;
        if(index>left) {
          l = After(sequence, left, index-1);
        }
        if(index<right) {
          r = After(sequence, index, right-1);
        }
        return l&&r;
    }
}