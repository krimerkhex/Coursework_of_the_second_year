//
// Created by ____krimer____ on 29.03.2023.
//

#ifndef CURSACH_INFO_H
#define CURSACH_INFO_H

#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <typeinfo>

/**
 * This is a stored class that stores the necessary information.
 * @public Info() - It's constructor, what fulling class properties by random values
 * @public Info(unsigned  met, unsigned pro, std::string n) - It's constructor, what fulling class properties by incoming values
 * @param methods (type unsigned) - count of methods
 * @param properties (type unsigned) - count of properties
 * @param name (type std::string) - name of class
 * That class on @public have only getters, setters
 */

template <class T>
class Info {
    public:
        using info = Info;
        using info_ref = Info &;
        using info_point = Info *;

        Info();
        Info(T n);
        Info(unsigned  met, unsigned pro, T n);
        Info(info_ref other);
        Info(info &&other);
        info_ref operator=(info_ref other);
        info_ref operator=(info &&other);
        ~Info() = default;

        bool operator==(info_ref other) const;
        bool operator!=(info_ref other) const;

        // Accessor (or Getter)
        unsigned getMethods() const noexcept;
        unsigned getProperties() const noexcept;
        T getName() const noexcept;

        // Mutator (or Setter)
        void setMethods(unsigned value);
        void setProperties(unsigned value);
        void setName(T value);

    private:
        unsigned methods;
        unsigned properties;
        T name;
};

#include "Info.tpp"

#endif //CURSACH_INFO_H
