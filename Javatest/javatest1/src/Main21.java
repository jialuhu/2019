public class Main21 {
    public static void main(String[] args) {
        Company company=new Company();
        System.out.println(company.getClassName());
       // String s = this.getClass().getName();

    }
}
interface ClassName{
    public abstract String getClassName();
}
class Company implements ClassName{
    @Override
    public String getClassName() {
        String s=this.getClass().getName();
        return s;
    }
}