// 6 - 42,45,49,55,58

import 'dart:io';
import 'dart:math';
import '../../reusableMethod.dart';

void main(List<String> args) {
  const OPTIONS = ['42', '45', '49', '55', '58', 'Exit.'];

  int? userChoice;
  do {
    CLEAR_TO_PROMPT('Option:\n');
    for (int i = 0; i < OPTIONS.length; i++) {
      print('${i + 1}.) ${OPTIONS[i]}');
    }
    stdout.write('Input: ');
    userChoice = int.tryParse(stdin.readLineSync()!);
    if (userChoice == 6)
      print('Exiting . . .');
    else if (userChoice != null && userChoice >= 1 && userChoice <= 5)
      setLottery(userChoice);
    else
      print('Invalid input.');
  } while (userChoice != OPTIONS.length);
}

void setLottery(int set) {
  Set<int> temp = {};

  while (temp.length != 6) {
    sleep(Duration(seconds: 1));
    int rand = Random().nextInt(_rangeNumber(set)) + 1;
    temp.add(rand);
    CLEAR_TO_PROMPT(temp.toString());
  }
  PAUSE();
}

int _rangeNumber(int set) {
  return (set == 1)
      ? 42
      : (set == 2)
          ? 45
          : (set == 3)
              ? 49
              : (set == 4)
                  ? 55
                  : (set == 5)
                      ? 58
                      : 0;
}
