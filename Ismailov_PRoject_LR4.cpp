#include<iostream>
#include<map>
#include<string>
#include<functional>

using namespace std;
int A,B,C;
bool UserInput(const string& input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input); 
        if (number < 0) return false;
    }
    catch(...)
    { return false; }
    return true;
}

function<void()> EnterNumber(int& varLink, string label) {
    return [&varLink, label]() {
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!UserInput(raw_input)) {
            cout << label << " = ";
            getline(cin, raw_input);
        }
        varLink = stoi(raw_input);
    };
}


void AB_C() {
  
}
void AB__C() {
  
}
void get_A(){
   
}
void get_B(){
    
}
void get_C(){
    
}
struct MenuItem {
    string title;
    function<void()> action;
};
int main() {
    setlocale(LC_ALL,"Russian");
    map<int, MenuItem> menu = {
        {1, {"Lead A", get_A}},
        {2, {"Lead B", get_B}},
        {3, {"Lead C", get_C}},
        {4, {"(A+B)_C = ",AB_C}},
        {5, {"(A+B)/C = ",AB__C}},
    };

    int choice = 0;
    for(const auto& item : menu){
        cout<<"Task "<<item.first<<". "<<item.second.title<<endl;
    }
    cout<<"0.Exit"<<endl;
    while (true) {
        EnterNumber(choice, "Введите номер пункта: ")();
        if (choice == 0) {
            std::cout << " 2025 Ismailov Agafendi" << std::endl;
            break;
        }
        cout << endl << " ============Action===========" << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        }
        else
        {
            std::cout << "Некорректный ввод.";
        }
        std::cout << std::endl;
    }
    
    return 0;

}