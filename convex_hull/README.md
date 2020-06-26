# Chan's Algorithm

This project aims to implement and test the famous Timothy Chan's algorithm for Convex Hull computation.

## Introduction
### Convex Hull

A convex hull of a given set of points is a minimal convex polygon which contains all the points within it.

### Related Algorithms

Convex Hull computation is a very well studied and important problem in computational geometry. It has many real world applications which makes worthy to be sought after.

Some of the other well known algorithms for convex hull are:
1. Jarvis March (Gift wrapping) algorithm | `O(n * h)`
2. Graham Scan algorithm | `O(n log n)`

Here, `n` is the number of points in the input and `h` is the number of points in the output convex hull.

### Algorithm & Complexity

Chan's algorithm is inspired by both `Graham Scan` and `Jarvis March`. It uses the ideas from both the algorithms to acheive the asymptotically optimal time complexity of `O(n log h)` where `n` is the number of points in the input and `h` is the number of points on the output convex hull.
Here, since the complexity depends on the output hence, it is a output sensitive algorithm.
Note, `h <= n` Hence, Chan's algorithm is atleast as good as `Graham Scan`.

Moreover, if `h \in o(n)` then Chan's algorithms is asymptotically better than `Graham Scan`.

### How to run

#### Compilation
To compile the programs use the corresponding make command:
1. Chan's algorithm : `make chan`
2. Graham Scan algorithm : `make graham`
3. Jarvis March : `make jarvis`

#### Execution
Execute the code by giving an input via console or through input file.

``` bash
./main_chan < ./tests/inputs/t0.txt
```

### Run tests
1. Compile tester code `make test_fixed_h`
2. Execute `./test_fixed_h n h numTests`
For example:
`./test_fixed_h 10000 10 100`

