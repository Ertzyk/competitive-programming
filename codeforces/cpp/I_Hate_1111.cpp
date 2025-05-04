#include <iostream>
#include <bitset>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    bitset<1099> precal;
    precal.reset();
    for(int a = 0; a < 10; a++){
        int b = 0;
        while(111*a + 11*b < 1099){
            precal[111*a + 11*b] = 1;
            b++;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(x < 1099) cout << ((precal[x]) ? "YES\n" : "NO\n");
        else if(x == 1099) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}