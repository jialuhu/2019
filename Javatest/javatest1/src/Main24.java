import java.util.*;
public class Main24 {

    /*covnertStringToList函数代码*/

    /*remove函数代码*/
    /*以空格(单个或多个)为分隔符，将line中的元素抽取出来，放入一个List*/
    public static List<String> convertStringToList(String line){
        List<String> list = new ArrayList<String>();
        String[] st = line.split(" ");
        int len = st.length;
        for(int i=0; i<len; i++){
            if(st[i].equals(" ")) continue;
            else list.add(st[i]);
        }
        return list;
    }
    /*在list中移除掉与str内容相同的元素*/
    public static void remove(List<String> list, String str){
        while (list.indexOf(str)!=-1){
            int a = list.indexOf(str);
            list.remove(a);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            List<String> list = convertStringToList(sc.nextLine());
            System.out.println(list);
            String word = sc.nextLine();
            remove(list,word);
            System.out.println(list);
        }
        sc.close();
    }

}
