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
		bool begin();
		bool receiveMessage(const char& message);
		bool receiveMessage(const String& message);
	protected:
		/// @brief Pointer to hardware serial to use
		HardwareSerial* serial;

		/// @brief The baud rate to use
		int baud;

};