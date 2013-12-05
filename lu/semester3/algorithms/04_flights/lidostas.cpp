// Andrejs Jurcenoks// aj05044// Datu strukturas un pamatalgoritmi II// PD3 Lidostas// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/04_flights/lidostas.cpp
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
struct flight{
    int departure_time;
    int arrival_airport;
    int arrival_time;
    bool used;
    flight* next_flight;
};
int main(){
    int airports, start_airport, arrival_airport, departure_airport, target_airport;
    int flights, arrival_time, departure_time;
    int start_HH, start_MM;
    int arrival_HH, arrival_MM;
    int departure_HH, departure_MM;
    string flight_line;

    FILE* in = fopen("lidostas.in", "r");
    FILE* out = fopen("lidostas.out", "w+");
    // starting data
    fscanf  (in, "%i", &airports);
    fscanf  (in, "%i", &start_airport);
    fscanf  (in, "%i", &target_airport);
    fscanf  (in, "%i:%i", &start_HH, &start_MM);

    // 1d array of pointers to airports first flights
    // each flight then has flag, if USED, and pointer to next flight
    // bet - "Reisi var nebūt doti hronoloģiskā secībā"!
    // tad ... tomēr lietot 2d ar laikiem kolonnā?

    // flights data
    fscanf  (in, "%i %i %i", &departure_airport, &arrival_airport, &flights);

    return 0;
}
