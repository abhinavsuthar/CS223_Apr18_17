//
// Created by Abhinav_Suthar on 24-04-2018.
//

#ifndef HOSTEL_ROOM_FINAL_STUDENT_H
#define HOSTEL_ROOM_FINAL_STUDENT_H


#include "DatabaseManager.h"

class Student {

public:
    Student() { login(); }

    bool loggedIn = false;

private:
    Student_ student_m;

    void login();

    void handler();

    void getRoomDetails();

    void getEmptyRooms();

    void putRequest();

    bool isRoomEmpty(int room_no);

    Room_ getRoomObject(int room_no);

    void viewMyRequest();

};


#endif //HOSTEL_ROOM_FINAL_STUDENT_H
