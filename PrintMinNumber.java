import java.util.*;
public class test {
    public static String PrintMinNumber(int [] numbers) {
        Arrays.sort(numbers);
        int sum=0;
        StringBuilder sb=new StringBuilder();
        int q=10;
        int b=0;
        while(sum<numbers.length){
            int minF=10;
            int min=0;
            int flag=0;
            for(int i=0;i<numbers.length;i++){
                if(numbers[i]!=Integer.MAX_VALUE) {
                    int tmp = numbers[i];
                    while (tmp / q > 0) {
                        tmp /= 10;
                    }
                    tmp = tmp % 10;
                    if (tmp == minF) {
                        flag=tmp;
                    }
                    if (tmp < minF) {
                        minF = tmp;
                        min = i;
                    }
                }
            }
            if(flag==0||flag>minF){
                sum++;
                sb.append(numbers[min]);
                numbers[min]=Integer.MAX_VALUE;
                q=1;
            }
            if(numbers[numbers.length-1]!=Integer.MAX_VALUE&&numbers[numbers.length-1]*100<q){
                b=1;
                break;
            }
            q*=10;
        }
        if(b==1){
            for(int i=0;i<numbers.length;i++){
                if(numbers[i]!=Integer.MAX_VALUE) {
                    sb.append(numbers[i]);
                }
            }
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        int[] numbers={3,32,321};
        System.out.println(PrintMinNumber(numbers));
    }
}
