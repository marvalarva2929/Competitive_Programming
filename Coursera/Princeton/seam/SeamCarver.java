import edu.princeton.cs.algs4.MinPQ;
import edu.princeton.cs.algs4.Picture;

import java.util.Arrays;

public class SeamCarver {
    private Picture picture;
    private final double[][] energy;
    private int[][] colors;
    private int width;
    private int height;

    private class Pixel implements Comparable<Pixel> {
        final double score;
        final Pixel previous;
        private final int x, y;

        public Pixel(int x, int y, double score, Pixel previous) {
            this.x = x;
            this.y = y;
            this.score = score;
            this.previous = previous;
        }

        public int compareTo(Pixel that) {
            return Double.compare(this.score, that.score);
        }
    }

    // create a seam carver object based on the given picture
    public SeamCarver(Picture picture) {
        if (picture == null) throw new IllegalArgumentException("argument to SeamCarver is null");
        this.picture = new Picture(picture);
        this.height = this.picture.height();
        this.width = this.picture.width();
        this.colors = new int[this.width][this.height];
        this.energy = new double[this.width][this.height];
        for (int i = 0; i < this.width; i++) {
            Arrays.fill(energy[i], 1000);
        }
        for (int i = 0; i < this.width; i++) {
            for (int j = 0; j < this.height; j++) {
                colors[i][j] = this.picture.getRGB(i, j);
                if (i > 1 && j > 1) fixEnergy(i - 1, j - 1);
            }
        }

    }

    private void fixEnergy(int i, int j) {
        if (i == 0 || j == 0 || j == this.picture.height() - 1
                || i == this.picture.width() - 1) {
            energy[i][j] = 1000;
            return;
        }
        // double deltaX =
        //         Math.pow(((colors[i - 1][j] >> 16) & 0xFF) - ((colors[i + 1][j] >> 16) & 0xFF), 2)
        //                 + Math.pow(
        //                 ((colors[i - 1][j] >> 8) & 0xFF) - ((colors[i + 1][j] >> 8) & 0xFF), 2)
        //                 + Math.pow(
        //                 ((colors[i - 1][j]) & 0xFF) - ((colors[i + 1][j]) & 0xFF), 2);
        // double deltaY =
        //         Math.pow(((colors[i][j - 1] >> 16) & 0xFF) - ((colors[i][j + 1] >> 16) & 0xFF), 2)
        //                 + Math.pow(
        //                 ((colors[i][j - 1] >> 8) & 0xFF) - ((colors[i][j + 1] >> 8) & 0xFF), 2)
        //                 + Math.pow(
        //                 ((colors[i][j - 1]) & 0xFF) - ((colors[i][j + 1]) & 0xFF), 2);
        // energy[i][j] = (deltaX + deltaY);
        int toLeftRed = (colors[i - 1][j] >> 16) & 0xFF;
        int toLeftGreen = (colors[i - 1][j] >> 8) & 0xFF;
        int toLeftBlue = (colors[i - 1][j]) & 0xFF;
        int toUpRed = (colors[i][j + 1] >> 16) & 0xFF;
        int toUpGreen = (colors[i][j + 1] >> 8) & 0xFF;
        int toUpBlue = (colors[i][j + 1]) & 0xFF;
        int toRightRed = (colors[i + 1][j] >> 16) & 0xFF;
        int toRightGreen = (colors[i + 1][j] >> 8) & 0xFF;
        int toRightBlue = (colors[i + 1][j]) & 0xFF;
        int toDownRed = (colors[i][j - 1] >> 16) & 0xFF;
        int toDownGreen = (colors[i][j - 1] >> 8) & 0xFF;
        int toDownBlue = (colors[i][j - 1]) & 0xFF;
        double deltaX = Math.pow(toLeftRed - toRightRed, 2) + Math.pow(
                toLeftGreen - toRightGreen, 2) + Math.pow(
                toLeftBlue - toRightBlue, 2);
        double deltaY = Math.pow(toDownRed - toUpRed, 2) + Math.pow(
                toDownGreen - toUpGreen, 2) + Math.pow(
                toDownBlue - toUpBlue, 2);
        energy[i][j] = Math.sqrt(deltaX + deltaY);
    }

