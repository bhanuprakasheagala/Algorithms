/*
Find the minimum number of points needed to cover all given segments on a line.
Input: A sequence of n segments [l1,r1],...,[ln,rn] on a line.
Output: A set of points of minimum size such that each segment [li,ri] contains a point,
i.e., there exists a point x from this set such that li ≤ x ≤ ri.


*/
#include <iostream>
#include <vector>
#include <algorithm>

struct line {
    int li;
    int ri;
    //line(int l, int r) : li(l), ri(r) {}
};

bool rightPointsCompare(const line& a, const line& b) {
    return a.ri < b.ri;
}

void coveringSegmentsByPoints(std::vector<line>& arr) {
    // Sort the segments based on their right end point
    std::sort(arr.begin(), arr.end(), rightPointsCompare);

    // To store the points
    std::vector<int> points;

    // Start with the right end point of the first segment
    int currentPoint = arr[0].ri;
    points.push_back(currentPoint); // Add the first point

    // Iterate through each segment
    for(size_t i=1; i < arr.size(); ++i) {
        // If the currentPoint is not within the current segment, add a new point
        if(currentPoint < arr[i].li) {
            currentPoint = arr[i].ri;
            points.push_back(currentPoint);
        }
    }
    std::cout << points.size() << '\n';
    for(int p : points) {
        std::cout << p << " ";
    }
    std::cout << '\n';
}

int main()
{   
    int n;
    std::cin>>n;
    std::vector<line> coordinates(n);
    for(int i=0; i<n; ++i) {
        int left, right;
        std::cin >> left >> right;
        coordinates[i] = {left, right};
    }
    coveringSegmentsByPoints(coordinates);

    return 0;
}

/*
Example:
4
2 5
1 3
3 6
7 8

1. Sort the segments based on their right endpoints:
After sorting, the segments would be in the following order:
Segment 2: [1, 3]
Segment 1: [2, 5]
Segment 3: [3, 6]
Segment 4: [7, 8]

2. Start with the right endpoint of the first segment, which is 3.
Add point 3 to the list of points.

3 .Move to the next segment.
The left endpoint of Segment 1 is 2, which is less than the current point (3). So, no new point is added.

4. Move to the next segment.
The left endpoint of Segment 3 is 3, which is equal to the current point (3). No new point is added.

5. Move to the next segment.
The left endpoint of Segment 4 is 7, which is greater than the current point (3).
Add point 6 (the right endpoint of Segment 3) to the list of points.

6. The algorithm finishes traversing all segments.

Finally, we find that the minimum number of points needed to cover all segments is 2,
and the points are {3, 6}.

Output:
2
3 6
*/