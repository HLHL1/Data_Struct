 class Solution {
    public boolean match(char[] str, char[] pattern) {
        if (str == null || pattern == null) {
            return false;
        }
        int strIndex = 0;
        int patternIndex = 0;
        return matchCore(str, strIndex, pattern, patternIndex);
    }

    public boolean matchCore(char[] str, int strIndex, char[] pattern, int patternIndex) {
        //?????:str??,pattern??,????
        if (strIndex == str.length && patternIndex == pattern.length) {
            return true;
        }
        //pattern???,????
        if (strIndex != str.length && patternIndex == pattern.length) {
            return false;
        }
        //???2??*,?????1?????1???,?3?????;????,????2?
        if (patternIndex + 1 < pattern.length && pattern[patternIndex + 1] == '*') {
            if ((strIndex != str.length && pattern[patternIndex] == str[strIndex]) || (pattern[patternIndex] == '.' && strIndex != str.length)) {
                return matchCore(str, strIndex, pattern, patternIndex + 2)//????2,??x*??0???
                        || matchCore(str, strIndex + 1, pattern, patternIndex + 2)//??????1???
                        || matchCore(str, strIndex + 1, pattern, patternIndex);//*??1?,???str?????
            } else {
                return matchCore(str, strIndex, pattern, patternIndex + 2);
            }
        }
        //???2???*,?????1?????1???,????1?,??????false
        if ((strIndex != str.length && pattern[patternIndex] == str[strIndex]) || (pattern[patternIndex] == '.' && strIndex != str.length)) {
            return matchCore(str, strIndex + 1, pattern, patternIndex + 1);
        }
        return false;
    }
}
public class test{
    public static void main(String[] args) {

        Solution solution=new Solution();
        char[] str={'a','.','a'};
        char[] pattern={'a','b','*','a','c','*','a'};
//        char[] str={};
//        char[] pattern={'.','*'};
        System.out.println(solution.match(str,pattern));
    }
}