#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>
#include <algorithm>
#include <regex>
#include <ctime>

using namespace std;

const int MAX_NAME_LEN = 30;
const int MAX_ID_LEN = 15;
const int PHONE_LEN = 12;
const int ROOM_COUNT = 10;
const int PRICE_PER_DAY = 500;
struct Date {
    int day, month, year;
};

struct Customer {
    string id;
    string name;
    string phone;
    int roomNumber;
    int checkIn;
    int checkOut;
    int stayDays;
    int totalBill;
    Customer* next;
};

Customer* head = nullptr;
bool rooms[ROOM_COUNT + 1] = {false};
 Customer* findCustomerById(const string& id);


 Date getCurrentDate() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return { now->tm_mday, now->tm_mon + 1, now->tm_year + 1900 };
}

 Date addDays(Date date, int days) {
    tm t = {};
    t.tm_mday = date.day;
    t.tm_mon = date.month - 1;
    t.tm_year = date.year - 1900;

     t.tm_mday += days;

    mktime(&t);

    return { t.tm_mday, t.tm_mon + 1, t.tm_year + 1900 };
}

 int dateToInt(Date d) {
    return d.year * 10000 + d.month * 100 + d.day;
}

 Date intToDate(int dateInt) {
    Date d;
    d.day = dateInt % 100;
    dateInt /= 100;
    d.month = dateInt % 100;
    dateInt /= 100;
    d.year = dateInt;
    return d;
}

 int daysBetween(Date start, Date end) {
    tm s = {};
    s.tm_mday = start.day;
    s.tm_mon = start.month - 1;
    s.tm_year = start.year - 1900;

    tm e = {};
    e.tm_mday = end.day;
    e.tm_mon = end.month - 1;
    e.tm_year = end.year - 1900;

     time_t t1 = mktime(&s);
    time_t t2 = mktime(&e);

     if (t1 == (time_t)-1 || t2 == (time_t)-1) {
        return 0;
    }


    return static_cast<int>(difftime(t2, t1) / (60 * 60 * 24));
}


 string inputID(bool check_uniqueness = true) {
    string id;
     regex idPattern("^[a-zA-Z0-9]{1,15}$");
    while (true) {
        cout << "Enter Customer ID (max 15 alphanumeric chars): ";
        getline(cin, id);
        if (regex_match(id, idPattern)) {
            if (check_uniqueness && findCustomerById(id) != nullptr) {
                cout << "This ID already exists! Please enter a unique ID for a new booking.\n";
            } else {
                return id;
            }
        } else {
            cout << "Invalid ID! Only alphanumeric characters (1-15) allowed.\n";
        }
    }
}

 string inputName() {
    string name;
     regex namePattern("^[a-zA-Z ]{1,30}$");
    while (true) {
        cout << "Enter Name (max 30 chars, letters and spaces only): ";
        getline(cin, name);
        if (regex_match(name, namePattern)) {
            return name;
        }
        cout << "Invalid Name! Use only letters and spaces (1-30).\n";
    }
}

string inputPhone() {
    string phone;
     regex phonePattern("^\\d{10,12}$");
    while (true) {
        cout << "Enter Phone Number (10 to 12 digits): ";
        getline(cin, phone);
        if (regex_match(phone, phonePattern)) {
            return phone;
        }
        cout << "Invalid Phone Number! Must be 10–12 digits.\n";
    }
}

 int inputRoom() {
    int room;
    while (true) {
        cout << "Enter Room Number (1-10): ";
        cin >> room;
         if (cin.fail() || room < 1 || room > ROOM_COUNT || rooms[room]) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid or already booked room. Try again.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return room;
        }
    }
}

 Date inputDate(const string& prompt) {
    string dateStr;
    Date d;
    while (true) {
        cout << prompt << " (DD/MM/YYYY): ";
        getline(cin, dateStr);

        if (sscanf(dateStr.c_str(), "%d/%d/%d", &d.day, &d.month, &d.year) == 3) {
             if (d.day >= 1 && d.day <= 31 && d.month >= 1 && d.month <= 12 && d.year >= 2000) {
                return d;
            }
        }
        cout << "Invalid date format or values! Please use DD/MM/YYYY format and valid dates (e.g., 01/01/2023).\n";
    }
}


 void saveCustomersToFile() {
    ofstream file("customers.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open customers.txt for writing.\n";
        return;
    }
    Customer* temp = head;
    while (temp) {
        file << temp->id << "," << temp->name << "," << temp->phone << ","
             << temp->roomNumber << "," << temp->checkIn << "," << temp->checkOut << ","
             << temp->stayDays << "," << temp->totalBill << "\n";
        temp = temp->next;
    }
    file.close();
}

 void loadCustomersFromFile() {

}



 void displayAvailableRooms() {


}


void displayAllBookedRooms() {


}


void bookRoom() {




}
void updateBooking() {


}

void deleteBooking() {


}
void searchCustomer() {



}
void sortCustomers() {

}


void manageBookedRooms() {



}

int main() {
    loadCustomersFromFile();
    while (true) {
        cout << "\n--- Hotel Management Menu ---\n";
        cout << "1. Display Available Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Manage Booked Rooms (View, Search, Sort)\n";
        cout << "4. Update Check-out Date\n";
        cout << "5. Delete Booking (Archive Customer)\n";
        cout << "0. Exit\n";
        cout << "---------------------------\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: displayAvailableRooms(); break;
            case 2: bookRoom(); break;
            case 3: manageBookedRooms(); break;
            case 4: updateBooking(); break;
            case 5: deleteBooking(); break;
            case 0:
                 while (head) {
                    Customer* temp = head;
                    head = head->next;
                    delete temp;
                }
                cout << "Exiting Hotel Management System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please enter a number from the menu.\n";
        }
    }

    return 0;
}

