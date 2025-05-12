# Food-Delivery-Routing-Optimization-Algorithm

## Project Title

*Delivery Route Optimization in a Grid using Graph Traversal*

## Team Members

* Muhammad Abubakar Nadeem (22I2003)
* Muhammad Huzaifa Swati (22I1899)

## Overview

This project models and solves a simplified delivery routing problem in a 2D grid. Given a set of restaurants, each with delivery destinations and deadlines, the program uses a graph-based representation of the grid and applies Breadth-First Search (BFS) to determine if orders can be delivered on time.

### Key Features

* Custom Queue class for BFS traversal
* Graph class simulating a grid with connections between adjacent nodes
* Efficient path finding using BFS
* Handles multiple test cases from a structured input file

## Problem Statement

Given:

* A grid of size n x n
* Several restaurants located at grid nodes
* A list of orders (destination + max time allowed)

Determine:

* Shortest path to each delivery location
* Whether each order can be delivered within the given time constraint
* Total time taken for successful deliveries

If even one order is not feasible within its time constraint, the test case fails.

## Input File Format (test_cases.txt)


<number_of_test_cases>
<grid_size> <start_index> <num_restaurants>
<restaurant_name> <location> <num_orders>
<order_name> <destination> <time_limit>
...


### Example:


1
4 0 2
Dominos 3 2
Order1 15 6
Order2 6 4
KFC 9 1
Order3 12 5


## Algorithms Used

### Breadth-First Search (BFS)

* Computes shortest paths from a restaurant to all grid nodes
* Uses a custom circular queue for efficient traversal
* Backtracks from destination to restaurant to check route feasibility

## Output Format

* For each test case:

  * Print the grid
  * For each restaurant, print the route to each order destination
  * Show time taken and if it meets the deadline
  * Summarize total delivery time or mark test case as failed

## Sample Output (Console)


Test Case 1:
Graph
 1-- 2-- 3-- 4
 |   |   |   
 5-- 6-- 7-- 8
 |   |   |   
 9--10--11--12
 |   |   |   
13--14--15--16

Dominos Route : 15 -> ... (5 time units)
Dominos Route : 6 -> ... (3 time units)
KFC Route : 12 -> ... (4 time units)
Total time for Dominos: 8 time units
Total time for KFC: 4 time units
Total minimum time required for this test case: 12 units


## Compilation & Execution

1. Ensure test_cases.txt is in the same directory as the executable.
2. Compile: g++ -o delivery_solver main.cpp
3. Run: ./delivery_solver

## File Structure


delivery_project/
├── main.cpp
├── test_cases.txt
└── README.md


## Key Classes

### Queue

* Implements a circular queue using arrays
* Used for BFS traversal

### Graph

* Represents the grid and its connections
* Contains BFS logic for route discovery
* Displays grid visually in text format

## Limitations & Assumptions

* Grid is fully connected (no blocked paths)
* BFS assumes all edges have equal weight
* Time is measured in grid hops (1 per move)

## Future Enhancements

* Use A\* algorithm for faster path finding
* Introduce obstacles into the grid
* Add support for concurrent deliveries with multiple agents
* Visual GUI for grid and routes
