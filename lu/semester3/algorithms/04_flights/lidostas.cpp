// Andrejs Jurcenoks aj05044 DSuPII PD3
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/04_flights_count/lidostas.cpp
#include <fstream>
using namespace std;
struct flight{
    int departure_airport;
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

int time_formatted(int HH, int MM){
    return HH * 100 + MM;
}

int time_between(flight* arrival, flight* departure){
    const int WHOLE_DAY = 2400;
    if(departure->departure_time > arrival->arrival_time)
        return departure->departure_time - arrival->arrival_time;
    else
        return WHOLE_DAY - arrival->arrival_time + departure->departure_time;
}

void print_flight(FILE* out, flight* f){
    fprintf(
        out,
        "%d->%d %02d:%02d-%02d:%02d\n",
        f->departure_airport,
        f->arrival_airport,
        f->departure_HH,
        f->departure_MM,
        f->arrival_HH,
        f->arrival_MM
    );
}

void read_flight(FILE* in, flight* f){
    fscanf(
        in,
        "%d:%d-%d:%d",
        &f->departure_HH,
        &f->departure_MM,
        &f->arrival_HH,
        &f->arrival_MM
    );
}

int main(){
    FILE* in = fopen("lidostas.in", "r");
    FILE* out = fopen("lidostas.out", "w+");

    ///////////////////////////////// reading main data
    int airports_count, start_airport, target_airport, start_HH, start_MM;
    fscanf  (in, "%i", &airports_count);
    fscanf  (in, "%i", &start_airport);
    fscanf  (in, "%i", &target_airport);
    fscanf  (in, "%i:%i", &start_HH, &start_MM);

    // [n+1] - just for easier reference in later ([n], not [n-1])
    // array of pointers to list of flights_count for each airport
    flight** airports = new flight* [airports_count + 1];
    for(int i = 0; i < (airports_count+1); i++) airports[i] = NULL;

    ///////////////////////////////// reading flights_count data
    flight *f;
    int departure_airport, arrival_airport, flights_count;
    while(true){

        fscanf(in, "%d", &departure_airport);
        if (departure_airport == 0) break; // end of data marked with 0

        fscanf(in, "%d %d", &arrival_airport, &flights_count);

        // read flight timings, like "12:20-13:47"
        for (int i = 1; i <= flights_count; i++){

            // first, creating structure to store flights_count
            f = new flight;
            f->departure_airport = departure_airport;
            f->arrival_airport = arrival_airport;
            f->used = false;
            f->other_flight = NULL;

            read_flight(in, f);

            // this format is easier for human reading - 18:20 is 1820, not 1100
            f->departure_time   = time_formatted(f->departure_HH, f->departure_MM);
            f->arrival_time     = time_formatted(f->arrival_HH, f->arrival_MM);

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

    flight* arrival = new flight;
    arrival->arrival_time = time_formatted(start_HH, start_MM);
    arrival->arrival_airport = start_airport;

    flight* nearest;
    const int WHOLE_DAY = 2400;
    int time_till_departure, min_time_till_departure;
    bool impossible = false;
    // until goal reached or there are no more flights:
    while(true){
        // setup
        nearest = NULL;
        min_time_till_departure = WHOLE_DAY;
        f = airports[arrival->arrival_airport];

        // loop through all airport's flights_count (until next flight == NULL)
        while(f != NULL){
            if(!f->used){
                // unifying departure time (to correctly compare next day's time)
                // if(f->departure_time > arrival->arrival_time){
                //     time_till_departure = f->departure_time - arrival->arrival_time;
                // }
                // else{
                //     time_till_departure = WHOLE_DAY - arrival->arrival_time + f->departure_time;
                // }
                time_till_departure = time_between(arrival, f);

                // finding flight with minimal time to wait
                if(time_till_departure < min_time_till_departure){
                    min_time_till_departure = time_till_departure;
                    nearest = f;
                }

            }
            f = f->other_flight;
        }

        // if all are used - exit, no more flights_count
        if(nearest == NULL){
            impossible = true;
            break;
        }

        print_flight(out, nearest);

        if (nearest->arrival_airport == target_airport)
            break; //if target airport reached

        // flying out with nearest flight
        arrival = nearest;
        nearest->used = true;
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