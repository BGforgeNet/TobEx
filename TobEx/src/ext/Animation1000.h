#ifndef ANIMATION1000_H
#define ANIMATION1000_H

#include "animext.h"

extern LPCTSTR (CAnimation1000::*Tramp_CAnimation1000_GetWalkingSound)(short);

class DETOUR_CAnimation1000 : public CAnimation1000 {
public:
	LPCTSTR DETOUR_GetWalkingSound(short wTerrainCode);
};

#endif //ANIMATION1000_H