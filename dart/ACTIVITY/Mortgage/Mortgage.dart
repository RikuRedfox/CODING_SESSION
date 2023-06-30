/*  Crate a mortgage
    First ask for Principal or loan want to get
    Annual Interest Rate: rate / 100 ((rate/100) for percentage) / 12 (months in
    year)
    Period(Years):
    Print Mortgage: display it as currency 
*/

import 'dart:io';
import 'dart:math';

void main(List<String> args) {
  const PERCENTAGE = 100;
  const MONTHS_IN_YEAR = 12;
  const MIN_PRINCIPAL = 1000;
  const MAX_PRINCIPAL = 1000000;
  const MIN_INTEREST = 0.01;
  const MAX_INTEREST = 30;
  const MIN_PERIOD = 1;
  const MAX_PERIOD = 30;

  late int period;
  late int principal;
  late double annual_interest;

  principal = readInt("Enter value (\$1K - \$1M): ", MIN_PRINCIPAL, MAX_PRINCIPAL);
  annual_interest = readDouble("Annual Interest Rate: ", MIN_INTEREST, MAX_INTEREST);

  double monthly_interest = annual_interest / PERCENTAGE / MONTHS_IN_YEAR;

  period = readInt("Period (Years): ", MIN_PERIOD, MAX_PERIOD);

  int number_of_payments = MONTHS_IN_YEAR * period;

  double mortgage = principal *
      (monthly_interest * pow(1 + monthly_interest, number_of_payments)) /
      (pow(1 + monthly_interest, number_of_payments) - 1);

  stdout.writeln("Mortgage: \$$mortgage");
}

int readInt(String prompt, int min, int max) {
  late int value;
  do {
    stdout.write(prompt);
    value = int.tryParse(stdin.readLineSync()!) ?? 0;
    if (value < min || value > max) {
      stdout.writeln("Enter a number between $min and $max");
    }
  } while (value < min || value > max);
  return value;
}

double readDouble(String prompt, double min, int max) {
  late double value;
  do {
    stdout.write(prompt);
    value = double.tryParse(stdin.readLineSync()!) ?? 0.0;
    if (value < min || value > max) {
      stdout.writeln("Enter a value between $min and $max");
    }
  } while (value < min || value > max);
  return value;
}