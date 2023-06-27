#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
template <typename T>
class Deque {
    // Internal structure representing a node in the deque
    struct Node {
        Node(T elem) {
            exp = elem;
        }
        Node* pointer_h = nullptr; // Pointer to the previous node
        Node* pointer_t = nullptr; // Pointer to the next node
        T exp;                     // Data stored in the node
    };

    Node* head = nullptr; // Pointer to the front (head) of the deque
    Node* tail = nullptr; // Pointer to the back (tail) of the deque
    int s1ze = 0;         // Size of the deque

public:
    // Pushes an element to the back of the deque
    void push_back(T elem) {
        Node* back_elem = new Node(elem);
        if (head == nullptr) {
            tail = back_elem;
            head = back_elem;
        } else {
            back_elem->pointer_h = tail;
            tail->pointer_t = back_elem;
            tail = back_elem;
        }
        s1ze++;
    }

    // Pushes an element to the front of the deque
    void push_front(T elem) {
        Node* fr_elem = new Node(elem);
        if (head == nullptr) {
            tail = fr_elem;
            head = fr_elem;
        } else {
            fr_elem->pointer_t = head;
            head->pointer_h = fr_elem;
            head = fr_elem;
        }
        s1ze++;
    }

    // Removes the element from the back of the deque
    void pop_back() {
        if (s1ze != 0) {
            tail = tail->pointer_h;
            tail->pointer_t = nullptr;
            s1ze--;
        } else {
            cerr << "Deque is clear, its size is 0" << endl;
            exit(1);
        }
    }

    // Removes the element from the front of the deque
    void pop_front() {
        if (s1ze != 0) {
            head = head->pointer_t;
            head->pointer_h = nullptr;
            s1ze--;
        } else {
            cerr << "Deque is clear, its size is 0" << endl;
            exit(1);
        }
    }

    // Overloading the << operator for printing the deque
    friend std::ostream& operator<<(std::ostream& os, Deque<T>& deck) {
        int length = deck.get_size();
        Node* pointer_t = deck.tail;
        for (int i = 0; i < length; i++) {
            os << pointer_t->exp << " ";
            pointer_t = pointer_t->pointer_h;
        }
        return os;
    }

    // Returns the size of the deque
    int get_size() { return s1ze; }

    // Returns the element at the front of the deque
    T get_front() {
        if (s1ze > 0)
            return head->exp;
        else {
            cerr << "Deque is clear, its size is 0" << endl;
            exit(1);
        }
    }

    // Returns the element at the back of the deque
    T get_back() {
        if (s1ze > 0)
            return tail->exp;
        else {
            cerr << "Deque is clear, its size is 0" << endl;
            exit(1);
        }
    }
};

void printDasn() {
    cout << "-----------------------" << endl;
}

template <typename T>
void printInfoDeque(Deque<T>& deq) {
    cout << "Front exper is " << deq.get_front() << endl;
    cout << "Back exper is " << deq.get_back() << endl;
    cout << "Size is " << deq.get_size() << endl;
    printDasn();
}

int main() {
    Deque<int> example;
    cout << "size is " << example.get_size() << endl;
    printDasn();
    example.push_back(15);
    printInfoDeque<int>(example);
    example.push_front(25);
    printInfoDeque<int>(example);
    example.push_front(20);
    printInfoDeque<int>(example);
    example.pop_back();
    printInfoDeque<int>(example);
    example.pop_front();
    printInfoDeque<int>(example);

    Deque<char> example1;
    cout << "size is " << example1.get_size() << endl;
    printDasn();
    example1.push_back('a');
    printInfoDeque<char>(example1);
    example1.push_front('b');
    printInfoDeque<char>(example1);
    example1.push_front('c');
    printInfoDeque<char>(example1);
    example1.pop_back();
    printInfoDeque<char>(example1);
    example1.pop_front();
    printInfoDeque<char>(example1);
}