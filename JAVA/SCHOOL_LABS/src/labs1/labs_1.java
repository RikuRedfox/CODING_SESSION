package src.labs1;
import java.util.Scanner;

public class labs_1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        float pq1, pq2, pex, mq1, mq2, mex, fq1, fq2, fex;

        // User input
        System.out.print("Enter your Prelim Quiz 1 : ");
        pq1 = sc.nextFloat();
        System.out.print("Enter your Prelim Quiz 2 : ");
        pq2 = sc.nextFloat();
        System.out.print("Enter your Prelim Exam : ");
        pex = sc.nextFloat();

        System.out.print("Enter your Midterm Quiz 1 : ");
        mq1 = sc.nextFloat();
        System.out.print("Enter your Midterm Quiz 2 : ");
        mq2 = sc.nextFloat();
        System.out.print("Enter your Midterm Exam : ");
        mex = sc.nextFloat();

        System.out.print("Enter your Final Quiz 1 : ");
        fq1 = sc.nextFloat();
        System.out.print("Enter your Final Quiz 2 : ");
        fq2 = sc.nextFloat();
        System.out.print("Enter your Final Exam : ");
        fex = sc.nextFloat();
        sc.close();

        // Computing the grades
        float pterm = (float) ((pq1 * .25) + (pq2 * .25) + (pex * .5));
        float mterm = (float) ((mq1 * .25) + (mq2 * .25) + (mex * .5));
        float fterm = (float) ((fq1 * .25) + (fq2 * .25) + (fex * .5));

        System.out.println("\n====================================\n");

        // Print out the result
        System.out.println("Your grade for Prelim : " + pterm);
        System.out.println("Your grade for Prelim : " + mterm);
        System.out.println("Your grade for Prelim : " + fterm);

        //overall grade w/computation
        float overall = (float) ((pterm * .3) + (mterm * .3) + (fterm * .4));

        String str_output = (overall >= 95) ? " [1.00]A+ Excellent." : 
            (overall >= 91) ? " [1.25]A Very Good." : 
                (overall >= 86) ? " [1.50]A- Very Good." :
                    (overall >= 81) ? " [1.75]B+ Good." : 
                        (overall >= 75) ? " [2.00]B Good." : 
                            (overall >= 69) ? " [2.25]B- Fair." :
                                (overall >= 63) ? " [2.50]C+ Fair." :
                                    (overall >= 57) ? " [2.75]C Fair." :
                                        (overall >= 50) ? " [3.00]C- Fair." :
                                        " [5.00]F Failed.";
        System.out.print("Your overall grade for semester : " + overall + str_output);
    }
}
