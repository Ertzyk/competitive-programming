#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, type = 1;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    for(int i = 0; i < n - 1; i++){
        if(type == 1){
            if(a[i] == a[i + 1]) type = 2;
            else if(a[i] > a[i + 1]) type = 3;
        } else if(type == 2){
            if(a[i] < a[i + 1]){
                cout << "NO\n";
                return 0;
            } else if(a[i] > a[i + 1]) type = 3;
        } else if(a[i] <= a[i + 1]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}