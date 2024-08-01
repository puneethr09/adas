#ifndef UTILS_HPP
#define UTILS_HPP

namespace utils {
    // Function to convert speed from km/h to m/s
    inline double convertKmphToMps(double speedKmph) {
        return speedKmph * (5.0 / 18.0);
    }
}

#endif // UTILS_HPP