#include "Info.h"

std::string random_string() {
    std::string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 22);
}

unsigned random_num() {
    unsigned num = std::random_device().max();
    while (num > 10) {
        num /= 10;
    }
    return num;
}

template <class T>
Info<T>::Info() {
    this->methods = random_num();
    this->properties = random_num();
    std::cout << typeid(T).name() << std::endl;
    if (typeid(T).name() == "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE") {
        this->name = std::move(random_string());
    }
}

template <class T>
Info<T>::Info(unsigned  met, unsigned pro, T n) {
    this->methods = met;
    this->properties = pro;
    this->name = n;
}

template <class T>
Info<T>::Info(T n) : Info() {
    this->name = std::move(n);
}

template <class T>
Info<T>::Info(typename Info<T>::info_ref other) {
    this->methods = other.methods;
    this->properties = other.properties;
    this->name = other.name;
}

template <class T>
Info<T>::Info(typename Info<T>::info &&other) {
    if (this != &other) {
        this->methods = other.methods;
        this->properties = other.properties;
        this->name = std::move(other.name);
        other.methods = other.properties = 0;
    }
}

template <class T>
typename Info<T>::info_ref Info<T>::operator=(typename Info<T>::info_ref other) {
    this->methods = other.methods;
    this->properties = other.properties;
    this->name = other.name;
    return *this;
}

template <class T>
typename Info<T>::info_ref Info<T>::operator=(typename Info<T>::info &&other) {
    if (this != &other) {
        this->methods = other.methods;
        this->properties = other.properties;
        this->name = std::move(other.name);
        other.methods = other.properties = 0;
    }
    return *this;
}

template <class T>
unsigned Info<T>::getMethods()  const noexcept {
    return this->methods;
}

template <class T>
unsigned Info<T>::getProperties()  const noexcept {
    return this->properties;
}

template <class T>
T Info<T>::getName()  const noexcept {
    return this->name;
}

template <class T>
void Info<T>::setMethods(unsigned int value) {
    this->methods = value;
}

template <class T>
void Info<T>::setProperties(unsigned int value) {
    this->properties = value;
}

template <class T>
void Info<T>::setName(T value) {
    this->name = std::move(value);
}

template <class T>
bool Info<T>::operator==(typename Info<T>::info_ref other) const {
    return this->name == other.name;
}

template <class T>
bool Info<T>::operator!=(typename Info<T>::info_ref other) const {
    return this->name != other.name;
}
