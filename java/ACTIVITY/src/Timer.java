import java.util.Scanner;

public class Timer {
  static Scanner sc = new Scanner(System.in);
  private int seconds, minutes, hours;

  public static void main(String[] args) {
    Timer timer = new Timer();
    timer.getTime();
  }

  void startTimer(int seconds, int minutes, int hours) throws InterruptedException {
    while (true) {
      Terminal.clearConsole();
      System.out.printf("%d : %d : %d%n", hours, minutes, seconds);
      Thread.sleep(1000);

      seconds--;
      if (seconds <= 0) {
        minutes -= 1;
        seconds += 60;
      }

      if (minutes <= 0) {
        hours -= 1;
        minutes += 60;
      }

      if (seconds == 0 && minutes == 0 && hours == 0)
        return;
    }
  }

  void getTime() {
    System.out.println("\tTIMER");

    while (true) {
      try {
        System.out.print("Enter seconds: ");
        seconds = sc.nextInt();
        System.out.print("Enter minutes: ");
        minutes = sc.nextInt();
        System.out.print("Enter hours: ");
        hours = sc.nextInt();
        break;
      } catch (NumberFormatException e) {
        System.err.println(e);
      }
    }

    if (seconds == 0 && minutes == 0 && hours == 0)
      return;

    try {
      startTimer(exceedSeconds(seconds), exceedMinutes(minutes), hours);
    } catch (InterruptedException e) {
      System.err.println(e);
    }
  }

  private int exceedSeconds(int secs) {
    if (secs >= 60) {
      minutes += secs / 60;
      return secs % 60;
    }
    return secs;
  }

  private int exceedMinutes(int mins) {
    if (mins >= 60) {
      hours += mins / 60;
      return mins % 60;
    }
    return mins;
  }
}
