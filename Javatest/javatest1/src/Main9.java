
import java.util.Scanner;
import java.text.DecimalFormat;

abstract class shape {// 抽象类
    /* 抽象方法 求面积 */
    public abstract double getArea( );

    /* 抽象方法 求周长 */
    public abstract double getPerimeter( );
}
/* 你提交的代码将被嵌入到这里 */
class Circle extends shape{
    private double r_;
    public Circle(double r){
        r_ = r;
    }
    @Override
    public double getArea() {
        return r_*r_*Math.PI;
    }

    @Override
    public double getPerimeter(){
        return 2*r_*Math.PI;
    }
}
public class Main9 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        DecimalFormat d = new DecimalFormat("#.####");// 保留4位小数
        double r = input.nextDouble( );
        shape c = new  Circle(r);

        System.out.println(d.format(c.getArea()));
        System.out.println(d.format(c.getPerimeter()));
        input.close();
    }
}