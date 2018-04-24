//
// Created by Abhinav_Suthar on 24-04-2018.
//

#ifndef HOSTEL_ROOM_FINAL_ADMIN_H
#define HOSTEL_ROOM_FINAL_ADMIN_H

#include <string>

using namespace std;


class Admin {

public:
    Admin() { login(); }

private:
    void login();

    void handler();

    void getStudentDetails();

    void viewRequest();

    void acceptRequest();

    void changeRoomStatus(int room_no, const string &status_);

    void getEmptyRooms();
};


#endif //HOSTEL_ROOM_FINAL_ADMIN_H
