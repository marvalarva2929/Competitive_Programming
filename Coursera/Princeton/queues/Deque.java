/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
    private int size = 0;
    private Node first, last;

    private class Node {
        Item item;
        Node after;
        Node before;
    }

    public Deque() {
        first = null;
        last = null;
    }

    // is the deque empty?
    public boolean isEmpty() {
        return first == null;
    }


    // return the number of items on the deque
    public int size() {
        return size;
    }


    // add the item to the front
    public void addFirst(Item item) {
        if (item == null)
            throw new IllegalArgumentException("Additions to the dequeue must not be null");
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        if (last == null) {
            last = first;
        }
        else {
            first.after = oldfirst;
            oldfirst.before = first;
        }
        size++;
    }

    // add the item to the back
    public void addLast(Item item) {
        if (item == null)
            throw new IllegalArgumentException("Additions to the dequeue must not be null");
        Node oldlast = last;
        last = new Node();
        last.item = item;
        if (isEmpty()) {
            first = last;
        }
        else {
            oldlast.after = last;
            last.before = oldlast;
        }
        size++;
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if (isEmpty())
            throw new NoSuchElementException("You cannot remove an element from an empty stack");
        Item item = first.item;
        first = first.after;
        if (isEmpty()) last = null;
        else first.before = null;
        size--;
        return item;
    }

    // remove and return the item from the back
    public Item removeLast() {
        if (isEmpty())
            throw new NoSuchElementException("You cannot remove an element from an empty stack");
        Item item = last.item;
        last = last.before;
        if (last == null) first = null;
        else last.after = null;
        size--;
        return item;
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {
        return new DequeIterator();
    }

    private class DequeIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {
            return (current != null);
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException(
                    "You cannot access the next element in the stack because it doesn't exist");
            Item item = current.item;
            current = current.after;
            return item;
        }

        public void remove() {
            throw new UnsupportedOperationException("Remove is not supported");
        }
    }

    // unit testing (required)
    public static void main(String[] args) {
        int n;
        n = StdIn.readInt();
        Deque<Integer> d = new Deque<Integer>();
        for (int i = 0; i < n; i++) {
            int x = StdIn.readInt();
            String inst = StdIn.readString();
            switch (inst) {
                case "rf":
                    d.removeFirst();
                    break;
                case "rl":
                    d.removeLast();
                    break;
                case "af":
                    d.addFirst(x);
                    break;
                case "al":
                    d.addLast(x);
                    break;
            }
        }
        for (int x : d) StdOut.print(x);
    }
}
