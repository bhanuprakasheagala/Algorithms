# Algorithms Design Paradigms

This repository covers various **algorithm design paradigms**, ranging from basic concepts to advanced techniques. Each section includes clear explanations and code examples to demonstrate the applications of each paradigm.

## Table of Contents
- [Introduction](#introduction)
- [Greedy Algorithms](#greedy-algorithms)
  - [Core Concept](#core-concept)
  - [Examples](#examples)
- [Divide and Conquer](#divide-and-conquer)
  - [Core Concept](#core-concept-1)
  - [Examples](#examples-1)
- [Dynamic Programming](#dynamic-programming)
  - [Core Concept](#core-concept-2)
  - [Examples](#examples-2)
- [Backtracking](#backtracking)
  - [Core Concept](#core-concept-3)
  - [Examples](#examples-3)
- [Branch and Bound](#branch-and-bound)
  - [Core Concept](#core-concept-4)
  - [Examples](#examples-4)
- [Advanced Topics](#advanced-topics)
  - [Memoization](#memoization)
  - [Amortized Analysis](#amortized-analysis)
  - [Approximation Algorithms](#approximation-algorithms)
  
---

## Introduction
Algorithm design paradigms provide a framework for solving problems efficiently. Each paradigm approaches problem-solving from a different perspective, and the choice of paradigm can significantly affect the performance and feasibility of an algorithm.

## Greedy Algorithms

### Core Concept
Greedy algorithms build up a solution piece by piece, selecting the most optimal choice at each step without revisiting previous decisions. The hope is that a locally optimal choice leads to a globally optimal solution.

**Key Idea**: Make the best choice at each step and never reconsider previous steps.

### Examples
#### 1. **Activity Selection Problem**
   - **Problem**: Given `n` activities with start and end times, select the maximum number of activities that can be performed by a single person, assuming that a person can only work on one activity at a time.
   - **Solution**:
     ```cpp
     // Sort activities by finish time and select the non-overlapping ones.
     ```
#### 2. **Huffman Encoding**
   - **Problem**: Generate the most optimal binary encoding for data, minimizing the average length of codes.
   - **Solution**: Uses a priority queue to repeatedly combine the two smallest frequency nodes.

---

## Divide and Conquer

### Core Concept
The **Divide and Conquer** paradigm splits a problem into subproblems, solves each subproblem recursively, and then combines the solutions of subproblems to form the final solution.

**Key Idea**: Break down a problem into smaller instances, solve them recursively, and merge the results.

### Examples
#### 1. **Merge Sort**
   - **Problem**: Sort an array of elements.
   - **Solution**:
     ```cpp
     // Split the array in half, recursively sort each half, and merge them.
     ```

#### 2. **Binary Search**
   - **Problem**: Search for an element in a sorted array.
   - **Solution**:
     ```cpp
     // Repeatedly divide the search space in half.
     ```

---

## Dynamic Programming

### Core Concept
Dynamic programming (DP) solves problems by combining the solutions of overlapping subproblems. Instead of solving the same subproblems repeatedly, DP stores the results of subproblems in a table and reuses them when needed.

**Key Idea**: Break problems into overlapping subproblems and store their results to avoid recomputation.

### Examples
#### 1. **Fibonacci Sequence**
   - **Problem**: Compute the nth Fibonacci number.
   - **Solution**:
     ```cpp
     // Use a table to store Fibonacci values and avoid redundant calculations.
     ```

#### 2. **Knapsack Problem**
   - **Problem**: Given weights and values of `n` items, find the most valuable subset of items to carry in a knapsack of a given capacity.
   - **Solution**:
     ```cpp
     // Solve using a 2D table where each entry represents the best value for a given capacity.
     ```

---

## Backtracking

### Core Concept
Backtracking is a general algorithm for finding solutions to some computational problems by incrementally building candidates to the solutions, and abandoning a candidate as soon as it determines that the candidate cannot possibly be a valid solution.

**Key Idea**: Explore all possibilities, but stop exploring as soon as you find that the current path won’t lead to a valid solution.

### Examples
#### 1. **N-Queens Problem**
   - **Problem**: Place `n` queens on an `n x n` chessboard so that no two queens threaten each other.
   - **Solution**:
     ```cpp
     // Use recursion to place queens one by one, backtracking if a conflict arises.
     ```

#### 2. **Sudoku Solver**
   - **Problem**: Solve a Sudoku puzzle.
   - **Solution**:
     ```cpp
     // Use backtracking to fill each empty cell and validate each step.
     ```

---

## Branch and Bound

### Core Concept
Branch and bound is an algorithm design paradigm for solving combinatorial optimization problems. It works by dividing the problem into several branches (subproblems) and bounding their solution spaces to prune suboptimal solutions.

**Key Idea**: Explore branches of solutions and use bounds to eliminate large sections of the search space that can't contain an optimal solution.

### Examples
#### 1. **Travelling Salesman Problem (TSP)**
   - **Problem**: Find the shortest possible route that visits each city exactly once and returns to the origin city.
   - **Solution**:
     ```cpp
     // Use bounds to prune paths that exceed known minimum distances.
     ```

---

## Advanced Topics

### Memoization
Memoization is a specific form of dynamic programming where function results are cached to avoid redundant computations. It is commonly used in top-down DP solutions.

**Example**: Recursive Fibonacci with memoization.

### Amortized Analysis
Amortized analysis provides a guarantee on the average performance (over a sequence of operations) of an algorithm, even if individual operations might be costly.

**Example**: Dynamic array resizing in languages like C++ (std::vector).

### Approximation Algorithms
For NP-hard problems, exact solutions may be computationally expensive. Approximation algorithms provide near-optimal solutions within a reasonable time frame.

**Example**: Approximation for the Vertex Cover problem.

---

