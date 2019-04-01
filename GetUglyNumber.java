class Solution {
     public int GetUglyNumber_Solution(int index) {
         if (index < 1) {
             return 0;
         }
         int ans = 0;
         int num = 1;
         while (true) {
             int flag = num;
                 while (flag % 2 == 0) {
                     flag /= 2;
                 }
                 while (flag % 3 == 0) {
                     flag /= 3;
                 }
                 while(flag % 5 == 0) {
                     flag /= 5;
                 }

             if (flag ==1) {
                 ans++;
                 if (ans == index) {
                     return num;
                 }
             }
             num++;
         }
     }
 }
public class test{
    public static void main(String[] args) {
        Solution solution=new Solution();
        System.out.println(solution.GetUglyNumber_Solution(10));

    }
}