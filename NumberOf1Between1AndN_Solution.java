/*
??????,?????????21345???,???????,????????

i = 10;

j = 1;

(1)????21345???????1???,?????10???1?,????????1????????1?

count = 21345 / i(10) * j (1) �+ 1( ??1 , 1 <= 1 < 2)

(2)????21345???????1???,????100??????1?1,?10?,?

count = 21345 / i(100) * j (10) �+ 10( ??45 , 20 < 45)

(3)???????1???

count = 21345 / i(1000) * j (100) �+ 100( ??345 , 200 < 345)

(4)???????1???

count = 21345 / i(10000) * j (1000) �+ (1345 - 1000 + 1)( ??1345 , 1000 <= 1345 < 2000)

(5)???????1???

count = 21345 / i(100000) * j (10000) �+ 10000( ??21345 , 20000 < 21345)

*/
public class test {
    public static int NumberOf1Between1AndN_Solution(int n) {
        int count = 0;
        int i = 10;
        int j = 1;
        while (i <= n * 10){
            count += n / i * j;
            int len = n % i;
            if (len >= 2 * j){
                count += j;
            }else if (len >= j){
                count += len - j + 1;
            }
            i *= 10;
            j *= 10;
        }
        return count;
    }
    public static void main(String[] args) {
        System.out.println(NumberOf1Between1AndN_Solution( 45));
    }
}