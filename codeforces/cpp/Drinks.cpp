#include <iostream>
#include <vector>
#include <iomanip>

class Drink{
    private:
    double content;
    public:
    Drink(double d) : content(d) {}
    double get_content() const{
        return content;
    }
};

class DrinkMixture{
    private:
    double volume;
    std::vector<Drink> drinks;
    public:
    DrinkMixture(): volume(0) {}
    void collect_input(){
        int t;
        std::cin >> t;
        for(int i = 0; i < t; i++){
            double o;
            std::cin >> o;
            Drink d(o);
            drinks.emplace_back(d);
        }
    }
    void print_result(){
        calculate_total_volume();
        std::cout << std::fixed << std::setprecision(12) << volume/drinks.size() << '\n';
    }
    void calculate_total_volume(){
        for(auto drink: drinks) volume += drink.get_content();
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    DrinkMixture mixture;
    mixture.collect_input();
    mixture.print_result();
    return 0;
}