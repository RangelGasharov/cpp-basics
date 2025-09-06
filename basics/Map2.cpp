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
};

namespace std
{
    template <>
    struct hash<CityRecord>
    {
        size_t operator()(const CityRecord &key)
        {
            return hash<std::string>()(key.Name);
        }
    }
};

int main()
{
    std::map<std::string, CityRecord> citiesMap;
    std::unordered_map<CityRecord, uint32_t> foundedMap;

    citiesMap["Berlin"] = CityRecord{"Berlin", 3500000, 800, 45, 15};
    foundedMap[citiesMap["Berlin"]] = 1200;
    citiesMap["Paris"] = CityRecord{"Paris", 2000000, 100, 40, 10};
    citiesMap["Shanghai"] = CityRecord{"Shanghai", 24000000, 2000, 45, 85};

    CityRecord &berlinData = citiesMap["Berlin"];
    std::cout << berlinData.Name << std::endl;
    return 0;
}