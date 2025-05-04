#include <iostream>
#include <cmath>
using namespace std;

bool perfect_square(int a){
    int x = floor(sqrt(a));
    return a == x*x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2) cout << "NO\n";
        else{
            while(n%2 == 0) n /= 2;
            if(perfect_square(n)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}