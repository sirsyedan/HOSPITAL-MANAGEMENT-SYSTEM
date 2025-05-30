#include "billing.h"
#include <iostream>

bool BillingManager::isAlreadyBilled(const Appointment& appt) const {
    for (const auto& bill : bills) {
        if (bill.doctorId == appt.doctorId &&
            bill.patientName == appt.patientName &&
            bill.date == appt.date &&
            bill.timeSlot == appt.timeSlot) {
            return true;
        }
    }
    return false;
}

void BillingManager::generateBill(const DoctorManager& dm, const std::vector<Appointment>& allAppointments) {
    std::cout << "Enter doctor ID for billing: ";
    int docId;
    std::cin >> docId;
    std::cin.ignore();

    Node* docNode = dm.getDoctorNodeById(docId);
    if (!docNode) {
        std::cout << "Doctor not found.\n";
        return;
    }

    std::vector<Appointment> doctorAppointments;
    for (const auto& appt : allAppointments) {
        if (appt.doctorId == docId && !isAlreadyBilled(appt)) {
            doctorAppointments.push_back(appt);
        }
    }

    if (doctorAppointments.empty()) {
        std::cout << "No unbilled appointments found for this doctor.\n";
        return;
    }

    std::cout << "Appointments for Dr. " << docNode->data.getName() << ":\n";
    for (size_t i = 0; i < doctorAppointments.size(); ++i) {
        const auto& appt = doctorAppointments[i];
        std::cout << i + 1 << ". Patient: " << appt.patientName
                  << ", Date: " << appt.date
                  << ", Time: " << appt.timeSlot << "\n";
    }

    std::cout << "Select appointment number to bill: ";
    int index;
    std::cin >> index;
    std::cin.ignore();

    if (index < 1 || index > static_cast<int>(doctorAppointments.size())) {
        std::cout << "Invalid selection.\n";
        return;
    }

    const auto& selectedAppt = doctorAppointments[index - 1];

    double amount;
    std::cout << "Enter billing amount: ";
    std::cin >> amount;
    std::cin.ignore();

    bills.push_back({selectedAppt.doctorId, selectedAppt.patientName, selectedAppt.date, selectedAppt.timeSlot, amount});
    std::cout << "Bill generated successfully.\n";
}

void BillingManager::displayAllBills() const {
    if (bills.empty()) {
        std::cout << "No bills generated yet.\n";
        return;
    }

    std::cout << "All Bills:\n";
    for (const auto& bill : bills) {
        std::cout << "Doctor ID: " << bill.doctorId
                  << ", Patient: " << bill.patientName
                  << ", Date: " << bill.date
                  << ", Time: " << bill.timeSlot
                  << ", Amount: $" << bill.amount << "\n";
    }
}
