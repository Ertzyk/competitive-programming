#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b, c;
    cout << "? 1 2\n";
    cout.flush();
    cin >> a;
    cout << "? 2 3\n";
    cout.flush();
    cin >> b;
    cout << "? 1 3\n";
    cout.flush();
    cin >> c;
    vector<int> result(n);
    result[0] = (a - b + c)/2;
    result[1] = (a + b - c)/2;
    result[2] = (- a + b + c)/2;
    for(int i = 3; i < n; i++){
        cout << "? 1 " << i + 1 << '\n';
        cout.flush();
        int x;
        cin >> x;
        result[i] = x - result[0];
    }
    cout << "! ";
    for(int i = 0; i < n; i++) cout << result[i] << ' ';
    cout.flush();
    return 0;
}