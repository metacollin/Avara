#include "MixedMode.h"
#include "DopplerPlug.h"

long	__procinfo = 
		 kThinkCStackBased
		| RESULT_SIZE(SIZE_CODE(sizeof(UniversalProcPtr)))
		| STACK_ROUTINE_PARAMETER(1, SIZE_CODE(sizeof(short)));

UniversalProcPtr	main(short a);

UniversalProcPtr	main(short a)
{
	UniversalProcPtr	theProc;

	switch(a)
	{	case kPowerClearMemory:
			{	static	RoutineDescriptor	powerClearMemory = BUILD_ROUTINE_DESCRIPTOR(
							kThinkCStackBased
							| RESULT_SIZE(SIZE_CODE(0))
							| STACK_ROUTINE_PARAMETER(1, SIZE_CODE(sizeof(long *))) 
							| STACK_ROUTINE_PARAMETER(2, SIZE_CODE(sizeof(long))),
							(ProcPtr)ClearMemoryAreaC);
				theProc = &powerClearMemory;
			}
			break;
		case kPowerRateMixer:
			{	static	RoutineDescriptor	powerRateMixer = BUILD_ROUTINE_DESCRIPTOR(
							kThinkCStackBased
							| RESULT_SIZE(SIZE_CODE(sizeof(short)))
							| STACK_ROUTINE_PARAMETER(1, SIZE_CODE(sizeof(Sample *))) 
							| STACK_ROUTINE_PARAMETER(2, SIZE_CODE(sizeof(WordSample *))) 
							| STACK_ROUTINE_PARAMETER(3, SIZE_CODE(sizeof(WordSample *))) 
							| STACK_ROUTINE_PARAMETER(4, SIZE_CODE(sizeof(short))) 
							| STACK_ROUTINE_PARAMETER(5, SIZE_CODE(sizeof(long))) 
							| STACK_ROUTINE_PARAMETER(6, SIZE_CODE(sizeof(SampleIndex *))) 
							| STACK_ROUTINE_PARAMETER(7, SIZE_CODE(sizeof(Fixed))),
							(ProcPtr)RateMixerC);
				theProc = &powerRateMixer;
			}
			break;
		case kPowerInterleave:
			{	static	RoutineDescriptor	powerInterleave = BUILD_ROUTINE_DESCRIPTOR(
							kThinkCStackBased
							| RESULT_SIZE(SIZE_CODE(0))
							| STACK_ROUTINE_PARAMETER(1, SIZE_CODE(sizeof(WordSample *))) 
							| STACK_ROUTINE_PARAMETER(2, SIZE_CODE(sizeof(WordSample *))) 
							| STACK_ROUTINE_PARAMETER(3, SIZE_CODE(sizeof(WordSample *))) 
							| STACK_ROUTINE_PARAMETER(4, SIZE_CODE(sizeof(short))),
							(ProcPtr)InterleaveStereoChannelsC);
				theProc = &powerInterleave;
			}
			break;
		default:
			theProc = NULL;
			break;
	}
	
	return theProc;
}
