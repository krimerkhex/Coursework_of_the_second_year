//
// Created by ____krimer____ on 29.03.2023.
//

#ifndef CURSACH_NODE_H
#define CURSACH_NODE_H

#include "Info.h"

/**
 * This class implements a tree structure and stores data in each of its objects.
 * @tparam T - It's maybe different types.
 * @param *data (type class Info) - pointer for stored information
 * @param *parent (type class Node) - pointer for node what upper then that
 * @param *brother (type class Node) - pointer for node what from the right side then that
 * @param *son (type class Node) - pointer for node what downer then that
 * @param *back (type class Node) - pointer for node what from the left side then that
 * That class on @public have only getters, setters and
 * @public clear() - function for clearing all this Node and use std::delete for field data
 */
template <class T>
class Node {
    public:
        using type = T();
        using ref = T &;
        using point = T *;
        using node = Node<T>;
        using node_ref = Node<T> &;
        using node_point = Node<T> *;
        using const_node_point = const Node<T> *;

        Node();
        Node(T value = T());
        Node(node_ref other);
        Node(node &&other);
        node_ref operator=(node_ref other);
        node_ref operator=(node &&other);
        ~Node();

        // Accessor (or Getter)
        Info<T> *getData() const noexcept;
        const_node_point getParent() const noexcept;
        const_node_point getBrother() const noexcept;
        const_node_point getBack() const noexcept;
        const_node_point getSon() const noexcept;

        node_point getParent() noexcept;
        node_point getBrother() noexcept;
        node_point getBack() noexcept;
        node_point getSon() noexcept;

        // Mutator (or Setter)
        void setData(point ptr);
        void setParent(node_point ptr);
        void setBrother(node_point ptr);
        void setBack(node_point ptr);
        void setSon(node_point ptr);

        // Technical
        void clear();
    private:
        Info<T> *data;
        node_point parent;
        node_point brother;
        node_point back;
        node_point son;
        void copy(node_ref other);
};

#include "Node.tpp"

#endif //CURSACH_NODE_H