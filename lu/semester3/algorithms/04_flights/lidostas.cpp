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
    flight* other_flight;
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
    // ne; var lietot sarakstu, bet nakamsi bus nevis "next", but vnk "other"
    // un bus jaizvelas tuvakais - jasalidzina ielidosanas laiks ar izlidosanas,
    // pie tam no pieejamiem
    // un jaizvelas mazakais
    for(int i = 0; i < 9; i++){
    // while(true){
        fscanf(in, "%d", &departure_airport);
        if (departure_airport == 0)
            break;
        fscanf(
            in,
            "%d %d %d:%d-%d:%d\n",
            &arrival_airport,
            &flights,
            &departure_HH,
            &departure_MM,
            &arrival_HH,
            &arrival_MM
        );
        fprintf(
            out,
            "flight %i: %i %i %i %i:%i-%i:%i\n",
            i,
            departure_airport,
            arrival_airport,
            flights,
            departure_HH,
            departure_MM,
            arrival_HH,
            arrival_MM
        );
    }

    return 0;
}
