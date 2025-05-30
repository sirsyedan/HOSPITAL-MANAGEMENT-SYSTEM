#include "patient.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int patient::nextID = 0;

patient::patient() : name(""), age(0), gender(""), disease(""), ID(++nextID) {}

void patient::setname() {
    cout << "ENTER PATIENT NAME: ";
    cin.ignore();
    getline(cin, name);
}

void patient::setage() {
    cout << "ENTER PATIENT AGE: ";
    while (!(cin >> age)) {
        cout << "Invalid input. Please enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void patient::setgender() {
    cout << "ENTER PATIENT GENDER: ";
    cin >> gender;
}

void patient::setdisease() {
    cout << "ENTER PATIENT DISEASE: ";
    cin.ignore();
    getline(cin, disease);
}

void patient::setname(const string& n) { name = n; }
void patient::setage(int a) { age = a; }
void patient::setgender(const string& g) { gender = g; }
void patient::setdisease(const string& d) { disease = d; }
void patient::setID(int id) { ID = id; }

string patient::getName() const { return name; }
int patient::getID() const { return ID; }
int patient::getAge() const { return age; }
string patient::getGender() const { return gender; }
string patient::getDisease() const { return disease; }

void patient::display() const {
    cout << "ID: " << ID << " | NAME: " << name
         << " | AGE: " << age
         << " | GENDER: " << gender
         << " | DISEASE: " << disease << endl;
}

PatientNode::PatientNode(const patient& p) : data(p), next(nullptr) {}

void addPatient(PatientNode*& head) {
    patient p;
    p.setname();
    p.setage();
    p.setgender();
    p.setdisease();
    PatientNode* newNode = new PatientNode(p);

    if (!head) head = newNode;
    else {
        PatientNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    cout << "Patient added successfully with ID: " << newNode->data.getID() << "\n";
}

void displayAllPatients(PatientNode* head) {
    if (!head) {
        cout << "No patients to display.\n";
        return;
    }

    int count = 1;
    cout << "\n======= PATIENT LIST =======\n";
    while (head) {
        cout << "Patient " << count++ << ": ";
        head->data.display();
        head = head->next;
    }
}

void searchPatientByName(PatientNode* head) {
    if (!head) {
        cout << "No patients to search.\n";
        return;
    }

    cout << "Enter name to search: ";
    string name;
    cin.ignore();
    getline(cin, name);

    while (head) {
        if (head->data.getName() == name) {
            cout << "Patient found:\n";
            head->data.display();
            return;
        }
        head = head->next;
    }

    cout << "No patient found with name: " << name << endl;
}

void searchPatientByID(PatientNode* head) {
    if (!head) {
        cout << "No patients to search.\n";
        return;
    }

    cout << "Enter patient ID to search: ";
    int id;
    while (!(cin >> id)) {
        cout << "Invalid input. Enter valid numeric ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (head) {
        if (head->data.getID() == id) {
            cout << "Patient found:\n";
            head->data.display();
            return;
        }
        head = head->next;
    }

    cout << "No patient found with ID: " << id << endl;
}

void deletePatient(PatientNode*& head) {
    if (!head) {
        cout << "No patients to delete.\n";
        return;
    }

    cout << "Enter patient ID to delete: ";
    int id;
    while (!(cin >> id)) {
        cout << "Invalid input. Enter valid numeric ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    PatientNode *temp = head, *prev = nullptr;
    while (temp && temp->data.getID() != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "No patient found with ID: " << id << endl;
        return;
    }

    if (!prev) head = temp->next;
    else prev->next = temp->next;

    delete temp;
    cout << "Patient deleted successfully.\n";
}

void editPatientByID(PatientNode* head) {
    cout << "Enter patient ID to edit: ";
    int id;
    while (!(cin >> id)) {
        cout << "Invalid input. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (head) {
        if (head->data.getID() == id) {
            cout << "Editing patient:\n";
            head->data.display();
            head->data.setname();
            head->data.setage();
            head->data.setgender();
            head->data.setdisease();
            cout << "Patient updated successfully.\n";
            return;
        }
        head = head->next;
    }

    cout << "Patient ID not found.\n";
}

void exportToFile(PatientNode* head) {
    ofstream file("patients.txt");
    int count = 1;
    while (head) {
        file << "Patient " << count++ << ": ID: " << head->data.getID()
             << ", Name: " << head->data.getName()
             << ", Age: " << head->data.getAge()
             << ", Gender: " << head->data.getGender()
             << ", Disease: " << head->data.getDisease() << endl;
        head = head->next;
    }
    file.close();
    cout << "Exported to 'patients.txt'\n";
}

void showStatistics(PatientNode* head) {
    int count = 0, totalAge = 0;

    while (head) {
        count++;
        totalAge += head->data.getAge();
        head = head->next;
    }

    if (count == 0) {
        cout << "No patients for statistics.\n";
        return;
    }

    cout << "Total Patients: " << count << ", Average Age: " << (totalAge / count) << endl;
}

void freeList(PatientNode*& head) {
    while (head) {
        PatientNode* temp = head;
        head = head->next;
        delete temp;
    }
}
