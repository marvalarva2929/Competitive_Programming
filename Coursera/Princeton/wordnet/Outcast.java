/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class Outcast {
    private final WordNet wordnet;

    public Outcast(WordNet wordnet) {
        this.wordnet = wordnet;
    }    // constructor takes a WordNet object

    public String outcast(String[] nouns) {
        int maxDist = Integer.MIN_VALUE;
        int outcast = 0;
        for (int i = 0; i < nouns.length; i++) {
            int totalDist = 0;
            for (int j = 0; j < nouns.length; j++) {
                totalDist += wordnet.distance(nouns[i], nouns[j]);
            }
            if (totalDist >= maxDist) {
                maxDist = totalDist;
                outcast = i;
            }
            // StdOut.printf("%s distance is: %d\n", nouns[i], totalDist);
        }
        return nouns[outcast];
    }  // given an array of WordNet nouns, return an outcast

    public static void main(String[] args) {
        WordNet wordnet = new WordNet(args[0], args[1]);
        Outcast outcast = new Outcast(wordnet);
        for (int t = 2; t < args.length; t++) {
            In in = new In(args[t]);
            String[] nouns = in.readAllStrings();
            StdOut.println(args[t] + ": " + outcast.outcast(nouns));
        }
    }
}
