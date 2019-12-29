class People{
    protected String id;
    protected String name;

    /** 你提交的代码将被嵌在这里（替换此行） **/
    public People(String id_, String name_){
        id = id_;
        name = name_;
    }
    public People(){

    }

    public void setId(String id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public String getName(){
        return name;
    }

    public void say(){
        System.out.println("I am a person! My name is"+this.name+".");
    }
}

class Student extends People{
    protected String sid;
    protected int score;
    public Student() {
        super();
        name = "Pintia Student";
    }
    public Student(String id, String name, String sid, int score) {
        super(id, name);
        this.sid = sid;
        this.score = score;
    }
    public void say() {
        System.out.println("I'm a student. My name is " + this.name + ".");
    }

}
public class Main17 {
    public static void main(String[] args) {
        Student zs = new Student();
        zs.setId("370211X");
        zs.setName("Zhang San");
        zs.say();
        System.out.println(zs.getId() + " , " + zs.getName());

        Student ls = new Student("330106","Li Si","20183001007",98);
        ls.say();
        System.out.println(ls.getId() + " : " + ls.getName());

        People ww = new Student();
        ww.setName("Wang Wu");
        ww.say();

        People zl = new People("370202", "Zhao Liu");
        zl.say();
    }
}