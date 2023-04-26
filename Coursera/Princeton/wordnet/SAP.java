/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class SAP {
    private final Digraph graph;
    private int prevV;
    private int prevW;
    private int cachedAnc;
    private int cachedDist;
    private final int vertices;

    // constructor takes a digraph (not necessarily a DAG)
    public SAP(Digraph G) {
        this.graph = new Digraph(G);
        this.vertices = G.V();
        // StdOut.printf("%d\n", G.V());

    }


    private int bfsDist(int v, int w) {
        Queue<Integer> list = new Queue<Integer>();
        boolean[] visited = new boolean[this.vertices];
        int[] distTo = new int[this.vertices];
        if (v == Integer.MAX_VALUE || w == Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (v == w) return 0;
        list.enqueue(v);
        distTo[v] = 0;
        while (!list.isEmpty()) {
            int curr = list.dequeue();
            visited[curr] = true;
            for (int adj : this.graph.adj(curr)) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    list.enqueue(adj);
                    distTo[adj] = distTo[curr] + 1;
                    if (adj == w) return distTo[curr] + 1;
                }
            }
        }
        return Integer.MAX_VALUE;
    }

    private int[] calculate(int v, int w) {
        Queue<Integer> listv = new Queue<Integer>();
        Queue<Integer> listw = new Queue<Integer>();
        boolean[] visitedV = new boolean[this.vertices];
        boolean[] visitedW = new boolean[this.vertices];
        if (v == w) return new int[] { 0, v };
        listv.enqueue(v);
        listw.enqueue(w);
        visitedV[v] = true;
        visitedW[w] = true;
        int currMin = Integer.MAX_VALUE;
        int currMinDist = Integer.MAX_VALUE;
        while (!listv.isEmpty() || !listw.isEmpty()) {
            if (!listv.isEmpty()) {
                int curr = listv.dequeue();
                for (int next : this.graph.adj(curr)) {
                    if (!visitedV[next]) {
                        int distTo = bfsDist(v, next) + bfsDist(w, next);
                        visitedV[next] = true;
                        listv.enqueue(next);
                        if (visitedW[next] && distTo < currMinDist) {
                            // StdOut.printf(
                            //         "Potential next could be %d, with a distance of %d, to beat %d\n",
                            //         next, distTo, currMinDist);
                            currMin = next;
                            currMinDist = distTo;
                        }
                    }
                }
            }
            if (!listw.isEmpty()) {
                int curr = listw.dequeue();

                visitedW[curr] = true;
                for (int next : this.graph.adj(curr)) {
                    if (!visitedW[next]) {
                        int distTo = bfsDist(v, next) + bfsDist(w, next);
                        visitedW[next] = true;
                        listw.enqueue(next);
                        if (visitedV[next] && distTo < currMinDist) {
                            // StdOut.printf(
                            //         "Potential next could be %d, with a distance of %d, to beat %d\n",
                            //         next, distTo, currMinDist);
                            currMin = next;
                            currMinDist = distTo;
                        }

                    }
                }
            }
        }
        if (currMinDist == Integer.MAX_VALUE) return new int[] { -1, -1 };
        else return new int[] { currMinDist, currMin };
    }

    // length of shortest ancestral path between v and w; -1 if no such path
    public int length(int v, int w) {
        if (v >= this.vertices || w >= this.vertices || v < 0 || w < 0)
            throw new IllegalArgumentException(
                    "arguments to SAP.length() must be within the range of the ");
        if (v == this.prevV && w == this.prevW) return cachedDist;
        else {
            prevV = v;
            prevW = w;
            int[] values = calculate(v, w);
            cachedAnc = values[1];
            cachedDist = values[0];
            return cachedDist;
        }
    }

    // a common ancestor of v and w that participates in a shortest ancestral path; -1 if no such path
    public int ancestor(int v, int w) {
        if (v >= this.vertices || w >= this.vertices || v < 0 || w < 0)
            throw new IllegalArgumentException(
                    "arguments to SAP.ancestor() must be within the range of the ");
        if (v == this.prevV && w == this.prevW) return cachedAnc;
        else {
            prevV = v;
            prevW = w;
            int[] values = calculate(v, w);
            cachedAnc = values[1];
            cachedDist = values[0];
            return cachedAnc;
        }
    }

    // length of shortest ancestral path between any vertex in v and any vertex in w; -1 if no such path
    public int length(Iterable<Integer> v, Iterable<Integer> w) {
        if (v == null || w == null)
            throw new IllegalArgumentException("Arguments to SAP must not be null");
        int minAncestor = Integer.MAX_VALUE;
        for (int i : v) {
            for (int j : w) {
                if (i > this.vertices || j > this.vertices || i < 0 || j < 0)
                    throw new IllegalArgumentException(
                            "arguments to SAP.ancestor() must be within the range of the graph");
                int[] distance = calculate(i, j);
                if (distance[0] < minAncestor) minAncestor = distance[0];
            }
        }
        return minAncestor == Integer.MAX_VALUE ? -1 : minAncestor;
    }

    // a common ancestor that participates in shortest ancestral path; -1 if no such path
    public int ancestor(Iterable<Integer> v, Iterable<Integer> w) {
        if (v == null || w == null)
            throw new IllegalArgumentException("Arguments to SAP must not be null");
        int minAncestor = Integer.MAX_VALUE;
        int answer = -1;
        for (int i : v) {
            for (int j : w) {
                if (i > this.vertices || j > this.vertices || i < 0 || j < 0)
                    throw new IllegalArgumentException(
                            "arguments to SAP.ancestor() must be within the range of the graph");
                int[] distance = calculate(i, j);
                if (distance[0] < minAncestor) {
                    minAncestor = distance[0];
                    answer = distance[1];
                }
            }
        }
        return answer;
    }

    // do unit testing of this class
    public static void main(String[] args) {
        In in = new In(args[0]);
        Digraph G = new Digraph(in);
        SAP sap = new SAP(G);
        while (!StdIn.isEmpty()) {
            int v = StdIn.readInt();
            int w = StdIn.readInt();
            int length = sap.length(v, w);
            int ancestor = sap.ancestor(v, w);
            //
            StdOut.printf("length = %d, ancestor = %d\n", length, ancestor);

        }
    }
}
