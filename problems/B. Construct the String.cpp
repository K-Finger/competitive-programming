#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;

        string pattern = "";
        for(int i = 0; i < b; i++){
            pattern += ('a' + i);
        }
        while(pattern.size() < a){
            pattern += 'a';
        }

        string ans = "";
        while(ans.size() < n){
            ans += pattern;
        }
        cout << ans.substr(0, n) << "\n";
    }
}
