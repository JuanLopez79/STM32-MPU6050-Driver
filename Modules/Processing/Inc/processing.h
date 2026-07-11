#ifndef PROCESSING_H
#define PROCESSING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system_context.h"

void Processing_Init(SystemContext_t *context);

void Processing_Update(void);

#ifdef __cplusplus
}
#endif

#endif
