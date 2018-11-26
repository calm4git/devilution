//HEADER_GOES_HERE
#ifndef __MSG_H__
#define __MSG_H__

extern int deltaload;
extern BYTE gbBufferMsgs;
extern int pkt_counter;

void __fastcall msg_send_drop_pkt(int pnum, int reason);
void __fastcall msg_send_packet(int pnum, const void *packet, DWORD dwSize);
TMegaPkt *__cdecl msg_get_next_packet();
BOOL __cdecl msg_wait_resync();
void __cdecl msg_free_packets();
int __cdecl msg_wait_for_turns();
void __cdecl msg_process_net_packets();
void __cdecl msg_pre_packet();
void __fastcall DeltaExportData(int pnum);
void *__fastcall DeltaExportItem(void *dst, void *src);
void *__fastcall DeltaExportObject(void *dst, void *src);
void *__fastcall DeltaExportMonster(void *dst, void *src);
void *__fastcall DeltaExportJunk(void *dst);
int __fastcall msg_comp_level(char *begin, void *end);
void __cdecl delta_init();
void __fastcall delta_kill_monster(int mi, BYTE x, BYTE y, BYTE bLevel);
void __fastcall delta_monster_hp(int mi, int hp, BYTE bLevel);
void __fastcall delta_sync_monster(TCmdLocParam1 *packet, BYTE level);
void __fastcall delta_sync_golem(TCmdGolem *pG, int pnum, BYTE bLevel);
void __fastcall delta_leave_sync(BYTE bLevel);
BOOL __fastcall delta_portal_inited(int i);
BOOL __fastcall delta_quest_inited(int i);
void __fastcall DeltaAddItem(int ii);
void __cdecl DeltaSaveLevel();
void __cdecl DeltaLoadLevel();
void __fastcall NetSendCmd(BOOL bHiPri, BYTE bCmd);
void __fastcall NetSendCmdGolem(BYTE mx, BYTE my, BYTE dir, BYTE menemy, int hp, BYTE cl);
void __fastcall NetSendCmdLoc(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y);
void __fastcall NetSendCmdLocParam1(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1);
void __fastcall NetSendCmdLocParam2(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2);
void __fastcall NetSendCmdLocParam3(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2, WORD wParam3);
void __fastcall NetSendCmdParam1(BOOL bHiPri, BYTE bCmd, WORD wParam1);
void __fastcall NetSendCmdParam2(BOOL bHiPri, BYTE bCmd, WORD wParam1, WORD wParam2);
void __fastcall NetSendCmdParam3(BOOL bHiPri, BYTE bCmd, WORD wParam1, WORD wParam2, WORD wParam3);
void __fastcall NetSendCmdQuest(BOOL bHiPri, BYTE q);
void __fastcall NetSendCmdGItem(BOOL bHiPri, BYTE bCmd, BYTE mast, BYTE pnum, int ii);
void __fastcall NetSendCmdGItem2(BOOL usonly, BYTE bCmd, BYTE mast, BYTE pnum, TCmdGItem *p);
BOOL __fastcall NetSendCmdReq2(BYTE bCmd, BYTE mast, BYTE pnum, TCmdGItem *p);
void __fastcall NetSendCmdExtra(TCmdGItem *p);
void __fastcall NetSendCmdPItem(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y);
void __fastcall NetSendCmdChItem(BOOL bHiPri, BYTE bLoc);
void __fastcall NetSendCmdDelItem(BOOL bHiPri, BYTE bLoc);
void __fastcall NetSendCmdDItem(BOOL bHiPri, int ii);
void __fastcall NetSendCmdDamage(BOOL bHiPri, BYTE bPlr, DWORD dwDam);
void __fastcall NetSendCmdString(int pmask, const char *pszStr);
void __fastcall RemovePlrPortal(int pnum);
int __fastcall ParseCmd(int pnum, TCmd *pCmd);
int __fastcall On_DLEVEL(int pnum, TCmdPlrInfoHdr *pCmd);
void __fastcall DeltaImportData(BYTE cmd, DWORD recv_offset);
void *__fastcall DeltaImportItem(void *src, void *dst);
void *__fastcall DeltaImportObject(void *src, void *dst);
void *__fastcall DeltaImportMonster(void *src, void *dst);
void __fastcall DeltaImportJunk(void *src);
int __fastcall On_SYNCDATA(void *packet, int pnum);
int __fastcall On_WALKXY(TCmdLoc *pCmd, int pnum);
int __fastcall On_ADDSTR(TCmdParam1 *pCmd, int pnum);
int __fastcall On_ADDMAG(TCmdParam1 *pCmd, int pnum);
int __fastcall On_ADDDEX(TCmdParam1 *pCmd, int pnum);
int __fastcall On_ADDVIT(TCmdParam1 *pCmd, int pnum);
int __fastcall On_SBSPELL(TCmdParam1 *pCmd, int pnum);
void msg_errorf(const char *pszFmt, ...);
int __fastcall On_GOTOGETITEM(TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_REQUESTGITEM(TCmdGItem *pCmd, int pnum);
BOOL __fastcall i_own_level(int nReqLevel);
int __fastcall On_GETITEM(TCmdGItem *pCmd, int pnum);
BOOL __fastcall delta_get_item(TCmdGItem *pI, BYTE bLevel);
int __fastcall On_GOTOAGETITEM(TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_REQUESTAGITEM(TCmdGItem *pCmd, int pnum);
int __fastcall On_AGETITEM(TCmdGItem *pCmd, int pnum);
int __fastcall On_ITEMEXTRA(TCmdGItem *pCmd, int pnum);
int __fastcall On_PUTITEM(TCmdPItem *pCmd, int pnum);
void __fastcall delta_put_item(TCmdPItem *pI, int x, int y, BYTE bLevel);
void __fastcall check_update_plr(int pnum);
int __fastcall On_SYNCPUTITEM(TCmdPItem *pCmd, int pnum);
int __fastcall On_RESPAWNITEM(TCmdPItem *pCmd, int pnum);
int __fastcall On_ATTACKXY(TCmdLoc *pCmd, int pnum);
int __fastcall On_SATTACKXY(TCmdLoc *pCmd, int pnum);
int __fastcall On_RATTACKXY(TCmdLoc *pCmd, int pnum);
int __fastcall On_SPELLXYD(TCmdLocParam3 *pCmd, int pnum);
int __fastcall On_SPELLXY(TCmdLocParam2 *pCmd, int pnum);
int __fastcall On_TSPELLXY(TCmdLocParam2 *pCmd, int pnum);
int __fastcall On_OPOBJXY(TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_DISARMXY(TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_OPOBJT(TCmdParam1 *pCmd, int pnum);
int __fastcall On_ATTACKID(TCmdParam1 *pCmd, int pnum);
int __fastcall On_ATTACKPID(TCmdParam1 *pCmd, int pnum);
int __fastcall On_RATTACKID(TCmdParam1 *pCmd, int pnum);
int __fastcall On_RATTACKPID(TCmdParam1 *pCmd, int pnum);
int __fastcall On_SPELLID(TCmdParam3 *pCmd, int pnum);
int __fastcall On_SPELLPID(TCmdParam3 *pCmd, int pnum);
int __fastcall On_TSPELLID(TCmdParam3 *pCmd, int pnum);
int __fastcall On_TSPELLPID(TCmdParam3 *pCmd, int pnum);
int __fastcall On_KNOCKBACK(TCmdParam1 *pCmd, int pnum);
int __fastcall On_RESURRECT(TCmdParam1 *pCmd, int pnum);
int __fastcall On_HEALOTHER(TCmdParam1 *pCmd, int pnum);
int __fastcall On_TALKXY(TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_NEWLVL(TCmdParam2 *pCmd, int pnum);
int __fastcall On_WARP(TCmdParam1 *pCmd, int pnum);
int __fastcall On_MONSTDEATH(TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_KILLGOLEM(TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_AWAKEGOLEM(TCmdGolem *pCmd, int pnum);
int __fastcall On_MONSTDAMAGE(TCmdParam2 *pCmd, int pnum);
int __fastcall On_PLRDEAD(TCmdParam1 *pCmd, int pnum);
int __fastcall On_PLRDAMAGE(TCmdDamage *pCmd, int pnum);
int __fastcall On_OPENDOOR(TCmdParam1 *pCmd, int pnum);
void __fastcall delta_sync_object(int oi, BYTE bCmd, BYTE bLevel);
int __fastcall On_CLOSEDOOR(TCmdParam1 *pCmd, int pnum);
int __fastcall On_OPERATEOBJ(TCmdParam1 *pCmd, int pnum);
int __fastcall On_PLROPOBJ(TCmdParam2 *pCmd, int pnum);
int __fastcall On_BREAKOBJ(TCmdParam2 *pCmd, int pnum);
int __fastcall On_CHANGEPLRITEMS(TCmdChItem *pCmd, int pnum);
int __fastcall On_DELPLRITEMS(TCmdDelItem *pCmd, int pnum);
int __fastcall On_PLRLEVEL(TCmdParam1 *pCmd, int pnum);
int __fastcall On_DROPITEM(TCmdPItem *pCmd, int pnum);
int __fastcall On_SEND_PLRINFO(TCmdPlrInfoHdr *pCmd, int pnum);
int __fastcall On_ACK_PLRINFO(TCmdPlrInfoHdr *pCmd, int pnum);
int __fastcall On_PLAYER_JOINLEVEL(TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_ACTIVATEPORTAL(TCmdLocParam3 *pCmd, int pnum);
void __fastcall delta_open_portal(int pnum, BYTE x, BYTE y, BYTE bLevel, BYTE bLType, BYTE bSetLvl);
int __fastcall On_DEACTIVATEPORTAL(TCmd *pCmd, int pnum);
int __fastcall On_RETOWN(TCmd *pCmd, int pnum);
int __fastcall On_SETSTR(TCmdParam1 *pCmd, int pnum);
int __fastcall On_SETDEX(TCmdParam1 *pCmd, int pnum);
int __fastcall On_SETMAG(TCmdParam1 *pCmd, int pnum);
int __fastcall On_SETVIT(TCmdParam1 *pCmd, int pnum);
int __fastcall On_STRING(TCmdString *pCmd, int pnum);
int __fastcall On_STRING2(int pnum, TCmdString *pCmd);
int __fastcall On_SYNCQUEST(TCmdQuest *pCmd, int pnum);
int __fastcall On_ENDSHIELD(TCmd *pCmd, int pnum);
int __fastcall On_CHEAT_EXPERIENCE(TCmd *pCmd, int pnum);
int __fastcall On_CHEAT_SPELL_LEVEL(TCmd *pCmd, int pnum);
int __cdecl On_DEBUG(TCmd *pCmd);
int __fastcall On_NOVA(TCmdLoc *pCmd, int pnum);
int __fastcall On_SETSHIELD(TCmd *pCmd, int pnum);
int __fastcall On_REMSHIELD(TCmd *pCmd, int pnum);

#endif /* __MSG_H__ */
