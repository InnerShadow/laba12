#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <ctime>
#include <exception>

using namespace std;

template<typename T>
class Vector {
protected:
    int isize;
    T* array;
public:
    Vector(){
        this->isize = 3;
        this->array = new T[isize];
        for(int i = 0; i < this->isize; i++){
            array[i] = T(0);
        }
    }

    Vector(int isize){
        this->isize = isize;
        this->array = new T[isize];
        for(int i = 0; i < this->isize; i++){
            array[i] = T(0);
        }
    }

    Vector(const Vector<T>& other){
        this->isize = other.isize;
        this->array = new T[other.isize];
        for(int i = 0; i < other.isize; i++){
            this->array[i] = other.array[i];
        }
    }

    Vector(Vector<T>&& other){
        isize = other.isize;
        array = other.array;
        other.array = nullptr;
        other.isize = 0;
    }

    ~Vector(){
        delete[] this->array;
    }

    Vector<T>& operator = (const Vector<T> &other){
        if(!this->array){
            delete this->array;
        }
        this->isize = other.isize;
       
        this->array = new T[this->isize];
        
        for(int i = 0; i < isize; i++){
            
            this->array[i] = other.array[i];
            
        }
        
        return *this;
    }

    Vector<T>& operator = (Vector<T> &&other){
        if(this != &other){
            delete[] this->array;

            isize = other.isize;
            array = other.array;
            other.array = nullptr;
            other.isize = 0;
        }
    
        return *this;
    }

    int getsize() const{
        return this->isize;
    }

    void print() const{
        for(int i = 0; i < isize; i++){
            printf("%10d", array[i]);
        }
    }

    void fillrandomly(){
        for(int i = 0; i < this->isize; i++){
            array[i] = T(rand() % 100);
        }
    }

    T& operator[](int index){
        if(index < 0 && index >= this->isize){
            throw runtime_error("Array index out of bounds!");
        }
        return array[index];
    }

    const T& operator[](int index) const {
        if(index < 0 || index >= this->isize){
            throw runtime_error("Array index out of bounds!");
        }
        return array[index];
    }

    Vector<T>& operator++ (int index){
        if(index < 0 && index >= this->isize){
            throw runtime_error("Array index out of bounds!");
        }
        this->array[index]++;
        return *this;
    }

    friend std::istream& operator >> (std::istream &str, Vector<T>& prototipe){
        str >> prototipe;
        return str;
    }

    friend std::ostream& operator << (std::ostream &str, const Vector<T>& prototipe){
        return str << prototipe;
    }
  
    Vector<T> operator + (Vector<T>& other){
        Vector<T> temp(this->isize);
        for(int i = 0; i < isize; i++){
            temp.array[i] = this->array[i] + other.array[i];
        }
        return temp;
    }

    void changeCapacity(int capacity){
        Vector<T> temp(*this);
        if(this->array){
            delete this->array;
        }
        this->isize = capacity;
        this->array = new int[this->isize];
        for(int i = 0; i < this->isize; i++){
            if(i < temp.isize){
                array[i] = temp[i];
            } else {
                array[i] = 0;
            }
        }
    }

    void printeq2(){
        for(int i = 0; i < isize; i++){
            if(array[i] == 2){
                cout << i << " ";
            }
        }
    }

    void setsize(int isize){
        this->isize = isize;
        if(array){
            delete[] array;
        }
        array = new T[this->isize];
    }

    void clean(){
        delete[] array;
    }

    T*& GetArray(){
        return array;
    }

};