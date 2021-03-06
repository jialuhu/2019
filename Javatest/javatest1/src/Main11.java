import java.util.*;
import java.lang.Math;
import java.text.DecimalFormat;
interface IShape{
    public abstract double getArea();
    public abstract double getPerimeter();
}
class RTriangle implements IShape
{
    private double a,b;
    public RTriangle(double a1,double b1)
    {
        a=a1;b=b1;
    }
    @Override
    public double getArea() {
        // TODO 自动生成的方法存根
        return a*b*0.5;
    }

    @Override
    public double getPerimeter() {
        // TODO 自动生成的方法存根
        return a+b+Math.sqrt(a*a+b*b);
    }
}
public class Main11 {
    public static void main(String[]args)
    {
        Scanner in=new Scanner(System.in);
        java.text.DecimalFormat df=new java.text.DecimalFormat("0.####");
        RTriangle r=new RTriangle(in.nextDouble(),in.nextDouble());
        System.out.println(df.format(r.getArea()));
        System.out.println(df.format(r.getPerimeter()));
    }
}