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

    fprintf (out, "%i\n", airports);
    fprintf (out, "%i\n", start_airport);
    fprintf (out, "%i\n", target_airport);
    fprintf (out, "%02i:%02i", start_HH, start_MM);

    // flights data
    fscanf  (in, "%i %i %i", &departure_airport, &arrival_airport, &flights);

    fprintf (out, " from %i", departure_airport);
    fprintf (out, " to %i", arrival_airport);
    fprintf (out, " there will be %i flights", flights);


    return 0;
}
