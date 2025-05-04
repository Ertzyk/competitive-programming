#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        vector<int> c(a.begin(), a.end());
        sort(c.begin(), c.end());
        int point = n - 1;
        while(point >= 0 && a[point] == c[point]) point--;
        double prob = 1;
        while(m--){
            int r;
            double p;
            cin >> r >> p;
            if(r > point) prob *= (1 - p);
        }
        if(point == -1) cout << "1\n";
        else cout << fixed << setprecision(16) << 1 - prob << '\n';
    }
    return 0;
}