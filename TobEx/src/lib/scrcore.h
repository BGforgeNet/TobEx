#ifndef SCRCORE_H
#define SCRCORE_H

#include "stdafx.h"
#include "rescore.h"

class CGameObject;
class CGameSprite;

typedef short ACTIONRESULT;
typedef IECPtrList CActionList; //AA5C5C
typedef IECPtrList CTriggerList; //AA5E28
typedef IECPtrList CScriptBlockList; //AA5E50

struct ResIdsContainer { //Size 10h
	BOOL bLoaded; //0h
	ResTxt* pRes; //4h
	ResRef name; //8h
};

class Identifiers { //Size 40h
//Constructor: 0x40FB70
public:
	int* vtable; //0h
	ResIdsContainer m_ids; //4h
	IECString u14; //14h
	IECPtrList entries; //18h, contain IdsEntry objects
	BOOL bUseArray; //34h
	int* pDataArray; //38h, ptr to array of pIdsEntry
	int nArraySize; //3ch
};

struct CVariable { //Size 54h
	char name[32]; //0h
	short u20;
	short u22;
	int u24;
	int value; //28h
	long u2c[2];
	char u34[32]; //for Store Local Variable, = res1 + res2 + res3 (associated with deathmatch?)
};

struct CVariableArray { //Size 8h
	CVariable* pArray;
	int nArraySize;
};

struct ObjectIds { //Size 5h
	//OBJECT.IDS indices
	char id1;
	char id2;
	char id3;
	char id4;
	char id5;
};

class Object { //Size 14h
//Constructor: 0x410CEE
public:
	//BCS correlation: OB ea, general, race, class, specific, gender, alignment, id1, id2, id3, id4, id5, name OB
	bool IsInvalid();

	Object();

	Object(unsigned char EnemyAlly, unsigned char General, unsigned char Race, unsigned char Class, char Specific, char Gender, char Alignment, Enum eTarget, ObjectIds* poids, IECString& sName);
	Object* Construct(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum, ObjectIds*, IECString&) {return this;} //dummy

	Object(unsigned char EnemyAlly, unsigned char General, unsigned char Race, unsigned char Class, char Specific, char Gender, char Alignment, Enum eTarget);
	Object* Construct(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum) {return this;} //dummy

	void operator=(Object& o);
	void OpEq(Object&) {} //dummy

	void DecodeIdentifiers(CGameSprite& spriteSource);
	unsigned char GetClass();
	void GetClasses(unsigned char* pClass1, unsigned char* pClass2);
	BOOL HasSubclass(unsigned char Class, BOOL bThreadAsync);

	IECString Name; //0h
	unsigned char EnemyAlly; //4h
	unsigned char General; //5h
	unsigned char Race; //6h
	unsigned char Class; //7h
	Enum eTarget; //8h, set and used after evaluation of Ids
	ObjectIds oids; //ch
	char Specific; //11h, for GroupOfType
	char Gender; //12h
	char Alignment; //13h
};

extern Object* (Object::*Object_Construct_10)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum, ObjectIds*, IECString&);
extern Object* (Object::*Object_Construct_8)(unsigned char, unsigned char, unsigned char, unsigned char, char, char, char, Enum);
extern void (Object::*Object_OpEq)(Object&);
extern void (Object::*Object_DecodeIdentifiers)(CGameSprite&);
extern unsigned char (Object::*Object_GetClass)();
extern void (Object::*Object_GetClasses)(unsigned char*, unsigned char*);
extern BOOL (Object::*Object_HasSubclass)(unsigned char, BOOL);

struct Trigger { //Size 2Eh
//Constructor: 430720h (3 args), 430180h (2 args)
//Note: trigger opcodes (short) from AA5E68-AA5F66
//BCS correlation: TR opcode, i, dwFlags, i2, u22, sName1, sName2, o TR

	short opcode; //0h
	int i; //2h, gets Arg1 (I)
	Object o; //6h (O)
	unsigned int dwFlags; //1ah
	//bit0: NOT[!]
	//bit1: trigger has been executed on CCreatureObject (added internally)
	//bit2: checked with ? CDerivedStats.u640 involved? (added internally)

	int i2; //1eh (I)
	int u22; //22h (unknown usage)
	IECString sName1; //26h, (S), first global, the global name is appended to the global type e.g. "LOCALSDead", "GLOBALTest"
	IECString sName2; //2ah, (S), second global
};

struct Action { //Size 5Eh
//Constructor: 0x405820
//Note: action opcodes (short) from AA5980-AA5B32
//BCS correlation: AC opcode, oOverride, oObject, oTarget, i, pt.x, pt.y, i2, i3, sName1, sName2 AC
public:
	Action();
	Action* Construct(void) {return this;} //dummy

	~Action();
	void Deconstruct(void) {} //dummy

	short opcode; //0h (A)
	Object oOverride; //2h (O)
	Object oObject; //16h (O)
	Object oTarget; //2ah (O)
	int i; //3eh (I)
	int i2; //42h (I)
	int i3; //46h (I)
	IECString sName1; //4ah (S)
	IECString sName2; //4eh (S)
	POINT pt; //52h (P)
	unsigned int dwFlags; //5ah, bit0 = do not purge on clear all actions
};

extern Action* (Action::*Action_Construct_0)(void);
extern void (Action::*Action_Deconstruct)(void);

struct Response { //Size 24h
//Constructor: 0x416130
	short probability; //0h
	short nResponseIdx; //2h, if chosen, gets response block # in the response list
	short nScriptBlockIdx; //4h, if chosen, gets script block # in the script
	short nScriptIdx; //6h, if chosen, gets script # in the script group (i.e. Override, Race, General, etc.), however this is always 0
	CActionList m_Actions; //8h
};

class CResponseList : public IECPtrList { //Size 20h
public:
	//AA5E10

	//IECPtrList m_Responses; //0h
	int totalProbability; //1ch
};

struct CScriptBlock { //Size 3Ch
//Constructor: see 0x41829F
	CTriggerList m_Triggers; //0h
	CResponseList m_Responses; //1ch
};

struct CScript { //Size 28h
	ResRef name; //0h
	int u8;
	CScriptBlockList blocks; //ch
};

struct CScriptParser { //Size EEh
//Constructor: 0x41926B
	short mode; //0h, 0 = outside IF...END, 1 = in Trigger, 2 = in Action
	int lineNumber;
	int* u6; //0x28 size, 0x0 ResRef, 0x8 int, 0xc CPtrListAA5E50
	IECPtrList* ua; //contains CPtrListAction objects
	CTriggerList* ue;
	CActionList* u12;
	IECString sError;
	CFile u1a;
	IECString u2a;
	Identifiers ACTION; //2eh
	Identifiers TRIGGER; //6eh
	Identifiers OBJECT; //aeh
};

#endif //SCRCORE_H