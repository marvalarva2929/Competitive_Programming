/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;


public class PercolationStats {
    private static final double CONFIDENCE_95 = 1.96;
    private double[] values;
    private double trials;

    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) {
        this.trials = trials;
        this.values = new double[trials];


        for (int i = 0; i < trials; i++) {
            Percolation p = new Percolation(n);
            while (!p.percolates()) {
                int x = StdRandom.uniformInt(1, n + 1);
                int y = StdRandom.uniformInt(1, n + 1);
                p.open(x, y);
            }
            this.values[i] = (double) p.numberOfOpenSites() / (n * n);
        }
    }


    // sample mean of percolation threshold
    public double mean() {
        return StdStats.mean(values);
    }

    //
    // // sample standard deviation of percolation threshold
    public double stddev() {
        return StdStats.stddev(values);
    }

    //
    // // low endpoint of 95% confidence interval
    public double confidenceLo() {
        double lo;
        lo = mean() - ((CONFIDENCE_95 * stddev()) / Math.sqrt(this.trials));
        return lo;
    }

    //
    // // high endpoint of 95% confidence interval
    public double confidenceHi() {
        double high;
        high = mean() + ((CONFIDENCE_95 * stddev()) / Math.sqrt(this.trials));
        return high;
    }

    // test client (see below)
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        PercolationStats ps = new PercolationStats(n, trials);
        if (!(trials > 0) || !(n > 0)) throw new IllegalArgumentException(
                "The amount of entered trials must be an integer above 0");
        StdOut.println("mean = " + ps.mean());
        StdOut.println("stddev = " + ps.stddev());
        StdOut.println(
                "95 confidence interval = [" + ps.confidenceLo() + ", " + ps.confidenceHi() + "]");
    }

}
