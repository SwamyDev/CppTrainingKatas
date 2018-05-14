
#ifndef STACK_STACK_H
#define STACK_STACK_H


#include <stdexcept>

template <size_t capacity>
class Stack {
public:
    class Underflow : public std::runtime_error {
    public:
        Underflow() : std::runtime_error("Popping an empty stack") {}
    };

    class Overflow : public std::runtime_error {
    public:
        Overflow() : std::runtime_error("The stack has exceeded its capacity") {}
    };

    bool empty() const{
        return itsSize == 0;
    }

    int pop(){
        if (empty()) throw Underflow();
        return itsElements[--itsSize];
    }

    void push(int element){
        if (itsSize == capacity) throw Overflow();
        itsElements[itsSize++] = element;
    }

private:
    size_t itsSize = 0;
    int itsElements[capacity] = {};
};

#endif //STACK_STACK_H
