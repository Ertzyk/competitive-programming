#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, i = 0, result = 0;
    string a, b;
    cin >> n >> a >> b;
    while(i < n){
        if(i < n - 1 && a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] != a[i + 1]){
            result++;
            i++;
        } else if (a[i] != b[i]) result++;
        i++;
    }
    cout << result;
    return 0;
}