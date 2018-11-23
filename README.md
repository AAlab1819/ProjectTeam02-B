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
The formula above is to print the amount of way to turn the Shashlik(s) for better cooking.

```
for(i=1+r/2;i<=n;i+=d)
	cout<<i<<" ";
```
Then print which skewer can be turned.\
Complexity:\
Worst Case : O(n)

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
Those are used to print the amount of way to turn the skewer(s).\
Then print which skewer to turn.
```
for(int k = 0; k < i; k++) {
	cout<<a[k]<<" ";
}	
```
Complexity:\
Worst Case : O(n)

### Comparison





