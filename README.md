# Edmonds-Branching-Algorithm
Implementation of the Edmunds Graph algoritm for generating MST in directed graphs.

This implementation was based on an [existing haskell implementation](https://github.com/prokls/edmonds-branching-algorithm/blob/master/haskell/edmonds.hs), I just rewrote it in C++ while still keeping the same structure and logic.

## How to use
If its the first time running the program, do a `make setup`. After that, just run `make run`

The graph to run should be specified in a separated file (assigned to a constant in `main.cpp`). 
Vertices will always start from 0 and the file should have the following format:

```
# comments are allowed

<n_vertices> <n_edges> <root>          # first line
<edge_src> <edge_dest> <edge_weight>   # subsequent lines
```
