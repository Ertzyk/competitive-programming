#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    srand(time(0));
    while(t--){
        int n;
        cin >> n;
        int i = 1, j = 2, k = 3;
        while(true){
            cout << "? " << i << ' ' << j << ' ' << k << '\n';
            cout.flush();
            int p;
            cin >> p;
            if(p == 0) break;
            int r = rand()%3;
            if(r == 0) i = p;
            else if(r == 1) j = p;
            else k = p;
        }
        cout << "! " << i << ' ' << j << ' ' << k << '\n';
        cout.flush();
    }
    return 0;
}