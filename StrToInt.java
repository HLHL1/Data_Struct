public class Solution {
        public int StrToInt(String str) {
        if(str==null||str.length()==0) return 0;
        if(str.charAt(0)==0){
            if(str.length()>1) return 0;
        }
        if(str.charAt(0)=='+'||str.charAt(0)=='-'){
            if(str.length()==1)return 0;
            if(str.charAt(1)=='0'){
                return 0;
            }
        }
        for(int i=0;i<str.length();i++){
            if(i==0){
                if((str.charAt(0)=='+')||(str.charAt(0)=='-')||(str.charAt(i)-'0'>=0&&str.charAt(i)-'0'<=9)){
                   continue;
                }else{
                    return 0;
                }
            }
            if(str.charAt(i)-'0'>=0&&str.charAt(i)-'0'<=9){

            }else{
                return 0;
            }
        }
        int ans=0;
        int len=str.length();
        len--;
        int index=0;
        int f=1;
        if((str.charAt(0)=='+')||(str.charAt(0)=='-')){
            len--;
            index++;
            if(str.charAt(0)=='-') {
                f = -1;
            }
        }
        for(int i=index;i<str.length();i++){
            ans+=(str.charAt(i)-'0')*(int)Math.pow(10,len);
            len--;
        }
        return ans*f;
    }
}