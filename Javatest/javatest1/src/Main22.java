import java.util.*;
class PersonSortable2{
    private String name;
    private int age;
    public PersonSortable2(String name_, int age_){
        name = name_;
        age = age_;
    }

    @Override
    public String toString(){
        return name+"-"+age;
    }

    public String getName(){
        return name;
    }

    public int getAge(){
        return age;
    }
}

class NameComparator implements Comparator<PersonSortable2>{
    @Override
    public int compare(PersonSortable2 o1, PersonSortable2 o2){
        return o1.getName().compareTo(o2.getName());
    }
}

class AgeComparator implements Comparator<PersonSortable2>{
    @Override
    public int compare(PersonSortable2 o1, PersonSortable2 o2){
        return o1.getAge()-o2.getAge();
    }

}
public class Main22{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PersonSortable2[] ps = new PersonSortable2[n];
        for(int i=0; i<n; i++){
            String name = scanner.next();
            int age = scanner.nextInt();
            PersonSortable2 p = new PersonSortable2(name,age);
            ps[i] = p;
        }
        System.out.println("NameComparator:sort");
        Arrays.sort(ps,new NameComparator());
        for(PersonSortable2 i: ps){
            System.out.println(i);
        }
        System.out.println("AgeComparator:sort");
        Arrays.sort(ps,new AgeComparator());
        for(PersonSortable2 i:ps){
            System.out.println(i);
        }
        System.out.println(Arrays.toString(NameComparator.class.getInterfaces()));
        System.out.println(Arrays.toString(AgeComparator.class.getInterfaces()));
        scanner.close();

    }


}