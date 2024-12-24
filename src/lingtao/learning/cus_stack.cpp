#include <iostream>

template <class T>
class Node {
    public:
        Node<T>* next;
        Node(T v): val(v) {}
        T value() {
            return val;
        }
    private:
        T val;
};

template <class T>
class CusStackLinkedList {
public:
    CusStackLinkedList(): stackSize(0), current(nullptr), last(nullptr) {};

    void push(T v) {
        Node<T>* node = new Node<T>(v); 
        
        if (current == nullptr) {
            current = node;
            last = node;
        }
        else {
            last->next = node;
            last = node;
        }
        stackSize = stackSize + 1;
    }

    T top() {
        if (current == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        
        return current->value();
    }

    void pop() {
        if (current == nullptr)
            throw std::runtime_error("Stack is empty.");

        Node<T>* tmpNode = current->next;
        current->next = nullptr;
        current = tmpNode;
        stackSize = stackSize - 1;
    }

    int size() {
        return stackSize;
    }

private:
    Node<T>* current;
    Node<T>* last;
    int stackSize;

};

template <class T>
class CusStackArray {
public:
    CusStackArray() : current(0), last(0) {}

    T top() {
        if (current != last) {
            return elements[current];
        }
        throw std::runtime_error("Stack is empty.");
    };
    void pop() {
        current = current + 1;
    };
    void push(T element) {
        elements[last] = element;
        last = last + 1;
    };
    bool isEmpty() {
        return current == last; 
    };

    int size() {
        return  last - current;
    }


private:
    int current;
    int last;
    T elements[];
};

int main() {
    CusStackLinkedList<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout<<stack.top()<< std::endl;
    stack.pop();
    std::cout<<stack.top()<< std::endl;
    stack.pop();
    std::cout<<stack.top()<< std::endl;
    stack.pop();
    std::cout<<"stack size: "<< stack.size()<< std::endl;


    return 0;
}