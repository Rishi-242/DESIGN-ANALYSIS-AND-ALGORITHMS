
import java.util.Scanner;

// Define a Point class
class Point {
    int x, y;
    
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class ClosestPair {

    // Function to calculate the Euclidean distance between two points
    static double dist(Point p1, Point p2) {
        return Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }

    // Function to find the minimum of two floats
    static double min(double x, double y) {
        return (x < y) ? x : y;
    }

    // Brute force method to find the closest pair of points
    static double bruteForce(Point P[], int n) {
        double minDist = Double.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                minDist = Math.min(minDist, dist(P[i], P[j]));
            }
        }
        return minDist;
    }

    // Function to find the closest pair of points using divide and conquer
    static double closestPair(Point P[], int n) {
        if (n <= 3)
            return bruteForce(P, n);

        // Sort points by x-coordinate
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (P[i].x > P[j].x) {
                    Point temp = P[i];
                    P[i] = P[j];
                    P[j] = temp;
                }
            }
        }

        // Find the middle point
        int mid = n / 2;
        Point midPoint = P[mid];

        // Recursively find the smallest distance in both halves
        double dl = closestPair(P, mid);
        double dr = closestPair(P, n - mid);
        double d = min(dl, dr);

        // Build an array strip[] that contains points close to the line passing through the middle point
        Point[] strip = new Point[n];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (Math.abs(P[i].x - midPoint.x) < d) {
                strip[j++] = P[i];
            }
        }

        // Sort points in strip[] by y-coordinate
        for (int i = 0; i < j - 1; i++) {
            for (int k = i + 1; k < j; k++) {
                if (strip[i].y > strip[k].y) {
                    Point temp = strip[i];
                    strip[i] = strip[k];
                    strip[k] = temp;
                }
            }
        }

        // Check for the closest points in the strip and update the minimum distance if found
        for (int i = 0; i < j; ++i) {
            for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; ++k) {
                d = Math.min(d, dist(strip[i], strip[k]));
            }
        }
        return d;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of points: ");
        int n = scanner.nextInt();
        Point[] points = new Point[n];
        
        System.out.println("Enter the coordinates of each point:");
        for (int i = 0; i < n; i++) {
            System.out.print("Point " + (i + 1) + ": ");
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points[i] = new Point(x, y);
        }
        
        System.out.println("The smallest distance is " + closestPair(points, n));
        scanner.close();
    }
}
