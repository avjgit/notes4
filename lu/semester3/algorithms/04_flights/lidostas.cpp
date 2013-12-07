// Andrejs Jurcenoks// aj05044// Datu strukturas un pamatalgoritmi II// PD3 Lidostas// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/04_flights/lidostas.cpp
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
struct flight{
    int arrival_airport;
    int departure_time;
    int arrival_time;
    bool used;
    flight* other_flight;
};
int main(){
    int airports_count, start_airport, arrival_airport, departure_airport, target_airport;
    int flights, arrival_time, departure_time;
    int start_HH, start_MM;
    int arrival_HH, arrival_MM;
    int departure_HH, departure_MM;
    string flight_line;

    FILE* in = fopen("lidostas.in", "r");
    FILE* out = fopen("lidostas.out", "w+");

    ///////////////////////////////// reading main data
    fscanf  (in, "%i", &airports_count);
    fscanf  (in, "%i", &start_airport);
    fscanf  (in, "%i", &target_airport);
    fscanf  (in, "%i:%i", &start_HH, &start_MM);
    // "+1" - just for easier reference in later ([n], not [n-1])
    //initializes array elements to null
    flight** airports = new flight* [airports_count + 1];

    ///////////////////////////////// reading flights data
    flight *f, *last_flight;
    while(true){
        fscanf(in, "%d", &departure_airport);
        if (departure_airport == 0) {break;}
        fscanf(in, "%d %d", &arrival_airport, &flights);

        for (int i = 1; i <= flights; i++){

            // read flight timings, like "12:20-13:47"
            fscanf(
                in,
                "%d:%d-%d:%d",
                &departure_HH,
                &departure_MM,
                &arrival_HH,
                &arrival_MM
            );

            // store them in structure
            f = new flight;
            f->arrival_airport = arrival_airport;
            // todo: fix correct time; this is just to quick check of idea
            f->departure_time = departure_HH * 100 + departure_MM;
            f->arrival_time = arrival_HH * 100 + arrival_MM;
            f->used = false;
            f->other_flight = NULL;


            // todo: hey, what about flights to other airports?

            // if this is first flight we read in
            if (i == 1){
                airports[departure_airport] = f;
                last_flight = f;
                fprintf(out, "%s\n", "ok, first time");
            }
            else{
                last_flight->other_flight = f;
                last_flight = f;
            }
        }
    }

    ///////////////////////////////// searching for nearest non-used flight
    f = airports[start_airport]; //flight to start to loop through
    arrival_time = arrival_HH*100 + arrival_MM;
    flight* nearest = 0;
    flight* nullptr = NULL;

    int current_departure_time;
    int nearest_departure_time = 2400;

    // until goal_found or no_more_flights:
    bool found = false;
    bool stuck = false;
    // while(!found && !stuck){
    for(int i = 0; i < 10; i++){
    //     select nearest non-used flight from departure_airport
        while(f != NULL){
            printf("%s %d\n", "checking flight to ", f->arrival_airport);
            if(f->used == false){
                // printf("%s %d\n", "checking flight to ", f->arrival_airport);
                if(f->departure_time < nearest_departure_time){
                    nearest_departure_time = f->departure_time;
                    nearest = f;
                }
            }
            f = f->other_flight;
        }

    //     if all are used - no "nearest non-used" found
        if(nearest == NULL)
            break; // no more flights

        if (nearest->arrival_airport == target_airport)
            break; //found

        f = airports[nearest->arrival_airport];
        arrival_time = nearest->arrival_time;
        nearest->used = true;
        nearest = NULL;
    }

    // searching for nearest available flight
    // while(true){
    //     if (!f->used){
    //         // unifing departure time, to correctly compare with next day's departures
    //         if(f->departure_time > arrival_time){
    //             departure_time = f->departure_time;
    //         }
    //         else{
    //             departure_time = f->departure_time + (2400 - arrival_time);
    //         }

    //         if (departure_time < nearest_departure_time){
    //             nearest_departure_time = departure_time;
    //             nearest = f;
    //         }
    //     }

    //     if(f->other_flight == NULL){
    //         if (nearest == NULL)
    //             // todo: no flight avaiable; output Impossible
    //             break;
    //     }

    //     f = f->other_flight;

    //     nearest->used = true;

    //     if(nearest->arrival_airport = target_airport){
    //         // todo: print to file
    //         printf("%s\n", "found!");
    //         break;
    //     // }

    // f = airports[nearest->arrival_airport];


    // }

    return 0;
}