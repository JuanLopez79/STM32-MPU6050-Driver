#include "processing.h"

static SystemContext_t *system = NULL;

void Processing_Init(SystemContext_t *context) {
	system = context;
}

void Processing_Update(void) {
	system->data.motion.acceleration = system->data.imu.acceleration;

	system->data.motion.angularRate = system->data.imu.angularRate;

	system->data.motion.temperature = system->data.imu.temperature;
}
