#include <iostream>
#include <exception>

#include "Objects.hpp"
#include "Array.hpp"
#include "../laba10/vector.hpp"

    Array::Array(){
        arr.setsize(0);
    }

    Array::Array(int isize){
        arr.setsize(isize);
    }

    Array::Array(const Array& other){
        arr = other.arr;
    }

    Array::Array(Array&& other){
        arr = std::move(other.arr);
    }

    Array& Array::operator=(Array&& other){
        arr = std::move(other.arr);
        return *this;
    }

    const Object& Array::operator[](unsigned int index) const {
        if(index >= this->arr.getsize()){
            throw invalid_argument("Array index out of bounds!");
        }
        return *arr[index];
    }

    Object& Array::operator[](unsigned int index){
        if(index >= this->arr.getsize()){
            throw invalid_argument("Array index out of bounds!");
        }
        return *arr[index];
    }

    void Array::Insert(Object* other, int index){
        arr[index] = other;
    }

    Array& Array::operator = (const Array &other){
        if(this != &other){
            arr = other.arr;
        }
        return *this;
    }



    void Array::remove(char* name){
        int i = 0;
        for( ; i < arr.getsize(); i++){
            if(arr[i]->GetName() == name){
                break;
            }
        }

        Array newArray = *this;
        arr.clean();
        arr.setsize(newArray.arr.getsize() - 1);
        for(int i_n = 0; i_n < i; i_n++){
            arr[i_n] = newArray.arr[i_n];
        }
        for(int i_n = i + 1; i_n < newArray.arr.getsize(); i_n++){
            arr[i_n - 1] = newArray.arr[i_n];
        }
    }

    void Array::Print() const {
        for(int i = 0; i < arr.getsize(); i++){
            if(arr[i] == nullptr){
                return;
            }
            arr[i]->Print();
        }
    }

    ostream& operator << (ostream& str, const Array& prototipe){
        prototipe.Print();
        return str;
    }


