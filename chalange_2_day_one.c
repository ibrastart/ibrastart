#include <stdio.h>
#include <stdio.h>

int main() 
{
    float temp_celsius, temp_kelvin;
    float distance_km, distance_yards;
    printf("Entrez la température en Celsius : ");
    scanf("%f", &temp_celsius);
    temp_kelvin = temp_celsius + 273.15;
    printf("La température en Kelvin est : %.2f K\n", temp_kelvin);
    printf("Entrez une distance en kilomètres : ");
    scanf("%f", &distance_km);
    distance_yards = distance_km * 1093.61;
    printf("La distance en yards est : %.2f yards\n", distance_yards);

    return 0;
}
// Écrivez un programme qui demande la température en Celsius et la transforme en Kelvin. Formule  
//Yards = Km * 1093.61