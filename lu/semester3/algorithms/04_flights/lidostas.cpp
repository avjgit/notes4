// Andrejs Jurcenoks
// aj05044
// Datu strukturas un pamatalgoritmi II
// PD3 Lidostas
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/04_flights/lidostas.cpp
#include <fstream>
#include <sstream>
using namespace std;

struct flight{int airport, time;};

int main(){
    // for 2d flights array, for columns (as departure times)
    const int DAY_HOURS = 24;
    const int HOUR_MINUTES = 60;
    const int DAY_MINUTES = DAY_HOURS * DAY_MINUTES;
    // cout << DAY_MINUTES;
    int airports, arrival_airport, target_airport;
    int flights, arrival_time, departur_time;
    string flight_line;

    ifstream in("lidostas.in");
    ofstream out("lidostas.out");

    in >> airports;
    in >> arrival_airport;
    in >> target_airport;

    out << "ok, there are " << airports << " airports.";
    out << "we need to get from " << arrival_airport << " to " << target_airport;

    // while (getline(in, line)){
        // istringstream linestream(flight_line);
//
    // }

    return 0;
}
