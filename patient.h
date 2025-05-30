#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class patient {
private:
    std::string name;
    int age;
    std::string gender;
    std::string disease;
    int ID;
    static int nextID;

public:
    patient();

    // Setters (interactive)
    void setname();
    void setage();
    void setgender();
    void setdisease();

    // Setters (manual)
    void setname(const std::string& n);
    void setage(int a);
    void setgender(const std::string& g);
    void setdisease(const std::string& d);
    void setID(int id);

    // Getters
    std::string getName() const;
    int getID() const;
    int getAge() const;
    std::string getGender() const;
    std::string getDisease() const;

    void display() const;
};

struct PatientNode {
    patient data;
    PatientNode* next;
    PatientNode(const patient& p);
};

// List operations
void addPatient(PatientNode*& head);
void displayAllPatients(PatientNode* head);
void searchPatientByName(PatientNode* head);
void searchPatientByID(PatientNode* head);
void deletePatient(PatientNode*& head);
void editPatientByID(PatientNode* head);
void exportToFile(PatientNode* head);
void showStatistics(PatientNode* head);
void freeList(PatientNode*& head);

#endif
