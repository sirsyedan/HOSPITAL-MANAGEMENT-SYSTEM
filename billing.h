#ifndef BILLING_H
#define BILLING_H

#include "doctor_manager.h"
#include "appointment1.h"
#include <vector>

struct Bill {
    int doctorId;
    std::string patientName;
    std::string date;
    std::string timeSlot;
    double amount;
};

class BillingManager {
private:
    std::vector<Bill> bills;

public:
    void generateBill(const DoctorManager& dm, const std::vector<Appointment>& allAppointments);
    void displayAllBills() const;

    // Check if appointment is already billed
    bool isAlreadyBilled(const Appointment& appt) const;
};

#endif
