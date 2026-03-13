#include <atomic>
using namespace std;

class Foo {
public:
    atomic<bool> first_done{false};
    atomic<bool> second_done{false};

    Foo() {}

    void first(function<void()> printFirst) {
        printFirst();
        first_done = true;
    }

    void second(function<void()> printSecond) {
        while(!first_done);
        printSecond();
        second_done = true;
    }

    void third(function<void()> printThird) {
        while(!second_done);
        printThird();
    }
};