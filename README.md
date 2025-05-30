# Hospital Management System (C++)

## Project Overview

This project is a console-based Hospital Management System implemented in C++. It allows management of doctors, appointments, and billing in a simplified manner. The system uses linked lists and vectors to store and manage data dynamically.

Key features include:
- Adding, updating, deleting, and searching doctors.
- Managing doctor availability.
- Booking patient appointments.
- Generating and displaying billing for appointments.

---

## File Structure

- **doctor.h / doctor.cpp**  
  Defines the `Doctor` class, including attributes like name, age, specialization, and availability.

- **doctor_manager.h / doctor_manager.cpp**  
  Implements the `DoctorManager` class, which handles a linked list of doctors and provides CRUD operations and sorting.

- **appointment1.h / appointment1.cpp**  
  Defines `Appointment` struct and `AppointmentManager` class for booking and displaying appointments.

- **billing.h / billing.cpp**  
  Implements billing functionality with the `BillingManager` class, allowing bill generation and display based on appointments.

- **main.cpp**  
  The main program providing a menu-driven interface to interact with all system features.

---

## Features

- **Doctor Management**  
  Add new doctors, update existing details, delete doctors, and search by name or ID.

- **Appointment Booking**  
  Book appointments for patients based on doctors' available slots and validate appointment details.

- **Billing System**  
  Generate bills for appointments and maintain a list of generated bills, preventing duplicate billing.

- **Data Structures**  
  Uses singly linked list for doctors and vectors for appointments and bills for efficient management.

---

## Usage Instructions

1. Compile all `.cpp` files together, for example:  
   ```bash
   g++ main.cpp doctor_manager.cpp appointment1.cpp billing.cpp doctor.cpp -o HospitalManagement
