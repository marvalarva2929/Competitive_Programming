/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.StdDraw;

import java.awt.Color;
import java.util.ArrayList;

public class KdTree {

    private Node root;
    private int size = 0;

    private class Node {
        Node right;
        Node left;
        Point2D value;
        int level; // mod 2
        RectHV container;

        public Node(Point2D value, int level, RectHV container) {
            this.value = value;
            this.level = level % 2;
            this.container = container;
        }
    }

    public KdTree() {

    }                               // construct an empty set of points

    public boolean isEmpty() {
        return root == null;
    }                      // is the set empty?

    public int size() {
        return this.size;
    } // number of points in the set

    private Node search(Point2D p, Node x) {
        if (x == null) return null; // node not found
        if (p.equals(x.value)) return x;
        if (compare(p, x) < 0) return search(p, x.left);
        else return search(p, x.right);
    }

    public void insert(Point2D p) {
        if (!contains(p)) root = insert(p, root, 0, new RectHV(0, 0, 1, 1));
    }             // add the point to the set (if it is not already in the set)

    private Node insert(Point2D p, Node x, int newLength, RectHV box) {
        if (x == null) {
            size++;
            return new Node(p, newLength, box);
        }
        double xmin = box.xmin(), xmax = box.xmax(), ymin = box.ymin(), ymax = box.ymax();
        double px = p.x(), py = p.y(), xx = x.value.x(), xy = x.value.y();
        if (x.level == 0) { // Vertical boundaries
            if (px < xx) {
                x.left = insert(p, x.left, x.level + 1,
                                new RectHV(xmin, ymin, xx, ymax));
            }
            else if (px >= xx) {
                x.right = insert(p, x.right, x.level + 1,
                                 new RectHV(xx, ymin, xmax, ymax));
            }
        }
        else if (x.level == 1) { // Horizontal boundaries
            if (py < xy) {
                x.left = insert(p, x.left, x.level + 1,
                                new RectHV(xmin, ymin, xmax, xy));
            }
            else if (py >= xy) {
                x.right = insert(p, x.right, x.level + 1,
                                 new RectHV(xmin, xy, xmax, ymax));
            }
        }
        return x;
    }

    public boolean contains(Point2D p) {
        if (p == null)
            throw new IllegalArgumentException("you must provide a non-null value to contains()");
        return this.search(p, root) != null;
    }            // does the set contain point p?

    public void draw() {
        StdDraw.clear();
        traverseAndPrint(root);
    }                         // draw all points to standard draw

    private void traverseAndPrint(Node x) {
        if (x == null) return;
        traverseAndPrint(x.left);
        traverseAndPrint(x.right);
        double xmin = x.container.xmin(), xmax = x.container.xmax(), ymin = x.container.ymin(), ymax
                = x.container.ymax(), xx = x.value.x(), xy = x.value.y();
        if (x.level == 1) {
            StdDraw.setPenColor(Color.blue);
            StdDraw.line(xmin, xy, xmax, xy);
        }
        else if (x.level == 0) {
            StdDraw.setPenColor(Color.red);
            StdDraw.line(xx, ymin, xx, ymax);
        }
    }

    public Iterable<Point2D> range(RectHV rect) {
        if (rect == null)
            throw new IllegalArgumentException("paramaters to range() must not be null");
        ArrayList<Point2D> pointsWithinRange = new ArrayList<Point2D>();
        searchAndAdd(root, rect, pointsWithinRange);
        return pointsWithinRange;
    }             // all points that are inside the rectangle (or on the boundary)


    private void searchAndAdd(Node x, RectHV rect, ArrayList<Point2D> addTo) {
        // double xmin = rect.xmin(), xmax = rect.xmax(), ymin = rect.ymin(), ymax = rect.ymax();
        if (x == null) return;
        if (rect.contains(x.value)) {
            addTo.add(x.value);
            searchAndAdd(x.left, rect, addTo);
            searchAndAdd(x.right, rect, addTo);
            return;
        }
        if (x.left != null) {
            if (rect.intersects(x.left.container)) {
                searchAndAdd(x.left, rect, addTo);
            }
        }
        if (x.right != null) {
            if (rect.intersects(x.right.container)) {

                searchAndAdd(x.right, rect, addTo);
            }
        }
    }


    public Point2D nearest(Point2D p) {
        if (p == null)
            throw new IllegalArgumentException("paramaters to nearest() must not be null");
        if (root != null) return track(p, root, root.value);
        else return null;
    }             // a nearest neighbor in the set to point p; null if the set is empty

    private Point2D track(Point2D p, Node x, Point2D champion) {
        if (x == null) return champion;
        if (x.left == null && x.right == null) {
            return min(champion, x.value, p);
        }
        Point2D newChampion = min(champion, x.value, p);
        if (x.left != null && x.right != null) {
            if (compare(p, x) > 0) {
                newChampion = track(p, x.right, newChampion);
                if (x.left.container.distanceSquaredTo(p) <= p.distanceSquaredTo(newChampion))
                    newChampion = track(p, x.left, newChampion);
            }
            else {
                newChampion = track(p, x.left, newChampion);
                if (x.right.container.distanceSquaredTo(p) <= p.distanceSquaredTo(newChampion))
                    newChampion = track(p, x.right, newChampion);
            }
        }
        else if (x.left == null) {
            if (x.right.container.distanceSquaredTo(p) <= p.distanceSquaredTo(newChampion))
                newChampion = track(p, x.right, newChampion);
        }
        else {
            if (x.left.container.distanceSquaredTo(p) <= p.distanceSquaredTo(newChampion))
                newChampion = track(p, x.left, newChampion);
        }
        return newChampion;
    }

    private int compare(Point2D p, Node x) {
        if (x == null) return -1;
        double px = p.x(), py = p.y(), xx = x.value.x(), xy = x.value.y();
        if (xx == px && xy == py) return 1;
        if (x.level == 0) {
            if (px < xx) return -1;
            else if (px > xx) return 1;
        }
        else if (x.level == 1) {
            if (py < xy) return -1;
            else if (py > xy) return 1;
        }
        return 0;
    }

    private Point2D min(Point2D a, Point2D b, Point2D compareTo) {
        if (a.distanceSquaredTo(compareTo) < b.distanceSquaredTo(compareTo)) return a;
        else if (a.distanceSquaredTo(compareTo) >= b.distanceSquaredTo(compareTo)) return b;
        return a;
    }

    public static void main(String[] args) {

    }            // unit testing of the methods (optional)
}
