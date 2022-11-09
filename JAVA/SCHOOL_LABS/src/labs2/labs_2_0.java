package src.labs2;
// 1st and second
import java.util.Scanner;

public class labs_2_0 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a;
		//int b;
		
		System.out.print("Enter first number : ");
		a = sc.nextInt();
		/*
	 	System.out.print("Enter second number : ");
		b = sc.nextInt();
		*/
		sc.close();
		
		
		if(a%2 == 0) {
			System.out.println("The number are even!");
		} else {
			System.out.println("The number are odd!");
		}

	}

}
