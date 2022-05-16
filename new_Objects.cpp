#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#include "Objects.hpp"

using namespace std;

    Object::Object(){
        ClassType = "Object\0";
        name = new char[256]{};
    }

    Object::Object(char* name, int price, int units_left){
        ClassType = "Object\0";

        this->name = new char[256];
        for(int i = 0; i < strlen(name); i++){
            this->name[i] = name[i];
        }
        this->name[strlen(name)] = '\0';

        this->price = price;
        this->units_left = units_left;
    }

    Object::Object(const Object& other){
        this->ClassType = other.ClassType;
        SetName(other.name);
        price = other.price;
        units_left = other.units_left;
    }

    Object& Object::operator = (const Object& other){
        if(name == nullptr){
            delete[] name;
            name = new char[256];
        }
        this->ClassType = other.ClassType;
        SetName(other.name);
        price = other.price;
        units_left = other.units_left;
        return *this;
    }

    Object::~Object(){
        delete[] name;
    }

    ostream& operator << (ostream &str, const Object& prototipe){
        prototipe.Print();
        return str;
    }

    void Object::SetName(char* name){
        for(int i = 0; i < strlen(name); i++){
            this->name[i] = name[i];
        }
        this->name[strlen(name)] = '\0';
    }

    char* Object::GetName() const{
        return name;
    }

    void Object::SetPrice(int price){
        this->price = price;
    }

    int Object::GetPrice() const{
        return price;
    }

    void Object::SetUnits_left(int units_left){
        this->units_left = units_left;
    }

    int Object::GetUnits_left() const{
        return units_left;
    }

    void Object::Print() const{
        cout << GetClassType() << endl;
        cout << "Numbers of " << name << " each for " << price << "$ left " << units_left << endl;
    }

    string Object::GetInfo() const{
        return string(name) + " " + to_string(price) + " " + to_string(units_left);
    }

    string Object::GetClassType() const{
        return this->ClassType;
    }

    Object::Object(ifstream& stream){
        ClassType = "Object\0";
        stream >> name >> price >> units_left;
    }



    Appliances::Appliances() : Object(){
        ClassType = "Appliances\0";
        manufacturer = new char[256];
    }

    Appliances::Appliances(char* name, int price, int units_left, char* manufacturer) : Object(name, price, units_left){
        ClassType = "Appliances\0";

        this->manufacturer = new char[256];
        for(int i = 0; i < strlen(manufacturer); i++){
            this->manufacturer[i] = manufacturer[i];
        }
        this->manufacturer[strlen(manufacturer)] = '\0';
    }

    Appliances::Appliances(const Appliances& other){
        this->ClassType = other.ClassType;
        SetName(other.name);
        price = other.price;
        units_left = other.units_left;
        SetManufacturer(other.manufacturer);
    }

    Appliances& Appliances::operator = (const Appliances& other){
        if(name == nullptr){
            delete[] name;
            name = new char[256];
        }
        if(manufacturer = nullptr){
            delete[] manufacturer;
            manufacturer = new char[256];
        }
        this->ClassType = other.ClassType;
        SetName(other.name);
        price = other.price;
        units_left = other.units_left;
        SetManufacturer(other.manufacturer);
        return *this;
    }

    Appliances::~Appliances(){
        delete[] manufacturer;
    }

    void Appliances::Print() const{
        cout << GetClassType() << endl;
        cout << "Numbers of " << name << " each for " << price << "$ made in " << manufacturer << " left " << units_left << endl;
    }

    string Appliances::GetInfo() const{
        return string(name) + " " + to_string(price) + " " + to_string(units_left) + " " + string(manufacturer);
    }

    void Appliances::SetManufacturer(char* manufacturer){
        for(int i = 0; i < strlen(manufacturer); i++){
            this->manufacturer[i] = manufacturer[i];
        }
        this->manufacturer[strlen(manufacturer)] = '\0';
    }

    char* Appliances::GetManufacturer() const{
        return manufacturer;
    }



    Cloth::Cloth() : Object(){
        ClassType = "Cloth\0";
        material = new char[256];
        size = 0;
    }

    Cloth::Cloth(char* name, int price, int units_left, char* material, int size) : Object(name, price, units_left){
        ClassType = "Cloth\0";

        this->material = new char[256];
        for(int i = 0; i < strlen(material); i++){
            this->material[i] = material[i];
        }
        this->material[strlen(material)];

        this->size = size;
    }

    Cloth::Cloth(const Cloth& other){
        this->ClassType = other.ClassType;
        SetName(other.name);
        price = other.price;
        units_left = other.units_left;
        this->size = other.size;
        SetMaterial(other.material);
    }

    Cloth& Cloth::operator=(const Cloth& other){
        if(name == nullptr){
            delete[] name;
            name = new char[256];
        }
        if(material == nullptr){
            delete[] material;
            material = new char[256];
        }
        this->ClassType = other.ClassType;
        SetName(other.name);
        price = other.price;
        units_left = other.units_left;
        this->size = other.size;
        SetMaterial(other.material);
        return *this;
    }


    Cloth::~Cloth(){
        delete[] material;
    }

    void Cloth::Print() const{
        cout << GetClassType() << endl;
        cout << "Numbers of " << name << " each for " << price << "$ made from " << material << " size " << size << " left " << units_left << endl;
    }

    string Cloth::GetInfo() const {
        return string(name) + " " + to_string(price) + " " + to_string(units_left) + " " + string(material) + " " + to_string(size);
    }

    void Cloth::SetMaterial(char* material){
        this->material = new char[256];
        for(int i = 0; i < strlen(material); i++){
            this->material[i] = material[i];
        }
        this->material[strlen(material)] = '\0';
    }

    char* Cloth::GetMaterial() const{
        return material;
    }

    void Cloth::SetSize(int size){
        this->size = size;
    }

    int Cloth::GetSize() const{
        return size;
    }

    Cloth::Cloth(ifstream& stream) : Object(stream){
        ClassType = "Cloth\0";
        stream >> material >> size;
    }



    Outwear::Outwear() : Cloth(){
        ClassType = "Outwear\0";
        season = new char[256];
    }

    Outwear::Outwear(char* name, int price, int units_left, char* material, int size, char* season) : Cloth(name, price, units_left, material, size){
        ClassType = "Outwear\0";
        this->season = new char[256];
        for(int i = 0; i < strlen(season); i++){
            this->season[i] = season[i];
        }
        this->season[strlen(season)] = '\0';
    }

    Outwear::~Outwear(){
        delete[] season;
    }

    Outwear::Outwear(const Outwear& other){
        this->ClassType = other.ClassType;
        SetName(other.name);
        price = other.price;
        units_left = other.units_left;
        this->size = other.size;
        SetMaterial(other.material);
        SetSeason(other.season);
    }

    Outwear& Outwear::operator=(const Outwear& other){
        if(name == nullptr){
            delete[] name;
            name = new char[256];
        }
        if(material == nullptr){
            delete[] material;
            material = new char[256];
        }
        if(season == nullptr){
            delete[] season;
            season   = new char[256];
        }
        this->ClassType = other.ClassType;
        SetName(other.name);
        price = other.price;
        units_left = other.units_left;
        this->size = other.size;
        SetMaterial(other.material);
        SetSeason(other.season);
        return *this;
    }

    void Outwear::Print() const{
        cout << GetClassType() << endl;
        cout << "Numbers of " << name << " each for " << price << "$ made from " << material << " size " << size << " on " << season << " season left " << units_left << endl;
    }

    string Outwear::GetInfo() const{
        return string(name) + " " + to_string(price) + " " + to_string(units_left) + " " + string(material) + " " + to_string(size) + " " + string(season);
    }

    void Outwear::SetSeason(char* season){
        this->season = new char[256];
        for(int i = 0; i < strlen(season); i++){
            this->season[i] = season[i];
        }
        this->season[strlen(season)] = '\0';
    }

    char* Outwear::GetSeason() const{
        return season;
    }

    Outwear::Outwear(ifstream& stream) : Cloth(stream){
        ClassType = "Outwear\0";
        stream >> season;
    }



    Sportswear::Sportswear() : Cloth(){
        ClassType = "Sportswear\0";
    }

    Sportswear::Sportswear(char* name, int price, int units_left, char* material, int size) : Cloth(name, price, units_left, material, size) {
        ClassType = "Sportswear\0";
    }

    Sportswear::Sportswear(ifstream& stream) : Cloth(stream){
        ClassType = "Sportswear\0";
    }



    Underwear::Underwear() : Cloth(){
        ClassType = "Underwear\0";
    }

    Underwear::Underwear(char* name, int price, int units_left, char* material, int size) : Cloth(name, price, units_left, material, size) {
        ClassType = "Underwear\0";
    }

    Underwear::Underwear(ifstream& stream) : Cloth(stream){
        ClassType = "Underwear\0";
    }
