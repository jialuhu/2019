import java.util.Scanner;

public class Main15 {

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();

        int array[]= new int[n];

        for(int i=0;i<n;i++)
        {
            array[i]=sc.nextInt();
        }

        MyArrays.printArray(array);//显示数组的内容
        MyArrays.sortArray(array);	//对数组元素排序
        MyArrays.printArray(array);//显示排序后的结果
        int sum=MyArrays.sumOfArray(array);//数组元素求和
        System.out.println(sum);//显示数组元素的和

    }

}

/* 请在这里填写MyArrays类的有关代码 */
class MyArrays{
    private static boolean b = true;
    private static int[] array_;
    public static void printArray(int array[]){
        if(b){
            array_ = array;
        }
        int len = array_.length;
        for(int i=0; i<len; i++){
            System.out.print(array_[i]);
            if(i<len-1){
                System.out.print(",");
            }
        }
        System.out.print("\n");
    }
    public static void sortArray(int array[]){
        int len = array_.length;
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                if(array_[i]>array_[j]){
                    int t = array_[i];
                    array_[i] = array_[j];
                    array_[j] = t;
                }
            }
        }
        b = false;
    }
    public static int sumOfArray(int array[]){
        int sum = 0;
        for(int i:array){
            sum += i;
        }
        return sum;
    }
}