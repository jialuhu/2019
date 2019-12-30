import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
class Student implements Comparable<Student>{
    private String name;
    private int no;
    public Student(int no_, String name_){
        no = no_;
        name = name_;
    }
    @Override
    public int compareTo(Student ob){
        return this.name.compareTo(ob.name);
    }

    @Override
    public String toString() {
        return "no=" + no +"&name=" + name;
    }
   /* @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Student other = (Student) obj;
        if (no != other.no)
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + no;
        return result;
    }

*/

}
public class Main23{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Student[] stus = new Student[3];

        for(int i=0;i<3;i++){
            int no = scan.nextInt();
            String name = scan.next();
            Student s = new Student(no,name);
            stus[i] =s;
        }
        //将stus中的3个学生对象，放入到HashSet中
        HashSet<Student> stuSet = new HashSet<Student>();
        for(Student s: stus){
            stuSet.add(s);
        }
        //要放入的第4个Student
        Student fourth = new Student(scan.nextInt(),scan.next());
        stuSet.add(fourth);//如果fourth的学号（no）与stuSet中的已有学生的no重复则无法放入
        System.out.println(stuSet.size());

        Arrays.sort(stus);//对stus中的3个原有对象，按照姓名首字符有小到大排序
        for(int i=0;i<stus.length;i++){
            System.out.println(stus[i].toString());//输出的格式为：no=XX&name=YY
        }

        scan.close();
    }
}
/* 请在这里填写答案 */