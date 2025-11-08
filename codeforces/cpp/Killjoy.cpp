#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        bool diff = false, same = false;
        int c = accumulate(a.begin(), a.end(), 0) - n*x;
        for(int i = 0; i < n; i++){
            if(a[i] != x) diff = true;
            else same = true;
        }
        if(c == 0 && !diff) cout << "0\n";
        else if(c == 0 || same) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}