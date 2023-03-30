#include "Node.h"

template <class T>
Node<T>::Node() {
    this->data = nullptr;
    this->clear();
}

template <class T>
Node<T>::Node(T value): Node() {
    this->clear();
    this->data = new T;
    this->data = std::move(value);
}

template <class T>
Node<T>::Node(typename Node<T>::node_ref other): Node() {
    this->copy(other);
}

template <class T>
Node<T>::Node(typename Node<T>::node &&other): Node() {
    if (this != &other) {
        this->copy(other);
        other.clear();
    }
}

template <class T>
typename Node<T>::node_ref Node<T>::operator=(typename Node<T>::node_ref other) {
    this->copy(other);
    return *this;
}

template <class T>
typename Node<T>::node_ref Node<T>::operator=(typename Node<T>::node &&other) {
    if (this != &other) {
        this->copy(other);
        other.clear();
    }
    return *this;
}

template <class T>
Node<T>::~Node() {
    this->clear();
}

template <class T>
void Node<T>::copy(node_ref other) {
    this->data = other.data;
    this->parent = other.parent;
    this->brother = other.brother;
    this->back = other.back;
    this->son = other.son;
}

template <class T>
void Node<T>::clear() {
    if (data != nullptr)
        delete data;
    this->data = nullptr;
    this->parent = this->son = nullptr;
    this->back = this->brother = nullptr;
}

// Accessor (or Getter)
template <class T>
T Node<T>::getData() const noexcept {
    return &this->data;
}

template <class T>
typename Node<T>::const_node_point Node<T>::getParent() const noexcept {
    return this->parent;
}

template <class T>
typename Node<T>::const_node_point Node<T>::getBrother() const noexcept {
    return this->brother;
}

template <class T>
typename Node<T>::const_node_point Node<T>::getBack() const noexcept {
    return this->back;
}

template <class T>
typename Node<T>::const_node_point Node<T>::getSon() const noexcept {
    return this->son;
}

template <class T>
typename Node<T>::node_point Node<T>::getParent() noexcept {
    return this->parent;
}

template <class T>
typename Node<T>::node_point Node<T>::getBrother() noexcept {
    return this->brother;
}

template <class T>
typename Node<T>::node_point Node<T>::getBack() noexcept {
    return this->back;
}

template <class T>
typename Node<T>::node_point Node<T>::getSon() noexcept {
    return this->son;
}

// Mutator (or Setter)
template <class T>
void Node<T>::setData(typename Node<T>::point ptr) {
    this->data = ptr;
}

template <class T>
void Node<T>::setParent(typename Node<T>::node_point ptr) {
    this->parent = ptr;
}

template <class T>
void Node<T>::setBrother(typename Node<T>::node_point ptr) {
    this->brother = ptr;
}

template <class T>
void Node<T>::setBack(typename Node<T>::node_point ptr) {
    this->back = ptr;
}

template <class T>
void Node<T>::setSon(typename Node<T>::node_point ptr) {
    this->son = ptr;
}
