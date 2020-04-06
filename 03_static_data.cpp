/*
Data is now variable and can be assigned at runtime.

This requires a type per context.
*/

#include <iostream>

using namespace std;

// note that we need a new type per integer
struct AddInteger {
    static int value;
};

struct MulInteger {
    static int value;
};

struct Boolean {
    static bool value;
};

template <typename Data>
struct Add {
    static int exec(int i) {
        return i + Data::value;
    }
};

template <typename Data>
struct Multiply {
    static int exec(int i) {
        return Data::value * i;
    }
};

template <typename Data>
struct Condition {
    static int exec(int i) {
        return Data::value ? i : 0;
    }
};

template <typename Strategy>
struct Computer {
    int compute(int i) {
        return Strategy::exec(i);
    }
};

int AddInteger::value = 1;
int MulInteger::value = 3;
bool Boolean::value = false;

int main() {
    // ugh....   
    Computer<Add<AddInteger>> incrementer;
    Computer<Multiply<MulInteger>> tripler;
    Computer<Condition<Boolean>> conditioner;

    cout << incrementer.compute(5) << endl;
    cout << tripler.compute(5) << endl;
    cout << conditioner.compute(5) << endl;
    
    return 0;
}