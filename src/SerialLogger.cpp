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
	serial->begin(baud);
	return true;
}

/// @brief Writes a char to the serial output
/// @param c The char to write
/// @return True on success
bool SerialLogger::receiveChar(char c) {
	serial->print(c);
	return true;
}

/// @brief Write a string to the serial output
/// @param message The string to write
/// @return True on success
bool SerialLogger::receiveMessage(String message) {
	serial->print(message);
	return true;
}