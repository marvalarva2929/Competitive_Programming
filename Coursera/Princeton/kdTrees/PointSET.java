/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.SET;
import edu.princeton.cs.algs4.StdDraw;

import java.util.ArrayList;

public class PointSET {

    private SET<Point2D> points;

    public PointSET() {
        this.points = new SET<Point2D>();
    }                               // construct an empty set of points

    public boolean isEmpty() {
        return this.points.isEmpty();
    }                      // is the set empty?

    public int size() {
        return this.points.size();
    } // number of points in the set

    public void insert(Point2D p) {
        if (p == null)
            throw new IllegalArgumentException("you must provide a non-null value to insert()");
        this.points.add(p);
    }             // add the point to the set (if it is not already in the set)

    public boolean contains(Point2D p) {
        if (p == null)
            throw new IllegalArgumentException("you must provide a non-null value to contains()");
        return this.points.contains(p);
    }            // does the set contain point p?

    public void draw() {
        StdDraw.clear();
        for (Point2D p : this.points) {
            StdDraw.point(p.x(), p.y());
        }
    }                         // draw all points to standard draw

    public Iterable<Point2D> range(RectHV rect) {
        if (rect == null)
            throw new IllegalArgumentException("you must provide a non-null value to contains()");
        ArrayList<Point2D> pointsWithinRange = new ArrayList<Point2D>();
        double xmin = rect.xmin(), xmax = rect.xmax(), ymin = rect.ymin(), ymax = rect.ymax();
        for (Point2D p : this.points)
            if (p.x() <= xmax && p.x() >= xmin && p.y() <= ymax && p.y() >= ymin)
                pointsWithinRange.add(p);
        return pointsWithinRange;
    }             // all points that are inside the rectangle (or on the boundary)

    public Point2D nearest(Point2D p) {
        if (p == null)
            throw new IllegalArgumentException("you must provide a non-null value to contains()");
        if (this.points.isEmpty()) return null;
        Point2D min = this.points.min();
        for (Point2D t : this.points) {
            if (p.distanceSquaredTo(t) < p.distanceSquaredTo(min)) min = t;
        }
        return min;
    }             // a nearest neighbor in the set to point p; null if the set is empty

    public static void main(String[] args) {

    }            // unit testing of the methods (optional)
}
