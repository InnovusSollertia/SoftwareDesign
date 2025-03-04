/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0     (GUI_ID_USER + 0x1A)
#define ID_TEXT_0     (GUI_ID_USER + 0x1B)
#define ID_TEXT_1     (GUI_ID_USER + 0x1C)
#define ID_BUTTON_0     (GUI_ID_USER + 0x1D)
#define ID_BUTTON_1     (GUI_ID_USER + 0x1E)
#define ID_BUTTON_2     (GUI_ID_USER + 0x1F)
#define ID_BUTTON_3     (GUI_ID_USER + 0x06)
#define ID_BUTTON_4     (GUI_ID_USER + 0x07)
#define ID_BUTTON_5     (GUI_ID_USER + 0x08)
#define ID_BUTTON_6     (GUI_ID_USER + 0x09)
#define ID_BUTTON_7     (GUI_ID_USER + 0x0A)
#define ID_BUTTON_8     (GUI_ID_USER + 0x0B)
#define ID_BUTTON_9     (GUI_ID_USER + 0x0C)
#define ID_BUTTON_10     (GUI_ID_USER + 0x0D)
#define ID_BUTTON_11     (GUI_ID_USER + 0x0E)
#define ID_BUTTON_12     (GUI_ID_USER + 0x0F)
#define ID_BUTTON_13     (GUI_ID_USER + 0x10)
#define ID_BUTTON_14     (GUI_ID_USER + 0x11)
#define ID_BUTTON_15     (GUI_ID_USER + 0x12)
#define ID_BUTTON_16     (GUI_ID_USER + 0x13)
#define ID_BUTTON_17     (GUI_ID_USER + 0x14)
#define ID_BUTTON_18     (GUI_ID_USER + 0x15)
#define ID_BUTTON_19     (GUI_ID_USER + 0x16)
#define ID_BUTTON_20     (GUI_ID_USER + 0x17)
#define ID_BUTTON_21     (GUI_ID_USER + 0x18)
#define ID_BUTTON_22     (GUI_ID_USER + 0x19)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Calculator", ID_FRAMEWIN_0, 120, 6, 240, 260, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "0", ID_TEXT_0, 0, 0, 230, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "0", ID_TEXT_1, 0, 20, 230, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Back", ID_BUTTON_0, 5, 55, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "CE", ID_BUTTON_1, 50, 55, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "C", ID_BUTTON_2, 95, 55, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "+/-", ID_BUTTON_3, 140, 55, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Sqrt", ID_BUTTON_4, 185, 55, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "7", ID_BUTTON_5, 5, 90, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "8", ID_BUTTON_6, 50, 90, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "9", ID_BUTTON_7, 95, 90, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "/", ID_BUTTON_8, 140, 90, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "%", ID_BUTTON_9, 185, 90, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "4", ID_BUTTON_10, 5, 125, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "5", ID_BUTTON_11, 50, 125, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "6", ID_BUTTON_12, 95, 125, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "*", ID_BUTTON_13, 140, 125, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "1/x", ID_BUTTON_14, 185, 125, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "1", ID_BUTTON_15, 5, 160, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "2", ID_BUTTON_16, 50, 160, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "3", ID_BUTTON_17, 95, 160, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "-", ID_BUTTON_18, 140, 160, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "0", ID_BUTTON_19, 5, 195, 85, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, ".", ID_BUTTON_20, 95, 195, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "+", ID_BUTTON_21, 140, 195, 40, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "=", ID_BUTTON_22, 185, 160, 40, 65, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Calculator'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetFont(hItem, GUI_FONT_20F_ASCII);
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetTextColor(hItem, 0x00000000);
    //
    // Initialization of '0'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetFont(hItem, GUI_FONT_16B_ASCII);
    TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
    //
    // Initialization of '0'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetFont(hItem, GUI_FONT_24B_ASCII);
    TEXT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
    TEXT_SetTextColor(hItem, 0x00000000);
    //
    // Initialization of 'Back'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of 'CE'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of 'C'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of '+/-'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of 'Sqrt'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of '7'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '8'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '9'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '/'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of '%'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of '4'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_10);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '5'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_11);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '6'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_12);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '*'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_13);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of '1/x'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_14);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of '1'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_15);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '2'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_16);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '3'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_17);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '-'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_18);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    //
    // Initialization of '0'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_19);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '.'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_20);
    BUTTON_SetFont(hItem, GUI_FONT_16B_ASCII);
    //
    // Initialization of '+'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_21);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
	//
    // Initialization of '='
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_22);
    BUTTON_SetFont(hItem, GUI_FONT_13B_ASCII);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'Back'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'CE'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by 'C'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_3: // Notifications sent by '+/-'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_4: // Notifications sent by 'Sqrt'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_5: // Notifications sent by '7'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_6: // Notifications sent by '8'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_7: // Notifications sent by '9'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_8: // Notifications sent by '/'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_9: // Notifications sent by '%'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_10: // Notifications sent by '4'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_11: // Notifications sent by '5'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_12: // Notifications sent by '6'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_13: // Notifications sent by '*'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_14: // Notifications sent by '1/x'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_15: // Notifications sent by '1'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_16: // Notifications sent by '2'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_17: // Notifications sent by '3'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_18: // Notifications sent by '-'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_19: // Notifications sent by '0'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_20: // Notifications sent by '.'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_21: // Notifications sent by '+'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_22: // Notifications sent by '='
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateCalculator
*/
WM_HWIN CreateCalculator(void);
WM_HWIN CreateCalculator(void)
{
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	FRAMEWIN_AddCloseButton(hWin, FRAMEWIN_BUTTON_RIGHT, 0);
	FRAMEWIN_SetMoveable(hWin, 1);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
