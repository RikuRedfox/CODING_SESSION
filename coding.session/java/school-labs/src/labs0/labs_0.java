package src.labs0;
public class labs_0 {
    public static void main(String[] args) {
        
        // Prelim grades and computation
        double pq1 = 90, pq2 = 85.71, pex = 100;
        double pterm = (pq1 * .25) + (pq2 * .25) + (pex * .5);

        // Midterm grades and computation
        double mq1 = 100, mq2 = 100, mex = 98;
        double mterm = (mq1 * .25) + (mq2 * .25) + (mex * .5);

        // Final grades and computation
        double fq1 = 100, fq2 = 100, fex = 90;
        double fterm = (fq1 * .25) + (fq2 * .25) + (fex * .5);

        // Print out the result
        System.out.println("Your grade for Prelim : " + pterm);
        System.out.println("Your grade for Prelim : " + mterm);
        System.out.println("Your grade for Prelim : " + fterm);

        //overall grade w/computation
        double overall = (pterm * .3) + (mterm * .3) + (fterm * .4);
        System.out.println("Your overall grade for semester : " + overall);
    }
}
