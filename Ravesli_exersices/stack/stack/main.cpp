//
//  main.cpp
//  stack
//
//  Created by  Mister on 01.11.2020.
//

#include <iostream>
#include <cassert>

class Stack {
private:
    int Arr[10];
    int counter;
    
public:
    void reset() {
        counter = 0;
        for (auto& i : Arr) {
            i = 0;
        }
    }
    bool push(int value) {
        if (counter == 10) {
            return false;
        } else {
            Arr[counter] = value;
            ++counter;
            return true;
        }
    }
    
    int pop() {
        assert(counter != 0 && "No values in Stack");
        return Arr[--counter];
    }
    
    void print() const {
        std::cout << "( ";
        for (int i = 0; i < counter; ++i) {
            std::cout << Arr[i] << " " ;
        }
        std::cout << " )\n";
    }
    
};

int main() {
    
    Stack stack;
    stack.reset();
    
    stack.print();
    
    stack.push(3);
    stack.push(0);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    
    stack.print();
    
    return 0;
}
