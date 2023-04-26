/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.Bag;
import edu.princeton.cs.algs4.FlowEdge;
import edu.princeton.cs.algs4.FlowNetwork;
import edu.princeton.cs.algs4.FordFulkerson;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

import java.util.TreeMap;

public class BaseballElimination {
    private final TreeMap<String, Integer> teams;
    private final TreeMap<Integer, String> names;
    private final int[] w, r, loss;
    private final int[][] games;
    private final Bag<String>[] inCut;
    private final boolean[] eliminated;
    private final int n;

    public BaseballElimination(String filename) {
        In in = new In(filename);
        this.n = in.readInt();
        teams = new TreeMap<>();
        names = new TreeMap<>();
        eliminated = new boolean[n];
        w = new int[n];
        r = new int[n];
        loss = new int[n];
        inCut = (Bag<String>[]) new Bag[n];
        for (int i = 0; i < n; i++) inCut[i] = new Bag<String>();
        games = new int[n][n];
        for (int i = 0; i < n; i++) {
            String name = in.readString();
            teams.put(name, i);
            names.put(i, name);
            w[i] = in.readInt();
            loss[i] = in.readInt();
            r[i] = in.readInt();
            for (int j = 0; j < n; j++) {
                games[i][j] = in.readInt();
            }
        }
        for (int team : teams.values()) {
            findEliminations(team, ((n - 1) * (n - 2) / 2) + this.games.length + 1);
        }
    }                // create a baseball division from given filename in format specified below

    public int numberOfTeams() {
        return this.teams.size();
    }                  // number of teams

    public Iterable<String> teams() {
        return this.teams.keySet();
    }                                // all teams

    public int wins(String team) {
        if (!teams.containsKey(team)) throw new IllegalArgumentException();
        return w[teams.get(team)];
    }                      // number of wins for given team

    public int losses(String team) {
        if (!teams.containsKey(team)) throw new IllegalArgumentException();
        return loss[teams.get(team)];
    }

    // number of losses for given team
    public int remaining(String team) {
        if (!teams.containsKey(team)) throw new IllegalArgumentException();
        return r[teams.get(team)];
    }                 // number of remaining games for given team

    public int against(String team1, String team2) {
        if (!teams.containsKey(team1) || !teams.containsKey(team2))
            throw new IllegalArgumentException();
        return games[teams.get(team1)][teams.get(team2)];
    }    // number of remaining games between team1 and team2

    public boolean isEliminated(String team) {
        if (!teams.containsKey(team)) throw new IllegalArgumentException();
        return eliminated[teams.get(team)];
    }         // is given team eliminated?

    public Iterable<String> certificateOfElimination(String team) {
        if (!teams.containsKey(team)) throw new IllegalArgumentException();
        return inCut[teams.get(team)];
    } // subset R of teams that eliminates given team; null if not eliminated

    private void findEliminations(int s, int t) {
        int pairs = this.games.length;
        FlowNetwork flowNetwork = new FlowNetwork(
                (((this.n - 1) * (this.n - 2) / 2) + this.games.length) + 2);
        for (int i = 0; i < this.games.length; i++) {
            for (int j = i; j < this.games.length; j++) {
                if (i != s && j != s && j != i) {
                    flowNetwork.addEdge(new FlowEdge(s, pairs, games[i][j]));
                    flowNetwork.addEdge(new FlowEdge(pairs, i, Double.POSITIVE_INFINITY));
                    flowNetwork.addEdge(new FlowEdge(pairs, j, Double.POSITIVE_INFINITY));
                    pairs++;
                }
            }
            int gamesLeft = w[s] + r[s] - w[i];
            if (gamesLeft < 0) {
                eliminated[s] = true;
                inCut[s].add(names.get(i));
                return;
            }
            flowNetwork.addEdge(new FlowEdge(i, t, gamesLeft));
            // StdOut.printf(flowNetwork.toString() + "\n");
        }

        FordFulkerson test = new FordFulkerson(flowNetwork, s, t);
        for (FlowEdge edge : flowNetwork.adj(s))
            if (edge.capacity() != edge.flow()) {
                eliminated[s] = true;
            }
        // else StdOut.printf(edge.toString() + "\n");

        if (eliminated[s]) {
            for (int i = 0; i < this.games.length; i++)
                if (test.inCut(i) && i != s)
                    inCut[s].add(names.get(i));
        }
        else {
            inCut[s] = null;
        }

    }

    public static void main(String[] args) {
        BaseballElimination division = new BaseballElimination(args[0]);
        for (String team : division.teams()) {
            if (division.isEliminated(team)) {
                StdOut.print(team + " is eliminated by the subset R = { ");
                for (String t : division.certificateOfElimination(team)) {
                    StdOut.print(t + " ");
                }
                StdOut.println("}");
            }
            else {
                StdOut.println(team + " is not eliminated");
            }
        }
    }
}
