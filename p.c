//(2,3),(12,30),(40,50),(5,1),(12,10),(3,4)
//The closest pair is (2,3)and (3,4) with a distance of approximately 1.41.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>

struct Point {
    int x, y;
};

float dist(struct Point p1, struct Point p2) {
return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float min(float x, float y) {
return (x < y) ? x : y;
}

float bruteForce(struct Point P[], int n) {
float minDist = FLT_MAX;
for (int i = 0; i < n; ++i){
for (int j = i + 1; j < n; ++j){
minDist = fmin(minDist, dist(P[i], P[j]));
}
}
return minDist;
}

float closestPair(struct Point P[], int n) {
if (n <= 3)
return bruteForce(P, n);
for (int i = 0; i < n - 1; i++) {
for(int j = i + 1; j < n; j++) {
if(P[i].x > P[j].x) {
struct Point temp = P[i];
P[i]=P[j];
P[j]=temp;
}
}
}
    
int mid = n / 2;
struct Point midPoint = P[mid];

float dl = closestPair(P, mid);
float dr = closestPair(P + mid, n - mid);
float d = fmin(dl, dr);
struct Point strip[n];
int j = 0;
for(int i = 0; i < n; i++) {
if(abs(P[i].x - midPoint.x) < d) {
strip[j]=P[i], j++;
}
}
for(int i = 0; i < j - 1; i++) {
for(int k = i + 1; k < j; k++) {
if(strip[i].y > strip[k].y){
struct Point temp = strip[i];
strip[i]=strip[k];
strip[k]=temp;
}
}
}

float minDist = d;
for(int i = 0; i < j; ++i) {
for(int k = i + 1; k < j && (strip[k].y - strip[i].y) < minDist; ++k) {
minDist = fmin(minDist, dist(strip[i], strip[k]));
}}
return minDist;
}

int main() {
int n;
printf("Enter the number of points: ");
scanf("%d", &n);
struct Point points[n];
printf("Enter the coordinates of each point:\n");
for(int i = 0; i < n; i++) {
printf("Point %d: ", i + 1);
scanf("%d %d", &points[i].x, &points[i].y);
}
printf("The smallest distance is %f\n", closestPair(points, n));
return 0;
}
