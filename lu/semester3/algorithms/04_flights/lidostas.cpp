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

    //////////////////////////////////////////////////// reading main data
    fscanf  (in, "%i", &airports_count);
    fscanf  (in, "%i", &start_airport);
    fscanf  (in, "%i", &target_airport);
    fscanf  (in, "%i:%i", &start_HH, &start_MM);
    // "+1" - just for easier reference in later ([n], not [n-1])
    flight* airports[airports_count + 1];

    //////////////////////////////////////////////////// reading flights data
    flight *f, *last_flight;
    while(true){
        fscanf(in, "%d", &departure_airport);
        // stop if 0
        if (departure_airport == 0)
            break;

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


            // todo: hey, what about flights to other airports?

            if (airports[departure_airport] == NULL){
                airports[departure_airport] = f;
                last_flight = f;
            }
            else{
                last_flight->other_flight = f;
                last_flight = f;
            }
        }

        f = airports[start_airport];
        arrival_time = arrival_HH*100 + arrival_MM;
        flight* nearest = NULL;
        int departure_time, nearest_time;

        // searching for nearest available flight
        while(true){
            if (!f->used){
                if(f->departure_time > arrival_time){
                    departure_time = f->departure_time;
                }
                else{
                    departure_time = f->departure_time + (2400 - arrival_time);
                }

                if (nearest == NULL){
                    nearest = f;
                    nearest_time = f->departure_time;
                }

                if (departure_time < nearest_time){
                    nearest_time = departure_time;
                    nearest = f;
                }
            }
            else{
                if(f->other_flight == NULL){
                    // todo: no flight avaiable; output Impossible
                    break;
                }
                else{
                    f = f->other_flight;
                }
            }
        }
        nearest->used = true;

        if(nearest->arrival_airport = target_airport){
            // todo: print to file
            break;
        }

        f = airports[nearest->arrival_airport];

        // fprintf(
        //     out,
        //     "flight %d: %d %d %d %02d:%02d-%02d:%02d\n",
        //     i,
        //     departure_airport,
        //     arrival_airport,
        //     flights,
        //     departure_HH,
        //     departure_MM,
        //     arrival_HH,
        //     arrival_MM
        // );
    }

    // fclose(out);
    // out = fopen("lidostas.out", "w");
    // fprintf(out, "%s\n", "Impossible");

    // fclose(in);
    // fclose(out);

    return 0;
}