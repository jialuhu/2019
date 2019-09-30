
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        /*Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        if(a<10){
            System.out.print(a);
        }
        else if(a>=10 && a<=15){
            System.out.printf("%x",a);
        }
        else{
                System.out.println("Invalid input");
        }*/
        boolean flag = true;
        String result = new String("");
        for(int i=3; i<=100; i++)
        {
            for(int j=2; j<i; j++)
            {
                if(i%j==0)
                {
                    flag = false;
                    //System.out.print(i);
                    break;
                }
                flag = true;
            }
            if(flag){
                System.out.println(i);
                flag = true;
            }
        }
    }
}
