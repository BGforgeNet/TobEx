#include "ScriptTrigger.h"

#include "console.h"

BOOL __stdcall CCreatureObject_EvaluateTrigger_Kit(int dwKit, CreFileData* pBaseStats) {
	int dwCreKit = pBaseStats->kit[1] | pBaseStats->kit[0] << 16;
	if (dwKit == 0) return !pBaseStats->kit[1];
	return dwKit == dwCreKit;
}
