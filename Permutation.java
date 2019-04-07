package hhh.Test;


import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;

import java.util.*;
import java.util.Scanner;
class Solution {

    public ArrayList<String> Permutation(String str) {

        ArrayList<String> arrayList=new ArrayList<>();
        if(str==null||str.length()==0){
            return arrayList;
        }
        help(str.toCharArray(),0,arrayList);
        Collections.sort(arrayList);//?????
        return arrayList;
    }
    private void help(char[] ch,int i,ArrayList<String> arrayList){
        if(i==ch.length-1){
           String val=String.valueOf(ch);
           if(!arrayList.contains(val)){
               arrayList.add(val);
           }
        }else{
            for(int j=i;j<ch.length;j++){
                swap(ch,i,j);
                help(ch,i+1,arrayList);
                swap(ch,i,j);
            }
        }
    }
    private void swap(char[] ch,int i,int j){
        char tmep=ch[i];
        ch[i]=ch[j];
        ch[j]=tmep;
    }
}
public class test{
    public static void main(String[] args)  {
        Solution solution=new Solution();
       ArrayList<String> a=solution.Permutation("abc");
      for (int i=0;i<a.size();i++){
          System.out.println(a.get((int)i));
      }
    }
}
