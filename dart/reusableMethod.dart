import 'dart:io';

void CLEAR_CONSOLE() {
  if (Platform.isWindows) {
    // For Windows
    print(Process.runSync('cls', [], runInShell: true).stdout);
  } else {
    // For macOS and Linux
    print(Process.runSync('clear', [], runInShell: true).stdout);
  }

  // Fallback option
  print('\x1B[2J\x1B[0;0H');
}

void CLEAR_TO_PROMPT(String prompt) {
  CLEAR_CONSOLE();
  stdout.write(prompt);
}

void PAUSE() {
  print('\nPress enter to continue...');
  stdin.readLineSync();
}

void CLEAR_AND_PAUSE(String prompt) {
  CLEAR_CONSOLE();
  print('$prompt');
  PAUSE();
}
