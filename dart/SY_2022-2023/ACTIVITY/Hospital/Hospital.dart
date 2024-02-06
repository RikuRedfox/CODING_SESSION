import 'dart:io';

class Date {
  int? year;
  int? month;
  int? day;

  Date({this.year, this.month, this.day});
}

class Patient {
  String? name;
  Date? date_of_admission;
  String? disease;
  Date? date_of_discharge;

  Patient(
      {this.name,
      this.date_of_admission,
      this.disease,
      this.date_of_discharge});

  factory Patient.enterInformation() {
    stdout.write('Enter patient name: ');
    final name = stdin.readLineSync()!;
    final date_of_admission = _enterDate('Enter date of admission');
    stdout.write('Enter disease: ');
    final disease = stdin.readLineSync()!;
    final date_of_discharge = _enterDate('Enter date of discharge');

    return Patient(
      name: name,
      date_of_admission: date_of_admission,
      disease: disease,
      date_of_discharge: date_of_discharge,
    );
  }

  static Date _enterDate(String prompt) {
    stdout.write('$prompt\nEnter year: ');
    final year = int.parse(stdin.readLineSync()!);
    stdout.write('Enter month: ');
    final month = int.parse(stdin.readLineSync()!);
    stdout.write('Enter day: ');
    final day = int.parse(stdin.readLineSync()!);

    return Date(year: year, month: month, day: day);
  }

  void displayInformation() {
    print('Patient name: $name');
    print('Date of admission: ${_formatDate(date_of_admission)}');
    print('Disease: $disease');
    print('Date of discharge: ${_formatDate(date_of_discharge)}');
  }

  String _formatDate(Date? date) {
    return date != null ? '${date.year}-${date.month}-${date.day}' : 'N/A';
  }
}

class PediatricPatient extends Patient {
  late int age;

  void enterAge() {
    stdout.write('Enter age: ');
    age = int.parse(stdin.readLineSync()!);
  }

  /// @ISSUE: DISPLAYING NULL
  @override
  void displayInformation() {
    print('Patient name: $name');
    print('Date of admission: ${_formatDate(date_of_admission)}');
    print('Disease: $disease');
    print('Date of discharge: ${_formatDate(date_of_discharge)}');
    print('Age: $age');
  }

  String _formatDate(Date? date) {
    // return date != null ? '${date.year}-${date.month}-${date.day}' : 'N/A';
    if (date != null &&
        date.year != null &&
        date.month != null &&
        date.day != null)
      return '${date.year}-${date.month}-${date.day}';
    else
      return 'N/A';
  }
}

void main() {
  List<Patient> patients = [];
  List<PediatricPatient> pediatricPatients = [];

  while (true) {
    print('\n1.) Enter patient information');
    print('2.) Display list of all patients');
    print('3.) Display list of pediatric patients');
    print('4.) Exit');

    stdout.write('\nEnter your choice: ');
    final choice = stdin.readLineSync()!;

    switch (choice) {
      case '1':
        final patient = Patient.enterInformation();
        patients.add(patient);

        final age = PediatricPatient();
        age.enterAge();
        pediatricPatients.add(age);
        break;
      case '2':
        if (patients.isEmpty) {
          print('No patients found? :3');
        } else {
          for (final patient in patients) {
            patient.displayInformation();
            print('');
          }
        }
        break;
      case '3':
        if (patients.isEmpty) {
          print('No patients found? :3');
        } else {
          for (final pediatricPatient in pediatricPatients) {
            pediatricPatient.displayInformation();
          }
        }

        break;
      case '4':
        print('Exiting the program? Yes, thanks! :3');
        return;
      default:
        print('Syntax error?');
        break;
    }
  }
}

// Bullshit, but atleast its working?