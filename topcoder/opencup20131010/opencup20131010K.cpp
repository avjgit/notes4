#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile ("k.in");
    long length;
    int* profits = NULL;
    // MAIN ALGORITHM
    infile >> length;
    profits = new int[length-1];

    int first_positive = -1;
    int last_positive = -1;
    int dayprofit;

    for(int i = 0; i < length; i++){
        infile >> dayprofit;
        profits[i] = dayprofit;

        if (first_positive < 0 && dayprofit >= 0){
            first_positive = i;
        }
        if (dayprofit >= 0){
            last_positive = i;
        }
    }

    // cout << "1st positive is " << first_positive;
    // cout << "last positive is " << last_positive;

    long max_sum = profits[first_positive];
    long check_sum= 0;
    int day_buy, day_sell;

    int check_start = first_positive;
    int next_start = 0;
    bool restart_loop = false;
    bool save_next_start = true;

    for(int i = check_start; i <= last_positive; i++){
        // cout << "i is " << i << endl;
        if(profits[i] > 0)
        {
            cout << " checking from " << check_start << " till " << i << endl;

            if(i != check_start && save_next_start){
                next_start = i;
                save_next_start = false;
                cout << "next start: " << next_start << endl;
            }

            for(int k = check_start; k <= i; k++){
                check_sum += profits[k];
            }
        //     if (check_sum > max_sum){
        //         day_buy = check_start+1;
        //         day_sell = i+1;
        //     }
        }
        if (i == last_positive && check_start != last_positive){
            cout << "now should be restarted" << endl;
            i = next_start;
            // save_next_start = true;
        }
        // else{
        //     restart_loop = false;
        // }
    }

    // cout << "day buy is " << day_buy;
    // cout << "day sell is " << day_sell;

    infile.close();
    return 0;
}