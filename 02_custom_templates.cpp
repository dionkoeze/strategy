/*
Same strategy pattern, but now the data is customizable through templates.
*/

#include <iostream>

using namespace std;

template <int Constant>
struct Add {
    static int exec(int i) {
        return i + Constant;
    }
};

template <int Factor>
struct Multiply {
    static int exec(int i) {
        return Factor * i;
    }
};

template <typename Strategy>
struct Computer {
    int compute(int i) {
        return Strategy::exec(i);
    }
};

int main() {
    Computer<Add<1>> incrementer;
    Computer<Multiply<3>> tripler;

    cout << incrementer.compute(5) << endl;
    cout << tripler.compute(5) << endl;
    
    return 0;
}