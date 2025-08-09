#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> Mex(n + 1);
    cout << "1 ";
    int M = n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        Mex[x] = true;
        while(Mex[M]) M--;
        cout << 1 + i - n + M << " \n"[i == n];
    }
    return 0;
}