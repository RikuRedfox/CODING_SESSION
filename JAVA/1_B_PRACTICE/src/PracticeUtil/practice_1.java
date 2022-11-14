package src.PracticeUtil;

import java.util.*;

public class practice_1 {
    public static int getChoice(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a day from 1 to 12 : ");
        int day = sc.nextInt();
        sc.close();
        return day;
    }
    public static void main(String[] args) {
        int day = getChoice();
        String song = "My true love gave to me ";

        switch(day){
            case 1: song += "and A partridge in a pear tree"; break;
            case 2: song += "Two turtles doves"; break;
            case 3: song += "Three french hens"; break;
            case 4: song += "Four calling birds"; break;
            case 5: song += "Five golden rings"; break;
            case 6: song += "Six geese a-lating"; break;
            case 7: song += "Seven swans a-swimming"; break;
            case 8: song += "Eight maidsca-milking"; break;
            case 9: song += "Nine ladies dancing"; break;
            case 10: song += "Ten lord a-leaping"; break;
            case 11: song += "Eleven pipers piping"; break;
            case 12: song += "Twelve drummers drummers"; break;
            default: song += "NOT A VALID DAY"; break;
        }
        System.out.println(song);
    }
}
