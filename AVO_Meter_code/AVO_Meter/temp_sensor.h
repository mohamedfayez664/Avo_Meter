#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "micro_compiler_config.h"
#include "std_types.h"
#include "std_macros.h"

void sensors_init();
uint8 temp_sensor_read(uint8);
uint8 hum_sensor_read(uint8);

#endif /* TEMP_SENSOR_H_ */
