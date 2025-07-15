import java.util.Arrays;
import java.util.Scanner;

// Define a Point class
class Point {
    int x, y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class ClosestPair {

    // Function to swap two points in an array
    static void swap(Point[] p, int i, int j) {
        Point temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }

    // Quicksort based on x-coordinate
    static void qsortx(Point[] p, int low, int high) {
        if (low < high) {
            int i = low, j = high;
            int pivot = p[low].x;
            while (i < j) {
                while (p[i].x <= pivot && i < high)
                    i++;
                while (p[j].x > pivot)
                    j--;
                if (i < j)
                    swap(p, i, j);
            }
            swap(p, low, j);
            qsortx(p, low, j - 1);
            qsortx(p, j + 1, high);
        }
    }

    // Quicksort based on y-coordinate
    static void qsorty(Point[] p, int low, int high) {
        if (low < high) {
            int i = low, j = high;
            int pivot = p[low].y;
            while (i < j) {
                while (p[i].y <= pivot && i < high)
                    i++;
                while (p[j].y > pivot)
                    j--;
                if (i < j)
                    swap(p, i, j);
            }
            swap(p, low, j);
            qsorty(p, low, j - 1);
            qsorty(p, j + 1, high);
        }
    }

    // Function to calculate Euclidean distance between two points
    static double distance(Point p1, Point p2) {
        return Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
    }

    // Brute force method to find closest pair of points in a small set
    static double bruteForce(Point[] p, int start, int end) {
        double min = Double.MAX_VALUE;
        for (int i = start; i < end; i++) {
            for (int j = i + 1; j <= end; j++) {
                double d = distance(p[i], p[j]);
                if (d < min) {
                    min = d;
                }
            }
        }
        return min;
    }

    // Recursive function to find closest pair of points
    static double closestPair(Point[] p, int start, int end) {
        if (end - start <= 2) {
            return bruteForce(p, start, end);
        }

        int mid = (start + end) / 2;
        double leftDist = closestPair(p, start, mid);
        double rightDist = closestPair(p, mid + 1, end);
        double minDist = Math.min(leftDist, rightDist);

        // Create an array for points in the strip
        Point[] strip = new Point[end - start + 1];
        int j = 0;
        for (int i = start; i <= end; i++) {
            if (Math.abs(p[i].x - p[mid].x) < minDist) {
                strip[j++] = p[i];
            }
        }

        // Sort strip array based on y-coordinate
        qsorty(strip, 0, j - 1);

        // Check for closest pair in the strip
        for (int i = 0; i < j; i++) {
            for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < minDist; k++) {
                double d = distance(strip[i], strip[k]);
                if (d < minDist) {
                    minDist = d;
                }
            }
        }

        return minDist;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of points: ");
        int n = scanner.nextInt();
        Point[] points = new Point[n];

        System.out.println("Enter coordinates of each point:");
        for (int i = 0; i < n; i++) {
            System.out.print("Point " + (i + 1) + ": ");
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points[i] = new Point(x, y);
        }

        // Sort points by x-coordinate
        qsortx(points, 0, n - 1);

        // Find closest pair of points
        double minDistance = closestPair(points, 0, n - 1);

        System.out.println("Minimum distance between two points: " + minDistance);

        scanner.close();
    }
}
