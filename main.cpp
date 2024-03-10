#include <cmath>
#include <iostream>
#include <string>
#include <tuple>


class SpaceObject {
   protected:
    std::string name;

   public:
    explicit SpaceObject(const std::string& name) : name(name) {}
    auto get_name() const -> std::string { return name; }
};

class Orbit {
   private:
    double semi_major_axis;
    double eccentricity;

   public:
    Orbit(double semi_major_axis, double eccentricity)
        : semi_major_axis(semi_major_axis), eccentricity(eccentricity) {}

    auto get_semi_major_axis() const -> double { return semi_major_axis; }
    auto get_eccentricity() const -> double { return eccentricity; }
};

class Satellite : public SpaceObject {
   private:
    double x, y, z;
    Orbit orbit;

   public:
    Satellite(const std::string& name, double x, double y, double z,
              double semi_major_axis, double eccentricity)
        : SpaceObject(name),
          x(x),
          y(y),
          z(z),
          orbit(semi_major_axis, eccentricity) {}

    auto set_position(double new_x, double new_y, double new_z) {
        x = new_x;
        y = new_y;
        z = new_z;
    }

    auto get_position() const -> std::tuple<double, double, double> {
        return std::make_tuple(x, y, z);
    }

    auto distance_to(const Satellite& other) const -> double {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    auto get_orbit() const -> const Orbit& { return orbit; }
};


void print_satellite_orbit(const Satellite& satellite) {

    const Orbit& orbit = satellite.get_orbit();

    std::cout << "'" <<satellite.get_name() << "'" << " orbit details: \n";
    std::cout << "  Semi-major axis: " << orbit.get_semi_major_axis() << std::endl;
    std::cout << "  Eccentricity: " << orbit.get_eccentricity() << std::endl;
    std::cout << std::endl;  
}

int main() {
    try {

        // Create two satellites with descriptive names for clarity
        Satellite satellite1(
            "Explorer One", 1000.0, 2000.0, 3000.0, 6778.0, 0.01);
        
        Satellite satellite2(
            "Hubble", 5000.0, 7000.0, 9000.0, 6950.0, 0.002);

        // Calculate distance between satellites
        double distance = satellite1.distance_to(satellite2);
        std::cout << "Distance between satellites: " << distance << std::endl;

        print_satellite_orbit(satellite1);
        print_satellite_orbit(satellite2);

        return 0;
    } catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
