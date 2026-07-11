#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system_context.h"

void Communication_Init(SystemContext_t *context);

void Communication_Update(void);

#ifdef __cplusplus
}
#endif

#endif
