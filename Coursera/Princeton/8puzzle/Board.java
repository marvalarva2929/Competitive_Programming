import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.ArrayList;
import java.util.Arrays;

public class Board {
    private int[][] tiles;
    private ArrayList<Board> neighbors = new ArrayList<Board>();
    private int manhattan;
    private int hamming;

    // create a board from an n-by-n array of tiles,
    // where tiles[row][col] = tile at (row, col)
    public Board(int[][] tiles) {
        this.tiles = copy(tiles);
        this.hamming = calcHamming();
        this.manhattan = calcManhattan();
    }

    private void swap(int[][] a, int i, int j, int p, int q) {
        int temp = a[i][j];
        a[i][j] = a[p][q];
        a[p][q] = temp;
    }

    private int[][] copy(int[][] a) {
        return Arrays.stream(a).map(int[]::clone)
                     .toArray(int[][]::new); // No clue what this means :D
    }


    // string representation of this board
    public String toString() {
        StringBuilder buf = new StringBuilder();
        for (int i = 0; i < this.tiles.length; i++) {
            for (int j = 0; j < this.tiles.length; ++j) {
                buf.append((this.tiles[i][j]) + " ");
            }
            buf.append("\n");
        }
        String ret = this.tiles.length + "\n" + buf.toString();
        return ret;
    }

    // board dimension n
    public int dimension() {
        return this.tiles.length;
    }

    private int calcHamming() {
        int count = 0;
        for (int i = 0; i < this.tiles.length; i++) {
            for (int j = 0; j < this.tiles.length; j++) {
                int num = this.tiles[i][j];
                int goalx = (num - 1) % this.tiles.length;
                int goaly = (num - 1) / this.tiles.length;
                if (num == 0) {
                    goalx = this.tiles.length - 1;
                    goaly = this.tiles.length - 1;
                }

                if ((i != goaly || j != goalx) && num != 0) count++;
            }
        }
        return count;
    }

    // number of tiles out of place
    public int hamming() {
        return this.hamming;
    }

    private void getNeighbors() {
        int zx = 0;
        int zy = 0;
        for (int i = 0; i < this.tiles.length; i++) {
            for (int j = 0; j < this.tiles.length; j++) {
                if (this.tiles[i][j] == 0) {
                    zx = j;
                    zy = i;
                    break;
                }
            }
        }
        if (zx > 0) {
            int[][] copy = copy(this.tiles);
            swap(copy, zy, zx, zy, zx - 1);
            neighbors.add(new Board(copy));
        }
        if (zx < this.tiles.length - 1) {
            int[][] copy = copy(this.tiles);
            swap(copy, zy, zx, zy, zx + 1);
            neighbors.add(new Board(copy));
        }
        if (zy > 0) {
            int[][] copy = copy(this.tiles);
            swap(copy, zy, zx, zy - 1, zx);
            neighbors.add(new Board(copy));
        }
        if (zy < this.tiles.length - 1) {
            int[][] copy = copy(this.tiles);
            swap(copy, zy, zx, zy + 1, zx);
            neighbors.add(new Board(copy));
        }
    }

    // sum of Manhattan distances between tiles and goal
    public int manhattan() {
        return this.manhattan;
    }

    private int calcManhattan() {
        int count = 0;
        for (int i = 0; i < this.tiles.length; i++) {
            for (int j = 0; j < this.tiles.length; j++) {

                int num = this.tiles[i][j];
                int goalx = (num - 1) % this.tiles.length;
                int goaly = (num - 1) / this.tiles.length;

                int diff = Math.abs(goalx - j) + Math.abs(goaly - i);
                if (num != 0) {
                    count += Math.abs(diff);
                }
            }
        }
        return count;
    }


    // is this board the goal board?
    public boolean isGoal() {
        return this.manhattan() == 0;
    }

    // does this board equal y?
    public boolean equals(Object y) {
        if (y == this) return true;
        if (y == null) return false;
        if (y.getClass() == this.getClass()) {
            Board b = (Board) y;
            if (b.tiles.length != this.tiles.length) return false;
            for (int i = 0; i < this.tiles.length; i++) {
                for (int j = 0; j < this.tiles.length; j++) {
                    if (b.tiles[i][j] != this.tiles[i][j]) return false;
                }
            }
        }
        else return false;
        return true;
    }

    // all neighboring boards
    public Iterable<Board> neighbors() {
        if (neighbors == null || neighbors.size() == 0) getNeighbors();
        return neighbors;
    }

    // a board that is obtained by exchanging any pair of tiles
    public Board twin() {
        int[][] copy = copy(this.tiles);
        while (Arrays.deepEquals(this.tiles, copy)) {
            int i = StdRandom.uniformInt(this.tiles.length);
            int j = StdRandom.uniformInt(this.tiles.length);
            int i2 = StdRandom.uniformInt(this.tiles.length);
            int j2 = StdRandom.uniformInt(this.tiles.length);
            while (copy[i][j] == 0) i = StdRandom.uniformInt(this.tiles.length);
            while (copy[i2][j2] == 0 && (i2 == i || j2 == j)) {
                i2 = StdRandom.uniformInt(this.tiles.length);
                j2 = StdRandom.uniformInt(this.tiles.length);
            }
            swap(copy, i, j, i2, j2);
        }
        return new Board(copy);
    }

    // unit testing (not graded)
    public static void main(String[] args) {

        // create initial board from file
        In in = new In(args[0]);
        int n = in.readInt();
        int[][] tiles = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tiles[i][j] = in.readInt();

        // In in2 = new In(args[1]);
        // int n2 = in2.readInt();
        // int[][] tiles2 = new int[n2][n2];
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         tiles2[i][j] = in2.readInt();

        Board initial = new Board(tiles);
        // Board second = new Board(tiles2);
        StdOut.println(initial);
        StdOut.println(initial.twin());
    }
}
