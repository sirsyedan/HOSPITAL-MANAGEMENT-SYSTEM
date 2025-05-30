#include "doctor_manager.h"
#include <iostream>
#include <limits>
#include <string>

Node::Node(const Doctor& d) : data(d), next(nullptr) {}

DoctorManager::DoctorManager() : head(nullptr) {
    addPredefinedDoctors();
}

DoctorManager::~DoctorManager() {
    freeList();
}

void DoctorManager::addPredefinedDoctors() {
    // Some pre-made doctors for testing
    Doctor d1("John Smith", 45, "Cardiologist",
              {{"2025-05-24", "09:00 AM - 11:00 AM"}, {"2025-05-25", "02:00 PM - 04:00 PM"}});
    Doctor d2("Alice Brown", 50, "Dermatologist", {{"2025-05-26", "10:00 AM - 12:00 PM"}});
    Doctor d3("Clara White", 38, "Pediatrician", {{"2025-05-27", "01:00 PM - 03:00 PM"}});

    Node* n1 = new Node(d1);
    Node* n2 = new Node(d2);
    Node* n3 = new Node(d3);

    n1->next = n2;
    n2->next = n3;
    head = n1;
}

void DoctorManager::addDoctor() {
    Doctor d;
    d.setName();
    d.setAge();
    d.setSpecialization();
    d.setAvailability();

    Node* newNode = new Node(d);

    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    std::cout << "Doctor added successfully. ID: " << d.getId() << "\n";
}

void DoctorManager::displayAllDoctors() const {
    if (!head) {
        std::cout << "No doctors to display.\n";
        return;
    }
    Node* temp = head;
    int count = 1;
    while (temp) {
        std::cout << "Doctor " << count++ << ":\n";
        temp->data.display();
        temp = temp->next;
    }
}

Node* DoctorManager::findDoctorById(int id) const {
    Node* temp = head;
    while (temp) {
        if (temp->data.getId() == id)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

// New public wrapper method
Node* DoctorManager::getDoctorNodeById(int id) const {
    return findDoctorById(id);
}

void DoctorManager::searchDoctorByName() const {
    if (!head) {
        std::cout << "No doctors to search.\n";
        return;
    }

    std::cout << "Enter name to search: ";
    std::string name;
    std::getline(std::cin, name);

    Node* temp = head;
    bool found = false;
    while (temp) {
        if (temp->data.getName() == name) {
            std::cout << "Doctor found:\n";
            temp->data.display();
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) std::cout << "No doctor found with that name.\n";
}

void DoctorManager::updateDoctorById() {
    if (!head) {
        std::cout << "No doctors to update.\n";
        return;
    }

    std::cout << "Enter doctor ID to update: ";
    int id;
    std::cin >> id;
    std::cin.ignore();

    Node* node = findDoctorById(id);
    if (!node) {
        std::cout << "Doctor not found.\n";
        return;
    }

    std::cout << "Updating doctor info:\n";
    node->data.setName();
    node->data.setAge();
    node->data.setSpecialization();
    node->data.updateAvailability();
    std::cout << "Doctor updated.\n";
}

void DoctorManager::deleteDoctorById() {
    if (!head) {
        std::cout << "No doctors to delete.\n";
        return;
    }

    std::cout << "Enter doctor ID to delete: ";
    int id;
    std::cin >> id;
    std::cin.ignore();

    Node* temp = head;
    Node* prev = nullptr;

    while (temp) {
        if (temp->data.getId() == id) {
            if (prev) prev->next = temp->next;
            else head = temp->next;
            delete temp;
            std::cout << "Doctor deleted.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    std::cout << "Doctor not found.\n";
}

void DoctorManager::sortDoctorsByName() {
    if (!head || !head->next) {
        std::cout << "Not enough doctors to sort.\n";
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            if (current->data.getName() > current->next->data.getName()) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    std::cout << "Doctors sorted by name.\n";
}

void DoctorManager::checkAvailabilityById() const {
    if (!head) {
        std::cout << "No doctors available.\n";
        return;
    }

    std::cout << "Enter doctor ID to check availability: ";
    int id;
    std::cin >> id;
    std::cin.ignore();

    Node* node = findDoctorById(id);
    if (!node) {
        std::cout << "Doctor not found.\n";
        return;
    }

    node->data.displayAvailability();
}

void DoctorManager::freeList() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
