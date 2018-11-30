# Solving Codeforces 1040 B using Greedy and Dynamic Programing

This repository will solve Codeforce's problem [1040B](https://codeforces.com/problemset/problem/1040/B) using Greedy approach and Dynamic Programing. We will also compare which approach is better.

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

The problem is about finding the minimum amount of move to turn the Shashlik for better cooking.
```
n = amount of shashlik
k = the skewer(s) beside the shashlik that will be chosen and according to amount of way

n = 3
	8	8	8 	
	8	8	8  \    
	8	8	8   -- These are the Shashliks
	8	8	8  /
	|	|	| 

	1 	2 	3

k = 1
- 2 as 1's k
- 1 and 3 as 2's k
- 2 as 3's k

k = 2
- 1 and 2 as 3's k
- 2 and 3 as 1's k
__________________________________________________________________________________

Example :

n = 5, k = 1

 8  8  8  8  8  
 8  8  8  8  8   
 8  8  8  8  8     
 8  8  8  8  8  
 |  |  |  |  |  

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
The problem solved using the formulas made base on the problem.
```
d=2*k+1;
q=n/d;
r=n%d;
if(r!=0)
	q++;
else
	r=2*k;
cout<<q<<endl;
```
The formula above is to print the amount of way to turn the Shashlik(s) for better cooking where :
- `d` is the formula made to check the `k` form every index where `d = 2 * k + 1`.
- `q` is a integer for dividing the amount of shashlik with the formula.
- `r` is to count the remainder between the amount of shashilik and the formula.

If there is a remainder, increment the `q`.\
If There are no remainder, `r` become `2 * k`

```
for(i=1+r/2;i<=n;i+=d)
	cout<<i<<" ";
```
Then print which skewer can be turned.\
Complexity:\
Worst Case : O(n)\
[Solution](https://codeforces.com/contest/1040/submission/46118595)

### Dynamic Programing

The problem can be solved by DP by memoization.\
Memoization is a optimization technique where we stored the calculations so they don't need to be recalculated.\
This technique is used by using array `a` , `val` and `last_val` , and then the `temp` to store the calculations.
```
int i = 0, a[10000] = {-100000000}, val = 0, last_val = -1000000000;
while(val + k + 1<= n) {
	val += k  + 1;
	a[i++] = val;
	last_val = val;
	val += k;
	}

if(last_val + k < n) {
	int temp = a[i-1] + 2*k + 1 - n;
	for(int j = 0; j < i; j++) {
		a[j] -= temp;
	}
	a[i++] = n;
}
cout << i << endl;
```
Those are used to print the amount of way to turn the skewer(s).
- First we make a condition when `val + k + 1` is smaller or equal to `n`.
- While it's still on this condition , `val` becomes `val + k + 1`.
- Then the array `a` with current values `i = i + 1` becomes `val`.
- And the `last_val` becomes `val` and then add `val` with `k`.
- If the `last_val + k` is smaller then `n`, declare `temp`.
- Where `temp` is equal too array `a` with value `i-1` + `2*k+1` - `n`.
- Loop `j` value on arrat `a` where the array is subtracted with `temp` value.
- And the array `a` with current values `i = i + 1` becomes `n`.

Then print which skewer to turn.
```
for(int k = 0; k < i; k++) {
	cout<<a[k]<<" ";
}	
```
Complexity:\
Worst Case : O(n)\
[Solution](https://codeforces.com/contest/1040/submission/46118666)

### Comparison
These are the comparison between Greedy and Dynamic Programing of `n` and `k` based on Greedy and Dynamic Programing with OpenMp.\
![](https://github.com/AAlab1819/ProjectTeam02-B/blob/master/Greedy.png?raw=true)\
![](https://github.com/AAlab1819/ProjectTeam02-B/blob/master/DP.png?raw=true)\
![](https://github.com/AAlab1819/ProjectTeam02-B/blob/master/Graph.png?raw=true)

The Problem can be solved by Greedy approach and Dynamic Programing.\
So Dynamic Programing can solve this problem by memoization, where it remembers the calculation on finding the amount of way.\
But this problem can be solved by greedy approach by making the formula based on the explanation on the problem.\
Based on the graph, we believe approach by Greedy is faster than Dynamic Programing.\
Approaching this problem by Dynamic Programing can be also faster if `n` value and `k` value is near or about the same like in the graph.
