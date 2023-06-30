import java.util.ArrayList;
import java.util.Scanner;

// Class to represent a date
class Date {
    int year;
    int month;
    int day;

    // A Contructor to initialize the date
    public Date(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }
}

// Class to represent a patient
class Patient {
    String name;
    Date dateOfAdmission;
    String disease;
    Date dateOfDischarge;

    // Constructor to initialize the patient
    public Patient(String name, Date dateOfAdmission, String disease, Date dateOfDischarge) {
        this.name = name;
        this.dateOfAdmission = dateOfAdmission;
        this.disease = disease;
        this.dateOfDischarge = dateOfDischarge;
    }

    // Method to displat the patient's information.
    public void display() {
        System.out.println("Name: " + name);
        System.out.println(
                "Date of Admission: " + dateOfAdmission.day + "/" + dateOfAdmission.month + "/" + dateOfAdmission.year);
        System.out.println("Disease: " + disease);
        System.out.println(
                "Date of Discharge: " + dateOfDischarge.day + "/" + dateOfDischarge.month + "/" + dateOfDischarge.year);
    }
}

// Class to represent a Pediatric Patient
// (Pediatric Patient also have Patient attribute because of
// Inheritance[extends])
class PediatricPatient extends Patient {
    int age;

    // Contructor to initialize the pediatric patient
    // (super keyword is refering to the parent class)
    public PediatricPatient(String name, Date dateOfAdmission, String disease, Date dateOfDischarge, int age) {
        super(name, dateOfAdmission, disease, dateOfDischarge);
        this.age = age;
    }

    // Override the parent class Patient display method
    // to display pediatric patient information
    @Override
    public void display() {
        super.display();
        System.out.println("Age: " + age);
    }
}

class Hospital {
    // An ArrayList to store the patients in the hospital
    ArrayList<Patient> patients;

    // Constructor to initialize the patients ArrayList
    public Hospital() {
        patients = new ArrayList<>();
    }

    // Method to add a patient to the hospital
    public void addPatient(Patient patient) {
        patients.add(patient);
    }

    // Method to display all patients in the Hospital
    public void displayAllPatients() {
        for (Patient patient : patients) {
            patient.display();
            System.out.println();
        }
    }

    // Method to displat only pediatric patients (Patient that is under 12 yrs old)
    public void displayPediatricPatients() {
        for (Patient patient : patients) {
            // Check if the patient is an instance of PediatricPatient
            // and if their age is less than 12
            if (patient instanceof PediatricPatient && ((PediatricPatient) patient).age < 12) {
                // If both conditions are true, display the patient's information
                patient.display();
                System.out.println();
            }
        }
    }
}

class mid_Act2 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        Hospital hospital = new Hospital();

        Patient patient1 = new Patient(
                "Andrew Jules", new Date(2023, 4, 1), "Flu", new Date(2023, 4, 5));
        PediatricPatient patient2 = new PediatricPatient(
                "Miguel Angel", new Date(2023, 4, 2), "Cold", new Date(2023, 4, 6), 7);
        PediatricPatient patient3 = new PediatricPatient(
                "Jan Yve Kyle", new Date(2023, 3, 14), "Covid-19", new Date(2023, 4, 9), 11);
        Patient patient4 = new Patient(
                "Jayson", new Date(2021, 1, 6), "Leukemia", new Date(2023, 4, 17));

        hospital.addPatient(patient1);
        hospital.addPatient(patient2);
        hospital.addPatient(patient3);
        hospital.addPatient(patient4);

        /*
         * System.out.print("Enter the number of patients: ");
         * int numPatients = sc.nextInt();
         * 
         * for (int i = 0; i < numPatients; i++) {
         * sc.nextLine();
         * System.out.print("Enter patient name: ");
         * String name = sc.nextLine();
         * 
         * System.out.print("Enter admission date (yyyy mm dd): ");
         * int year = sc.nextInt();
         * int month = sc.nextInt();
         * int day = sc.nextInt();
         * Date admissionDate = new Date(year, month, day);
         * 
         * System.out.print("Enter illness: ");
         * String illness = sc.next();
         * 
         * System.out.print("Enter release date (yyyy mm dd): ");
         * year = sc.nextInt();
         * month = sc.nextInt();
         * day = sc.nextInt();
         * Date releaseDate = new Date(year, month, day);
         * 
         * System.out.print("Is this a pediatric patient? (y/n): ");
         * String isPediatric = sc.next();
         * 
         * if (isPediatric.equalsIgnoreCase("y") || isPediatric.equalsIgnoreCase("yes"))
         * {
         * System.out.print("Enter age: ");
         * int age = sc.nextInt();
         * 
         * PediatricPatient patient = new PediatricPatient(
         * name, admissionDate, illness, releaseDate, age);
         * hospital.addPatient(patient);
         * } else if (isPediatric.equalsIgnoreCase("n") ||
         * isPediatric.equalsIgnoreCase("no")) {
         * Patient patient = new Patient(
         * name, admissionDate, illness, releaseDate);
         * hospital.addPatient(patient);
         * } else {
         * return;
         * }
         * }
         */

        System.out.println("All Patients:");
        hospital.displayAllPatients();

        System.out.println("Pediatric Patients:");
        hospital.displayPediatricPatients();
    }
}