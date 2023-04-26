/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.MinPQ;
import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class Solver {
    private Board[] route;
    private boolean solvable;

    private class SearchNode implements Comparable<SearchNode> {
        private final Board board;
        private final int moves;
        private final SearchNode previous;
        private final int priority;

        public SearchNode(Board board, SearchNode previous, int moves) {
            this.board = board;
            this.moves = moves;
            this.previous = previous;
            this.priority = (this.board.manhattan() + this.moves);
        }

        public int compareTo(SearchNode that) {
            return this.priority - that.priority;
        }
    }

    // find a solution to the initial board (using the A* algorithm)
    public Solver(Board initial) {
        if (initial == null)
            throw new IllegalArgumentException("you must provide a non-null value");
        Board twin = initial.twin();
        MinPQ<SearchNode> pq = new MinPQ<SearchNode>();
        MinPQ<SearchNode> parallel = new MinPQ<SearchNode>();
        pq.insert(new SearchNode(initial, new SearchNode(initial, null, 0), 0));
        parallel.insert(new SearchNode(twin, new SearchNode(twin, null, 0), 0));

        while (true) {
            SearchNode curr2 = parallel.delMin();
            if (curr2.board.isGoal()) {
                // StdOut.println(curr2.board + "\n" + curr2.board.manhattan());
                solvable = false;
                break;
            }
            for (Board b : curr2.board.neighbors()) {
                if (!b.equals(curr2.previous.board)) {
                    parallel.insert(new SearchNode(b, new SearchNode(curr2.board, curr2.previous,
                                                                     curr2.moves),
                                                   curr2.moves + 1));
                }
            }

            SearchNode curr = pq.delMin();
            if (curr.board.isGoal()) {
                solvable = true;
                // StdOut.println(curr.moves);
                route = new Board[curr.moves + 1];
                for (int i = curr.moves; i >= 0; i--) {
                    // StdOut.println(curr.board);
                    route[i] = curr.board;
                    curr = curr.previous;
                }
                break;
            }
            for (Board b : curr.board.neighbors()) {
                if (!b.equals(curr.previous.board)) {
                    // StdOut.println(curr.board + "\n" + curr.board.manhattan() + " - " + curr.moves);
                    pq.insert(
                            new SearchNode(b, curr, curr.moves + 1));
                }
            }

        }


    }

    // is the initial board solvable? (see below)
    public boolean isSolvable() {
        return solvable;
    }

    // min number of moves to solve initial board; -1 if unsolvable
    public int moves() {
        if (!isSolvable()) return -1;
        else return route.length - 1;
    }

    // sequence of boards in a shortest solution; null if unsolvable
    public Iterable<Board> solution() {
        if (!isSolvable()) return null;
        else return Arrays.asList(route);
    }

    // test client (see below)
    public static void main(String[] args) {

        // create initial board from file
        In in = new In(args[0]);
        int n = in.readInt();
        int[][] tiles = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tiles[i][j] = in.readInt();
        Board initial = new Board(tiles);

        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board + " " + board.manhattan());
        }
    }

}
