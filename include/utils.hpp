#ifndef UTILS_HPP
#define UTILS_HPP

namespace utils {
    // Function to convert speed from km/h to m/s
    inline double convertKmphToMps(double speedKmph) {
        return speedKmph / 3.6;
    }

    // Function to convert speed from m/h to km/h
    inline double convertMpsToKmph(double speedMps) {
        return speedMps * 3.6;
    }
}

#endif // UTILS_HPP