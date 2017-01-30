#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>
using namespace std;

/// Function Prototypes
#pragma region Prototypes
void tick();
void openFile(string);
void closeFile();
#pragma endregion
/// Global Variables
#pragma region GLOBAL_VARIABLES
chrono::time_point<chrono::system_clock> start, stop;
bool stopwatch = true;
double timeElapsed;
const int secondModifier = 1000; ///seconds to ms
ofstream outfile;
#pragma endregion

void main() {
	tick(); // Starts stop watch

	tick(); // Stops stopwatch, also updates timeElapsed to timeElapsed in milliseconds
}

#pragma region define_Functions
void tick() {
	if (stopwatch) {
		start = chrono::system_clock::now();
	}
	else {
		stop = chrono::system_clock::now();
		timeElapsed = ((chrono::duration<double>(stop - start)).count()) * secondModifier;
	}
	stopwatch = !stopwatch;
}
void openFile(string file) {
	closeFile();
	outfile.open(file.c_str());
}
void closeFile() {
	if (outfile.is_open()) { outfile.close(); }
}
#pragma endregion
