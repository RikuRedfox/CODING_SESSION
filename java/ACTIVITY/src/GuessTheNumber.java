import java.util.Scanner;
import java.util.Random;

public class GuessTheNumber {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        while (true) {
            Terminal.CLEAR_CONSOLE();
            System.out.println("[1] Easy.");
            System.out.println("[2] Medium rare.");
            System.out.println("[3] More Harder.");
            System.out.println("[4] Exit.");
            System.out.print("Choose your difficulty: ");
            int setDifficulty = sc.nextInt();

            if (setDifficulty == 4)
                return;
            else if (setDifficulty >= 1 && setDifficulty <= 3)
                playGame(setDifficulty);
            else
                System.out.println("Syntax Error! Try again.");
        }
    }

    private static void playGame(int difficulty) {
        Random random = new Random();
        int randomNumber = random.nextInt(getMaxRange(difficulty)) + 1;
        int userChance = getChances(difficulty);
        int userGuess = 0;

        Terminal.CLEAR_CONSOLE();
        System.out.println("you have " + userChance + " chances to get the correct number.");
        while (userChance > 0) {
            System.out.print("Enter your guess: ");
            userGuess = sc.nextInt();

            if (userGuess > randomNumber) {
                System.out.println("Hint: Lower! Chances: " + --userChance + "\n");
            } else if (userGuess < randomNumber) {
                System.out.println("Hint: Higher! Chances: " + --userChance + "\n");
            } else if (userGuess == randomNumber) {
                System.out.println("Congratulations! Ypu guessed it right.");
                Terminal.PAUSE();
                return;
            }
        }

        System.out.println("You ran out of chances. The number was " + randomNumber);
        Terminal.PAUSE();
        return;
    }

    private static int getMaxRange(int difficulty) {
        return (difficulty == 1) ? 10 : (difficulty == 2) ? 100 : (difficulty == 3) ? 500 : 0;
    }

    private static int getChances(int difficulty) {
        return (difficulty == 1) ? 10 : (difficulty == 2) ? 6 : (difficulty == 3) ? 5 : 0;
    }
}