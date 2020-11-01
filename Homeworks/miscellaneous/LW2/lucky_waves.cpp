#include <iostream>
using namespace std;

/* Sameer Hussain - CSCE 121 - Labworks #2 - Jan 27, 2020 
    Lucky Waves
*/

int main() {
    int n, length_of_longest_wave = -1, count = 1;
    double num, last_wave_num;
    cin >> n;
    cin >> last_wave_num;
    for (n = n - 1; n > 0; n--){
        cin >> num;
        if (num > last_wave_num) {
            count++;
        } else {
            if (length_of_longest_wave < count) {
                length_of_longest_wave = count;
            }
            count = 1;
        }
        last_wave_num = num;
    }
    if (length_of_longest_wave < count) {
        length_of_longest_wave = count;
    }
    cout << length_of_longest_wave << endl;
}
