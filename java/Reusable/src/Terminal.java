import java.io.IOException;

public class Terminal {
    public static void CLEAR_CONSOLE() {
        try {
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                new ProcessBuilder("clear").inheritIO().start().waitFor();
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void CLEAR_TO_PROMPT(String prompt){
        CLEAR_CONSOLE();
        System.out.print(prompt);
    }

    public static void PAUSE() {
        System.out.println("Press enter to continue...");
        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void CLEAR_AND_PAUSE(String prompt) {
        CLEAR_CONSOLE();
        System.out.println(prompt);
        PAUSE();
    }
}
