import java.math.BigInteger;
import java.util.Scanner;
public class Main29{
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        BigInteger m=in.nextBigInteger();
        int n=in.nextInt();
        int count=0;
        while(count<n){
            if(m.isProbablePrime(100)){
                System.out.println(m);
                count++;
            }
            m=m.nextProbablePrime();
        }
        in.close();
    }
}