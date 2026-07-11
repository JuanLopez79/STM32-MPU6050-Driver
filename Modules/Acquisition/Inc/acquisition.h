#ifndef ACQUISITION_H
#define ACQUISITION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system_context.h"

void Acquisition_Init(SystemContext_t *context);

void Acquisition_Update(void);

#ifdef __cplusplus
}
#endif

#endif
