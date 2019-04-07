package hhh.Test;


import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;

import java.util.*;
import java.util.Scanner;
class Solution {
    public int MoreThanHalfNum_Solution(int [] array) {
        int length=array.length;
        if(array==null||length<=0){
            return 0;
        }

        int result=array[0];
        int times=1;
        for(int i=1;i<length;i++){
            if(times==0){
                result=array[i];
                times=1;
            }else{
                if(array[i]==result){
                    times++;
                }else{
                    times--;
                }
            }
        }

        times=0;
        for(int i=0;i<length;i++){
            if(result==array[i]){
                times++;
            }
        }

        if(times*2<length){
            result=0;
        }
        return result;
    }
}
public class test{
    public static void main(String[] args)  {
        Solution solution=new Solution();
        int[] a={1,2,3,2,2,5,4,2};
        System.out.println(solution.MoreThanHalfNum_Solution(a));
    }
}
