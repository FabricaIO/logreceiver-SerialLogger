#include "SerialLogger.h"

/// @brief Creates a new serial logger
/// @param HWSerial Pointer to a hardware serial object to use
/// @param Baud The baud rate to use
SerialLogger::SerialLogger(HardwareSerial* HWSerial, int Baud) {
	serial = HWSerial;
	baud = Baud;
}

/// @brief Creates a new serial logger
/// @param HWSerial Pointer to a hardware serial object to use
/// @param Baud The baud rate to use
SerialLogger::SerialLogger(USBCDC* HWSerial, int Baud) {
	usbcdc = HWSerial;
	baud = Baud;
	use_usb = true;
}

/// @brief Creates a new serial logger
/// @param HWSerial Pointer to a hardware serial object to use
/// @param Baud The baud rate to use
SerialLogger::SerialLogger(HWCDC* HWSerial, int Baud) {
	hwcdc = HWSerial;
	baud = Baud;
	use_hwcdc = true;
}

/// @brief Starts the serial logger
/// @return True on success
bool SerialLogger::begin() {
	Description.name = "Serial Logger";
	Description.version = "0.8";
	if (use_usb) {
		usbcdc->begin(baud);
	} else if (use_hwcdc) {
		hwcdc->begin(baud);
	} else {
		serial->begin(baud);
	}
	return true;
}

/// @brief Writes a char to the serial output
/// @param message The char to write
/// @return True on success
bool SerialLogger::receiveMessage(char message) {
	if (use_usb) {
		usbcdc->print(message);
	} else if (use_hwcdc) {
		hwcdc->print(message);
	} else {
		serial->print(message);
	}
	return true;
}

/// @brief Write a string to the serial output
/// @param message The string to write
/// @return True on success
bool SerialLogger::receiveMessage(String message) {
	if (use_usb) {
		usbcdc->print(message);
	} else if (use_hwcdc) {
		hwcdc->print(message);
	} else {
		serial->print(message);
	}
	return true;
}