    // current picture
    public Picture picture() {
        return new Picture(this.picture);
    }

    // width of current picture
    public int width() {
        return this.width;
    }

    // height of current picture
    public int height() {
        return this.height;
    }

    // energy of pixel at column x and row y
    public double energy(int x, int y) {
        if (x < 0 || y < 0 || x >= this.width || y >= this.height)
            throw new IllegalArgumentException("arguments to energy() must be within range");
        if (x == 0 || y == 0 || y == this.picture.height() - 1
                || x == this.picture.width() - 1) {
            return 1000;
        }
        // double deltaX =
        //         Math.pow(((colors[i - 1][j] >> 16) & 0xFF) - ((colors[i + 1][j] >> 16) & 0xFF), 2)
        //                 + Math.pow(
        //                 ((colors[i - 1][j] >> 8) & 0xFF) - ((colors[i + 1][j] >> 8) & 0xFF), 2)
        //                 + Math.pow(
        //                 ((colors[i - 1][j]) & 0xFF) - ((colors[i + 1][j]) & 0xFF), 2);
        // double deltaY =
        //         Math.pow(((colors[i][j - 1] >> 16) & 0xFF) - ((colors[i][j + 1] >> 16) & 0xFF), 2)
        //                 + Math.pow(
        //                 ((colors[i][j - 1] >> 8) & 0xFF) - ((colors[i][j + 1] >> 8) & 0xFF), 2)
        //                 + Math.pow(
        //                 ((colors[i][j - 1]) & 0xFF) - ((colors[i][j + 1]) & 0xFF), 2);
        // energy[i][j] = (deltaX + deltaY);
        int toLeftRed = (colors[x - 1][y] >> 16) & 0xFF;
        int toLeftGreen = (colors[x - 1][y] >> 8) & 0xFF;
        int toLeftBlue = (colors[x - 1][y]) & 0xFF;
        int toUpRed = (colors[x][y + 1] >> 16) & 0xFF;
        int toUpGreen = (colors[x][y + 1] >> 8) & 0xFF;
        int toUpBlue = (colors[x][y + 1]) & 0xFF;
        int toRightRed = (colors[x + 1][y] >> 16) & 0xFF;
        int toRightGreen = (colors[x + 1][y] >> 8) & 0xFF;
        int toRightBlue = (colors[x + 1][y]) & 0xFF;
        int toDownRed = (colors[x][y - 1] >> 16) & 0xFF;
        int toDownGreen = (colors[x][y - 1] >> 8) & 0xFF;
        int toDownBlue = (colors[x][y - 1]) & 0xFF;
        double deltaX = Math.pow(toLeftRed - toRightRed, 2) + Math.pow(
                toLeftGreen - toRightGreen, 2) + Math.pow(
                toLeftBlue - toRightBlue, 2);
        double deltaY = Math.pow(toDownRed - toUpRed, 2) + Math.pow(
                toDownGreen - toUpGreen, 2) + Math.pow(
                toDownBlue - toUpBlue, 2);
        return Math.sqrt(deltaX + deltaY);
    }

