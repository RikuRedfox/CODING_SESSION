package src;

//Conditions and Booleans. if else.
public class practice_2 {
    public static void main(String[] args) {
        /* 
        > Greater than              |
        < Less Than                 |
        == Equal to                 |
        >= Greater than or equal to |
        <= Less than or equal to    |
        != Not equal                |
        && logical and              |
        || logical or               |
        */

        float x=.3f,
         y=72,
         z=8;

        boolean compare = (z <= y+x || z > x*y) || (z/y <= z/x || y+x >= x+x );
        //output
        System.out.println(compare);

        // --------------------------------------
        
        int a = 76, b = 74;

        if(a > 74){
            System.out.println("'Passed'");
        } else {
            System.out.println("'False'");
        }

        if(b > 74){
            System.out.println("'Passed'");
        } else {
            System.out.println("'False'");
        }
    }
}
