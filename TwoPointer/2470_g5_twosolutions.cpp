// BOJ GOLD 5
// https://www.acmicpc.net/problem/2470

#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> arr[i];
    	
    sort(arr, arr + n);
    
    int Min = 2'000'000'000;
    int s = 0, e = n - 1;
    int ms = s, me = e;
    while (s < e) {
    	int sum = arr[s] + arr[e];
    	if (Min > abs(sum)) {
			ms = s;
			me = e;
			Min = abs(sum);
		}
		
    	if (sum < 0) {
			s++;
		}
		else if (sum > 0) {
			e--;
		}
		else { // sum is 0
			ms = s;
			me = e;
    		break;
		}
	}
	
	cout << arr[ms] << ' ' << arr[me];
    
	return 0;
}