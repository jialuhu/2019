import java.util.Scanner;
import java.util.Arrays;
interface shapes{
   public int getArea();
   public int getPrimeter();
}

class Rectangle implements shapes{
    private int width;
    private int height;
    public Rectangle(int w, int h){
        width = w;
        height = h;
    }
    @Override
    public int getArea(){
       return width*height;
    }
    @Override
    public int getPrimeter(){
        return 2*(width+height);
    }
    public int getWidth(){
        return width;
    }
    public int getHeight(){
        return height;
    }
    @Override
    public String toString(){
        return "Rectangle ["+
                "width=" + this.width+
                ", length=" + this.height+
                "]";
    }
}

class Circle implements shapes{
    private int r_;
    public Circle(int r){
        r_ = r;
    }
    @Override
    public int getArea(){
        return (int)(Math.PI*r_*r_);
    }

    @Override
    public int getPrimeter(){
        return (int)(2*r_*Math.PI);
    }

    public int getR_(){
        return r_;
    }
    @Override
    public String toString(){
        return "Circle [" + "radius=" +
                this.r_ +
                "]";
    }
}

public class Main19{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        Object[][] ob = new Object[2][2];
        int primeter = 0;
        int area = 0;
        for(int i=0; i<2; i++){
            int w = scanner.nextInt();
            int h = scanner.nextInt();
            Rectangle R = new Rectangle(w,h);
            primeter += R.getPrimeter();
            area += R.getArea();
            ob[0][i] = R;
        }
        for(int i=0; i<2; i++){
            int r;
            r = scanner.nextInt();
            Circle C = new Circle(r);
            primeter += C.getPrimeter();
            area += C.getArea();
            ob[1][i] = C;
        }
        System.out.println(primeter);
        System.out.println(area);
        System.out.println(Arrays.deepToString(ob[0]));
        System.out.println(Arrays.deepToString(ob[1]));


    }
}