    // sequence of indices for horizontal seam
    public int[] findHorizontalSeam() {
        MinPQ<Pixel> queue = new MinPQ<>();
        int[] path = new int[this.picture.width()];
        boolean[][] visited = new boolean[this.picture.width()][this.picture.height()];
        Pixel curr = new Pixel(0, 0, 1000, new Pixel(0, 0, 1000, null));
        if (this.picture.height() > 2 && this.picture.width() > 1) {
            for (int i = 1; i < this.picture.height() - 1; i++) {
                queue.insert(new Pixel(1, i, energy(1, i), new Pixel(0, i, 1000, null)));
            }
        }
        else queue.insert(curr);

        Pixel minimumEnd = new Pixel(0, 0, Double.POSITIVE_INFINITY, null);
        while (!queue.isEmpty()) {
            curr = queue.delMin();

            if (curr.x == this.picture.width() - 1) {
                if (minimumEnd.score > curr.score) minimumEnd = curr;
                visited[curr.x][curr.y] = true;
            }
            if (!visited[curr.x][curr.y]) {
                visited[curr.x][curr.y] = true;
                double downScore, rightScore, upScore;
                if (curr.y > 0) {
                    downScore = curr.score + energy[curr.x + 1][curr.y - 1];
                    if (downScore < minimumEnd.score && !visited[curr.x + 1][curr.y - 1])
                        queue.insert(new Pixel(curr.x + 1, curr.y - 1, downScore, curr));
                }

                if (!visited[curr.x + 1][curr.y]) {
                    rightScore = curr.score + (energy[curr.x + 1][curr.y]);
                    if (rightScore < minimumEnd.score) {
                        queue.insert(new Pixel(curr.x + 1, curr.y, rightScore, curr));
                    }
                }

                if (curr.y < this.picture.height() - 1) {
                    upScore = curr.score + (energy[curr.x + 1][curr.y + 1]);
                    if (upScore < minimumEnd.score && !visited[curr.x + 1][curr.y + 1]) {
                        queue.insert(new Pixel(curr.x + 1, curr.y + 1, upScore, curr));
                    }
                }
            }
        }
        Pixel backtrack = minimumEnd;
        while (backtrack != null) {
            path[backtrack.x] = backtrack.y;
            backtrack = backtrack.previous;
        }
        // StdOut.print("path\n");
        return path;
    }

    // sequence of indices for vertical seam
    public int[] findVerticalSeam() {
        MinPQ<Pixel> queue = new MinPQ<>();
        int[] path = new int[this.height];
        boolean[][] visited = new boolean[this.width][this.height];
        Pixel curr = new Pixel(0, 0, 1000, new Pixel(0, 0, 1000, null));
        if (this.width > 2 && this.height > 1) {
            for (int i = 1; i < this.width - 1; i++) {
                queue.insert(new Pixel(i, 1, energy(i, 1), new Pixel(i, 0, 1000, null)));
            }
        }
        else queue.insert(curr);
        Pixel minimumEnd = new Pixel(0, 0, Double.POSITIVE_INFINITY, null);
        while (!queue.isEmpty()) {
            curr = queue.delMin();
            if (curr.y == this.height - 1 && !visited[curr.x][curr.y]) {
                if (minimumEnd.score > curr.score) minimumEnd = curr;
                visited[curr.x][curr.y] = true;
            }
            if (!visited[curr.x][curr.y]) {
                double rightScore, downScore, leftScore;
                visited[curr.x][curr.y] = true;
                if (curr.x < this.width - 1) {
                    rightScore = curr.score + (energy[curr.x + 1][curr.y + 1]);
                    if (rightScore < minimumEnd.score && !visited[curr.x + 1][curr.y + 1]) {
                        queue.insert(new Pixel(curr.x + 1, curr.y + 1, rightScore, curr));
                    }
                }
                if (!visited[curr.x][curr.y + 1]) {
                    downScore = curr.score + (energy[curr.x][curr.y + 1]);
                    if (downScore < minimumEnd.score) {
                        queue.insert(new Pixel(curr.x, curr.y + 1, downScore, curr));
                    }
                }

                if (curr.x > 0) {
                    leftScore = curr.score + (energy[curr.x - 1][curr.y + 1]);
                    if (leftScore < minimumEnd.score && !visited[curr.x - 1][curr.y + 1]) {
                        queue.insert(new Pixel(curr.x - 1, curr.y + 1, leftScore, curr));
                    }
                }
            }
        }
        Pixel backtrack = minimumEnd;
        while (backtrack != null) {
            path[backtrack.y] = backtrack.x;
            backtrack = backtrack.previous;
        }
        return path;
    }

