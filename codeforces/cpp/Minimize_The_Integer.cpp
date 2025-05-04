#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a, result = "";
        cin >> a;
        a += "A";
        int point_even = 0, point_odd = 0;
        while(point_even < a.size() - 1 && (int)a[point_even]%2){
            point_even++;
        }
        while (point_odd < a.size() - 1 && (int)a[point_odd]%2 == 0){
            point_odd++;
        }
        while (point_even < a.size() - 1 || point_odd < a.size() - 1) {
            if((int)a[point_even] < (int)a[point_odd]){
                result += a[point_even];
                point_even++;
            } else {
                result += a[point_odd];
                point_odd++;
            }
            while(point_even < a.size() - 1 && (int)a[point_even]%2){
                point_even++;
            }
            while (point_odd < a.size() - 1 && (int)a[point_odd]%2 == 0){
                point_odd++;
            }
        }
        cout << result << "\n";
    }
    return 0;
}