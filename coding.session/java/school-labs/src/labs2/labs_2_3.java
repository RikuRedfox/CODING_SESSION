package src.labs2;
// zero and pos nega
import java.util.Scanner;

public class labs_2_3 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a;
		
		System.out.print("Enter number : ");
		a = sc.nextInt();
		sc.close();
		
		String str_output = (a == 0) ? "The number are Zero!" : 
			(a > 0) ? "The number are Positive!" : 
				(a < 0) ? "The number are Zero!" : "Out of range!";
		System.out.println(str_output);
	}

}