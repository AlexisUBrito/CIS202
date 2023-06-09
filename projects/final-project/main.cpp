#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Mountain {

private:
    string mounName;
    string country;
    double elevation;

public:
    // --------the constructor----------
    Mountain(const string& Name, const string& Country, double Elevation){
        this->mounName = Name;
        this->country = Country;
        this->elevation = Elevation;
    }
    
    // ----------the Getters-----------
    string getNa() const {
        return mounName;
    }
    
    string getCo() const {
        return country;
    } 

    double getElv() const {
        return elevation;
    }

    // ---------the Setters----------------
    void setNa(const string& Name){
        this->mounName = Name;
    }

    void setCo(const string& Country){
        this->country = Country;
    }

    void setEl(double Elevation){
        this->elevation = Elevation;
    }
    
    double toMeters() const {
        return elevation / 3.2808;
    }
};

Mountain findMin(const vector<Mountain>& mountains) {
    
    Mountain smallest = mountains[0];

    for (const Mountain& mountain : mountains) {

        if (mountain.getElv() < smallest.getElv()) {
            smallest = mountain;
        }
    }
    return smallest;
}

int main() {
// Mountain Info
    vector<Mountain> info;
    

    info.push_back(Mountain("Chimborazo","Ecuador",20549));
    info.push_back(Mountain("Matterhorn", "Switzerland", 14692));
    info.push_back(Mountain("Olympus", "Greece (Macedonia)", 9573));
    info.push_back(Mountain("Everest", "Nepal", 29029));
    info.push_back(Mountain("Mount Marcy - Adirondacks", "United States", 5344));
    info.push_back(Mountain("Mount Mitchell - Blue Ridge", "United States", 6684));
    info.push_back(Mountain("Zugspitze", "Switzerland", 9719));
    
    // Title
    cout << left << setw(30) << "Mountain" << setw(25) << "Country" << setw(18) << "Elevation (ft)" << "Elevation (m)" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    
    // Table
    for (const Mountain& mountain : info) {
        cout << left << setw(30) << mountain.getNa() << setw(25) << mountain.getCo() << setw(18) << mountain.getElv() << mountain.toMeters() << endl;
    }

    Mountain min = findMin(info);

    cout << endl;
    cout<< min.getNa() << " is the smallest mountain in the list with a Elevation of " << min.getElv() << " ft." << endl;

    return 0;
}