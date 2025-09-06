#include <iostream>
#include <vector>
#include <stdint.h>

#include <map>
#include <unordered_map>

struct CityRecord
{
    std::string Name;
    uint64_t Population;
    double Area;
    double Latitude, Longitude;

    bool operator==(const CityRecord &other) const
    {
        return Name == other.Name &&
               Population == other.Population &&
               Area == other.Area &&
               Latitude == other.Latitude &&
               Longitude == other.Longitude;
    }
};

namespace std
{
    template <>
    struct hash<CityRecord>
    {
        size_t operator()(const CityRecord &key) const
        {
            return hash<std::string>()(key.Name);
        }
    };
}

int main()
{
    std::map<std::string, CityRecord> citiesMap;
    std::unordered_map<CityRecord, uint32_t> foundedMap;

    citiesMap["Berlin"] = CityRecord{"Berlin", 3500000, 800, 45, 15};
    foundedMap[citiesMap["Berlin"]] = 1200;
    citiesMap["Paris"] = CityRecord{"Paris", 2000000, 100, 40, 10};
    citiesMap["Shanghai"] = CityRecord{"Shanghai", 24000000, 2000, 45, 85};

    const auto &cities = citiesMap;
    if (cities.find("Berlin") != cities.end())
    {
        const CityRecord &berlinData = cities.at("Berlin");
    }

    for (auto &[name, city] : citiesMap)
    {
        std::cout << name << "\n Population:" << city.Population << "\n Area:" << city.Area << std::endl;
    }

    CityRecord &berlinData = citiesMap["Berlin"];
    std::cout << berlinData.Name << std::endl;
    return 0;
}