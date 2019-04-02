import java.util.*;
public class Solution {
    public boolean isContinuous(int [] numbers) {
         if(numbers==null||numbers.length==0)return false;
        Arrays.sort(numbers);
        int zero=0;
        int flag=0;
        int ret=0;
        for(int i=0;i<numbers.length;i++){
            if(numbers[i]==0){
                zero++;
            }
            if(flag==1){
                if(numbers[i]==numbers[i-1]){
                    return false;
                }else {
                    ret += numbers[i] - numbers[i - 1]-1;
                }
            }
            if(numbers[i]!=0){
                flag=1;
            }
        }
        if(ret>zero)return false;
        else return true;
    }
}