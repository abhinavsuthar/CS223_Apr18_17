//
// Created by Abhinav_Suthar on 24-04-2018.
//

#include "DatabaseManager.h"

void DatabaseManager::saveAllDataToFile() {

    string room_str;

    for (auto &i : room_) {
        if (!i.status.empty())
            room_str += to_string(i.room_number) + " " + to_string(i.floor) + " " + i.hostel + " " +
                        i.status + "\n";
    }

    ofstream out_file;
    out_file.open("rooms.txt");
    out_file << room_str;
    out_file.close();


    string student_str;
    for (auto &j : student_) {
        if (!j.student_id.empty())
            student_str += j.first_name + " " + j.last_name + " " + j.student_id + " " +
                           j.cell_no + " " + to_string(j.room.room_number) + "\n";
    }

    out_file.open("student.txt");
    out_file << student_str;
    out_file.close();

    string request_str;
    for (auto &k : request_) {
        if (!k.student_R.student_id.empty())
            request_str +=
                    k.student_R.student_id + " " + to_string(k.room_R.room_number) + " " + k.status + " " + k.type +
                    "\n";

    }

    out_file.open("request.txt");
    out_file << request_str;
    out_file.close();

}

void DatabaseManager::getRoomsFormFile() {

    string text;
    ifstream in_file;
    in_file.open("rooms.txt");

    int i = 0;
    while (getline(in_file, text)) {
        vector<std::string> ret = split(text);

        room_[i].room_number = stoi(ret[0]);
        room_[i].floor = stoi(ret[1]);
        room_[i].hostel = ret[2];
        room_[i].status = ret[3];

        i++;
    }

    for (int j = 0; j < i; ++j) {
        //cout<<room_[j].room_number<<room_[j].status<<endl;
    }
}

void DatabaseManager::getStudentFormFile() {

    string text;
    ifstream in_file;
    in_file.open("student.txt");

    int i = 0;
    while (getline(in_file, text)) {
        vector<std::string> ret = split(text);


        student_[i].first_name = ret[0];
        student_[i].last_name = ret[1];
        student_[i].student_id = ret[2];
        student_[i].cell_no = ret[3];

        int room_no = stoi(ret[4]);

        setRoomStatus(room_no, "Occupied");
        student_[i].room = getRoomObject(room_no);

        i++;
    }

    for (int j = 0; j < i; ++j) {
        //cout<<student_[j].student_id<<student_[j].room.room_number<<endl;
    }

    //getRequestFromFile();

}

void DatabaseManager::getRequestFromFile() {

    string text;
    ifstream in_file;
    in_file.open("request.txt");

    int i = 0;
    request_no = 0;
    while (getline(in_file, text)) {
        vector<std::string> ret = split(text);

        string student_id = ret[0];
        int room_no = stoi(ret[1]);

        request_[i].student_R = getStudentObject(student_id);
        request_[i].room_R = getRoomObject(room_no);
        request_[i].status = ret[2];
        request_[i].type = ret[3];

        //cout << "Test: " << request_[i].student_R.student_id << endl;

        request_no++;

        i++;
    }
}

Student_ DatabaseManager::getStudentObject(const string &id) {

    for (int j = 0; j < 30; ++j) {
        cout<<"Test2: "<<student_[j].student_id<<"  "<<id<<endl;
        if (student_[j].student_id == id) return student_[j];
    }
    cout<<"Test : Default";
    return student_[0];

}

Room_ DatabaseManager::getRoomObject(int room_no) {

    for (auto &i : room_) {
        if (i.room_number == room_no)return i;
    }
    return room_[0];
}

void DatabaseManager::setRoomStatus(int room_no, const string &status) {
    for (auto &i : room_) {
        if (i.room_number == room_no)i.status = status;
    }
}
