/*
This is a simple strategy pattern, but the strategies are templates.

Note that you do lose the ability to switch strategy at runtime!
*/

#include <iostream>

using namespace std;

struct Increment {
    static int exec(int i) {
        return i + 1;
    }
};

struct Triple {
    static int exec(int i) {
        return 3 * i;
    }
};

template <typename Strategy>
struct Computer {
    int compute(int i) {
        return Strategy::exec(i);
    }
};

int main() {
    Computer<Increment> incrementer;
    Computer<Triple> tripler;

    cout << incrementer.compute(5) << endl;
    cout << tripler.compute(5) << endl;
    
    return 0;
}