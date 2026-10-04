#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vector<int> p;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		p.push_back(l);
	}
	
	// [1, 5]
	//   x       x
	// 1 6 3 4 5 2 = p[]
	
	// 1 2 3 4 5 6
	// 2 and 6 have to match
	
	// 2 <> 6
	vector<int> wrong;
	// [ 1, 5 ]

	for (int i = 0; i < n; i++) {
    	if (p[i] != i + 1) {
       		wrong.push_back(i);
    	}
	}
	
	int l = 0, r = (int) wrong.size() - 1;
	while (l <= r) {
		int leftIdx = wrong[l];
		int rightIdx = wrong[r];
		
		if (p[leftIdx] != rightIdx + 1 || p[rightIdx] != leftIdx + 1) {
			cout << "NO\n";
			return;
		}
		
		l++;
		r--;
	}
	
	cout << "YES\n";
}
	

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        solve();
    }
    return 0;
}
