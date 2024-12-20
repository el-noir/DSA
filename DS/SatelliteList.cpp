#include <iostream>
using namespace std;

class Satellite {
public:
    int id;
    bool isOnline;
    string data;
    Satellite* next;

    Satellite(int id) : id(id), isOnline(true), data(""), next(NULL) {}
};

class SatelliteSys {
private:
    Satellite* head;
    Satellite* tail;

public:
    SatelliteSys() : head(NULL), tail(NULL) {}

    void AddSat(int id) {
        Satellite* newSat = new Satellite(id);

        if (head == NULL) {
            head = tail = newSat;
        }
        else {
            tail->next = newSat;
            tail = newSat;
        }
    }

    void toggle(int id) {
        Satellite* temp = head;

        while (temp) {
            if (temp->id == id) {
                temp->isOnline = !temp->isOnline;
                cout << "Satellite " << id << " is now " << (temp->isOnline ? "Online" : "Offline") << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Satellite with ID " << id << " not found." << endl;
    }

    void transmit(string data) {
        Satellite* temp = head;

        while (temp) {
            if (temp->isOnline) {
                temp->data = data;
                cout << "Data is transmitted to Satellite " << temp->id << endl;
            }
            else {
                Satellite* cur = temp->next;
                while (cur && !cur->isOnline) {
                    cur = cur->next;
                }
                if (cur) {
                    cur->data = data;
                    cout << "Data is transmitted to Satellite " << cur->id << ", skipping Satellite " << temp->id << " as it was offline." << endl;
                }
            }
            temp = temp->next;
        }
    }

    void displayData() const {
        Satellite* temp = head;
        while (temp) {
            cout << "Satellite " << temp->id << ": " << temp->data << endl;
            temp = temp->next;
        }
    }
};