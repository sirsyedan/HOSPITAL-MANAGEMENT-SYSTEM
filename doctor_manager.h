#ifndef DOCTOR_MANAGER_H
#define DOCTOR_MANAGER_H

#include "doctor.h"

struct Node {
    Doctor data;
    Node* next;
    Node(const Doctor& d);
};

class DoctorManager {
private:
    Node* head;

    Node* findDoctorById(int id) const;  // Private helper to find node by ID
    void freeList();
    void addPredefinedDoctors();

public:
    DoctorManager();
    ~DoctorManager();

    void addDoctor();
    void displayAllDoctors() const;
    void searchDoctorByName() const;
    void updateDoctorById();
    void deleteDoctorById();
    void sortDoctorsByName();
    void checkAvailabilityById() const;

    Node* getDoctorNodeById(int id) const;  // Public wrapper to access findDoctorById
};

#endif
