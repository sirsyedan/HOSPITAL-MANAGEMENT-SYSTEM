#include "appointment1.h"
#include <iostream>

void AppointmentManager::bookAppointment(const DoctorManager& dm) {
    std::cout << "Enter doctor ID to book appointment: ";
    int docId;
    std::cin >> docId;
    std::cin.ignore();

    Node* docNode = dm.getDoctorNodeById(docId);
    if (!docNode) {
        std::cout << "Doctor not found.\n";
        return;
    }

    std::cout << "Available slots for Dr. " << docNode->data.getName() << ":\n";
    docNode->data.displayAvailability();

    std::string patientName, date, timeSlot;
    std::cout << "Enter patient name: ";
    std::getline(std::cin, patientName);

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    std::cout << "Enter time slot (e.g., 09:00 AM - 11:00 AM): ";
    std::getline(std::cin, timeSlot);

    // Validate slot
    const auto& avail = docNode->data.getAvailabilities();
    bool validSlot = false;
    for (const auto& entry : avail) {
        if (entry.date == date && entry.time == timeSlot) {
            validSlot = true;
            break;
        }
    }

    if (!validSlot) {
        std::cout << "Invalid date or time slot. Appointment not booked.\n";
        return;
    }

    Appointment appt{docId, patientName, date, timeSlot};
    appointments.push_back(appt);
    std::cout << "Appointment booked successfully.\n";
}

void AppointmentManager::displayAppointments() const {
    if (appointments.empty()) {
        std::cout << "No appointments booked yet.\n";
        return;
    }

    std::cout << "All Appointments:\n";
    for (const auto& appt : appointments) {
        std::cout << "Doctor ID: " << appt.doctorId
                  << ", Patient: " << appt.patientName
                  << ", Date: " << appt.date
                  << ", Time: " << appt.timeSlot << '\n';
    }
}

const std::vector<Appointment>& AppointmentManager::getAppointments() const {
    return appointments;
}
