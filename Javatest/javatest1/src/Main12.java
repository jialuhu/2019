import java.util.Scanner;
import java.text.DecimalFormat;
interface Ishape_{
    public abstract double getArea();
    public abstract double getPerimeter();
}

class RTriangle_ implements Ishape_{
    @Override
    public double getArea(){
        return 0.5*r1_*r2_;
    }
    @Override
    public double getPerimeter() {
        return r1_+r2_+Math.sqrt((r1_*r1_)+(r2_*r2_));
    }
    private double r1_;
    private double r2_;
    public RTriangle_(double r1, double r2){
        r1_ = r1;
        r2_ = r2;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        DecimalFormat d = new DecimalFormat("#.####");
        double r1 = scanner.nextDouble();
        double r2 = scanner.nextDouble();
        RTriangle_ rp = new RTriangle_(r1,r2);
        System.out.println(d.format(rp.getArea()));
        System.out.println(d.format(rp.getPerimeter()));
    }
}

