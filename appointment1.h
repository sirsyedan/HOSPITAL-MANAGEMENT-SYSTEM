#ifndef APPOINTMENT1_H
#define APPOINTMENT1_H

#include "doctor_manager.h"
#include "doctor.h"
#include <string>
#include <vector>

struct Appointment {
    int doctorId;
    std::string patientName;
    std::string date;
    std::string timeSlot;
};

class AppointmentManager {
private:
    std::vector<Appointment> appointments;

public:
    void bookAppointment(const DoctorManager& dm);
    void displayAppointments() const;

    // Getter to access all appointments
    const std::vector<Appointment>& getAppointments() const;
};

#endif
