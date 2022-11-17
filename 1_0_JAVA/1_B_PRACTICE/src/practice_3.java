package src;

public class practice_3 {
    public static double pounds (double kg){
        return kg / 0.45359237;
    }
    public static void main(String[] args) {
        double result = pounds(4);
        System.out.println("Result [kg to pounds] : " + result);
    }
}
