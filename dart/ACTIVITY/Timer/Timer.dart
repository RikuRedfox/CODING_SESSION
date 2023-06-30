import 'dart:io';

const String CLEAR_LOG = "\x1B[2J\x1B[0;0H";

void main(List<String> args) => Timer().getTime();

class Timer {
  late int seconds, minutes, hours;

  void startTimer(int seconds, int minutes, int hours) {
    while (true) {
      print(CLEAR_LOG);
      stdout.writeln("$hours : $minutes : $seconds");
      sleep(Duration(seconds: 1));

      seconds--;

      if (seconds <= 0) {
        minutes -= 1;
        seconds += 60;
      }

      if (minutes <= 0) {
        hours -= 1;
        minutes += 60;
      }

      if (seconds == 0 && minutes == 0 && hours == 0) return;
    }
  }

  void getTime() {
    stdout.writeln("\tTIMER");
    while (true) {
      try {
        stdout.write("Enter second: ");
        seconds = int.parse(stdin.readLineSync()!);
        stdout.write("Enter minute: ");
        minutes = int.parse(stdin.readLineSync()!);
        stdout.write("Enter hour: ");
        hours = int.parse(stdin.readLineSync()!);
        break;
      } on FormatException catch (e) {
        stderr.write(e);
      }
    }

    if (seconds == 0 && minutes == 0 && hours == 0) return;

    startTimer(exceedSeconds(seconds), exceedMinutes(minutes), hours);
  }

  int exceedSeconds(int seconds) {
    if (seconds >= 60) {
      minutes += seconds ~/ 60;
      return seconds % 60;
    }
    return seconds;
  }

  int exceedMinutes(int minutes) {
    if (minutes >= 60) {
      hours += minutes ~/ 60;
      return minutes % 60;
    }
    return minutes;
  }
}
