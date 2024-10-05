#include <stdio.h>


float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
void categorize_temperature(float celsius);
void print_temp(float temp, int scale);


int main() {
	int user_scale;
	int convert_scale;
	float user_temp;
	float new_temp;
	int i = 1;
	//if invalid input is entered, program repeats until vaild input is entered
	while (i = 1){
		printf("Enter the temperature value: ");
		scanf(" %f", &user_temp);
		printf("Choose the temperature scale (Celsius=1, Fahrenheit=2, Kelvin=3): ");
		scanf(" %d", &user_scale);
		printf("Choose the conversion target (Celsius=1, Fahrenheit=2, Kelvin=3): ");
		scanf(" %d", &convert_scale);
		//converts to C
		if (convert_scale == 1) {
			if (user_scale == 2){
				new_temp = fahrenheit_to_celsius(user_temp);
				print_temp(new_temp, 1);
				categorize_temperature(new_temp);
				return 0;
			} else if (user_scale == 3 && user_temp > 0){
				new_temp = kelvin_to_celsius(user_temp);
				print_temp(new_temp, 1);
				categorize_temperature(new_temp);
				return 0;
			} else {
				printf("Invalid input.\n");
			}
		//converts to F
		} else if (convert_scale == 2) {
			if (user_scale == 1){
				new_temp = celsius_to_fahrenheit(user_temp);
				print_temp(new_temp, 2);
				categorize_temperature(user_temp);
				return 0;
			} else if (user_scale ==3 && user_temp > 0) {
				float i = kelvin_to_celsius(user_temp);
				new_temp = celsius_to_fahrenheit(new_temp);
				print_temp(new_temp, 2);
				categorize_temperature(i);	
				return 0;
			} else {
				printf("Invalid input.\n");

			}
		//Converts to K
		} else if (convert_scale == 3) {
			if (user_scale == 1){
				new_temp = celsius_to_kelvin(user_temp);
				print_temp(new_temp, 3);
				categorize_temperature(user_temp);
				return 0;
			} else if (user_scale == 2) {
				float i = fahrenheit_to_celsius(user_temp);
				new_temp = celsius_to_kelvin(i);
				print_temp(new_temp, 3);
				categorize_temperature(i);	
				return 0;
			} else {
				printf("Invalid input.\n");

			}
		}
	}

}


float celsius_to_fahrenheit(float celsius){
	return (9.0/5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit){
	return (5.0/9.0) * (fahrenheit - 32);
}
float celsius_to_kelvin(float celsius){
	return celsius + 273.15;
}
float kelvin_to_celsius(float kelvin){
	return kelvin - 273.15;
}
void categorize_temperature(float celsius){
	//Categorizes the current temp based on the Celsius, including edge cases
	if (celsius < -34) {
		printf("Temperature category: Deathly freezing!\nWeather advisory: Get inside or you may freeze to death!\n");
	} else if (celsius <= 0) {
		printf("Temperature category: Freezing\nWeather advisory: Put on a winter coat\n");
	} else if (celsius <= 10) {
		printf("Temperature category: Cold\nWeather advisory: Put on a jacket\n");
	} else if (celsius <= 25) {
		printf("Temperature category: Comfortable\nWeather advisory: Enjoy the temperate weather\n");
	} else if (celsius <= 35) {
		printf("Temperature category: Hot\nWeather advisory: Put on sunscreen before going out\n");
	} else if (celsius >= 52) {
		printf("Temperature category: Deathly hot!\nWeather advisory: Stay inside and crank up the AC\n");
	} else {
		printf("Temperature category: Extreme heat\nWeather advisory: Drink water and reapply sunscreen often\n");
	}
}
void print_temp(float temp, int scale){
	//Prints the converted temperature
	if (scale == 1){
		printf("Converted temperature: %f degrees C\n", temp);	
	} else if (scale == 2) {
		printf("Converted temperature: %f degrees F\n", temp);
	} else {
		printf("Converted temperature: %f degrees K\n", temp);
	}
}

