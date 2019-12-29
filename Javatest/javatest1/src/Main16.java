import java.util.Scanner;
class TDVector {
    private double x;
    private double y;
    public String toString() {
        return "("+this.x+","+this.y+")";
    }

    /** 你所提交的代码将被嵌在这里（替换此行） **/
    public TDVector(TDVector s){
        this.x = s.getX();
        this.y = s.getY();
    }
    public TDVector(double x_, double y_){
        this.x = x_;
        this.y = y_;
    }
    public TDVector(){

    }
    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }
    public TDVector add(TDVector t){
        double x = this.x + t.getX();
        double y = this.y + t.getY();
        return new TDVector(x,y);
    }
}
public class Main16 {
    public static void main(String[] args) {
        TDVector a = new TDVector();  /* 无参构造，向量的x和y默认为0 */
        Scanner sc = new Scanner(System.in);
        double x,y,z;
        x = sc.nextDouble();
        y = sc.nextDouble();
        z = sc.nextDouble();
        TDVector b = new TDVector(x, y);  /* 按照参数构造向量的x和y */
        TDVector c = new TDVector(b);  /* 按照向量b构造向量 */
        a.setY(z);
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        c.setX(z);
        a = b.add(c);
        System.out.println(a);
        System.out.println("b.x="+b.getX()+" b.y="+b.getY());
        sc.close();
    }
}