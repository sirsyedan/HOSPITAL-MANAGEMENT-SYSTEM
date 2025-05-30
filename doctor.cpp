#include "doctor.h"
#include <iostream>
#include <limits>

int Doctor::next_id = 0;

Doctor::Doctor() : name(""), age(0), specialization(""), id(++next_id) {}

Doctor::Doctor(const std::string& n, int a, const std::string& s, const std::vector<Availability>& avails)
    : name(n), age(a), specialization(s), availabilities(avails), id(++next_id) {}

void Doctor::setName() {
    std::cout << "Enter doctor name: ";
    std::getline(std::cin, name);
}

void Doctor::setAge() {
    std::cout << "Enter doctor age: ";
    while (!(std::cin >> age) || age <= 0) {
        std::cout << "Invalid age, try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(); // To clear the newline
}

void Doctor::setSpecialization() {
    std::cout << "Enter specialization: ";
    std::getline(std::cin, specialization);
}

void Doctor::setAvailability() {
    availabilities.clear();
    int n;
    std::cout << "Enter number of availability slots: ";
    while (!(std::cin >> n) || n < 0) {
        std::cout << "Invalid input. Enter non-negative integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    for (int i = 0; i < n; ++i) {
        Availability a;
        std::cout << "Enter date (e.g., 2025-05-24): ";
        std::getline(std::cin, a.date);
        std::cout << "Enter time (e.g., 09:00 AM - 11:00 AM): ";
        std::getline(std::cin, a.time);
        availabilities.push_back(a);
    }
}

void Doctor::updateAvailability() {
    std::cout << "Current availability:\n";
    displayAvailability();

    std::cout << "Do you want to overwrite availability? (y/n): ";
    char c;
    std::cin >> c;
    std::cin.ignore();

    if (c == 'y' || c == 'Y') {
        setAvailability();
        std::cout << "Availability updated.\n";
    } else {
        std::cout << "Availability not changed.\n";
    }
}

void Doctor::display() const {
    std::cout << "ID: " << id
              << " | Name: " << name
              << " | Age: " << age
              << " | Specialization: " << specialization << "\n";
    displayAvailability();
}

void Doctor::displayAvailability() const {
    if (availabilities.empty()) {
        std::cout << "  No availability.\n";
        return;
    }
    for (const auto& a : availabilities) {
        std::cout << "  Date: " << a.date << ", Time: " << a.time << "\n";
    }
}

int Doctor::getId() const { return id; }

std::string Doctor::getName() const { return name; }

std::string Doctor::getSpecialization() const { return specialization; }

const std::vector<Availability>& Doctor::getAvailabilities() const {
    return availabilities;
}

void swap(Doctor& a, Doctor& b) {
    std::swap(a.name, b.name);
    std::swap(a.age, b.age);
    std::swap(a.specialization, b.specialization);
    std::swap(a.availabilities, b.availabilities);
    std::swap(a.id, b.id);
}
