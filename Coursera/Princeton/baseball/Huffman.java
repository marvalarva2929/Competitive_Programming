import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.MinPQ;
import edu.princeton.cs.algs4.StdOut;

public class Huffman {
    public class Letter implements Comparable<Letter> {
        public int weight;
        public int letter;
        public int minHeight;
        public int maxHeight;
        private final Letter left;
        private final Letter right;

        Letter(Letter r, Letter lef) {
            this.left = lef;
            this.right = r;
        }

        public int compareTo(Letter that) {
            return Integer.compare(this.weight, that.weight);
        }
    }

    Huffman() {
        In in = new In("huffman.in");
        int n = in.readInt();
        int minLength = Integer.MAX_VALUE;
        int maxLength = Integer.MIN_VALUE;
        MinPQ<Letter> nextLetter = new MinPQ<>();
        for (int i = 0; i < n; i++) {
            int weight = in.readInt();
            Letter newLetter = new Letter(null, null);
            newLetter.weight = weight;
            newLetter.letter = i;
            newLetter.minHeight = 0;
            newLetter.maxHeight = 0;
            nextLetter.insert(newLetter);
        }
        while (nextLetter.size() > 1) {
            Letter left = nextLetter.delMin();
            Letter right = nextLetter.delMin();
            Letter ancestor = new Letter(left, right);
            ancestor.minHeight = Math.min(left.minHeight, right.minHeight) + 1;
            ancestor.maxHeight = Math.max(left.maxHeight, right.maxHeight) + 1;
            maxLength = Math.max(maxLength, ancestor.maxHeight);
            ancestor.weight = left.weight + right.weight;
            nextLetter.insert(ancestor);
        }
       
    }


    public static void main(String[] args) {
        Huffman huff = new Huffman();
    }
}
