/*
Find the position of the survivor in the vicious series of killings described by Flavius Josephus,
the first-century historian and head of Jewish forces in Galilee.

Input: 
Natural numbers n and k. They represent n rebels standing in a circle.
Rebels are being eliminated in such a way that every k-th still alive rebel around the circle
is killed until only one rebel left. Rebels are killed clockwise
starting from rebel 0, i.e., rebel k-1 is killed first.

Output: 
The position of the survivor, denoted Josephus(n,k).
*/

#include <iostream>

int josephus(int n, int k) {
    if(n == 1)
        return 0;
    else
        return (josephus(n-1, k) + k) % n;
}

int main() {

    int n,k;
    std::cin >> n >> k;
    std::cout << josephus(n, k) << '\n';
    return 0;
}

/*
The Josephus problem is a theoretical problem related to a certain elimination game. Let's walk through an example to illustrate how the given `josephus` function works.

### Example: Josephus Problem with \( n = 7 \) and \( k = 3 \)

**Problem Statement:**
- There are 7 people standing in a circle.
- Every 3rd person is eliminated until only one person remains.
- We need to find out the position of the last person remaining (using 0-based indexing).

**Step-by-Step Explanation:**

1. **Initial Call:**
   - `josephus(7, 3)`

2. **First Recursive Step:**
   - Since \( n = 7 \), the function will call `josephus(6, 3)`.
   - Result is computed as: `(josephus(6, 3) + 3) % 7`.

3. **Second Recursive Step:**
   - Now, `josephus(6, 3)` calls `josephus(5, 3)`.
   - Result is computed as: `(josephus(5, 3) + 3) % 6`.

4. **Third Recursive Step:**
   - `josephus(5, 3)` calls `josephus(4, 3)`.
   - Result is computed as: `(josephus(4, 3) + 3) % 5`.

5. **Fourth Recursive Step:**
   - `josephus(4, 3)` calls `josephus(3, 3)`.
   - Result is computed as: `(josephus(3, 3) + 3) % 4`.

6. **Fifth Recursive Step:**
   - `josephus(3, 3)` calls `josephus(2, 3)`.
   - Result is computed as: `(josephus(2, 3) + 3) % 3`.

7. **Sixth Recursive Step:**
   - `josephus(2, 3)` calls `josephus(1, 3)`.
   - Result is computed as: `(josephus(1, 3) + 3) % 2`.

8. **Base Case:**
   - `josephus(1, 3)` returns 0 because when there is only one person left, they are at position 0.

9. **Returning Back Up the Recursive Calls:**
   - Now we compute the results going back up:
     - `josephus(2, 3)` = `(0 + 3) % 2` = 1
     - `josephus(3, 3)` = `(1 + 3) % 3` = 1
     - `josephus(4, 3)` = `(1 + 3) % 4` = 0
     - `josephus(5, 3)` = `(0 + 3) % 5` = 3
     - `josephus(6, 3)` = `(3 + 3) % 6` = 0
     - `josephus(7, 3)` = `(0 + 3) % 7` = 3

### Final Result:
- The position of the last remaining person when \( n = 7 \) and \( k = 3 \) is 3 (0-based indexing).

**Summary of Steps:**
1. Recursive function keeps reducing the problem size by 1 until it reaches the base case.
2. It then uses the results of smaller subproblems to build up the final solution.
3. The modulus operation ensures that the positions wrap around correctly in the circle.

This demonstrates how the recursive function solves the Josephus problem by breaking it down into smaller instances of itself and building up the solution through recursive calls.
*/