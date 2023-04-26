//
// Created by ____krimer____ on 29.03.2023.
//

#ifndef CURSACH_TREE_H
#define CURSACH_TREE_H
#include "Node.h"

/**
 * This class has a non-binary tree representation based on binary. It actually have:
 * @tparam T - It's maybe different types.
 * @param count (type unsigned) - Count of Nodes in Tree.
 * @param *root (type class Node) - Pointer for header Node.
 * @public : insert(T value) - Adding element into tree.
 * @public : insert(T value, T srch) - Adding element into tree after Node with data == srch.
 * @private : p_insert(T value, node_point local) - Recursive traversal algorithm
 * @public : search(T value) - Search for element in tree.
 * @private : p_search(T value, node_point local) - Recursive traversal algorithm
 * @public : erase(T value) - Remove element from tree.
 * @private : p_erase(T value, node_point local) - Recursive traversal algorithm
 * @public : clear() - After that function *root = nullptr & no leaks.
 * @private : p_clear(node_point local) - Recursive traversal algorithm
 * @public : print() - Show all elements in tree with std::cout.
 * @private : p_print(node_point local) - Recursive traversal algorithm
 * @private : init_node(T value) - Initialization for nodes with std::new.
 */
template <class T>
class Tree {
    friend class Node<T>;
    public:
        using type = T();
        using point = T *;
        using node_point = Node<T> *;
        using tree_point = Tree<T> *;
        using node_ref = Node<T> &;
        using tree_ref = Tree<T> &;
        using tree = Tree<T>;
        using ref = T &;

        // Constructors / Distructors
        Tree();
        Tree(node_point point);
        Tree(std::initializer_list<T> const &items);
        Tree(tree_ref other);
        Tree(tree &&other);
        tree_ref operator=(tree_ref other);
        tree_ref operator=(tree &&other);
        ~Tree();

        void insert(T value);
        void insert(T value, T srch);
        bool search(T value);
        void erase(T value);

        void clear();
        void print() const;

        // Accessor (or Getter)
        unsigned getCount() const noexcept;
        node_point getRoot() const noexcept;

        // Mutator (or Setter)
        void setCount(unsigned value);
        void setRoot(node_point ptr);

    private:
        unsigned count;
        node_point root;
        node_point init_node(T value);

        int counting(node_point local);
        void copy(node_point local);
        void move(tree &other);
        void p_insert(T value, T srch, node_point local);
        bool p_search(T value, node_point local);
        void p_erase(T value, node_point local);
        void p_clear(node_point local);
        void p_print(node_point local) const;
};

#include "Tree.tpp"

#endif //CURSACH_TREE_H
