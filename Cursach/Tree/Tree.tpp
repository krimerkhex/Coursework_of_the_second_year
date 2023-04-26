#include "Tree.h"

template <class T>
Tree<T>::Tree() {
    this->count = 0;
    this->root = nullptr;
}

template <class T>
Tree<T>::Tree(typename Tree<T>::node_point point) : Tree() {
    this->count = 1;
    this->root = this->counting(point);
}

template <class T>
Tree<T>::Tree(std::initializer_list<T> const &items) : Tree() {
    for (auto it = items.begin(); it != items.end(); it++) {
        this->insert(*it);
    }
}

template <class T>
Tree<T>::Tree(typename Tree<T>::tree_ref other) {
    this->count = other.count;
    this->copy(other.root);
}

template <class T>
Tree<T>::Tree(typename Tree<T>::tree &&other) {
    this->move(other);
}

template <class T>
typename Tree<T>::tree_ref Tree<T>::operator=(typename Tree<T>::tree_ref other) {
    this->count = other.count;
    this->copy(other.root);
    return *this;
}

template <class T>
typename Tree<T>::tree_ref Tree<T>::operator=(typename Tree<T>::tree &&other) {
    this->move(other);
    return *this;
}

template<class T>
void Tree<T>::move(Tree::tree &other) {
    if (this != &other) {
        this->count = other.count;
        this->root = other.root;
        other.count = 0;
        other.root = nullptr;
    }
}

template <class T>
Tree<T>::~Tree(){
    this->clear();
    this->count = 0;
    this->root = nullptr;
}

template <class T>
typename Tree<T>::node_point Tree<T>::init_node(T value) {
    auto temp = new Node<T>(value);
    return temp;
}

template<class T>
unsigned Tree<T>::getCount() const noexcept {
    return this->count;
}

template<class T>
typename Tree<T>::node_point Tree<T>::getRoot() const noexcept {
    return this->root;
}

template<class T>
void Tree<T>::setCount(unsigned int value) {
    this->count = value;
}

template<class T>
void Tree<T>::setRoot(Tree::node_point ptr) {
    if (this->root != nullptr) {
        this->clear();
    }
    this->root = ptr;
}

template <class T>
void Tree<T>::insert(T value) {
    if (this->root == nullptr)
        this->root = new Node<T>(value);
    else
        this->insert(value, root->getData());
}

template <class T>
void Tree<T>::insert(T value, T srch) {
    if (this->search(srch)) {
        p_insert(value, srch, root);
    }
}

template <class T>
void Tree<T>::p_insert(T value, T srch, typename Tree<T>::node_point local) {
    bool flag = false;
    if (srch == local->getData()) {
        auto node = new Node<T>(value);
        if (local->getSon() == nullptr) {
            local->setSon(node);
            node->setParent(local);
        } else {
            auto temp = local;
            while (temp->getBrother() != nullptr) {
                temp = temp->getBrother();
            }
            temp->setBrother(node);
        }
        flag = true;
    }
    if (!flag && local->getBrother() != nullptr) {
        this->p_insert(value, srch, local->getBrother());
    }
    if (!flag && local->getSon() != nullptr) {
        this->p_insert(value, srch, local->getSon());
    }
}

template <class T>
bool Tree<T>::search(T value) {
    return this->root == nullptr ? false : this->p_search(value, this->root);
}

template <class T>
bool Tree<T>::p_search(T value, typename Tree<T>::node_point local) {
    bool flag = false;
    if (value == local->getData()) {
        flag = true;
    }
    if (!flag && local->getBrother() != nullptr) {
        flag += this->p_search(value, local->getBrother());
    }
    if (!flag && local->getSon() != nullptr) {
        flag += this->p_search(value, local->getSon());
    }
    return flag;
}

template <class T>
void Tree<T>::erase(T value) {
    if (this->root != nullptr) {
        this->p_erase(value, root);
    }
}

template <class T>
void Tree<T>::p_erase(T value, typename Tree<T>::node_point local) {
    bool flag = false;
    if (value == local->getData()) {
        this->p_clear(local);
        flag = true;
    }
    if (!flag && local->getBrother() != nullptr) {
        this->p_erase(value, local->getBrother());
    }
    if (!flag && local->getSon() != nullptr) {
        this->p_erase(value, local->getSon());
    }
}


template <class T>
void Tree<T>::clear() {
    if (this->root != nullptr) {
        this->p_clear(this->root);
    }
}

template <class T>
void Tree<T>::p_clear(typename Tree<T>::node_point local) {
    if (local->getBrother() != nullptr) {
        this->p_clear(local->getBrother());
    }
    if (local->getSon() != nullptr) {
        this->p_clear(local->getSon());
    }
    delete local;
}

template <class T>
void Tree<T>::print() const {
    if (this->root != nullptr) {
        this-p_print(this->root);
    }
}

// Need make user-friendly std::cout
template <class T>
void Tree<T>::p_print(typename Tree<T>::node_point local) const {
    if (local->getBrother() != nullptr) {
        this->p_print(local->getBrother());
    }
    if (local->getSon() != nullptr) {
        this->p_print(local->getSon());
    }
}

template<class T>
int Tree<T>::counting(Tree::node_point local) {
    int i = 0;
    if (local->getBrother() != nullptr) {
        i++;
        this->counting(local->getBrother());
    }
    if (local->getSon() != nullptr) {
        i++;
        this->counting(local->getSon());
    }
    return i;
}

template<class T>
void Tree<T>::copy(Tree::node_point local) {
    this->insert(local->getData());
    if (local->getBrother() != nullptr)
        this->copy(local->getBrother());
    if (local->getSon() != nullptr)
        this->copy(local->getSon());
}
