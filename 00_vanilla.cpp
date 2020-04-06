/*
This is a simple strategy pattern on the same type of data.
*/

#include <iostream>

using namespace std;

struct Strategy {
    virtual int exec(int i) = 0;
};

struct Increment : public Strategy {
    int exec(int i) {
        return i + 1;
    }
};

struct Triple : public Strategy {
    int exec(int i) {
        return 3 * i;
    }
};

struct Computer {
    Strategy *strategy;

    Computer(Strategy *strategy) : strategy(strategy) {}

    int compute(int i) {
        return strategy->exec(i);
    }
};

int main() {
    Strategy *increment = new Increment();
    Strategy *triple = new Triple();

    Computer incrementer(increment);
    Computer tripler(triple);

    cout << incrementer.compute(5) << endl;
    cout << tripler.compute(5) << endl;
    
    return 0;
}