    // remove horizontal seam from current picture
    public void removeHorizontalSeam(int[] seam) {
        if (seam == null)
            throw new IllegalArgumentException("argument to removeHorizontalSeam() is null");
        if (seam.length != this.width)
            throw new IllegalArgumentException("arguments to seam() are too few");
        if (this.height <= 1) throw new IllegalArgumentException(
                "you cannot remove horizontal streams when there is only one row!");
        Picture newPic = new Picture(this.width, this.height - 1);
        for (int i = 0; i < newPic.width(); i++) {
            for (int j = 0; j < newPic.height(); j++) {
                newPic.setRGB(i, j, colors[i][j]);
            }
        }
        int colShift;
        for (int i = 0; i < seam.length; i++) {
            if (i < seam.length - 1) {
                if (Math.abs(seam[i] - seam[i + 1]) > 1)
                    throw new IllegalArgumentException(
                            "entries in removeHorizontalSeam() do not comply: %d, %d");
            }
            colShift = seam[i];
            if (colShift >= this.height || colShift < 0)
                throw new IllegalArgumentException(
                        "entries in removeHorizontalSeam() are out of range");
            while (colShift < this.height - 1) {
                colors[i][colShift] = colors[i][colShift + 1];
                if (colShift > 1) fixEnergy(i, colShift - 1);
                if (i > 1) fixEnergy(i - 1, colShift);
                if (i < this.width - 1) fixEnergy(i + 1, colShift);
                newPic.setRGB(i, colShift, colors[i][colShift]);
                colShift++;
            }

        }
        this.picture = newPic;
        this.height = this.picture.height();
        this.width = this.picture.width();
    }

    // remove vertical seam from current picture
    public void removeVerticalSeam(int[] seam) {
        if (seam == null)
            throw new IllegalArgumentException("argument to removeVerticalSeam() is null");
        if (seam.length != this.height)
            throw new IllegalArgumentException("arguments to seam() are too few");
        if (this.width <= 1) throw new IllegalArgumentException(
                "you cannot remove vertical seams when the width is only 1!");
        Picture newPic = new Picture(this.width - 1, this.height);
        for (int i = 0; i < newPic.width(); i++) {
            for (int j = 0; j < newPic.height(); j++) {
                newPic.setRGB(i, j, colors[i][j]);
            }
        }
        int rowShift;
        for (int i = 0; i < seam.length; i++) {
            if (i < seam.length - 1) {
                if (Math.abs(seam[i] - seam[i + 1]) > 1)
                    throw new IllegalArgumentException(
                            "entries in removeVeritcalSeam() do not comply");
            }
            rowShift = seam[i];
            if (rowShift >= this.width || rowShift < 0)
                throw new IllegalArgumentException(
                        "entries in removeVerticalSeam() are out of range");
            while (rowShift != this.width - 1) {
                colors[rowShift][i] = colors[rowShift + 1][i];
                if (rowShift > 1) fixEnergy(rowShift - 1, i);
                if (i > 1) fixEnergy(rowShift, i - 1);
                if (i < this.height - 1) fixEnergy(rowShift, i + 1);
                newPic.setRGB(rowShift, i, colors[rowShift][i]);
                rowShift++;
            }
        }
        this.picture = newPic;
        this.width = this.picture.width();
        this.height = this.picture.height();
    }

    public static void main(String[] args) {
        Picture inputImg = new Picture(args[0]);
        SeamCarver carver = new SeamCarver(inputImg);
        SCUtility.seamOverlay(inputImg, true, carver.findHorizontalSeam()).show();
        SCUtility.seamOverlay(inputImg, false, carver.findVerticalSeam()).show();
    }
}
