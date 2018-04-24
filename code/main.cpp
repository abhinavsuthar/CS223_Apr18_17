#include "Student.cpp"
#include "Admin.cpp"


void main_handler() {

    int x;
    cout << "Press 1 for student" << endl;
    cout << "Press 2 for admin" << endl;
    cout << "Press 3 for exit" << endl;

    while (!(cin >> x)) {
        cout << "Integer wanted" << endl;
        cin.clear();
        cin.ignore();
    }

    if (x == 1)new Student();
    else if (x == 2)new Admin();

    if (x != 3) main_handler();

}

int main() {

    //std::cout << "Hello, World!" << std::endl;

    main_handler();

    dataClass->saveAllDataToFile();

    return 0;
}



