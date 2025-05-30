Hospital Management System (HMS)

Project Overview
This project is a Hospital Management System written in C++. It allows managing doctors, appointments, and billing through a console-based menu. The system supports adding, updating, deleting, and searching doctors; booking appointments with doctor availability checks; and generating bills for appointments.

Features

Add new doctors and maintain their availability schedules.

Display all doctors with details.

Search doctors by name.

Update or delete doctor information by ID.

Sort doctors alphabetically by name.

Check availability of doctors by their ID.

Book patient appointments by selecting a doctor and time slot.

Display all booked appointments.

Generate bills for completed appointments and avoid duplicate billing.

View all generated bills with details.

Installation and Running

Download or clone the project files to your computer.

Compile all C++ source files together. For example, using g++ compiler:
g++ main.cpp doctor_manager.cpp appointment1.cpp billing.cpp -o program.exe

Run the compiled executable by typing in the command prompt:
.\program.exe

Use the console menu to perform operations like managing doctors, booking appointments, and billing.

Code Structure

doctor_manager.h and doctor_manager.cpp: Handle doctor information using a linked list.

appointment1.h and appointment1.cpp: Manage appointments using vectors.

billing.h and billing.cpp: Handle billing related to appointments, ensuring no repeated bills for the same appointment.

main.cpp: Contains the main menu and connects all modules.

Future Improvements

Add file or database support to save data permanently.

Improve appointment validation and conflict resolution.

Add user roles and login authentication.

Develop a graphical user interface (GUI) for easier use.

