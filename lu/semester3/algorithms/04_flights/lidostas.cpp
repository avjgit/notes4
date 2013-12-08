// Andrejs Jurcenoks aj05044 DSuPII PD3
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/04_flights/lidostas.cpp
#include <fstream>
using namespace std;
struct flight{
    int arrival_airport;
    int departure_time;     // _time - for easier comparison
    int departure_HH;       // _H - for easier output
    int departure_MM;
    int arrival_time;
    int arrival_HH;
    int arrival_MM;
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
    flight** airports = new flight* [airports_count + 1];
    for(int i = 0; i < (airports_count+1); i++) airports[i] = NULL;

    ///////////////////////////////// reading flights data
    flight *f;
    while(true){
        fscanf(in, "%d", &departure_airport);
        if (departure_airport == 0) {break;} // end of data marked with 0
        fscanf(in, "%d %d", &arrival_airport, &flights);

        // read flight timings, like "12:20-13:47"
        for (int i = 1; i <= flights; i++){

            // first, creating structure to store flights
            f = new flight;
            f->arrival_airport = arrival_airport;
            f->used = false;
            f->other_flight = NULL;

            fscanf(
                in,
                "%d:%d-%d:%d",
                &f->departure_HH,
                &f->departure_MM,
                &f->arrival_HH,
                &f->arrival_MM
            );

            // this format is easier for human reading - 18:20 is 1820, not 1100
            f->departure_time = f->departure_HH * 100 + f->departure_MM;
            f->arrival_time = f->arrival_HH * 100 + f->arrival_MM;

            // if this is first flight we read in
            if (airports[departure_airport] == NULL){
                airports[departure_airport] = f;
            }
            else{
                f->other_flight = airports[departure_airport];
                airports[departure_airport] = f;
            }
        }
    }

    ///////////////////////////////// searching for nearest non-used flight
    fprintf(out, "%d %02d:%02d\n", start_airport, start_HH, start_MM);

    arrival_time = start_HH*100 + start_MM;
    departure_airport = start_airport;
    f = airports[start_airport]; //flight to start to loop through

    flight* nearest = NULL;
    int time_till_departure;
    int nearest_departure_time = 2400;

    bool impossible = false;
    // until goal_found or no_more_flights:
    while(true){
        // loop through all airport's flights (until next flight == NULL)
        while(f != NULL){
            if(f->used == false){
                // unifying departure time (to correctly compare next day's time)
                if(f->departure_time > arrival_time){
                    time_till_departure = f->departure_time - arrival_time;
                }
                else{
                    time_till_departure = 2400 - arrival_time + f->departure_time;
                }
                // finding flight with minimal time to wait
                if(time_till_departure < nearest_departure_time){
                    nearest_departure_time = time_till_departure;
                    nearest = f;
                }
            }
            f = f->other_flight;
        }

        // if all are used - exit, no more flights
        if(nearest == NULL){
            impossible = true;
            break;
        }
        // printing flight data
        fprintf(
            out,
            "%d->%d %02d:%02d-%02d:%02d\n",
            departure_airport,
            nearest->arrival_airport,
            nearest->departure_HH,
            nearest->departure_MM,
            nearest->arrival_HH,
            nearest->arrival_MM
        );

        if (nearest->arrival_airport == target_airport)
            break; //if target airport reached

        // setting for next flight
        arrival_time = nearest->arrival_time;
        departure_airport = nearest->arrival_airport;
        f = airports[departure_airport];
        nearest->used = true;
        nearest = NULL;
        nearest_departure_time = 2400;
    }

    if(impossible){
        fclose(out);
        out = fopen("lidostas.out", "w");
        fprintf(out, "%s\n", "Impossible");
    }

    fclose(in);
    fclose(out);

    return 0;
}