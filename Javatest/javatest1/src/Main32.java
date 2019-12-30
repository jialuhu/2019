import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
public class Main32 {
    public static void main(String[] args){
        char[] ch = {'+','-','*','/'};
        Scanner input = new Scanner(System.in);
        String t = input.nextLine();
        int len = -1;
        int flag = -1;
        for(int i=0; i<ch.length; i++){
            len = t.indexOf(ch[i]);
            if(len!=-1){
                flag = i;
                break;
            }
        }
        BigDecimal m = new BigDecimal(t.substring(0,len));
        BigDecimal n = new BigDecimal(t.substring(len+1));
        switch (flag){
            case 0:{
                System.out.println(m.add(n));
                break;
            }
            case 1:{
                System.out.println(m.subtract(n));
                break;
            }
            case 2:{
                System.out.println(m.multiply(n));
                break;
            }
            case 3:{
                System.out.println(m.divide(n));
                break;
            }
        }
    }
}
