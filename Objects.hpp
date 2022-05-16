#pragma once

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// выпіліть insert, сделать конструктор копирования, оператор копирваняи для char*
// ToDO:: Object(ifstream& stream);

class Object
{
protected:
    char *name;
    int price = 0;
    int units_left = 0;
    string ClassType;

    Object();
    Object(char* name, int price, int units_left);

    Object(ifstream &stream);

public:
    Object(const Object &other);
    Object &operator=(const Object &other);

    virtual ~Object();

    virtual Object* copy(){
        return new Object(*this);
    }

    virtual void Print() const;
    virtual string GetInfo() const;

    friend ostream &operator<<(ostream &str, const Object &prototipe);
    string GetClassType() const;

    void SetName(char *name);
    char *GetName() const;

    void SetPrice(int price);
    int GetPrice() const;

    void SetUnits_left(int units_left);
    int GetUnits_left() const;
};

class Appliances : public Object
{
protected:
    char *manufacturer;

public:
    Appliances();
    Appliances(char *name, int price, int units_left, char *manufacturer);
    ~Appliances() override;

    Appliances(const Appliances &other);
    Appliances &operator=(const Appliances &other);

    void Print() const override;
    string GetInfo() const override;

    void SetManufacturer(char *manufacturer);
    char *GetManufacturer() const;
};

// Cloth
class Cloth : public Object
{
protected:
    char *material;
    int size;

public:
    Cloth();
    Cloth(char *name, int price, int units_left, char *material, int size);
    ~Cloth() override;
    Cloth(ifstream &stream);

    Object* copy() override{
        return new Cloth(*this);
    }

    Cloth(const Cloth &other);
    Cloth &operator=(const Cloth &other);

    void Print() const override;
    virtual string GetInfo() const;

    void SetMaterial(char *material);
    char *GetMaterial() const;

    void SetSize(int size);
    int GetSize() const;
};

// Outwear
class Outwear : public Cloth
{
protected:
    char *season;

public:
    Outwear();
    Outwear(char *name, int price, int units_left, char *material, int size, char *season);
    ~Outwear() override;

    Object* copy() override{
        return new Outwear(*this);
    }

    Outwear(ifstream &stream);

    Outwear(const Outwear &other);
    Outwear& operator=(const Outwear &other);

    void Print() const override;
    string GetInfo() const override;

    void SetSeason(char *season);
    char *GetSeason() const;
};

class Sportswear : public Cloth
{
public:
    Sportswear();
    Sportswear(char *name, int price, int units_left, char *material, int size);
    Sportswear(ifstream& stream);

    Object* copy() override{
        return new Sportswear(*this);
    }
};

// Underwear
class Underwear : public Cloth
{
public:
    Underwear();
    Underwear(char *name, int price, int units_left, char *material, int size);
    Underwear(ifstream& stream);

    Object* copy() override{
        return new Underwear(*this);
    }
};
