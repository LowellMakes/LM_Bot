// Lidar.h

#ifndef _LIDAR_h
#define _LIDAR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class LidarClass
{
 protected:


 public:
	void init();
};

extern LidarClass Lidar;

#endif

