import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

import java.util.ArrayList;
import java.util.Arrays;

/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */
public class BruteCollinearPoints {
    private ArrayList<LineSegment> segments;

    public BruteCollinearPoints(Point[] points) {
        if (points == null) throw new IllegalArgumentException("paramaters must not be null");
        if (containsDuplicates(points) || containsNulls(points))
            throw new IllegalArgumentException(
                    "Check to make sure that the entered number of points is greater than 4 and that the list contains no null entries or duplicates");
        this.segments = new ArrayList<LineSegment>();
        Point[] points1 = Arrays.copyOf(points, points.length);
        boolean found;
        for (int i = 0; i < points1.length; i++) {
            found = false;

            for (int j = 0; j < points1.length; j++) {
                if (j != i && !(points1[i].compareTo(points1[j]) >= 0)) {

                    for (int k = 0; k < points1.length; k++) {
                        if (points1[i].slopeTo(points1[j]) == points1[i].slopeTo(points1[k])
                                && k != i && k != j && !(points1[j].compareTo(points1[k]) >= 0)) {

                            // StdOut.printf(
                            //         "i %d, j %d, k %d, point 1: %f, point 2: %f\n",
                            //         i, j, k, points[i].slopeTo(points[j]),
                            //         points[j].slopeTo(points[k]));

                            for (int m = 0; m < points1.length; m++) {
                                if (points1[j].slopeTo(points1[k]) == points1[k].slopeTo(points1[m])
                                        && points1[k].slopeTo(points1[m]) == points1[i].slopeTo(
                                        points1[m])
                                        && m != k && m != i && m != j && !(
                                        points1[k].compareTo(points1[m]) >= 0)) {

                                    Point start = points1[i];
                                    Point end = points1[m];
                                    // if (this.points[i].compareTo(end) > 0) end = this.points[i];
                                    // else if (this.points[i].compareTo(start) < 0) start = this.points[i];
                                    // if (this.points[j].compareTo(end) > 0) end = this.points[j];
                                    // else if (this.points[j].compareTo(start) < 0) start = this.points[j];
                                    // if (this.points[k].compareTo(end) > 0) end = this.points[k];
                                    // else if (this.points[k].compareTo(start) < 0) start = points[k];
                                    // if (this.points[m].compareTo(end) > 0) end = this.points[m];
                                    // else if (this.points[m].compareTo(start) < 0) start = this.points[m];
                                    segments.add(new LineSegment(start, end));
                                    found = true;
                                    break;
                                }
                            }
                        }
                        if (found) break;
                    }
                }
                if (found) break;
            }
        }
    }  // finds all line segments containing 4 points


    public int numberOfSegments() {
        return segments.size();
    }

    public LineSegment[] segments() {
        LineSegment[] lines = new LineSegment[segments.size()];
        for (int i = 0; i < segments.size(); i++) {
            lines[i] = segments.get(i);
        }
        return lines;
    }           // the line segments

    public static void main(String[] args) {

        // read the n points from a file
        In in = new In(args[0]);
        int n = in.readInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = in.readInt();
            int y = in.readInt();
            points[i] = new Point(x, y);
        }

        // draw the points
        StdDraw.enableDoubleBuffering();
        StdDraw.setXscale(0, 32768);
        StdDraw.setYscale(0, 32768);
        for (Point p : points) {
            p.draw();
        }
        StdDraw.show();

        // print and draw the line segments
        BruteCollinearPoints collinear = new BruteCollinearPoints(points);
        for (LineSegment segment : collinear.segments()) {
            StdOut.println(segment);
            segment.draw();
        }
        StdDraw.show();
    }

    private boolean containsDuplicates(Point[] ps) {
        Point[] check = Arrays.copyOf(ps, ps.length);
        Arrays.sort(check);
        for (int i = 0; i < check.length - 1; i++) {
            if (check[i].compareTo(check[i + 1]) == 0) return true;
        }
        return false;
    }

    private boolean containsNulls(Point[] ps) {
        Point[] check = Arrays.copyOf(ps, ps.length);
        Arrays.sort(check);
        for (int i = 0; i < check.length; i++) {
            if (check[i] == null) return true;
        }
        return false;
    }
}
