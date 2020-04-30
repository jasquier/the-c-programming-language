#include <stdio.h>

float convertFahrenheitToCelsius(float temperatureInFahrenheit);

/* print Fahrenheit-Celsius table; uses a helper function */
int main() {

    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, convertFahrenheitToCelsius(fahr));
    }
}

float convertFahrenheitToCelsius(float temperatureInFahrenheit) {
    return (5.0 / 9.0) * (temperatureInFahrenheit - 32);
}
