/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

public class Percolation {
    private final int sites;
    private final int length;
    private int[] sz;
    private int[] id;
    private int[] id2;
    private int[] sz2;
    private boolean[] open;
    private int nopen = 0;

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        if (n <= 0) throw new IllegalArgumentException("Number of sites must be greater than 0");
        this.length = n;
        this.sites = (n * n);
        sz = new int[sites + 1];
        id = new int[sites + 1];
        sz2 = new int[sites + 1];
        id2 = new int[sites + 1];
        open = new boolean[sites + 1];

        for (int i = 1; i <= sites; i++) {
            sz[i] = 1;
            sz2[i] = 1;
            open[i] = false;
            if (i <= n) { // first row
                id[i] = 0;
                sz[0] = sites; // ensure that the first row keeps the same root
                id2[i] = 0;
                sz2[0] = sites;
            }
            else if (i > sites - n) { // last row
                id[i] = sites;
                id2[i] = i;
            }
            else {
                id[i] = i;
                id2[i] = i;
            }
        }
    }

    private int xy(int p, int q) {
        return ((q) + (this.length * (p - 1)));
    }

    private void union(int p, int q) {
        if (sz[root(p)] >= sz[root(q)]) {
            id[root(q)] = root(p);
            sz[root(p)] += sz[root(q)];
            id2[root2(q)] = root2(p);
            sz2[root2(p)] += sz2[root2(q)];
        }
        else {
            id[root(p)] = root(q);
            sz[root(q)] += sz[root(p)];
            id2[root2(p)] = root2(q);
            sz2[root2(q)] += sz2[root2(p)];
        }
    }

    private int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    private int root2(int i) {
        while (i != id2[i]) {
            id2[i] = id2[id2[i]];
            i = id2[i];
        }
        return i;
    }

    // opens the site (row, col) if it is not open already
    public void open(int p, int q) {
        if (p > this.length || q > this.length || p <= 0 || q <= 0)
            throw new IllegalArgumentException(
                    "Arguments to open() must be within the domain of sites");
        if (!isOpen(p, q)) {
            if (p > 1) {
                if (isOpen(p - 1, q)) union(xy(p, q), xy(p - 1, q));
            }
            if (q > 1) {
                if (isOpen(p, q - 1)) union(xy(p, q), xy(p, q - 1));
            }
            if (p < this.length) {
                if (isOpen(p + 1, q)) union(xy(p, q), xy(p + 1, q));
            }
            if (q < this.length) {
                if (isOpen(p, q + 1)) union(xy(p, q), xy(p, q + 1));
            }
            open[xy(p, q)] = true;

            nopen += 1;
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int p, int q) {
        if (p > this.length || q > this.length || p <= 0 || q <= 0)
            throw new IllegalArgumentException(
                    "Arguments to isOpen() must be within the domain of sites");
        return open[xy(p, q)];
    }

    // is the site (row, col) full?
    public boolean isFull(int p, int q) {
        if (xy(p, q) > this.sites) throw new IllegalArgumentException(
                "Arguments to isFull() must be within the domain of sites");
        return root2(xy(p, q)) == root2(1) && isOpen(p, q);
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return nopen;
    }

    // does the system percolate?
    public boolean percolates() {
        return root(sites - 1) == root(1);
    }

    // test client (optional)
    // public static void main(String[] args) {
    //     Percolation p = new Percolation(10);
    // }
}
