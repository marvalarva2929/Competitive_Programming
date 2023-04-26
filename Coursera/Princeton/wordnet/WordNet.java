/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.DirectedCycle;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.Topological;

import java.util.ArrayList;
import java.util.TreeMap;
import java.util.TreeSet;

public class WordNet {
    private final ArrayList<String> synsets;
    private final SAP shortest;
    private final TreeMap<String, ArrayList<Integer>> indeces;
    private final TreeSet<String> allWords;

    // constructor takes the name of the two input files
    public WordNet(String synsets, String hypernyms) {
        if (synsets == null || hypernyms == null)
            throw new IllegalArgumentException("Arguments to WordNet() must not be null");
        In in = new In((synsets));
        In in2 = new In((hypernyms));
        this.synsets = new ArrayList<String>();
        this.indeces = new TreeMap<>();
        this.allWords = new TreeSet<String>();
        while (in.hasNextLine()) {
            String[] line = in.readLine().split(",");
            String[] syns = line[1].split(" ");
            for (String syn : syns) {
                if (indeces.get(syn) == null) indeces.put(syn, new ArrayList<Integer>());
                ArrayList<Integer> toAdd = indeces.get(syn);
                toAdd.add(Integer.parseInt(line[0]));
                indeces.put(syn, toAdd);
                allWords.add(syn);
            }
            this.synsets.add(Integer.parseInt(line[0]), line[1]);
        }
        Digraph tree = new Digraph(this.synsets.size());
        while (in2.hasNextLine()) {
            String[] line = in2.readLine().split(",");
            int hyponym = Integer.parseInt(line[0]);
            for (int i = 1; i < line.length; i++) tree.addEdge(hyponym, Integer.parseInt(line[i]));
        }
        Topological b = new Topological(tree);
        DirectedCycle a = new DirectedCycle(tree);
        if (!b.hasOrder() || a.hasCycle())
            throw new IllegalArgumentException("arguments to WordNet must be a rooted DAG");
        this.shortest = new SAP(tree);
    }


    // returns all WordNet nouns
    public Iterable<String> nouns() {
        return synsets;
    }

    // is the word a WordNet noun?
    public boolean isNoun(String word) {
        if (word == null)
            throw new IllegalArgumentException("arguments to isNoun must not be null");
        return this.allWords.contains(word);
    }

    // distance between nounA and nounB (defined below)
    public int distance(String nounA, String nounB) {
        if (!isNoun(nounA) || !isNoun(nounB))
            throw new IllegalArgumentException(
                    "Arguments to WordNet.distance() must be nouns " + nounA + ": " + nounB
                            + " are not part of this wordNet");
        return shortest.length(indeces.get(nounA), indeces.get(nounB));
    }

    // a synset (second field of synsets.txt) that is the common ancestor of nounA and nounB
    // in a shortest ancestral path (defined below)
    public String sap(String nounA, String nounB) {
        if (!isNoun(nounA) || !isNoun(nounB))
            throw new IllegalArgumentException("Arguments to WordNet.sap() must be nouns");
        int ancestor = shortest.ancestor(indeces.get(nounA), indeces.get(nounB));
        return synsets.get(ancestor);
    }

    // do unit testing of this class
    public static void main(String[] args) {
        if (args.length != 2) throw new IllegalArgumentException(
                "confirm that the command line arguments contain two files");
        WordNet wordnet = new WordNet(args[0], args[1]);
        while (!StdIn.isEmpty()) {
            String v = StdIn.readString();
            String w = StdIn.readString();
            int length = wordnet.distance(v, w);
            String ancestor = wordnet.sap(v, w);
            //
            StdOut.printf("length = %d, ancestor = %s\n", length, ancestor);
            // StdOut.printf("1: %s\n", Arrays.toString(sap.bfs(v, false)));
            // StdOut.printf("2: %s\n", Arrays.toString(sap.bfs(w, false)));
        }
    }
}
