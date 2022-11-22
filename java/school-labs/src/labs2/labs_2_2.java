package src.labs2;
//parking fee
import java.util.Scanner;

public class labs_2_2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a;
		
		System.out.print("Enter the hours : ");
		a = sc.nextInt();
		sc.close();
		
		if(a <= 3) {
			System.out.print("Pay : 100Php ");
		} else if (a > 3) {
			int payment = (100 + (a - 3)*20);
			System.out.print("Pay : " + payment);
		} else{
			System.out.print("Error!!");
		}
	}

}