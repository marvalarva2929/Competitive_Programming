/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private int size = 0;
    private Node first, last;

    private class Node {
        Item item;
        Node after;
        Node before;
    }

    public RandomizedQueue() {
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

    public Item sample() {
        Item item = removeFirst();
        addLast(item);
        return item;
    }

    // add the item to the front
    public void enqueue(Item item) {
        size++;
        if (StdRandom.bernoulli(0.5)) addFirst(item);
        else addLast(item);
    }

    // remove and return the item from the back
    public Item dequeue() {
        size--;
        return removeFirst();
    }

    // add the item to the front
    private void addFirst(Item item) {
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
    }

    // add the item to the back
    private void addLast(Item item) {
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
    }

    // remove and return the item from the front
    private Item removeFirst() {
        if (isEmpty())
            throw new NoSuchElementException("You cannot remove an element from an empty stack");
        Item item = first.item;
        first = first.after;
        if (isEmpty()) last = null;
        return item;
    }

    // remove and return the item from the back
    // private Item removeLast() {
    //     if (isEmpty())
    //         throw new NoSuchElementException("You cannot remove an element from an empty stack");
    //     Item item = last.item;
    //     last = last.before;
    //     if (last == null) first = null;
    //     return item;
    // }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {
        return new QueueIterator();
    }

    private class QueueIterator implements Iterator<Item> {
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
        RandomizedQueue<Integer> d = new RandomizedQueue<Integer>();
        for (int i = 0; i < n; i++) {
            int x = StdIn.readInt();
            String inst = StdIn.readString();
            switch (inst) {
                case "en":
                    d.enqueue(x);
                    break;
                case "de":
                    StdOut.println(d.dequeue());
                    break;
                case "s":
                    StdOut.println(d.sample());
                    break;
            }
        }
    }
}
