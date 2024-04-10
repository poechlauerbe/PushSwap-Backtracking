# PushSwap-Backtracking

This was my first approach to the 42 project PushSwap.

The basic idea of the project is to sort a stack of integers in ascending order using two stacks and a limited set of operations. The algorithm must be efficient in terms of the number of operations used. To achieve all points, the algorithm has to sort 100 numbers within 700 operations and 500 numbers within 5500 operations.

## My Approach:

I attempted to solve the project with backtracking which is a recursive algorithmic approach that systematically explores all possible solutions to a problem by trying different choices, backtracking from paths that lead to dead ends until a solution is found.

Stack A is unsorted at the beginning, and Stack B is empty. I first push two numbers onto Stack B and sort them in descending order. The next number should be pushed to the right spot. So, I started a linked tree (also known as a tree data structure), where each possible operation has one branch. The goal is to reach a position where I can push a number onto Stack B in the correct place.

For example, at the beginning, I have 7 different operations (I limited myself a bit), and I create a solution for each of them. If one of the solutions is correct and it's possible to push a number onto Stack B, I win and can print out the used operation. If not, I have to go one level deeper. So, for each of the 7 solutions, I try to use my 7 operations, resulting in 49 solutions. I check again. If I get a solution, great! If not, the next round will give me 343 different solutions... and so on. You can see that a lot of memory is allocated.

## Why I Didn't Submit This Version for Evaluation?

I believe the last explanation already shows my problem - too many allocations, which means my program was pretty slow.

I attempted to reduce the amount of allocated memory by blocking combinations. For example, if "rotate A" was used, the next operation can't be "reverse rotate A". But even then, the time taken was too much. I even implemented a limit (in the header file: MAX_BACKTRACK_OPS); after that, only a simplified operation is used.

I could fix my program on the campus computers for 100 numbers, but not for 500. There would have been an endless waiting time during evaluation. So I had to find a different solution.

## My Final Solution (Not Included in This Repository):

The basis is the same. Only instead of trying for each number, I calculated the number of operations to get from Stack A to the right place on Stack B for each number, and then only executed the way with the fewest operations. This algorithm was invented by a 42 student and is called [Turk Sort](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

Instead of trial and error, I used a smarter (and faster) approach in the end.

## Instructions for Use


1. Use the provided Makefile to compile the `push_swap` executable:
```bash
make
```

2. Run the push_swap executable with the desired arguments:
```bash
./push_swap [arguments]
```
Replace [arguments] with any integers you like to sort.

For example:

```bash
./push_swap 4 2 7 1 5
```
This would execute the push_swap program with the list of integers 4 2 7 1 5.

## Fun Exercise:

Run this executable with Valgrind and, for example, 200 integers. I hope you have time - but you will see a lot of `malloc`s and `free`s. ;)
