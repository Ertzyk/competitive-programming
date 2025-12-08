#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <bitset>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <complex>
using namespace std;
using ll = long long;

bool check(int l, int r, vector<int>& far1, vector<int>& far2,vector<int>& first1,vector<int>& first2){
    if(min(far1[r], first1[l]) + min(far2[r], first2[l]) >= far1.size()/2 + 1) return true;
    return false;
}

int main(){
    //UNFINISHED
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a1(n), a2(n);
        for(int &x: a1) cin >> x;
        for(int &x: a2) cin >> x;
        vector<int> far1(2*n + 1), far2(2*n + 1);
        int p = 0;
        for(int i = 1; i <= 2*n; i++){
            while(p < n && a1[p] <= i) p++;
            far1[i] = p;
        }
        vector<int> first1(2*n + 1, n);
        for(int i = 0; i < n; i++){
            if(first1[a1[i]] == n) first1[a1[i]] = i;
        }

        for(int i = 2; i <= 2*n; i++){
            first1[i] = min(first1[i], first1[i - 1]);
        }

        p = n - 1;
        for(int i = 1; i <= 2*n; i++){
            while(p >= 0 && a2[p] <= i) p--;
            far2[i] = n - p - 1;
        }
        vector<int> first2(2*n + 1, n);
        reverse(a2.begin(), a2.end());
        for(int i = 0; i < n; i++){
            if(first2[a2[i]] == n) first2[a2[i]] = i;
        }

        for(int i = 2; i <= 2*n; i++){
            first2[i] = min(first2[i], first2[i - 1]);
        }


        // for(int x: far1) cout << x << ' ';
        // cout << "\n";
        // for(int x: far2) cout << x << ' ';
        // cout << "\n";
        // for(int x: first1) cout << x << ' ';
        // cout << "\n";
        // for(int x: first2) cout << x << ' ';
        // cout << "\n";
        int res = 0;
        for(int i = 1; i <= n; i++){
            int l = i, r = n;
            int k = n;
            while(l <= r){
                int m = (l + r)/2;
                if(check(i, m, far1,  far2, first1, first2)){
                    r = m - 1;
                    k = m;
                } else {
                    l = m + 1;
                }
            }
            res += n - k + 1;
        }
        cout << res << '\n';
    }
    return 0;
}