package basic;

class Basics1 {
    // Private can only be used within the class and cannot be passed down. 
    // Protected is like private but can be used for inheritance.
    // Public It can be used everywhere (within the package).

    // Static keyword: Static means that the variable or method marked as such is
    // available at the class level. In other words, you don't need to create an
    // instance of the class to access it.

    // example of without static keyword:
    // public class Foo {
    //     public void doStuff() {
    //         // does stuff
    //     }

    //     public static void main(String[] args) {
    //         Foo f = new Foo();
    //         f.doStuff();
    //     }
    // }

    // example of with static keyword:
    // public class Foo {
    //     public static void doStuff() {
    //         // does stuff
    //     }

    //     public static void main(String[] args) {
    //         doStuff();
    //     }
    // }

    // Primitive types
    private static byte age = 19; // +-127
    private static int planetAge = 2_000_000_000; // around +-2 million
    private static long universeAge = 9_000_000_000_000_000_000L; // +-9 Quintillion
    private static float atoms = 2_000.123456789123456789F; // holds 8 floating point
    private static double density = 2_000.123456789123456789; // holds 11 floating point
    private static boolean isAlive = true; // true or false
    private static char startLetter = 'E'; // ASCII characters | international characters
    // Storing string or words/sentence
    // String is not a primitive type
    // String is not mutable using references
    private static String name = "Andrew Jules R. Miyajima";
    private static String planetName = startLetter + "arth";

    public static void printSentence() {
        System.out.println("I'm coding Java, my name " + name + " I'am still alive (" + isAlive + ") at age of " + age
                + " live in " + planetName + " planet age is " + planetAge + " and universe age is " + universeAge
                + " I don't know about atoms " + atoms + " and density " + density);
    }

    public static void main(String[] args) {
        printSentence();
    }
}
