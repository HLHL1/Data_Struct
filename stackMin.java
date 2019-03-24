import java.util.Stack;


class Solution {
    private Stack<Integer> stack=new Stack();
    private Stack<Integer> stackTmp=new Stack();
    public void push(int node) {
        if(stack.isEmpty()){
            stack.push(node);
            stackTmp.push(node);
        }else {
            stack.push(node);
            if(node<stackTmp.peek()){
                stackTmp.push(node);
            }
        }
    }

    public void pop() {
        int tmp=stack.peek();
        stack.pop();
        if(tmp==stackTmp.peek()){
            stackTmp.pop();
        }
    }

    public int top() {
        return stack.peek();
    }

    public int min() {
        return stackTmp.peek();
    }
}
public class test{
    public static void main(String[] args) {

       Solution solution=new Solution();
       solution.push(4);
       solution.push(3);
       solution.push(6);
        System.out.println(solution.min());
        }
}