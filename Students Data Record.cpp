#include<iostream>
#include<string>
using namespace std;

class Unidata {
private:
    string name;
    int age;
    string roll_no;
    int sem;
    float fee;

public:
    void dataentry();
    void process();
    void datasearch();
    void outdata();
    string getName() { return name; }
    int getAge() { return age; }
    string getRollNo() { return roll_no; }
    int getSemester() { return sem; }
    float getFee() { return fee; }
};

void Unidata::dataentry() {
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Roll number: ";
    cin>>roll_no;
    cout << "Semester: ";
    cin >> sem;
}

void Unidata::process() {
    switch(sem) {
        case 1:
            fee = 120000;
            break;
        case 2:
            fee = 100000;
            break;
        case 3:
            fee = 90000;
            break;
        case 4:
            fee = 80000;
            break;
        case 5:
            fee = 75000;
            break;
        case 6:
            fee = 70000;
            break;
        case 7:
            fee = 65000;
            break;
        case 8:
            fee = 60000;
            break;
        default:
            cout << "Invalid semester entered!" << endl;
            fee = 0; // Setting fee to 0 for invalid semester
    }
}

void Unidata::outdata() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Roll number: " << roll_no << endl;
    cout << "Semester: " << sem << endl;
    cout << "Your fee is: " << fee << endl;
}

void Unidata::datasearch() {
    cout << "Whose data do you want to find?" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Roll Number: ";
    cin>>roll_no;
}

int main() {
    int stnum;
    cout << "Number of students whose data needs to be recorded: ";
    cin >> stnum;

    Unidata *students = new Unidata[stnum];
    for (int i = 0; i < stnum; i++) {
        cout << "Enter data for student " << i + 1 << ":" << endl;
        students[i].dataentry();
        students[i].process();
    }
    cout<<endl;
    cout << "Do you want to search for student data? (Y/N): ";
    char choice;
    cin >> choice;
    cout<<endl;
    if (toupper(choice) == 'Y') {
        Unidata searchData;
        searchData.datasearch();
        bool found = false;
        for (int i = 0; i < stnum; i++) {
            if (searchData.getName() == students[i].getName() && searchData.getRollNo() == students[i].getRollNo()) {
                cout << "Data for student found:" << endl;
                students[i].outdata();
                found = true;
                break;
            }
        }
        cout<<endl;
        if (!found)
            cout << "Data for student not found!" << endl;
    }

    delete[] students;
    return 0;
}
