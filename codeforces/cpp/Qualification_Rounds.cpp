#include <iostream>
#include <vector>
using namespace std;

struct Problem{
    int a, b, c, d;
    int mysum(){
        return a + b + c + d;
    }
    int binary(){
        return 8*a + 4*b + 2*c + d;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if(k == 1){
        bool found = false;
        while(n--){
            int a;
            cin >> a;
            if(a == 0) found = true;
        }
        cout << (found ? "YES\n" : "NO\n");
    } else if(k == 2){
        bool found1 = false, found2 = false;
        while(n--){
            int a, b;
            cin >> a >> b;
            if(a == 0) found1 = true;
            if(b == 0) found2 = true;
        }
        cout << ((found1 && found2) ? "YES\n" : "NO\n");
    } else if(k == 3){
        bool found1 = false, found2 = false, found3 = false, lessThan2 = false;
        while(n--){
            int a, b, c;
            cin >> a >> b >> c;
            if(a == 0) found1 = true;
            if(b == 0) found2 = true;
            if(c == 0) found3 = true;
            if(a + b + c <= 1) lessThan2 = true;
        }
        cout << ((found1 && found2 && found3 && lessThan2) ? "YES\n" : "NO\n");
    } else {
        bool found1 = false, found2 = false, found3 = false, found4 = false;
        vector<Problem> v(n);
        int m = 4;
        for(int i = 0; i < n; i++){
            cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
            if(v[i].a == 0) found1 = true;
            if(v[i].b == 0) found2 = true;
            if(v[i].c == 0) found3 = true;
            if(v[i].d == 0) found4 = true;
            m = min(m, v[i].mysum());
        }
        if(m == 0) cout << "YES\n";
        else if(m == 1) cout << ((found1 && found2 && found3 && found4) ? "YES\n" : "NO\n");
        else if(m == 2){
            bool b12 = false, b3 = false, b9 = false, b6 = false, b10 = false, b5 = false;
            for(int i = 0; i < n; i++){
                if(v[i].binary() == 12) b12 = true;
                else if(v[i].binary() == 3) b3 = true;
                else if(v[i].binary() == 9) b9 = true;
                else if(v[i].binary() == 6) b6 = true;
                else if(v[i].binary() == 10) b10 = true;
                else if(v[i].binary() == 5) b5 = true;
            }
            cout << (((b12 && b3) || (b9 && b6) || (b10 && b5)) ? "YES\n" : "NO\n"); 
        } else cout << "NO\n";
    }
    return 0;
}