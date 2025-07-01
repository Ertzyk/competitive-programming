#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%4 == 0) cout << "Bob\n"; 
        else cout << "Alice\n";
    }
    return 0;
}