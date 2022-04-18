#pragma once
#include "Objects.hpp"
#include "../laba10/vector.hpp"

class Array{
private:
    Vector<Object*> arr; //TODO: use 2.1
public:
    Array();
    Array(int isize);
    Array(const Array& other);
    Array(Array&& other);
    
    Array& operator = (const Array &other);
    Array& operator=(Array&& other);

    void remove(char* name);

    const Object& operator[](unsigned int index) const;
    Object& operator[](unsigned int index);

    friend ostream& operator << (ostream &str, const Array& prototipe);

    void Print() const;

    void Insert(Object* other, int index);
};