//
// Created by Михаил Степанов on 18.08.2020.
//

#include <iostream>

template<class T>
class optional {
    bool _isValid;
    T _v;
public:
    optional() : _isValid(false) {}; // Nothing
    optional(T x) : _isValid(true), _v(x) {}; // Nothing
    bool isValid() const { return _isValid; }

    T val() const { return _v; }
};


template<class A, class B>
std::function<optional<B>(optional<A>)>
fmap(std::function<B(A)> f) {
    return [f](optional<A> opt) {
        if (!opt.isValid()) { return optional<B>{}; }
        else { return optional<B>{f(opt.val())}; }
    };
}

int sqrt<T>(int value) {
    return value * value;
}

int main() {
    optional g = fmap(sqrt);

    return 0;
}