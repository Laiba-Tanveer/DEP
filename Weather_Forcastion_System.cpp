#include <iostream>
#include <vector>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <fstream>
using namespace std;
using json = nlohmann::json;
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
class Location {
public:
    string name;
    double latitude, longitude;
    Location(string n, double lat, double lon) : name(n), latitude(lat), longitude(lon) {}
    void display() {
        cout << "Location: " << name << ", Latitude: " << latitude << ", Longitude: " << longitude << endl;
    }
};
class WeatherVariable {
public:
    double temperature, windSpeed, humidity;
    WeatherVariable(double temp, double wind, double hum) 
        : temperature(temp), windSpeed(wind), humidity(hum) {}
    void display() {
        cout << "Temperature: " << temperature << " °C, Wind Speed: " << windSpeed << " km/h, Humidity: " << humidity << "%" << endl;
    }
};
class WeatherForecastingSystem {
public:
    void fetchWeatherData(string location) {
        CURL* curl;
        CURLcode res;
        string readBuffer;
        string apiKey = "your_api_key";  
        string url = "http://api.openweathermap.org/data/2.5/weather?q=" + location + "&appid=" + apiKey + "&units=metric";
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            } else {
                json weatherData = json::parse(readBuffer);
                displayWeather(weatherData);
            }
            curl_easy_cleanup(curl);
        }
    }
    void displayWeather(const json& data) {
        double temp = data["main"]["temp"];
        double windSpeed = data["wind"]["speed"];
        double humidity = data["main"]["humidity"];
        cout << "Current Weather:\n";
        cout << "Temperature: " << temp << " °C\n";
        cout << "Wind Speed: " << windSpeed << " km/h\n";
        cout << "Humidity: " << humidity << " %\n";
    }
};
class DataExporter {
public:
    void exportToCSV(double temperature, double windSpeed, double humidity) {
        ofstream file("weather.csv");
        file << "Temperature,Wind Speed,Humidity\n";
        file << temperature << "," << windSpeed << "," << humidity << "\n";
        file.close();
    }
    void exportToJSON(double temperature, double windSpeed, double humidity) {
        json j;
        j["Temperature"] = temperature;
        j["Wind Speed"] = windSpeed;
        j["Humidity"] = humidity;
        ofstream file("weather.json");
        file << j.dump(4);
        file.close();
    }
};
class LocationManager {
private:
    vector<Location> locations;
public:
    void addLocation(string name, double lat, double lon) {
        locations.push_back(Location(name, lat, lon));
    }
    void listLocations() {
        for (const auto& loc : locations) {
            loc.display();
        }
    }
};
int main() {
    WeatherForecastingSystem weatherSystem;
    DataExporter dataExporter;
    LocationManager locationManager;
    int choice;
    do {
        cout << "\n--- Weather App Menu ---\n";
        cout << "1. Add Location\n";
        cout << "2. List Locations\n";
        cout << "3. Fetch and Display Weather Data\n";
        cout << "4. Export Data (CSV and JSON)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name;
                double lat, lon;
                cout << "Enter location name: ";
                cin >> name;
                cout << "Enter latitude: ";
                cin >> lat;
                cout << "Enter longitude: ";
                cin >> lon;
                locationManager.addLocation(name, lat, lon);
                break;
            }
            case 2: {
                locationManager.listLocations();
                break;
            }
            case 3: {
                string location;
                cout << "Enter location name: ";
                cin >> location;
                weatherSystem.fetchWeatherData(location);
                break;
            }
            case 4: {
                double temp, windSpeed, humidity;
                cout << "Enter temperature: ";
                cin >> temp;
                cout << "Enter wind speed: ";
                cin >> windSpeed;
                cout << "Enter humidity: ";
                cin >> humidity;
                dataExporter.exportToCSV(temp, windSpeed, humidity);
                dataExporter.exportToJSON(temp, windSpeed, humidity);
                cout << "Data exported to weather.csv and weather.json\n";
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);
    return 0;
}
