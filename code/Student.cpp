//
// Created by Abhinav_Suthar on 24-04-2018.
//

#include "Student.h"
#include "StaticObjects.cpp"

using namespace std;

void Student::login() {
    string id = "B16CS001", pass = "7240505091";//for tests only

    cout << "Enter your id" << endl;
    cin >> id;
    cout << "Enter your password i.e, phone_no" << endl;
    cin >> pass;

    Student_ *ss = dataClass->getStudent();

    for (int i = 0; i < 30; i++) {

        if (ss[i].student_id == id && ss[i].cell_no == pass) {

            cout << "Login Successful" << endl;
            loggedIn = true;

            student_m = (ss[i]);
        }
    }
    cout << "Test: " << student_m.student_id << endl;
    if (loggedIn)handler();
    else cout << "Login Unsuccessful" << endl;
}

void Student::handler() {

    int xx;
    cout << "Press 1 for get room details" << endl;
    cout << "Press 2 for get all empty rooms" << endl;
    cout << "Press 3 for put request" << endl;
    cout << "Press 4 for view all request" << endl;
    cout << "Press 5 for exit" << endl;

    while (!(cin >> xx)) {
        cout << "Integer wanted" << endl;
        cin.clear();
        cin.ignore();
    }

    if (xx == 1) getRoomDetails();
    else if (xx == 2) getEmptyRooms();
    else if (xx == 3) putRequest();
    else if (xx == 4) viewMyRequest();
    else if (xx != 5) {
        cout << "Enter a valid command\n";
        handler();
    }

}

void Student::getRoomDetails() {
    int room_no;
    cout << "Enter room number you want to check status of: " << endl;
    cin >> room_no;

    Room_ *rr = dataClass->getRooms();

    int j = 0;
    for (int i = 0; i < 30; ++i) {
        if (rr->room_number == room_no) {
            cout << "Status of room " + to_string(room_no) + " is " + rr->status << endl;
        } else j++;

        *rr = *(rr + i + 1);
    }
    if (j == 30)cout << "No such room found" << endl;

    handler();
}

void Student::getEmptyRooms() {

    Room_ *rr = dataClass->getRooms();

    int j = 0;
    for (int i = 0; i < 30; ++i) {
        if (rr->status == "free") {
            cout << "Status of room " + to_string(rr->room_number) + " is " + rr->status << endl;
        } else j++;

        *rr = *(rr + i + 1);
    }
    if (j == 30)cout << "No empty room found" << endl;

    handler();
}

void Student::putRequest() {

    Request_ *req = dataClass->getRequest();

    for (int i = 0; i < req->position; ++i) {
        cout << req->position << endl;
    }
    cout << "Req No " << request_no << endl;

    int room_no;
    cout << "Enter room number" << endl;
    cin >> room_no;

    if (isRoomEmpty(room_no)) {

        auto *request_1 = new Request_();
        request_1->student_R = student_m;
        request_1->room_R = getRoomObject(room_no);
        request_1->status = "Pending";
        request_1->type = "Change-room";

        req[request_no] = *request_1;

        request_no++;

        cout << "Request successfully placed :-)" << endl;

    } else cout << "Room is not empty try again" << endl;

    handler();
}

bool Student::isRoomEmpty(int room_no) {

    Room_ *rr = dataClass->getRooms();

    for (int i = 0; i < 30; ++i) {
        if (rr[i].room_number == room_no && rr[i].status == "free")return true;
    }
    return false;
}

Room_ Student::getRoomObject(int room_no) {

    Room_ *rr = dataClass->getRooms();

    for (int i = 0; i < 30; ++i) {
        if (rr[i].room_number == room_no)return rr[i];
    }
    return rr[0];
}

void Student::viewMyRequest() {

    Request_ *req = dataClass->getRequest();

    int j = 0;
    for (int i = 0; i < request_no; i++) {
        if (req[i].student_R.student_id == student_m.student_id) {
            cout << "Your request for room no " + to_string(req[i].room_R.room_number) + " is " + req[i].status << endl;
        } else j++;
    }
    if (j == request_no)cout << "You don't have any request placed" << endl;

    handler();
}
