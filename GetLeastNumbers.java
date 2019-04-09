import java.util.*;
class Solution {
    public ArrayList<Integer> help(int[] input,int left,int right,int k,ArrayList<Integer> arrayList){
        if(left>right){
            return arrayList;
        }
        int begin=left,end=right;
        int mid=input[begin];
        while(begin<end){
            while (begin<end&&input[end]>=mid){
                end--;
            }
            input[begin]=input[end];
            while(begin<end&&input[begin]<=mid){
                begin++;
            }
            input[end]=input[begin];
        }
        input[begin]=mid;
        if(begin+1==k){
            for(int i=0;i<k;i++){
                arrayList.add(input[i]);
            }
        }else{
            if(begin>=k){
                help(input,left,begin-1,k,arrayList);
            }else{
                help(input,begin+1,right,k,arrayList);
            }
        }
        return arrayList;
    }
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> arrayList=new ArrayList<>();
        if(k==0){
            return arrayList;
        }
        if(k==input.length){
            for(int i=0;i<k;i++){
                arrayList.add(input[i]);
            }
            return arrayList;
        }
       return help(input,0,input.length-1,k,arrayList);
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
