# word-grid-search

## Problem
Given a **NxM** grid of characters, find all instances of word **W**.

## Input
Following the standard input file format of the repository, the first line of the input contains the number of test cases **T** and immediately after follows all data for test cases.

The test case data for this problem starts with two consecutive lines indicating the grid's *height* **M** and *width* **N** respectively. The next **M** lines each consisting of 0 up to **N** characters represent the contents of the grid. Lastly, a line containing the word **W** to be searched.

### Constraints

> 0 < **T** < 100
>
> 0 < **N** < 65536
>
> 0 < **M** < 65536
>
> 0 < Length of **W** < M

## Output
For every test case, the program should output

```
Case T: C
```

where **T** is the test case number *(starting from 1)* and **C** being the number of times the word is found in the grid.

## Example

Given an input file containing the following data:
```
3
4
4
DOGE
OGED
GEDO
EDOG
DOG
4
3
WAR
ARW
RWA
WAR
WAR
3
5
POWER
WOPPE
OOWE
POW
```

The program should output:

```
Case 1: 4
Case 2: 4
Case 3: 3
```