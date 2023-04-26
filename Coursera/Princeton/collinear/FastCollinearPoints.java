/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class FastCollinearPoints {
    private ArrayList<LineSegment> segments;
    private Point[] points;

    public FastCollinearPoints(Point[] points) {
        if (points == null) throw new IllegalArgumentException("paramaters must not be null");
        if (containsDuplicates(points) || containsNulls(points))
            throw new IllegalArgumentException(
                    "Check to make sure that the entered number of points is greater than 4 and that the list contains no null entries or duplicates");
        this.segments = new ArrayList<LineSegment>();
        this.points = Arrays.copyOf(points, points.length);
        Arrays.sort(this.points);
        Point[] NO = Arrays.copyOf(this.points, this.points.length);
        for (int i = 0; i < NO.length; i++) {
            Point ref = NO[i];
            Comparator<Point> c = ref.slopeOrder();
            Arrays.sort(this.points);
            Arrays.sort(this.points, c);
            Point[] SO = Arrays.copyOf(this.points, this.points.length);

            int count = 1;
            Point lineBeggining = ref;

            // for (Point p : SO) StdOut.printf("%d -- %s -- %f\n", i, p.toString(), ref.slopeTo(p));
            for (int j = 0; j < SO.length - 1; j++) {
                if (ref.slopeTo(SO[j]) == ref.slopeTo(SO[j + 1])) {
                    count++;

                    if (count == 2) {
                        // StdOut.printf("The beggining of the line %s is: %s", ref.toString(),
                        //               SO[j].toString());
                        lineBeggining = SO[j];
                    }
                    if ((count >= 3) && j == SO.length - 2) {
                        // StdOut.printf("%d:  ", i);
                        // StdOut.println(
                        // ref.toString() + " -- " + lineBeggining.toString() + " -- " + SO[j]
                        //         + " - " + count);

                        if (ref.compareTo(lineBeggining) < 0) {
                            segments.add(new LineSegment(ref, SO[j + 1]));
                        }
                    }
                }
                else {
                    if (count >= 3) {
                        // StdOut.printf("%d:  ", i);
                        // StdOut.println(
                        // ref.toString() + " -- " + lineBeggining.toString() + " -- " + SO[j]
                        //         + " - " + count);
                        // StdOut.printf("%d:  ", i);
                        // StdOut.println(
                        //         ref.slopeTo(SO[j]) + " " + ref.slopeTo(SO[j + 1]) + " - " + count);
                        if (ref.compareTo(lineBeggining) < 0) {
                            segments.add(new LineSegment(ref, SO[j]));
                        }
                    }
                    count = 1;
                }
            }

        }
    }    // finds all line segments containing 4 or more points

    public int numberOfSegments() {
        return segments.size();
    }

    public LineSegment[] segments() {
        LineSegment[] lines = new LineSegment[segments.size()];
        for (int i = 0; i < segments.size(); i++) {
            lines[i] = segments.get(i);
        }
        return lines;
    }

    private Point[] merge(int low, int high, int n, Comparator<Point> c) {
        if (high - low == 1) return new Point[] { this.points[low] };

        Point[] a1 = merge(low, (high + low) / 2, n / 2, c);
        Point[] a2 = merge((high + low) / 2, high, n - n / 2, c);

        Point[] re = new Point[n];
        int i = 0, j = 0, k = 0;
        for (int q = 0; q < n; q++) {
            if (i < a1.length) {
                if (j < a2.length) {
                    if (c.compare(a1[i], a2[j]) < 0) {
                        re[k] = a1[i];
                        k++;
                        i++;
                    }
                    else if (c.compare(a1[i], a2[j]) >= 0) {
                        re[k] = a2[j];
                        k++;
                        j++;
                    }
                }
                else {
                    re[k] = a1[i];
                    k++;
                    i++;
                }
            }
            else {
                if (j < a2.length) {
                    re[k] = a2[j];
                    k++;
                    j++;
                }
            }
        }
        return re;
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        int n = in.readInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = in.readInt();
            int y = in.readInt();
            points[i] = new Point(x, y);
        }
        // FastCollinearPoints f = new FastCollinearPoints(points);
        // draw the points
        StdDraw.enableDoubleBuffering();
        StdDraw.setXscale(0, 32768);
        StdDraw.setYscale(0, 32768);
        for (Point p : points) {
            p.draw();
        }
        StdDraw.show();

        // print and draw the line segments
        FastCollinearPoints collinear = new FastCollinearPoints(points);
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
    // for (int m = 0; m < points.length; m++) {

    // Arrays.sort(points);
    // Point[] NO = Arrays.copyOf(points, points.length);
    //
    // // StdOut.println();
    // for (int i = 0; i < NO.length; i++) {
    //     Point ref = points[i];
    //     Comparator<Point> c = ref.slopeOrder;
    //     Arrays.sort(points, c);
    //     Point[] SO = Arrays.copyOf(points, points.length);
    //
    //     int count = 1;
    //     for (int j = 0; j < SO.length - 1; j++)
    //     {
    //         Point lineBeggining;
    //         StdOut.printf("%d:  ", i);
    //         StdOut.println(SO[i].toString() + " " + SO[j + 1].toString());
    //         StdOut.printf("%d:  ", i);
    //         StdOut.println(ref.slopeTo(SO[j]) + " " + ref.slopeTo(SO[j + 1]));
    //
    //         if (ref.slopeTo(SO[j]) == ref.slopeTo(SO[j + 1]))
    //         {
    //             count++;
    //             if (count == 2)
    //             {
    //                 lineBeggining = SO[j];
    //             }
    //         }
    //         else
    //         {
    //             if (count >= 4)
    //             {
    //
    //             }
    //         }
    //     }

}
// if (end - start >= 2)
// StdOut.printf("from %s to %s\n", ref.toString(), ne[end].toString());
