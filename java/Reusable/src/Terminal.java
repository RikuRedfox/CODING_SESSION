import java.io.IOException;

public class Terminal {
    private static final boolean IS_WINDOWS = System.getProperty("os.name").contains("Windows");

    public static void clearConsole() {
        try {
            if (IS_WINDOWS) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                new ProcessBuilder("clear").inheritIO().start().waitFor();
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void clearAndPrompt(String prompt) {
        clearConsole();
        System.out.print(prompt);
    }

    public static void pauseConsole() {
        System.out.println("Press enter to continue. . .");
        try {
            System.in.read();
        } catch (IOException e) {
            System.out.println("An error occurred while waiting for input.");
            e.printStackTrace();
        }
    }

    public static void clearAndPromptThenPause(String prompt) {
        clearConsole();
        System.out.println(prompt);
        pauseConsole();
    }
}
