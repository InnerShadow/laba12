#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

#include "Array.hpp"

using namespace std;

class IObjectFactory{
public:
    virtual ~IObjectFactory() = default;
    virtual Object* CreateObject(ifstream& input_Data) = 0;
    virtual Object* CreateObjectKeyboard() = 0;
};

class ObjectFactorySportswear: public IObjectFactory {
public:
    ObjectFactorySportswear() = default;
    ~ObjectFactorySportswear() = default;

    Object* CreateObject(ifstream& input_Data) override {
        return new Outwear(input_Data);
    }
    
    Object* CreateNewObject(Array& arr, int i, ofstream& stream) override{
        char* name = new char[256];
        cin >> name;
        int price = 0;
        cin >> price;
        int units_left = 0;
        cin >> units_left;
        char* matiral = new char[256];
        cin >> matiral;
        int size = 0;
        cin >> size;
        auto result =  new Sportswear(name, price, units_left, matiral, size);
         delete[] name;
        delete[] matiral;
        
        return temp;
    }
};

class ObjectFactoryUnderwear: public IObjectFactory {
public:
    ObjectFactoryUnderwear() = default;
    ~ObjectFactoryUnderwear() override{};
    Object* CreateObject(ifstream& input_Data) override {
        return new Underwear(input_Data);
    }
    
    Object* CreateNewObject(Array& arr, int i, ofstream& stream) override{
        char* name = new char[256];
        cin >> name;
        int price = 0;
        cin >> price;
        int units_left = 0;
        cin >> units_left;
        char* matiral = new char[256];
        cin >> matiral;
        int size = 0;
        cin >> size;
        auto* temp = new Underwear(name, price, units_left, matiral, size);
        arr.Insert(temp, i);
        stream << temp->GetClassType();
        string str = temp->GetInfo();
        stream << str << "\n";
        delete[] name;
        delete[] matiral;
        return temp;
    }

};

class ObjectFactoryOutwear: public IObjectFactory {
public:
    ObjectFactoryOutwear() = default;
    ~ObjectFactoryOutwear() override{};
    Object* CreateObject(ifstream& input_Data) override {
        return new Outwear(input_Data);
    }

    Object* CreateNewObject(Array& arr, int i, ofstream& stream) override{
        arr[i] >>
        char* name = new char[256];
        cin >> name;
        int price = 0;
        cin >> price;
        int units_left = 0;
        cin >> units_left;
        char* matiral = new char[256];
        cin >> matiral;
        int size = 0;
        cin >> size;
        char* season = new char[256];
        cin >> season;
        auto* temp = new Outwear(name, price, units_left, matiral, size, season);
        arr.Insert(temp, i);
        stream << temp->GetClassType();
        string str = temp->GetInfo();
        stream << str << "\n";
        delete[] name;
        delete[] matiral;
        delete[] season;
        return temp;
    }
};

Array Load(std::map<std::string, IObjectFactory*> factories, int i){
    Array result(12);

    ifstream stream("./Objects.txt");
    string type;
    while(stream >> type){
        result.Insert(factories[type]->CreateObject(stream), i++);
    }
    return result;
}

void Save_data(Array& arr, std::map<std::string, IObjectFactory*> factories, int i){
    ofstream stream("./Objects.txt", ios::app);
    if(!stream){
        cout << "AAA!\n";
    }
    cout << "Enter (Sportswear), (Underwear) or (Outwear): ";
    string str;
    cin >> str;
    cin.get();
    arr.Insert(factories[str]->CreateNewObject(arr, i + 1, stream), i++);
}

int main(){
    std::map<std::string, IObjectFactory*> factories;
    factories.emplace("Sportswear", new ObjectFactorySportswear());
    factories.emplace("Underwear", new ObjectFactoryUnderwear());
    factories.emplace("Outwear", new ObjectFactoryOutwear());
    int i = 0;
    Array arr = Load(factories, i);
    arr.Print();
    Save_data(arr, factories, i);

    return 0;
}

/*
int n;
cin >>n;

for i -0 .. n
   string type
   cin type
   arr.push_back(factories[type].CreateKeyboard())

arr.writefile(....)

*/