import java.util.*;
public class Main31{
    public static void prints(String s1, String s2){
        int len1 = s1.length()-1;
        int len2 = s2.length()-1;
        int count = 0;
        String r = new String("");
        if(s1.charAt(len1)!=s2.charAt(len2)){
            System.out.println("No common suffix.");
        }else{
            for(int i=len1,j=len2; i>=0&&j>=0; i--,j--){
                if(s1.charAt(i)==s2.charAt(j)){
                    count++;
                }else{
                    //System.out.println("No common suffix.");
                    break;
                }
            }
            //System.out.println("count"+count+"-len:"+len1);

            r = s1.substring(len1+1-count,len1+1);
            System.out.println("The common suffix is "+r+". ");
        }
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String s1 = input.next();
        String s2 = input.next();
        prints(s1,s2);
    }
}