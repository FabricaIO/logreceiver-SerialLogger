/*
* This file and associated .cpp file are licensed under the GPLv3 License Copyright (c) 2024 Sam Groveman
*
* Contributors: Sam Groveman
*/

#include <LogReceiver.h>

/// @brief Logs to the Arduino serial output
class SerialLogger : public LogReceiver {
	public:
		SerialLogger(HardwareSerial* HWSerial = &Serial, int Baud = 115200);
		bool begin();
		bool receiveChar(char c);
		bool receiveMessage(String message);
	private:
		/// @brief Pointer to hardware serial to use
		HardwareSerial* serial;
		int baud;
};