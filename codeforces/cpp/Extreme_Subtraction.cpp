#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, decreased = 0;
        bool out = false;
        cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        for(int i = n - 2; i >= 0; i--){
            if(a[i] < decreased){
                cout << "NO\n";
                out = true;
                break;
            }
            if(a[i] > a[i + 1]) decreased += a[i] - a[i + 1];
        }
        if(!out) cout << "YES\n";
    }
    return 0;
}