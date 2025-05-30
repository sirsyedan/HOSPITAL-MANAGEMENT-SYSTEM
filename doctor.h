#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>

struct Availability {
    std::string date;
    std::string time;
};

class Doctor {
private:
    std::string name;
    int age;
    std::string specialization;
    int id;
    std::vector<Availability> availabilities;

    static int next_id;

public:
    Doctor();
    Doctor(const std::string& name, int age, const std::string& spec, const std::vector<Availability>& avails);

    // Setters (interactive)
    void setName();
    void setAge();
    void setSpecialization();
    void setAvailability();
    void updateAvailability();

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getSpecialization() const;
    const std::vector<Availability>& getAvailabilities() const;

    // Display
    void display() const;
    void displayAvailability() const;

    // Swap helper
    friend void swap(Doctor& a, Doctor& b);
};

void swap(Doctor& a, Doctor& b);

#endif
