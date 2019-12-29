import java.util.Scanner;
import java.text.DecimalFormat;
abstract class shape13{
    public abstract double getArea();
    public abstract double getPerimeter();
}

class RPentagon13 extends shape13{
    @Override
    public double getArea(){
        return r_*r_*Math.sqrt(25+10*Math.sqrt(5))/4;
    }

    @Override
    public double getPerimeter() {
        return r_*5;
    }
    private double r_;
    public RPentagon13(double r){
        r_  = r;
    }
}
public class Main13 {
    public static void mian(String[] args){

        Scanner input = new Scanner(System.in);
        DecimalFormat d = new DecimalFormat("#.####");// 保留4位小数

        double side = input.nextDouble();
        shape13 rp = new RPentagon13(side);
        System.out.println(d.format(rp.getArea()));
        System.out.println(d.format(rp.getPerimeter()));
        input.close();
    }
}
