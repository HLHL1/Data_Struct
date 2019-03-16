import java.util.Stack;

class Solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();

    public void push(int node) {
        stack1.push(node);
    }
    public int pop() {

        if(stack2.isEmpty()){
            if(stack1.isEmpty()){
                return 0;
            }
            while(!(stack1.isEmpty())){
                stack2.push(stack1.pop());
            }
            return stack2.pop();
        }else{
            return stack2.pop();
        }
    }
}
public class Interview {
    public static void main(String[] args) {

        Solution solution=new Solution();
        solution.push(1);
        System.out.println(solution.pop());
        solution.push(2);
        System.out.println(solution.pop());


    }
}

