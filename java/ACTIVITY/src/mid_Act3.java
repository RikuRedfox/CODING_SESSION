class Professor {
    String name;
    double salary;

    public Professor(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }
}

class Dean extends Professor {
    String department;

    public Dean(String name, double salary, String department) {
        super(name, salary);
        this.department = department;
    }

    public String toString() {
        return "Dean's name: " + name + ", Department: " + department + ", Salary: " + salary;
    }
}

class Executive extends Dean {
    public Executive (String name, double salary, String department){
        super(name, salary, department);
    }

    @Override
    public String toString() {
        return "Executive " + super.toString();
    }
}

public class mid_Act3 {
    public static void main(String[] args) {
        Dean dean = new Dean("Miguel Angel", 1_000_000.0, "Information Technology");
        System.out.println(dean);

        Executive executive = new Executive("Andrew Jules", 1_500_000.0, "Computer Science");
        System.out.println(executive);
    }
}
