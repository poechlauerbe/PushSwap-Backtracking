# PushSwap-Backtracking

This was my first approach for the 42 project PushSwap. The basic idea of the project is to sort a stack of integers in ascending order using two stacks and a limited set of operations. The algorithm must be efficient in terms of the number of operations used. To get all points the algorithm has to sort 100 numbers within 700 operations and 500 numbers within 5500 operations.

## My approach:

I tried to solve the project with backtracking. Stack A is unsorted at the beginning. Stack B is empty. I first push two numbers to stack B and sort them in descending order. The next number should be pushed to the right spot. So I started a linked tree (also known as a tree data structure). for each possible operation there is one branch in this linked tree. The goal is to get into the position to push something on stack B in the right place.

So f.e. in the beginning I have 7 different operations (I limited myself a bit) and I create for each of them a solution. If one of the solutions is correct and it is it is possible to push a number to stack B - I win and can just print out the used operation. If not - I have to go one level deeper. So for each of 7 solutions I try to use my 7 operations. Now I get 49 solutions. I check again. If I get a solution - great! If not - the next round will give me 343 different solutions... Next 2401, then 16807, 117649, ... You see - a lot of allocated memory.

## Why I didn't submit this version for evaluation?

I think the last explanation already shows my problem - to many allocations which means my program was pretty slow.

I tried to reduce the amount of allocated memory by blocking combinations - f.e. if rotate A was used - the next operation  can't be reverse rotate A. But even then the amount of time was too much. I even implemented a limit (in the header file: MAX_BACKTRACK_OPS) after that only a simplified operation is possible.

I could fix my program on the campus computers for 100 numbers. But not for 500. There would have been an endless waiting time during evaluation. So i had to find something different.

## My final solution (not in this repository included):

The base is the same. Only instead of trying for each number, I calculate the amount of operations to get from stack A to the right place on stack B for each number and then only execute the way with the fewest operations. This algorithm was invented by a 42 student and is called [turk sort](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

Instead of trial and error I used a smarter (and faster) way in the end.

## Fun exercise:

Run this executable with valgrind and for example 200 integers - I hope you have time - but you will see a lot of malloc's and free's ;)
