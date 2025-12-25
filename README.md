# Graph Dependency Analyzer

## Overview
Graph Dependency Analyzer is an interactive system for building, modifying, and analyzing a directed weighted graph.
It is designed to model dependencies between entities such as files in a compilation pipeline.

Users can dynamically add or remove nodes and edges, while the system continuously analyzes the graph structure and reports important properties like cycles, connectivity, and dependency relationships.

This project is useful for build systems, dependency resolution, compilation order analysis, and graph theory experimentation.

---

## Features

### 1. Dynamic Graph Management
- Add nodes manually
- Delete existing nodes
- Add directed edges between nodes
- Delete edges between nodes
- If an edge is added between nodes that do not exist, the system automatically creates those nodes

---

### 2. Edge Format and Weights
Only the following edge formats are accepted:

- Without weight: `A->B`  
  (Default weight = 0)

- With weight: `A-{w}->B`  
  where `w` is an integer (can be negative)

All edges are directed.  
If weight is not provided, it is assumed to be **0**.

---

### 3. Continuous Graph Status Monitoring
The system continuously displays the status of the graph, including:

- Presence of orphan nodes
- Whether the graph contains:
  - Any cycle
  - Any negative cycle
  - Any negative-weight edge
- Whether the graph is connected or disconnected

This feedback updates automatically whenever the graph changes.

---

### 4. Dependency Queries
For any given node, users can:

- Find all nodes/files that depend on this node
- Find all nodes/files on which this node depends

This is useful for impact analysis and dependency tracking.

---

### 5. Compilation Flow & Minimum Time Analysis
When the graph represents compilation times of files:

- Computes the correct order in which files should be compiled
- Determines which file must be compiled first
- Calculates the minimum possible compilation time for each file
- Provides the minimum working flow respecting all dependencies

If a negative cycle exists, minimum-time computation is not valid.

---

### 6. Cycle Detection and Resolution
- Detects cycles in the graph
- Identifies negative cycles explicitly
- Shows where cycles exist
- Allows users to obtain a modified graph after removing cycles

This helps make the graph valid for scheduling and compilation analysis.

---

## Use Cases
- Build system dependency analysis
- Compilation order optimization
- Detecting cyclic dependencies in projects
- Workflow and task scheduling
- Graph theory learning and experimentation

---

## Assumptions & Constraints
- Graph is directed
- Edge weights are integers (positive, zero, or negative)
- Negative cycles invalidate minimum-time computation
- Only specified edge formats are accepted

---

## Example

Input:
A->B  
B-{3}->C  
D->A  

Output:
- Nodes: A, B, C, D
- Graph is connected
- No negative cycle
- Compilation order: D → A → B → C

---

## Tech Stack
- Language: C++ / Python (depending on implementation)
- Core Concepts:
  - Graph traversal
  - Cycle detection
  - Dependency analysis
  - Shortest paths
  - Topological ordering

---

## Author
Sagar Kumar
