import java.util.*;
public class Main27 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        while(true){
            int sum = 0;
            String next = scanner.nextLine();
            char[] st = next.toCharArray();
            for(int i=0; i<st.length; i++){
                if(st[i]=='-'||st[i]=='+'||st[i]=='.') continue;
                else{
                    int t = st[i]-48;
                    sum = sum + t;
                }
            }
            System.out.println(sum);
        }
    }
}
