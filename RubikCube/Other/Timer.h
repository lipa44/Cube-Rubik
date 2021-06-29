#ifndef RUBIKCUBE_TIMER_H
#define RUBIKCUBE_TIMER_H


// Class which is evaluating the time of cube solving (for large amount of cubes)
class Timer {
public:

    Timer() {
        start = chrono::high_resolution_clock::now();
        cout << endl;
    }

    ~Timer() {
        end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;

        int durationMinutes = (int) duration.count() / 60;
        int durationSeconds = (int) ((duration.count() / 60) * ((float) 6 / 10) * 100 - 3) % 60;
        string resultDuration = "";
        if (durationMinutes != 0)
            resultDuration += to_string(durationMinutes) + " min. ";

        cout << "\n\nDuration of solving: " << resultDuration << setprecision(0) << durationSeconds << " sec.";
    }

private:
    chrono::time_point<chrono::steady_clock> start, end;
};


#endif //RUBIKCUBE_TIMER_H
