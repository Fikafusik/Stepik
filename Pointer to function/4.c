
#include <stdio.h>
#include <stdlib.h>

typedef struct Country {
    char name[30];
    unsigned int population;
    char capital[30];
} Country;

Country * countries;

int compare(const void * country1, const void * country2) {
    return ((*(Country *)country1).population - (*(Country *)country2).population);
}

int main() {
    size_t countriesCount;
    scanf("%zd", &countriesCount);
    countries = (Country *)malloc(countriesCount * sizeof(Country));
    int i;
    for (i = 0; i < countriesCount; ++i) {
        scanf("%s", countries[i].name);
        scanf("%u", &countries[i].population);
        scanf("%s", countries[i].capital);
    }

    qsort(countries, countriesCount, sizeof(Country), compare);
    for (i = 0; i < countriesCount; ++i)
        printf("%s %u %s ", countries[i].name, countries[i].population, countries[i].capital);
    
    return 0;
}