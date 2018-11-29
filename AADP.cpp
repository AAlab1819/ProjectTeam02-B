#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

int main() {
	double startTime=omp_get_wtime();
	int n, k;
	cin>>n>>k;

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

	cout<<i<<endl;
	for(int k = 0; k < i; k++) {
		cout<<a[k]<<" ";
	}	

	cout<<endl;
	cout<<omp_get_wtime()-startTime<<endl;

	return 0;
}
