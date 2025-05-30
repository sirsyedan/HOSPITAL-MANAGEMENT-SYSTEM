#include "doctor_manager.h"
#include "appointment1.h"
#include "billing.h"
#include <iostream>

int main() {
    DoctorManager dm;
    AppointmentManager am;
    BillingManager bm;

    int choice;
    do {
        std::cout << "\n--- Hospital Management Menu ---\n";
        std::cout << "1. Add Doctor\n";
        std::cout << "2. Display All Doctors\n";
        std::cout << "3. Search Doctor by Name\n";
        std::cout << "4. Update Doctor by ID\n";
        std::cout << "5. Delete Doctor by ID\n";
        std::cout << "6. Sort Doctors by Name\n";
        std::cout << "7. Check Doctor Availability\n";
        std::cout << "8. Book Appointment\n";
        std::cout << "9. Display Appointments\n";
        std::cout << "10. Generate Bill (after booking)\n";
        std::cout << "11. Display All Bills\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                dm.addDoctor();
                break;
            case 2:
                dm.displayAllDoctors();
                break;
            case 3:
                dm.searchDoctorByName();
                break;
            case 4:
                dm.updateDoctorById();
                break;
            case 5:
                dm.deleteDoctorById();
                break;
            case 6:
                dm.sortDoctorsByName();
                break;
            case 7:
                dm.checkAvailabilityById();
                break;
            case 8:
                am.bookAppointment(dm);
                break;
            case 9:
                am.displayAppointments();
                break;
            case 10:
                bm.generateBill(dm, am.getAppointments());
                break;
            case 11:
                bm.displayAllBills();
                break;
            case 0:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
