//
// Created by Abhinav_Suthar on 24-04-2018.
//

#include "Admin.h"
using namespace std;

void Admin::handler(){

    int xx;
    cout << "Press 1 for get view requests" << endl;
    cout << "Press 2 for get all empty rooms" << endl;
    cout << "Press 3 for accept request" << endl;
    cout << "Press 4 for get student details" << endl;
    cout << "Press 5 for exit" << endl;

    while (!(cin >> xx)) {
        cout << "Integer wanted" << endl;
        cin.clear();
        cin.ignore();
    }

    if (xx == 1) viewRequest();
    else if (xx == 2) getEmptyRooms();
    else if (xx == 3) acceptRequest();
    else if (xx == 4) getStudentDetails();
    else if (xx != 5) {
        cout << "Enter a valid command\n";
        handler();
    }
}

void Admin::login() {

    string id, pass;//for tests only

    cout << "Enter your id" << endl;
    cin >> id;
    cout << "Enter your password i.e, phone_no" << endl;
    cin >> pass;

    if (id == "abhinav" && pass == "suthar") handler();
    else {
        cout << "Wrong credentials, try again :-(" << endl;
        login();
    }
}

void Admin::getStudentDetails() {
    Student_ *sss = dataClass->getStudent();

    string id;
    cout << "Enter student id ";
    cin >> id;

    bool exist = false;
    for (int i = 0; i < 30; i++) {
        if (sss[i].student_id == id) {
            exist = true;

            cout << "Name: " + sss[i].first_name + " " + sss[i].last_name << endl;
            cout << "Student Id: " + sss[i].student_id << endl;
            cout << "Student Room No: " + sss[i].room.hostel + " " + to_string(sss[i].room.room_number) << endl;
            cout << "Contact No: " + sss[i].cell_no << endl;

        }
    }
    if (!exist) cout << "No such student id exist" << endl;

    handler();
}

void Admin::viewRequest() {
    Request_ *req = dataClass->getRequest();

    for (int i = 0; i < request_no; i++) {
        cout << "Request of student " + req[i].student_R.student_id + " for room no " +
                to_string(req[i].room_R.room_number) + " of type " + req[i].type + " is " + req[i].status << endl;
    }
    if (request_no == 0) cout << "No request placed" << endl;

    handler();
}

void Admin::acceptRequest() {
    string student_id, status;
    int room_no, status_int;
    cout << "Enter student id ";
    cin >> student_id;
    cout << "Enter room no ";
    while (!(cin >> room_no)) {
        cout << "Integer wanted" << endl;
        cin.clear();
        cin.ignore();
    }

    status_:
    cout << "Enter 1 for grant permission or 0 for deny request";
    while (!(cin >> status_int)) {
        cout << "Integer wanted" << endl;
        cin.clear();
        cin.ignore();
    }
    if (status_int == 0) status = "Permission-Denied";
    else if (status_int == 1) status = "Permission_Granted";
    else {
        cout << "Enter valid option";
        goto status_;
    }


    Request_ *req = dataClass->getRequest();

    bool found = false;
    for (int i = 0; i < request_no; i++) {
        if (req[i].student_R.student_id == student_id && req[i].room_R.room_number == room_no) {
            req[i].status = "Permission-Granted";
            if (status_int == 1) changeRoomStatus(room_no, "Occupied");
            found = true;
        }
    }
    if (found) cout << "Request status changed" << endl;
    else cout << "Something bad happened try again or request doesn't exist" << endl;
    handler();
}

void Admin::changeRoomStatus(int room_no, const string &status_) {

    Room_ *rrr = dataClass->getRooms();

    for (int i = 0; i < 30; ++i) {
        if (rrr[i].room_number == room_no) {
            rrr[i].status = status_;
        }
    }
}

void Admin::getEmptyRooms() {

    Room_ *rr = dataClass->getRooms();

    int j = 0;
    for (int i = 0; i < 30; ++i) {
        if (rr[i].status == "free") {
            cout << "Status of room " + to_string(rr[i].room_number) + " is " + rr[i].status << endl;
        } else j++;
    }
    if (j == 30)cout << "No empty room found" << endl;

    handler();
}

