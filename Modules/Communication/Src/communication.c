#include "communication.h"

#include <stdio.h>

static SystemContext_t *system = NULL;

void Communication_Init(SystemContext_t *context) {
	system = context;
}

void Communication_Update(void) {
	MotionData_t *motion = &system->data.motion;

	printf("ACC: %.3f %.3f %.3f g\r\n", motion->acceleration.x,
			motion->acceleration.y, motion->acceleration.z);

	printf("GYR: %.3f %.3f %.3f dps\r\n", motion->angularRate.x,
			motion->angularRate.y, motion->angularRate.z);

	printf("TMP: %.2f C\r\n", motion->temperature);

	printf("\r\n");
}
