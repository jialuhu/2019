import java.util.Scanner;
public class Main {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int input = scanner.nextInt();
        String result = new String ("");
        result = result + input;
        System.out.println(new StringBuffer(result).reverse().toString());
        //System.out.println(result);
    }
}
