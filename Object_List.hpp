#pragma once

#include <iostream>
#include <cstring>
#include <string.h>

#include "./../laba10/List.hpp"
#include "Objects.hpp"

template <typename T>
class Object_List {
private:
    List<Object*> _list;
public:
    Object_List() = default;

    Object_List(Object* it){
        _list.push_back(it);
    }

    Object_List(Object_List<T>* other){
        for(int i = 0; i < other->size(); i++){
            _list.push(other->_list[i]->copy());
        }
    }

    Object_List(const Object_List<T>&& other){
        _list = std::move(other._list);
    }

    Object_List<T>& operator=(const Object_List<T>& other){
        if(_list.GetSize() != 0){
            _list.clear();
        }
        for(int i = 0; i < _list.GetSize(); i++){
            _list.push_back(other._list.head->data);
        }
        return *this;
    }

    Object_List<T>& operator=(const Object_List<T>&& other){
        _list = std::move(other._list);
        return *this;
    }

    void pop_front(){
        _list.pop_front();
    }

    void push_back(Object* it){
        _list.push_back(it);
    }

    void Print(){
        for(int i = 0; i < _list.GetSize(); i++){
            _list[i]->Print();
        }
    }

    void RemoveObject(Object* object){
        int pos = 0;
        for(int i = 0; i < _list.GetSize(); i++){
            if(object == _list[i]){
                pos = i;
                break;
            }
        }
        List<Object*> temp = _list;
        _list.clear();
        for(int i = 0; i < temp.GetSize(); i++){
            if(i == pos){
                continue;
            }
            _list.push_back(temp[i]);
        }
    }

    void clear(){
        while(_list.GetSize()){
            pop_front();
        }
    }

    size_t size() const {
        return _list.GetSize();
    }
};
