#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system_context.h"

void APP_Init(SystemContext_t *context);

void APP_Run(void);

#ifdef __cplusplus
}
#endif

#endif
