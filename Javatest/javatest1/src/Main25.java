import java.util.*;
public class Main25 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String text = scanner.nextLine();
        String text2 = new String ("");
        while(!text.equals("end")){
            text2 =text2 + text;
            text2 = text2 + "\n";
            text = scanner.nextLine();
        }
        String st1 = scanner.nextLine();
        String st2 = scanner.nextLine();
        System.out.println(text2.replace(st1,st2));
    }

}
