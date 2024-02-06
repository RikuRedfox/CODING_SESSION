import java.util.Scanner;

interface Values {
  final int PERCENTAGE = 100;
  final int MONTHS_IN_YR = 12;
  final int MIN_PRINCIPAL = 1000;
  final int MAX_PRINCIPAL = 1_000_000;
  final double MIN_INTEREST = 0.01;
  final double MAX_INTEREST = 30.0;
  final int MIN_PERIOD = 1;
  final int MAX_PERIOD = 32;
}

public class Mortage implements Values {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int principal = readInt("Enter value ($1k - $1M): ", MIN_PRINCIPAL, MAX_PRINCIPAL);
    double annual_interest = readDouble("Annual Interest Rate: ", MIN_INTEREST, MAX_INTEREST);
    int period = readInt("Period (Years): ", MIN_PERIOD, MAX_PERIOD);

    double monthly_interest = annual_interest / PERCENTAGE / MONTHS_IN_YR;
    int number_of_payments = MONTHS_IN_YR * period;

    double mortage = principal *
        (monthly_interest + Math.pow(1 + monthly_interest, number_of_payments)) /
        (Math.pow(1 + monthly_interest, number_of_payments) - 1);

    System.out.println("Mortage: $" + mortage);
  }

  private static int readInt(String prompt, int min, int max) {
    int value;
    do {
      System.out.print(prompt);
      value = sc.nextInt();
      if (value < min || value > max)
        System.out.println("Enter a number between " + min + " and " + max);
    } while (value < min || value > max);
    return value;
  }

  private static double readDouble(String prompt, double min, double max) {
    double value;
    do {
      System.out.print(prompt);
      value = sc.nextDouble();
      if (value < min || value > max)
        System.out.println("Enter a number between " + min + " and " + max);
    } while (value < min || value > max);
    return value;
  }
}
