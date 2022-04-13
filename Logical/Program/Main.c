
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	speed = 1000;
	EVIRD.ENABLE=1;
}

void _CYCLIC ProgramCyclic(void)
{
	DRIVE(&EVIRD);
	if ( speedPlus == 1 )
	{
		speed +=1;
	}
	if ( speedMinus == 1 )
	{
		speed -=1;
	}
	if (reverse == 1)
	{
		speed = -speed;
	}
	if(reset == 1)
	{
		speed = 1000;
		EVIRD.ENABLE=1;	
	}
	if (speed>=2000)
	{
		speed = 2000;
	}
	if (speed<= -2000)
	{
		speed = -2000;
	}
}

void _EXIT ProgramExit(void)
{

}

