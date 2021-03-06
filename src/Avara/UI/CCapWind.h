/*
    Copyright �1994-1995, Juri Munkki
    All rights reserved.

    File: CCapWind.h
    Created: Wednesday, November 16, 1994, 2:20
    Modified: Monday, June 12, 1995, 6:39
*/

#include "CWindowCommander.h"

class	CCapMaster;

#define	KEYBOARDSETTINGSFILETYPE	'AVKB'


class	CCapWind : public CWindowCommander
{
public:
			CCapMaster			*theMaster;
			Handle				mapRes;

	virtual	void				IWindowCommander(CCommander *theCommander,
												CWindowCommander **theList);
	virtual	void				Dispose();
	virtual	CloseRequestResult	CloseRequest(Boolean isQuitting);
	virtual	void				Close();
	virtual	Boolean				DoEvent(CEventHandler *master, EventRecord *theEvent);
	virtual	void				ContentClick(EventRecord *theEvent, Point where);
	virtual	void				UpdateKeyResource();
	
	virtual	OSErr				OpenFile(FSSpec *theFile);
	virtual	OSErr				Save();
	
	virtual	void				AdjustMenus(CEventHandler *master);
	virtual	void				DoCommand(long theCommand);
	
	virtual	void				DrawContents();
};