/*
* This file and associated .cpp file are licensed under the GPLv3 License Copyright (c) 2024 Sam Groveman
*
* Contributors: Sam Groveman
*/

#include <LogReceiver.h>

/// @brief Logs to the Arduino serial output
class SerialLogger : public LogReceiver {
	public:
		SerialLogger(HardwareSerial* HWSerial, int Baud = 115200);
		SerialLogger(USBCDC* HWSerial, int Baud = 115200);
		bool begin();
		bool receiveMessage(char message);
		bool receiveMessage(String message);
	protected:
		/// @brief Pointer to hardware serial to use
		HardwareSerial* serial;

		/// @brief Pointer to the USBCDC serial device to use
		USBCDC* usbcdc;
		
		/// @brief True if using USBCDC
		bool use_usb = false;

		/// @brief The baud rate to use
		int baud;

};