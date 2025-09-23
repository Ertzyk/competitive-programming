#include <iostream>
#include <vector>
using namespace std;

struct FiveDimensionalPoint{
    int a, b, c, d, e;
};

int scalar_xy_xz(const FiveDimensionalPoint& x, const FiveDimensionalPoint& y, const FiveDimensionalPoint&z){
    return (y.a - x.a)*(z.a - x.a) + (y.b - x.b)*(z.b - x.b) + (y.c - x.c)*(z.c - x.c) + 
    (y.d - x.d)*(z.d - x.d) + (y.e - x.e)*(z.e - x.e);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<FiveDimensionalPoint> p(n);
    vector<int> good_points;
    for(auto &x: p) cin >> x.a >> x.b >> x.c >> x.d >> x.e;
    if(n >= 12){
        cout << "0\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        bool good = true;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            for(int k = 0; k < n; k++){
                if(i == k || j == k) continue;
                if(scalar_xy_xz(p[i], p[j], p[k]) > 0){
                    good = false;
                    break;
                }
            }
            if(!good) break;
        }
        if(good) good_points.push_back(i + 1);
    }
    cout << good_points.size() << '\n';
    for(int x: good_points) cout << x << '\n';
    return 0;
}