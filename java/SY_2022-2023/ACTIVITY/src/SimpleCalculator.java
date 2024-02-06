import java.util.function.DoubleBinaryOperator;
import java.util.Scanner;

public class SimpleCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first number: ");
        double num1 = sc.nextDouble();

        System.out.print("Enter second number: ");
        double num2 = sc.nextDouble();

        System.out.print("Enter operation (+, -, *, /, %): ");
        char operator = sc.next().charAt(0);

        double result;
        switch (operator) {
            case '+':
                result = performOperation(num1, num2, (a, b) -> a + b);
                break;
            case '-':
                result = performOperation(num1, num2, (a, b) -> a - b);
                break;
            case '*':
                result = performOperation(num1, num2, (a, b) -> a * b);
                break;
            case '/':
                result = performOperation(num1, num2, (a, b) -> a / b);
                break;
            case '%':
                result = performOperation(num1, num2, (a, b) -> a % b);
                break;
            default:
                result = 0;
                sc.close();
                return;
        }

        System.out.println("Result: " + result);
        sc.close();
    }

    private static double performOperation(double a, double b, DoubleBinaryOperator operation) {
        return operation.applyAsDouble(a, b);
    }
}
