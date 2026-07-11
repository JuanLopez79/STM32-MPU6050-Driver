#include "machine.h"

#include "acquisition.h"
#include "processing.h"
#include "communication.h"

static SystemContext_t *system = NULL;

void Machine_Init(SystemContext_t *context) {
	system = context;

	Acquisition_Init(system);

	Processing_Init(system);

	Communication_Init(system);
}

void Machine_Run(void) {
	Acquisition_Update();

	Processing_Update();

	Communication_Update();

	HAL_Delay(500);
}
