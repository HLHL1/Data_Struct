package hhh.Test;


import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;

import java.util.*;
import java.util.Scanner;
class Solution {
    public int MoreThanHalfNum_Solution(int[] array) {
        Map<Integer, Integer> map = new HashMap<>();
        if (array == null || array.length == 0) {
            return 0;
        }
        if(array.length==1){
            return array[0];
        }
        int len = array.length;
        for (int i = 0; i < array.length; i++) {
            if (!map.containsKey((Integer) array[i])) {
                map.put(array[i], 1);
            } else {
                map.put(array[i], map.get((Integer) array[i]) + 1);
                if (map.get(array[i]) >len / 2) {
                    return array[i];
                }
            }
        }
        return 0;
    }
}
public class test{
    public static void main(String[] args)  {
        Solution solution=new Solution();
        int[] a={1,2,3,2,2,5,4,2};
        System.out.println(solution.MoreThanHalfNum_Solution(a));
    }
}
