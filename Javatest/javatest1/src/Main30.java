import java.util.*;
public class Main30{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String txt = input.nextLine();
        int flag = 0;
        int count = 0;
        int len = txt.length();
        for(int i=0; i<len; i++){
            if(txt.charAt(0)=='.'||txt.charAt(len-1)=='.'){
                flag = 0;
                break;
            }
            if(txt.charAt(i)>'9'||txt.charAt(i)<'0'){
                if(txt.charAt(i)!='.' || count>1){
                    flag = 0;
                }else if(txt.charAt(i)=='.'){
                    count++;
                }
            }else{
                flag = 1;
            }
        }
        if(flag==1 && count<=1){
            System.out.println("true");
        }else{
            System.out.println("false");
        }
    }
}
