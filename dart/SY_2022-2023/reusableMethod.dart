import 'dart:io';

Future<void> CLEAR_CONSOLE() async {
  if (Platform.isWindows) {
    // For Windows
    await Process.run('cls', [], runInShell: true);
  } else {
    // For macOS and Linux
    await Process.run('clear', [], runInShell: true);
  }
  // Fallback option
  print('\x1B[2J\x1B[0;0H');
}

void CLEAR_TO_PROMPT(String prompt) {
  CLEAR_CONSOLE().then((_) {
    stdout.write(prompt);
  });
}

Future<void> PAUSE() async {
  print('\nPress enter to continue...');
  await stdin.readLineSync();
}

void CLEAR_AND_PAUSE(String prompt) {
  CLEAR_CONSOLE().then((_) {
    print('$prompt');
    PAUSE();
  });
}
