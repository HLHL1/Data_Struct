
import java.util.*;
class Solution {

    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        Arrays.sort(input);
        if(k>input.length||k<=0){
            return arrayList;
        }
        for (int i = 0; i < k; i++) {
            arrayList.add(input[i]);
        }
        return arrayList;
    }
}
public class test{
    public static void main(String[] args) {
        int[] input={4,5,1,6,2,7,2,8};
        Solution solution=new Solution();
        ArrayList<Integer> arrayList=solution.GetLeastNumbers_Solution(input,2);
        for(int i=0;i<arrayList.size();i++){
            System.out.println(arrayList.get(i));
        }
    }
}
