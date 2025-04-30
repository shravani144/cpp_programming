#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle {
protected:
    string vehicleID;
    string make;
    string model;
    int year;
    bool isRented;
    double dailyRentalRate;

public:
    Vehicle(string id, string m, string mdl, int yr, double rate)
        : vehicleID(id), make(m), model(mdl), year(yr), isRented(false), dailyRentalRate(rate) {}

    virtual ~Vehicle() {}

    // Getters
    string getVehicleID() { return vehicleID; }
    string getMake() { return make; }
    string getModel() { return model; }
    int getYear() { return year; }
    bool getIsRented() { return isRented; }
    double getDailyRentalRate() { return dailyRentalRate; }

    // Virtual methods
    virtual double calculateRentalCost(int days) = 0; // Pure virtual function
    virtual void displayDetails() {
        cout << "Vehicle ID: " << vehicleID << "\n"
             << "Make: " << make << "\n"
             << "Model: " << model << "\n"
             << "Year: " << year << "\n"
             << "Rental Rate: $" << dailyRentalRate << " per day\n"
             << "Rented: " << (isRented ? "Yes" : "No") << "\n";
    }

    // Methods for renting and returning
    void rentVehicle() { isRented = true ;}
    void returnVehicle() { isRented = false ;}
};

// Derived class: Car
class Car : public Vehicle {
private:
    int numberOfDoors;
    string fuelType;

public:
    Car(string id, string m, string mdl, int yr, double rate, int doors, string fuel)
        : Vehicle(id, m, mdl, yr, rate), numberOfDoors(doors), fuelType(fuel) {}

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Number of Doors: " << numberOfDoors << "\n"
             << "Fuel Type: " << fuelType << "\n";
    }
};

// Derived class: Motorcycle
class Motorcycle : public Vehicle {
private:
    string engineType;
    bool hasSidecar;

public:
    Motorcycle(string id, string m, string mdl, int yr, double rate, string engine, bool sidecar)
        : Vehicle(id, m, mdl, yr, rate), engineType(engine), hasSidecar(sidecar) {}

    double calculateRentalCost(int days) override {
        double extraCharge = hasSidecar ? 20 * days : 0;
        return dailyRentalRate * days + extraCharge;
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Engine Type: " << engineType << "\n"
             << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << "\n";
    }
};

// Derived class: Truck
class Truck : public Vehicle {
private:
    double cargoCapacity;
    int numberOfAxles;

public:
    Truck(string id, string m, string mdl, int yr, double rate, double capacity, int axles)
        : Vehicle(id, m, mdl, yr, rate), cargoCapacity(capacity), numberOfAxles(axles) {}

    double calculateRentalCost(int days) override {
        return dailyRentalRate * days + (cargoCapacity * 10 * days);
    }

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Cargo Capacity: " << cargoCapacity << " cubic meters\n"
             << "Number of Axles: " << numberOfAxles << "\n";
    }
};

// RentalSystem class
class RentalSystem {
private:
    vector<Vehicle*> vehicles;

public:
    ~RentalSystem() {
        // Cleanup dynamic memory allocation
        for (auto vehicle : vehicles) {
            delete vehicle;
        }
    }

    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAvailableVehicles() {
        bool foundAvailable = false;
        for (auto vehicle : vehicles) {
            if (!vehicle->getIsRented()) {
                vehicle->displayDetails();
                cout << "\n";
                foundAvailable = true;
            }
        }
        if (!foundAvailable) {
            cout << "No available vehicles.\n";
        }
    }

    Vehicle* findVehicle(string vehicleID) {
        for (auto vehicle : vehicles) {
            if (vehicle->getVehicleID() == vehicleID) {
                return vehicle;
            }
        }
        return nullptr;
    }

    void rentVehicle(string vehicleID, int days) {
        Vehicle* vehicle = findVehicle(vehicleID);
        if (vehicle) {
            if (vehicle->getIsRented()) {
                cout << "This vehicle is already rented.\n";
            } else {
                vehicle->rentVehicle();
                cout << "Rental Cost for " << vehicleID << ": $" << vehicle->calculateRentalCost(days) << "\n";
            }
        } else {
            cout << "Vehicle not found.\n";
        }
    }

    void returnVehicle(string vehicleID) {
        Vehicle* vehicle = findVehicle(vehicleID);
        if (vehicle) {
            if (vehicle->getIsRented()) {
                vehicle->returnVehicle();
                cout << "Vehicle returned successfully.\n";
            } else {
                cout << "This vehicle is not rented.\n";
            }
        } else {
            cout << "Vehicle not found.\n";
        }
    }
};

int main() {
    RentalSystem system;

    // Creating vehicles
    system.addVehicle(new Car("CAR123", "Toyota", "Camry", 2020, 50, 4, "Gasoline"));
    system.addVehicle(new Motorcycle("MOTO456", "Harley", "Sportster", 2021, 30, "V-Twin", true));
    system.addVehicle(new Truck("TRUCK789", "Ford", "F-150", 2019, 100, 15, 4));

    int choice;
    string vehicleID;
    int days;

    do {
        cout << "1. Display Available Vehicles\n"
             << "2. Rent a Vehicle\n"
             << "3. Return a Vehicle\n"
             << "4. Find Vehicle and Display Details\n"
             << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.displayAvailableVehicles();
                break;
            case 2:
                cout << "Enter Vehicle ID: ";
                cin >> vehicleID;
                cout << "Enter number of days: ";
                cin >> days;
                system.rentVehicle(vehicleID, days);
                break;
            case 3:
                cout << "Enter Vehicle ID: ";
                cin >> vehicleID;
                system.returnVehicle(vehicleID);
                break;
            case 4:
                cout << "Enter Vehicle ID: ";
                cin >> vehicleID;
                {
                    Vehicle* vehicle = system.findVehicle(vehicleID);
                    if (vehicle) {
                        vehicle->displayDetails();
                    } else {
                        cout << "Vehicle not found.\n";
                    }
                }
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
