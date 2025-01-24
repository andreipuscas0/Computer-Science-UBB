#ifndef DURATION_H
#define DURATION_H

#include <string>

class Duration {

private:
    double value;
    std::string unit;

public:
    // Constructor
    Duration(double value, const std::string& unit);

    // Metode de acces
    double get_value() const;
    const std::string& get_unit() const;

    // Metode de operare
    Duration add(const Duration& other) const;
    Duration subtract(const Duration& other) const;
    Duration multiply(double multiplier) const;
    Duration divide(double divisor) const;
//    Duration convert_to(const std::string& target_unit) const;
    std::string to_string() const;
    int compare(const Duration& other) const;
};

#endif // DURATION_H
