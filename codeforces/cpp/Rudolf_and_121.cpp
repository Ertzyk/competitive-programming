#include <iostream>
#include <vector>
using namespace std;

bool can_zeroize(vector<int>& a, int pointer){
    if(pointer == 2){
        if(2*a[0] == a[1] && 2*a[2] == a[1]) return true;
        else return false;
    }
    a[pointer - 1] -= 2*a[pointer];
    a[pointer - 2] -= a[pointer];
    if(a[pointer - 1] < 0 || a[pointer - 2] < 0) return false;
    else return can_zeroize(a, pointer - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        cout << ((can_zeroize(a, n - 1)) ? "YES\n" : "NO\n");
    }
    return 0;
}