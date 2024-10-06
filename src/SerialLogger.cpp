#include "SerialLogger.h"

/// @brief Creates a new serial logger
/// @param HWSerial Pointer to a hardware serial object to use
/// @param Baud The baud rate to use
SerialLogger::SerialLogger(HardwareSerial* HWSerial, int Baud) {
	serial = HWSerial;
	baud = Baud;
}

/// @brief Starts the serial logger
/// @return 
bool SerialLogger::begin() {
	Description.name = "Serial Logger";
	Description.version = "0.8";
	serial->begin(baud);
	return true;
}

/// @brief Writes a char to the serial output
/// @param message The char to write
/// @return True on success
bool SerialLogger::receiveMessage(char message) {
	serial->print(message);
	return true;
}

/// @brief Write a string to the serial output
/// @param message The string to write
/// @return True on success
bool SerialLogger::receiveMessage(String message) {
	serial->print(message);
	return true;
}