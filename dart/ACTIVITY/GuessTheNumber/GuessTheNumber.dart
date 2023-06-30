/// Author: Andrew Jules R. Miyajima
/// Date: 6/12/2023
import 'dart:io';
import 'dart:math';

void main() {
  while (true) {
    CLEAR_LOG;
    print('[1] Easy.');
    print('[2] Midium rare.');
    print('[3] More Harder.');
    print('[4] Exit');

    stdout.write('Choose your difficulty?: ');
    int setDifficulty = int.parse(stdin.readLineSync()!);

    if (setDifficulty == 4)
      return;
    else if (setDifficulty >= 1 && setDifficulty <= 3)
      playGame(setDifficulty);
    else
      print('Syntax Error! Try again.');
  }
}

void playGame(int difficulty) {
  final randomBS = Random().nextInt(_getMaxRange(difficulty)) + 1;
  int userChance = _getChances(difficulty);
  int userGuess = 0;

  CLEAR_LOG;
  print('You have $userChance chances to get the correct number.');
  while (userChance > 0) {
    stdout.write('Enter your guess: ');
    userGuess = int.parse(stdin.readLineSync()!);

    if (userGuess > randomBS) {
      print('Hint: Lower!, Chances: ${--userChance}\n');
    } else if (userGuess < randomBS) {
      print('Hint: Higher! Chances: ${--userChance}\n');
    } else if (userGuess == randomBS) {
      print('Congratulations! You guessed it right.');
      return;
    }
  }

  print('You ran out of chances. The number was ${randomBS}');
}

int _getMaxRange(int difficulty) {
  return (difficulty == 1)
      ? 10
      : (difficulty == 2)
          ? 100
          : 500;
}

int _getChances(int difficulty) {
  return (difficulty == 1)
      ? 10
      : (difficulty == 2)
          ? 6
          : 5;
}

void get CLEAR_LOG => print('\x1B[2J\x1B[0;0H');