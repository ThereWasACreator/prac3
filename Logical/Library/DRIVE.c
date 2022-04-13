
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DRIVE(struct DRIVE* inst)
{
	UINT mask = inst->STATE & 0x6f;
	if (!inst->ENABLE)
	{
		inst->COMMAND=CMD_SHUTDOWN;
	}
	else
	{
		switch(mask)
		{
			case STATE_DISABLED:
			
				inst->COMMAND=CMD_SHUTDOWN;
				break;
			
			case STATE_READY:
			
				inst->COMMAND=CMD_ENABLED;
				break;
			
			case STATE_SWITCHED_ON:
			
				inst->COMMAND=CMD_SWITCHED_ON;
				break;
			
		}
	}
	/*TODO: Add your code here*/
}
