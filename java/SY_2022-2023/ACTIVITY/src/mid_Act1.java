

import java.util.Scanner;

class mid_Act1 {
    static Scanner sc = new Scanner(System.in);
    private static double balance = 0;

    public static void main(String[] args) {
        System.out.println("Welcome to Andrew's Bank Center.");
        System.out.print("Enter your balance: ");
        balance = sc.nextDouble();

        while (true) {
            System.out.println("Select an option:");
            System.out.println("1. Withdraw Amount");
            System.out.println("2. Deposit Amount");
            System.out.print("3. Exit \n> ");

            byte userChoice = sc.nextByte();
            switch (userChoice) {
                case 1:
                    final short MIN_WITHDRAW = 200;
                    double withdrawBalance;

                    do {
                        System.out.println("[Current Balance: " + balance + " ]");
                        System.out.print("How much amount you want to withdaw from your account? \nAmount: ");
                        withdrawBalance = sc.nextDouble();
                        if (withdrawBalance < MIN_WITHDRAW)
                            System.out.println("You can't withdraw lower than $" + MIN_WITHDRAW + ".");
                        else if (withdrawBalance > balance)
                            System.out.println("Don't!");
                    } while (withdrawBalance < MIN_WITHDRAW || withdrawBalance > balance);

                    balance -= withdrawBalance;
                    System.out.println("Your new balance: " + balance);
                    break;
                case 2:
                    final short MIN_DEPOSITE = 100;
                    double depositeBalance;

                    do {
                        System.out.println("[Current Balance: " + balance + " ]");
                        System.out.print("\nHow much amount you want to deposit in your account? \nAmount: ");
                        depositeBalance = sc.nextDouble();
                        if (depositeBalance < MIN_DEPOSITE)
                            System.out.println("You can't deposit lower than $" + MIN_DEPOSITE + ".");
                    } while (depositeBalance < MIN_DEPOSITE);

                    balance += depositeBalance;
                    System.out.println("Your new balance: " + balance);
                    break;
                case 3:
                    System.out.println("Thank you for using the Andrew's Bank Central.");
                    return;
                default:
                    System.err.println("OUT OF RANGE!!!");
                    return;
            }
        }
    }
}