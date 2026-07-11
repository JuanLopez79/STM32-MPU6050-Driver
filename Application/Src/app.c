#include "app.h"

#include "machine.h"

static SystemContext_t *system = NULL;

void APP_Init(SystemContext_t *context)
{
    system = context;

    Machine_Init(system);
}

void APP_Run(void)
{
    Machine_Run();
}
