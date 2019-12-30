import java.util.*;
public class Main26 {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        Calendar cal = Calendar.getInstance();
        cal.set(1969,1,1);
        long a = scanner.nextLong();
        cal.setTimeInMillis(a);
        String year = String.valueOf(cal.get(Calendar.YEAR));
        String month = String.valueOf(cal.get(Calendar.MONTH));
        String day = String.valueOf(cal.get(Calendar.DAY_OF_MONTH));
        System.out.println(year+"-"+month+"-"+day);
        scanner.close();
        String st = "23423";
        System.out.println();
    }
}
