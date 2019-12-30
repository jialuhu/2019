import java.util.*;
public class Main28 {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int n,begin,end;
        StringBuilder a= new StringBuilder();
        while(true)
        {
            n=in.nextInt();
            begin=in.nextInt();
            end=in.nextInt();
            for(int i=0;i<n;i++)
                a.append(String.valueOf(i));
            System.out.println(a.substring(begin,end));
        }
    }
}
