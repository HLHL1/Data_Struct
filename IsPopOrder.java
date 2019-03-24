import java.util.Stack;


class Solution {
    Stack<Integer> stack=new Stack<>();
    public boolean IsPopOrder(int [] pushA,int [] popA) {
        int j=0;
        for(int i=0;i<popA.length;i++){
            while (j<pushA.length&&popA[i]!=pushA[j]){
                stack.push(pushA[j]);
                j++;
            }
            if(j>=pushA.length){
                if(popA[i]!=stack.peek()){
                    return false;
                }
                stack.pop();
            }
            j++;
        }
        return true;
    }
}
public class test{
    public static void main(String[] args) {

       Solution solution=new Solution();
       int[] a={1,2,3,4,5};
       int[] b={4,5,3,2,1};
        System.out.println(solution.IsPopOrder(a,b));
    }
}