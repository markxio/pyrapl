#include <sys/time.h>
#include <cstdlib>
#include <stdio.h>
#include <cstring>

extern "C" {

long get_epoch() {
    struct timeval tm;
    gettimeofday(&tm, NULL);
    return (tm.tv_sec * 1000000) + tm.tv_usec;
}

double get_timing(long end_time, long start_time) {
    return (end_time - start_time) / 1.0e3;
}

double get_joules_rapl() {
    const char* rapl_base_path = "/sys/class/powercap/intel-rapl/intel-rapl:";
    int packages = 2;
    const char* energy = "/energy_uj";
    char str[20];
    long long joules = 0;

    for (int i = 0; i < packages; i++) {
        sprintf(str, "%d", i);
        char path[100];
        strcpy(path, rapl_base_path);
        strcat(path, str);
        strcat(path, energy);

        FILE *file = fopen(path, "r");
        if (file != NULL) {
            char line[100];
            while (fgets(line, sizeof line, file) != NULL) {
                joules += atoll(line);
            }
            fclose(file);
        } else {
            perror(path);
        }
    }

    return static_cast<double>(joules) / 1000000.0;
}

}

