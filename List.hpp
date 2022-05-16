#pragma once
#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T> *p;
    Node(T data, Node<T>* p = nullptr){
        this->data = data;
        this->p = p;
    }
    ~Node(){
        delete data;
    }
};


template <typename T>
class List{
protected:
    Node<T> *head = nullptr;
    int isize = 0;
public:
    List() = default;

    List(const T &data){
        head->push_back(data);
    }

    List(const List<T> &other){
        Node<T> *it = other->head;
        while (it != nullptr){
            this->push_back(it->data);
            it = it->p;
        }
    }

    List<T>& operator=(const List<T>& other){
        this->clear();
        Node<T> *it = other->head;
        while (it != nullptr)
        {
            this->push_back(it->data);
            it = it->p;
        }
        return *this;
    }

    List<T>& operator = (List<T> &&other){
        if(this != &other){
            delete[] this->head;

            isize = other.isize;
            head = other.head;
            other.array = nullptr;
            other.isize = 0;
        }
    
        return *this;
    }

    List(List<T>&& other){
        isize = other.isize;
        head = other.head;
        other.head = nullptr;
        other.isize = 0;
    }

    virtual ~List(){
        clear();
    }

    virtual void pop_front(){
        Node<T> *temp = head;
        head = head->p;
        delete temp;
        isize--;
    }
    
    void clear(){
        while (isize){
            pop_front();
        }
    }

    Node<T>* GetHead() const {
        return head;
    }

    T* GetData() const{
        return head->data;
    }

    void GoAhead(){
        head = head->p;
    }

    int GetSize() const{
        return isize;
    }

    T& operator[](int index){
        Node<T>* it = head;
        for(int i = 0; i < index; i++){
            it = it->p;
        }
        return it->data;
    }

    const T& operator[](int index) const{
        Node<T>* it = head;
        for(int i = 0; i < index; i++){
            it = it->p;
        }
        return it->data;
    }

    bool find(const T key) const{
        Node<T> *temp = head;

        while (temp != nullptr){
            if (temp->data == key){
                return true;
            }
            temp = temp->p;
        }
        return false;
    }

    virtual void push_back(const T &data){
        // cout << *data;
        if (head == nullptr){
            head = new Node<T>(data);
        } else {
            Node<T> *current = this->head;
            while (current->p != nullptr)
            {
                current = current->p;
            }
            current->p = new Node<T>(data);
        }
        isize++;
    }

    virtual void push(T data){
        // cout << "1212\n";
        if (head == nullptr){
            head = new Node<T>(data);
        } else {
            Node<T> *current = this->head;
            while (current->p != nullptr)
            {
                current = current->p;
            }
            current->p = new Node<T>(data);
        }
        // cout << *data;
        isize++;
    }

    virtual void Print(){
        while (head != nullptr){
            cout << head->data << " ";
            head = head->p;
        }
        cout << endl;
    }

    List<T> *GetUnicElements(List<T> *other){
        List<T> *result = new List<T>();
        while (head != nullptr){
            char temp = head->data;
            if (!other->find(temp) && !result->find(temp)){
                result->push_back(temp);
            }
            head = head->p;
        }
        return result;
    }

};
