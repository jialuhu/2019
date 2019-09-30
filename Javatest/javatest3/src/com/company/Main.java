package com.company;

import java.util.Scanner;

class Applicant{
    protected int age;
    protected String name;
    protected int experience;
    protected String planguage;

    public Applicant(int Age, String Name, int Experience,String Planguage){
        age = Age;
        name = Name;
        experience = Experience;
        planguage = Planguage;
    }
    boolean juge(){
        if(age>35){
            return false;
        }
        else if((!planguage.equals("Java")) &&(!planguage.equals("C"))){
            return false;
        }
        else if(experience<3){
            return false;
        }
        return true;
    }
}
public class Main {

    public static void main(String[] args) {
        while (true){
            Scanner scanner = new Scanner(System.in);
            System.out.printf("Input your name:\n");
            String name = scanner.nextLine();
            System.out.printf("Input your age:\n");
            int age = scanner.nextInt();
            System.out.printf("What programing language do you know(c/Java)?\n");
            scanner.nextLine();
            String language = scanner.nextLine();
            System.out.printf("How many years of work experience do you have?\n");
            int experience = scanner.nextInt();
            scanner.nextLine();
            Applicant applicant = new Applicant(age,name,experience,language);
            if(applicant.juge()){
                System.out.println("Congratulation,you passed");
            }
            else{
                System.out.println("Sorry,you don't passed");
            }
            System.out.println("Exit or contiune(1/0):");
            int ch = scanner.nextInt();
            if(ch==1){
                break;
            }
        }

    }
}
