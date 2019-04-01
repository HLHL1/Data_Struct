 class Solution {
     public int GetUglyNumber_Solution(int index) {
         if(index<=0){
             return 0;
         }
        int[] nums=new int[index];
         nums[0]=1;
        int next=1;
        int m2=0;
        int m3=0;
        int m5=0;

        int min=0;
        while(next<index){
            min=Math.min(nums[m2]*2,Math.min(nums[m3]*3,nums[m5]*5));
            nums[next]=min;

            while(nums[m2]*2<=nums[next]){
                m2++;
            }
            while(nums[m3]*3<=nums[next]){
                m3++;
            }
            while(nums[m5]*5<=nums[next]){
                m5++;
            }
            next++;
        }
        return nums[index-1];
     }
 }
public class test{
    public static void main(String[] args) {
        Solution solution=new Solution();
        System.out.println(solution.GetUglyNumber_Solution(10));

    }
}