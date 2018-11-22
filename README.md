# Solving Codeforces 1040 B using Greedy and Dynamic Programing

This repository will solve Codeforce's problem 1040 B using Greedy approach and Dynamic Programing. We will also compare which approach is better.

## Team Member
- Ferinzhy Halik
- Jacky Siek
- Matius Ebenhaezer
- Noach Nathanael Tjahjadi

## Requirement
- C++ 14

## Sample I/O
**Sample #1**

input
```
7 2
```
output
```
2
1 6
```

**Sample #2**
input
```
5 1
```
output
```
2
1 4
```

## Explanation
### Problem Statement

The problem is about finding the minimum amount of move to turn the Shashlik for better cooking.\
Example :

```
n = 5, k = 1

 8  8  8  8  8  \
 8  8  8  8  8   \
 8  8  8  8  8     -- These are the Shashliks
 8  8  8  8  8   /
 |  |  |  |  |  /

 1  2  3  4  5

 There are 2 ways to turn all the skewers.
 One of them is turning the second skewer and the last skewer from left to right.

 Output: 
 2
 2 5 or 1 4

 2 = skewer 1 2 3 turned
 5 = skewer 4 and 5 turned.
 ------------------------------
 1 = skewer 1 2
 4 = skewer 3 4 5
```	

### Greedy Approach



### Dynamic Programing

