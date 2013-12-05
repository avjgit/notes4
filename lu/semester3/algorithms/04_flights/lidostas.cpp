// Andrejs Jurcenoks// aj05044// Datu strukturas un pamatalgoritmi II// PD3 Lidostas// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/04_flights/lidostas.cpp
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
struct flight{
    int departure_time;
    int arrival_airport;
    itn arrival_time;
    flight* next_flight;
    bool used;
};

int main(){
    // for 2d flights array, for columns (as departure times)
    const int DAY_HOURS = 24;
    const int HOUR_MINUTES = 60;
    const int DAY_MINUTES = DAY_HOURS * DAY_MINUTES;
    const int END_OF_INPUT = 0;
    const char MM_SEPARATOR = ':';
    const char TIME_SEPARATOR = '-';

    // cout << DAY_MINUTES;
    int airports, start_airport, arrival_airport, departure_airport, target_airport;
    int flights, arrival_time, departure_time;
    int start_HH, start_MM;
    int arrival_HH, arrival_MM;
    int departure_HH, departure_MM;
    string flight_line;



    // ifstream in("lidostas.in");
    // ofstream out("lidostas.out");

    // in >> airports;
    // in >> start_airport;
    // in >> target_airport;

    // out << "ok, there are " << airports << " airports.";
    // out << "we need to get from " << start_airport << " to " << target_airport << "\n";


    FILE* in = fopen("lidostas.in", "r");
    FILE* out = fopen("lidostas.out", "w+");
    fscanf  (in, "%i", &airports);
    fprintf (out, "%i", airports);

    fscanf  (in, "%i", &start_airport);
    fscanf  (in, "%i", &target_airport);

    fprintf (out, "%i", start_airport);
    fprintf (out, "%i", target_airport);


    fscanf  (in, "%i:%i", &start_HH, &start_MM);
    // fscanf  (in, "%i", &start_MM);

    fprintf (out, "%i", start_HH);
    fprintf (out, "%i", start_MM);


    fscanf  (in, "%i", &departure_airport);
    fscanf  (in, "%i", &arrival_airport);

    fprintf (out, " from %i", departure_airport);
    fprintf (out, " to %i", arrival_airport);
// int x;

//     in >> departure_airport;
//     in >> x;
//     out << "we arriving at ";
//     out << std::setw(2) << std::setfill('0') << departure_airport;
//     out << ":";
//     out << std::setw(2) << std::setfill('0') << x;
    // while(true){
        // in >> start_MM;
        // if (departure_airport == END_OF_INPUT)
            // break;
        // in >> start_HH;
        // in >> flights;
        // in >> departure_HH;
        // in >> departure_MM;
        // in >> arrival_HH;
        // in >> arrival_MM;
    // }
    // out << "ok";
        // out << "\n" << start_MM ;
        // out << start_HH << "\n";
        // out << flights << "\n";
        // out << departure_HH << ":";
        // out << departure_MM << "-";
        // out << arrival_HH << ":";
        // out << arrival_MM;





    // while (getline(in, line)){
        // istringstream linestream(flight_line);
//
    // }

    return 0;
}
