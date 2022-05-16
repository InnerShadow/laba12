#include <iostream>

#include "Objects.hpp"
#include "Object_List.hpp"

int main(){

    Object_List<Object*> list;
    Sportswear* sp = new Sportswear("glowe", 300, 666, "latex", 43);
    Underwear* ud = new Underwear("Peanse", 12, 300, "flax", 42);
    Outwear* out = new Outwear("Outfit", 600, 1300, "wool", 45, "WEWE");
    list.push_back(sp);
    list.push_back(ud);
    list.push_back(out);

    list.Print();
    cout << "\n\n";

    Object_List<Object*> b(list);
    list.clear();
    b.Print();


    return 0;
}


int fff (){

    string str;
    getline(cin, str);
    cin.het();
    string str2;
    for(int i = 0; i < str.size(); i++){
        str.push_back(str.at(i));
        if(str.at(i) == 'z' || str.at(i) == 'Z'){
            str.push_back('!');
        }
    }
}

int foo(){
    int num = 0;
    cin >> num;
    string str;
    do{
        int resualt = num % 16;
        num /= 16;
        switch(resualt){

            case 10 : {
                str.push_back('A');
            }
            case 11 : {
                str.push_back('B');
            }
            case 12 : {
                str.push_back('C');
            }
            case 13 : {
                str.push_back('D');
            }
            case 14 : {
                str.push_back('E');
            }
            case 15 : {
                str.push_back('F');
            }
            defualt : {
                str.push_back(char('0') + resualt);
            }
        }
        reverse(str.begin(), str.end());
        cout << str;
    }while(num > 0)
}