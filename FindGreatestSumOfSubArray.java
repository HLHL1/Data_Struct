public class test {
    public static int FindGreatestSumOfSubArray(int[] array) {
        int max=array[0],sum=0;
        for(int i=0;i<array.length;i++){
            sum+=array[i];
            if(sum<0){
                sum=array[i];
                max=Math.max(max,sum);
                sum=0;
            }else{
                max=Math.max(max,sum);
            }
        }
        return max;
    }
    public static void main(String[] args) {
        int arr[]={6,-3,-2,7,-15,1,2,2};
        System.out.println(FindGreatestSumOfSubArray(arr));
    }
}