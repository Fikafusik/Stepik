
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Country {
    char name[30];
    unsigned int population;
    char capital[30];
} Country;

Country * countries;

int compare(const void * country1, const void * country2) {
    Country * c1 = (Country *)country1;
    Country * c2 = (Country *)country2;
    char p1[sizeof(unsigned int) + 42];  
    char p2[sizeof(unsigned int) + 42];
    sprintf(p1, "%u", c1->population);
    sprintf(p2, "%u", c2->population);
    int compareName = strcmp(c1->name, c2->name);
    int comparePopu = strcmp(p1, p2);
    return (compareName == 0 ? comparePopu : compareName);
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