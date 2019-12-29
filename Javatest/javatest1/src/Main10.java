import java.util.Scanner;
import java.text.DecimalFormat;

abstract class shape1 {// 抽象类

    /* 抽象方法 求面积 */
    public abstract double getArea();

    /* 抽象方法 求周长 */
    public abstract double getPerimeter();
}
/* 你提交的代码将被嵌入到这里 */
class RPentagon extends shape1{
    private double side_;
    public RPentagon(double side){
        side_ = side;
    }
    @Override
    public double getArea(){
        return side_*side_*Math.sqrt(25+10*Math.sqrt(5))/4;
    }
    @Override
    public double getPerimeter(){
        return side_*5;

    }
}
public class Main10 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        DecimalFormat d = new DecimalFormat("#.####");// 保留4位小数
        double side = input.nextDouble();

        shape1 rp = new RPentagon(side);

        System.out.println(d.format(rp.getArea()));
        System.out.println(d.format(rp.getPerimeter()));
        input.close();
    }
}
