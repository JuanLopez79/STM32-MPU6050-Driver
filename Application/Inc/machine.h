#ifndef MACHINE_H
#define MACHINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system_context.h"

void Machine_Init(SystemContext_t *context);

void Machine_Run(void);

#ifdef __cplusplus
}
#endif

#endif
