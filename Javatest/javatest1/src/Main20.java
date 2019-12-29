import java.util.Arrays;
import java.util.Scanner;

import java.util.Scanner;
public class Main20{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int age1,age2;
        age1 = in.nextInt();
        age2 = in.nextInt();
        Person a=new Person(age1);
        Farmer b=new Farmer(age1,age2);
        System.out.print(Farmer.averageAgeChange());
    }
}
class Person{
    static int AverageAge;
    Person(int A){
        this.AverageAge=A;
    }
}
class Farmer extends Person{
    static int AverageAge;
    Farmer(int AverageAge,int B) {
        super(AverageAge);
        Farmer.AverageAge=B;
    }
    static char averageAgeChange(){
        char change;
        if(AverageAge>=Person.AverageAge){
            change = 'A';
        }else{
            change = 'B';
        }
        return change;
    }
}