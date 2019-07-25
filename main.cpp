#include "StdAfx.h"
#include <dbosnap2.h>
#include <dbobjptr2.h>
#include <dbindex.h>
#include <dbboiler.h>
#include <AcTc.h>
#include <acedCmdNF.h>
#include <ol_errno.h>
#include <dbMPolygon.h>
#include <subselect.h>
#include <brmesh2d.h>
#include <brbrep.h>
#include <rxmfcapi.h>
#include <string.h>
#include <memory>
#include <gs.h>


void test1()
{
}

//**************************************************************
extern "C"
AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void *pkt)
//**************************************************************
{
	switch(msg)
	{
		case AcRx::kInitAppMsg:
			acrxDynamicLinker->unlockApplication(pkt);
			acrxDynamicLinker->registerAppMDIAware(pkt);
			acrxBuildClassHierarchy();/*use this for derived classes*/
			
			/*Load commands*/
			acedRegCmds->addCommand(_T("TestCmd"), _T("AdskPoly"), _T("AdskPoly"), ACRX_CMD_MODAL, test1);
		
			
			break;
		
		
		case AcRx::kUnloadAppMsg:
					
			acedRegCmds->removeGroup(_T("TestCmd"));

			break;

		default:
			break;
	}
	return AcRx::kRetOK;
}