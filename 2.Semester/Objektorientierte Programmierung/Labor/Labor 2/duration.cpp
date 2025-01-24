#include "duration.h"

Duration::Duration(double value, const std::string& unit) : value(value), unit(unit) {}

double Duration::get_value() const {
    return value;
}

const std::string& Duration::get_unit() const {
    return unit;
}

Duration Duration::add(const Duration& other) const {
    return Duration(value + other.value, unit);
}

Duration Duration::subtract(const Duration& other) const {
    return Duration(value - other.value, unit);
}

Duration Duration::multiply(double multiplier) const {
    return Duration(value * multiplier, unit);
}

Duration Duration::divide(double divisor) const {
    return Duration(value / divisor, unit);
}

//Duration Duration::convert_to(const std::string& target_unit) const {
//    static const std::unordered_map<std::string, double> conversion_table = {
//            {"hours", 1.0},
//            {"minutes", 1.0 / 60.0},
//            {"seconds", 1.0 / 3600.0}
//    };
//double converted_value = value * conversion_table.at(target_unit) / conversion_table.at(unit);
//return Duration(converted_value, target_unit);


std::string Duration::to_string() const {
    return std::to_string(value) + " " + unit;
}

int Duration::compare(const Duration& other) const {
    if (value < other.value) {
        return -1;
    } else if (value > other.value) {
        return 1;
    } else {
        return 0;
    }
}
