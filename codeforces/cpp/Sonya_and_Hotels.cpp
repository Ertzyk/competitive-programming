#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    for(int &p: x) cin >> p;
    int result = 2;
    for(int i = 0; i < n - 1; i++){
        if(x[i + 1] - x[i] > 2*d) result += 2;
        else if(x[i + 1] - x[i] == 2*d) result++;
    }
    cout << result << '\n';
    return 0;
}