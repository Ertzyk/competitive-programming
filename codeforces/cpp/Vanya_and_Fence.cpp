#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, h, result = 0;
    cin >> n >> h;
    vector<int> a(n);
    while(n--){
        int x;
        cin >> x;
        if(x > h) result += 2;
        else result++;
    }
    cout << result << '\n';
    return 0;
}