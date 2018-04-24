//
// Created by Abhinav_Suthar on 24-04-2018.
//

#ifndef HOSTEL_ROOM_FINAL_DATABASEMANAGER_H
#define HOSTEL_ROOM_FINAL_DATABASEMANAGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

static int request_no = 0;

struct Room_ {
    int room_number{};
    int floor{};
    string hostel;
    string status;
} room_[30];

struct Student_ {
    string first_name;
    string last_name;
    string student_id;
    string cell_no;
    Room_ room;
} student_[30];

struct Admin_ {
    string username;
    string password;
} admin_[10];

struct Request_ {
    Student_ student_R;
    Room_ room_R;
    int position{};
    string status;
    string type;
} request_[30];

struct Allocation {
    int student_id{};
    int room_number{};
    int floor{};
    string hostel;
    int date_of_allotment{};
    int date_of_leaving{};
} allocation_[30];


class DatabaseManager {

public:
    DatabaseManager() {
        getRoomsFormFile();
        getStudentFormFile();
        getRequestFromFile();
    }

    Room_ *getRooms() { return room_; }

    Admin_ *getAdmin() { return admin_; }

    Student_ *getStudent() { return student_; }

    Request_ *getRequest() { return request_; }

    Allocation *getAllocation() { return allocation_; }

    void saveAllDataToFile();

private:
    void getRoomsFormFile();

    void getStudentFormFile();

    void getRequestFromFile();

    // warning:
    std::vector<std::string> split(std::string const &input) {
        std::istringstream buffer(input);
        std::vector<std::string> ret;

        std::copy(std::istream_iterator<std::string>(buffer),
                  std::istream_iterator<std::string>(),
                  std::back_inserter(ret));
        return ret;
    }

    Student_ getStudentObject(const string &id);

    Room_ getRoomObject(int room_no);

    void setRoomStatus(int room_no, const string &status);
};


#endif //HOSTEL_ROOM_FINAL_DATABASEMANAGER_H
