#include <iostream>
#include "Tree/Tree.h"

int main() {
    Tree<std::string> tree;
    tree.insert("gg");
    tree.print();
    std::cout << "All fine" << std::endl;
    return 0;
}
