package src;

//Variables, Data Types and Basic Operations.
//Type Casting
public class practice_1 {
    public static void main(String[] args) {
        int a = 2, num1 = 22, num2 = 31, num3 = 81;
        var b = 5;
        double c = 13.99023, num4 = 41, num5 = 9, num6 = 231, sumNum = num1+num2+num3+num4+num5+num6;
        float d = 44.21f;
        String txt = "Hello my number is: ";
        boolean t = true;
        String txt1 = "Then my letter character are ";
        char l = 'A';
        
        System.out.println(txt+((d/a) * b) / c + " '"+t+"' ");
        System.out.println(txt1+" '"+l+"' ");

        System.out.println(sumNum);

        System.out.println(((double)a/(float)c)*(int)b);
    }
}