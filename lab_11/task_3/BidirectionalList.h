#pragma once

#include <memory>

template<typename T>
struct Node {
    T value;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;

    Node() = default;

    explicit Node(T value) : value(value) {}

    ~Node() { std::cout << "Node with value " << value << " destructor" << std::endl; }
};

template<class T>
class BidirectionalList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
public:
    BidirectionalList();

    void insertFirstNode(std::shared_ptr<Node<T>> nodePtr);

    void pushFront(T item);

    void pushBack(T item);

    bool popFront();

    bool popBack();

    bool isEmpty();

    void print();
};

template<class T>
BidirectionalList<T>::BidirectionalList() {
    head = std::make_shared<Node<T>>();
    tail = std::make_shared<Node<T>>();
}

template<class T>
void BidirectionalList<T>::insertFirstNode(std::shared_ptr<Node<T>> nodePtr) {
    head->next = nodePtr;
    nodePtr->prev = head;
    tail->prev = nodePtr;
    nodePtr->next = tail;
}

template<class T>
void BidirectionalList<T>::pushFront(T item) {
    std::shared_ptr<Node<T>> nodePtr = std::make_shared<Node<T>>(item);
    if (isEmpty()) {
        insertFirstNode(nodePtr);
        return;
    }

    nodePtr->next = head->next;
    head->next->prev = nodePtr;
    head->next = nodePtr;
    nodePtr->prev = head;
}

template<class T>
void BidirectionalList<T>::pushBack(T item) {
    std::shared_ptr<Node<T>> nodePtr = std::make_shared<Node<T>>(item);
    if (isEmpty()) {
        insertFirstNode(nodePtr);
        return;
    }

    nodePtr->prev = tail->prev;
    tail->prev.lock()->next = nodePtr;
    tail->prev = nodePtr;
    nodePtr->next = tail;
}

template<class T>
bool BidirectionalList<T>::popFront() {
    if (isEmpty())
        return false;

    head->next->next->prev = head;
    head->next = head->next->next;
    if (head->next == tail) {
        tail->prev = std::weak_ptr<Node<T>>();
        head->next = std::shared_ptr<Node<T>>();
    }
    return true;
}

template<class T>
bool BidirectionalList<T>::popBack() {
    if (isEmpty())
        return false;

    std::shared_ptr<Node<T>> tail_prev = tail->prev.lock();
    tail->prev.lock()->prev.lock()->next = tail;
    tail->prev = tail_prev->prev;

    if (head->next == tail) {
        tail->prev = std::weak_ptr<Node<T>>();
        head->next = std::shared_ptr<Node<T>>();
    }
    return true;
}

template<class T>
bool BidirectionalList<T>::isEmpty() {
    return head->next == nullptr;
}

template<class T>
void BidirectionalList<T>::print() {
    if (isEmpty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    std::shared_ptr<Node<T>> it = head->next;
    while (it->next != nullptr) {
        std::cout << it->value << " ";
        it = it->next;
    }
    std::cout << std::endl;
}