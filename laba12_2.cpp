#include <iostream>

#include "Objects.hpp"
#include "Array.hpp"
#include "../laba10/vector.hpp"

using namespace std;

int main(){
    cout << "Enter number of Elements in youre arry: ";
    int isize = 0;
    cin >> isize;
    Array array(isize);
    for(int i = 0; i < isize; i++){
        cout << "Enter 2 for Appliances, 4 for Outerwear, 5 for Sportswear, 6 for Lingerie: ";
        int key = 0;
        cin >> key;
        switch(key){
            case 2: {
                cout << "Enter name of appliances: ";
                char* name = new char[256];
                cin >> name;
                cout << "Enter price: ";
                int price = 0;
                cin >> price;
                cout << "Enter units left on storage: ";
                int units_left = 0;
                cin >> units_left;
                cout << "Enter menufacture countri: ";
                char* manufacture = new char[256];
                cin >> manufacture;
                Appliances* temp = new Appliances(name, price, units_left, manufacture);
                array.Insert(temp, i);
                delete[] manufacture;
                delete[] name;
                break;
            }
            case 4: {
                cout << "Enter name of outweare: ";
                char* name = new char[256];
                cin >> name;
                cout << "Enter price: ";
                int price = 0;
                cin >> price;
                cout << "Enter units left on storage: ";
                int units_left = 0;
                cin >> units_left;
                cout << "Enter matireal of the cloath: ";
                char* matiral = new char[256];
                cin >> matiral;
                cout << "Enter size of this cloath: ";
                int size = 0;
                cin >> size;
                cout << "Enter season of this cloath: ";
                char* season = new char[256];
                cin >> season;
                Outwear* temp = new Outwear(name, price, units_left, matiral, size, season);
                array.Insert(temp, i);
                delete[] season;
                delete[] matiral;
                delete[] name;
                break;
            }
            case 5: {
                cout << "Enter name of sportsweare: ";
                char* name = new char[256];
                cin >> name;
                cout << "Enter price: ";
                int price = 0;
                cin >> price;
                cout << "Enter units left on storage: ";
                int units_left = 0;
                cin >> units_left;
                cout << "Enter matireal of the cloath: ";
                char* matiral = new char[256];
                cin >> matiral;
                cout << "Enter size of this cloath: ";
                int size = 0;
                cin >> size;
                Sportswear* temp = new Sportswear(name, price, units_left, matiral, size);
                array.Insert(temp, i);
                delete[] matiral;
                delete[] name;
                break;
            }
            case 6: {
                cout << "Enter name of lingerie: ";
                char* name = new char[256];
                cin >> name;
                cout << "Enter price: ";
                int price = 0;
                cin >> price;
                cout << "Enter units left on storage: ";
                int units_left = 0;
                cin >> units_left;
                cout << "Enter matireal of the cloath: ";
                char* matiral = new char[256];
                cin >> matiral;
                cout << "Enter size of this cloath: ";
                int size = 0;
                cin >> size;
                Underwear* temp = new Underwear(name, price, units_left, matiral, size);
                array.Insert(temp, i);
                delete[] matiral;
                delete[] name;
                break;
            }
        }
    }
    
    array.Print();
    return 0;
}