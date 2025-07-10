#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Piece{
    char type;
    int x, y;
    bool operator<(const Piece &other) const {
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Piece king;
    int n;
    king.type = 'K';
    cin >> n >> king.x >> king.y;
    vector<Piece> r, c, d1, d2;
    r.push_back(king);
    c.push_back(king);
    d1.push_back(king);
    d2.push_back(king);
    for(int i = 0; i < n; i++){
        Piece p;
        cin >> p.type >> p.x >> p.y;
        if(p.x == king.x) r.push_back(p);
        else if(p.y == king.y) c.push_back(p);
        else if(p.x + p.y == king.x + king.y) d1.push_back(p);
        else if(p.x - p.y == king.x - king.y) d2.push_back(p);
    }
    sort(r.begin(), r.end());
    for(int i = 0; i < r.size(); i++){
        if(r[i].type == 'K'){
            if((i > 0 && r[i - 1].type != 'B') || (i < r.size() - 1 && r[i + 1].type != 'B')){
                cout << "YES\n";
                return 0;
            } else break;
        }
    }
    sort(c.begin(), c.end());
    for(int i = 0; i < c.size(); i++){
        if(c[i].type == 'K'){
            if((i > 0 && c[i - 1].type != 'B') || (i < c.size() - 1 && c[i + 1].type != 'B')){
                cout << "YES\n";
                return 0;
            } else break;
        }
    }
    sort(d1.begin(), d1.end());
    for(int i = 0; i < d1.size(); i++){
        if(d1[i].type == 'K'){
            if((i > 0 && d1[i - 1].type != 'R') || (i < d1.size() - 1 && d1[i + 1].type != 'R')){
                cout << "YES\n";
                return 0;
            } else break;
        }
    }
    sort(d2.begin(), d2.end());
    for(int i = 0; i < d2.size(); i++){
        if(d2[i].type == 'K'){
            if((i > 0 && d2[i - 1].type != 'R') || (i < d2.size() - 1 && d2[i + 1].type != 'R')){
                cout << "YES\n";
                return 0;
            } else break;
        }
    }
    cout << "NO\n";
    return 0;
}