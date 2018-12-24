////////////////////////////////////////////////////////////////////
// Filename : StringPool.h
// Desc     : ���������� ���Ǵ� string ���� pool
////////////////////////////////////////////////////////////////////

#ifndef __STRING_POOL_H__
#define __STRING_POOL_H__

#include "Exception.h"

#include <string>
#include <hash_map>

enum StringID
{
	STRID_SLAYER,											// 0
	STRID_VAMPIRE,											// 1
	STRID_APPLICATE_COMBAT_SLAYER_BONUS,					// 2
	STRID_APPLICATE_COMBAT_VAMPIRE_BONUS,					// 3
	STRID_NO_MORE_COMBAT_BONUS,								// 4
	STRID_NO_MORE_COMBAT_SLAYER_BONUS,						// 5
	STRID_NO_MORE_COMBAT_VAMPIRE_BONUS,						// 6
	STRID_HAVING_SLAYER_RELIC,								// 7
	STRID_HAVING_VAMPIRE_RELIC,								// 8
	STRID_RELIC_IN_ZONE,									// 9
	STRID_SERVER_SHUT_DOWN_COUNT_DOWN,						// 10
	STRID_SERVER_SHUT_DOWN,									// 11
	STRID_TAKE_SLAYER_RELIC,								// 12
	STRID_TAKE_VAMPIRE_RELIC,								// 13
	STRID_TRANSPORT_CREATURE,								// 14
	STRID_DISCONNECT_COUNT_DOWN,							// 15
	STRID_MASTER_LAIR_OPENED,								// 16
	STRID_MASTER_LAIR_CLOSED,								// 17
	STRID_MASTER_LAIR_OPENING_COUNT_DOWN,					// 18
	STRID_EVENT_SANTA_NAME,									// 19
	STRID_EVENT_WOLF_NAME,									// 20
	STRID_SLAYER_RELIC_SHRINE,								// 21
	STRID_VAMPIRE_RELIC_SHRINE,								// 22
	STRID_CANNOT_ENTER,										// 23
	STRID_CANNOT_ENTER_PAY_ZONE,							// 24
	STRID_PCROOM_REMAIN_PLAY_TIME,							// 25
	STRID_PERSONAL_REMAIN_PLAY_TIME,						// 26
	STRID_NEWBIE_TRANSPORT_TO_GUILD,						// 27
	STRID_CLERIC_GUILD,										// 28
	STRID_SOLDIER_GUILD,									// 29
	STRID_KNIGHT_GUILD,										// 30
	STRID_CANNOT_TAKE_RELIC_NOW,							// 31
	STRID_RELIC_FROM_RELIC_TABLE,							// 32
	STRID_ALERT_VAMPIRE,									// 33
	STRID_ALERT_SLAYER,										// 34
	STRID_PUT_RELIC_TO_RELIC_TABLE,							// 35
	STRID_COMBAT_SLAYER_WIN,								// 36
	STRID_COMBAT_VAMPIRE_WIN,								// 37
	STRID_COMBAT_ALEADY_START,								// 38
	STRID_COMBAT_START,										// 39
	STRID_COMBAT_END,										// 40
	STRID_CANNOT_END_COMBAT,								// 41
	STRID_WRONG_VARIABLE_NAME,								// 42
	STRID_LOAD_MASTER_LAIR_INFO,							// 43
	STRID_LOAD_MONSTER_INFO,								// 44
	STRID_LOAD_ALL_MONSTER_INFO,							// 45
	STRID_LOAD_WRONG_MONSTER_INFO,							// 46
	STRID_LOAD_DIRECTIVESET,								// 47
	STRID_LOAD_ZONE_INFO,									// 48
	STRID_LOAD_ZONE,										// 49
	STRID_LOAD_LOG_USER,									// 50
	STRID_LOAD_ITEM_INFO,									// 51
	STRID_LOAD_OPTION_INFO,									// 52
	STRID_LOAD_RANK_BONUS_INFO,								// 53
	STRID_SET_STAR_RATIO,									// 54
	STRID_EVENT_START,										// 55
	STRID_EVENT_END,										// 56
	STRID_SET_EVENT_MONSTER_RATIO,							// 57
	STRID_SET_EXP_RATIO,									// 58
	STRID_SET_ITEM_PROBE_RATIO,								// 59
	STRID_SET_COMBAT_BONUS_TIME,							// 60
	STRID_SET_COMBAT_SLAYER_BONUS_HP,						// 61
	STRID_SET_COMBAT_VAMPIRE_BONUS_HP,						// 62
	STRID_SET_COMBAT_SLAYER_BONUS_DAMAGE,					// 63
	STRID_SET_COMBAT_VAMPIRE_BONUS_DAMAGE,					// 64
	STRID_SET_PREMIUM_EXP_RATIO,							// 65
	STRID_SET_PREMIUM_ITEM_PROBE_RATIO,						// 66
	STRID_SET_ZONE_GROUP_BALANCING_TIME,					// 67
	STRID_SET_GAMBLE_ITEM_TYPE_RATIO,						// 68
	STRID_SET_GAMBLE_ITEM_OPTION_RATIO,						// 69
	STRID_SET_SUMMON_MOTORCYCLE,							// 70
	STRID_SET_MONSTER_FORGET_TIME,							// 71
	STRID_SET_RARE_ITEM_RATIO,								// 72
	STRID_SET_UNIQUE_ITEM_RATIO,							// 73
	STRID_SET_MASTER_LAIR_ACTIVATE,							// 74
	STRID_SET_RETRY_MASTER_LAIR,							// 75
	STRID_SET_HARVEST_FESTIVAL_ITEM_RATIO,					// 76
	STRID_SET_MASTER_BLOOD_DRAIN_START_HP,					// 77
	STRID_SET_MASTER_BLOOD_DRAIN_START_BD,					// 78
	STRID_SET_MASTER_BLOOD_DRAIN_END_HP,					// 79
	STRID_SET_MASTER_BLOOD_DRAIN_END_BD,					// 80
	STRID_SET_CHIEF_MONSTER,								// 81
	STRID_SET_CHIEF_MONSTER_RARE_ITEM_RATIO,				// 82
	STRID_SET_NEWBIE_TRANSPORT_TO_GUILD,					// 83
	STRID_SAVE_YOUR_DATA,									// 84
	STRID_PLAYER_IN_GAMESERVER,								// 85
	STRID_PLAYER_NOT_IN_GAMESERVER,							// 86
	STRID_CURRENT_NUMBER_OF_PLAYER,							// 87
	STRID_CANNOT_CREATE_ITEM,								// 88
	STRID_CANNOT_CREATE_ITEM_2,								// 89
	STRID_ZONE_GROUP_BALANCING,								// 90
	STRID_MASTER_LAIR_REGEN,								// 91
	STRID_NOT_IN_MASTER_LAIR,								// 92
	STRID_INVINCIBLE,										// 93
	STRID_GHOST,											// 94
	STRID_AIR_BLOCKED,										// 95
	STRID_GROUND_BLOCKED,									// 96
	STRID_CLEAR_INVENTORY,									// 97
	STRID_GUILD_WAIT_MEMBER_FULL,							// 98
	STRID_TEAM_JOIN_ACCEPTED,								// 99
	STRID_CLAN_JOIN_ACCEPTED,								// 100
	STRID_TEAM_JOIN_TRY,									// 101
	STRID_CLAN_JOIN_TRY,									// 102
	STRID_TEAM_JOIN_ACCEPTED_2,								// 103
	STRID_CLAN_JOIN_ACCEPTED_2,								// 104
	STRID_TEAM_JOIN_TRY_2,									// 105
	STRID_CLAN_JOIN_TRY_2,									// 106
	STRID_TEAM_REGISTERED,									// 107
	STRID_CLAN_REGISTERED,									// 108
	STRID_TEAM_JOIN_DENY,									// 109
	STRID_CLAN_JOIN_DENY,									// 110
	STRID_TEAM_JOIN_DENY_2,									// 111
	STRID_CLAN_JOIN_DENY_2,									// 112
	STRID_EXPEL_TEAM_MEMBER,								// 113
	STRID_EXPEL_CLAN_MEMBER,								// 114
	STRID_EXPEL_TEAM_MEMBER_2,								// 115
	STRID_EXPEL_CLAN_MEMBER_2,								// 116
	STRID_ACCEPT_TEAM_JOIN,									// 117
	STRID_ACCEPT_CLAN_JOIN,									// 118
	STRID_TEAM_RIGHT_CHANGED,								// 119
	STRID_CLAN_RIGHT_CHANGED,								// 120
	STRID_TEAM_RIGHT_CHANGED_2,								// 121
	STRID_CLAN_RIGHT_CHANGED_2,								// 122
	STRID_QUIT_TEAM,										// 123
	STRID_QUIT_CLAN,										// 124
	STRID_QUIT_TEAM_2,										// 125
	STRID_QUIT_CLAN_2,										// 126

	// Action �� �ִ� String ó�� �ȵǾ� �־���
	STRID_NOT_ENOUGH_MONEY,									// 127
	STRID_NOT_ENOUGH_INVENTORY_SPACE,						// 128
	STRID_ITEM_NOT_EXIST,									// 129
	STRID_TRANS_BONUS_POINT,								// 130
	STRID_STR_LOW_LIMIT,									// 131
	STRID_DEX_LOW_LIMIT,									// 132
	STRID_INT_LOW_LIMIT,									// 133
	STRID_SET_RESURRECTION_POSITION,						// 134
	STRID_NPC_ERROR,										// 135
	STRID_NO_LAIR_ITEM,										// 136
	STRID_ITEM_CREATE_ERROR,								// 137
	STRID_TRADE_SUCCESS,									// 138

	STRID_CANNOT_ENTER_DURING_RACE_WAR,						// 139
	STRID_CANNOT_ENTER_NOT_OWNER_GUILD,						// 140

	STRID_DO_NOT_SUPPORT_OLD_WAR,							// 141
	STRID_LOAD_WAR_SCHEDULE_INFO,							// 142
	STRID_WAR_OFF,											// 143
	STRID_LOAD_BLOOD_BIBLE_OWNER_INFO,						// 144
	STRID_LOAD_RACE_WAR_PC_LIMIT_INFO,						// 145
	STRID_WRONG_ITEM_TAX_RATIO,								// 146
	STRID_DO_NOT_BELONG_TO_GUILD,							// 147
	STRID_NO_SUCH_CHARACTOR,								// 148
	STRID_NOT_IN_CASTLE,									// 149
	STRID_WAR_OFF_DO_WAR_ACITIVE_ON,						// 150
	STRID_RACE_WAR_START,									// 151
	STRID_ALREADY_WAR_STARTED_OF_SERVER_ERROR,				// 152
	STRID_GUILD_WAR_REMOVED,								// 153
	STRID_NO_GUILD_WAR_IN_ACTIVE,							// 154
	STRID_RACE_WAR_REMOVED,									// 155
	STRID_NO_RACE_WAR_IN_ACTIVE,							// 156
	STRID_SAVE_BLOOD_BIBLE_OWNER_INFO_IN_DB,				// 157
	STRID_KILL_ALL_MONSTER_IN_ZONE,							// 158
	STRID_MODIFY_GUILD_MASTER,								// 159

	STRID_BECOME_SLAYER_COMMON_CASTLE,						// 160
	STRID_BECOME_VAMPIRE_COMMON_CASTLE,						// 161
	STRID_BECOME_SLAYER_GUILD_CASTLE,						// 162
	STRID_BECOME_VAMPIRE_GUILD_CASTLE,						// 163
	STRID_RETURN_TO_GUARD_SHRINE_CASTLE_SYMBOL,				// 164
	STRID_BROADCAST_CASTLE_SYMBOL_POSITION,					// 165
	STRID_BROADCAST_CASTLE_SYMBOL_POSITION_2,				// 166
	STRID_BROADCAST_CASTLE_SYMBOL_POSITION_3,				// 167

	STRID_WAR_SCHEDULE_INFO,								// 168
	STRID_THIS_ZONE_IS_NOT_CASTLE,							// 169
	STRID_NO_SUCH_ZONE,										// 170
	STRID_BLOOD_BIBLE_FROM_SHRINE,							// 171
	STRID_CASTLE_SYMBOL_FROM_SHRINE,						// 172
	STRID_RETURN_TO_GUARD_SHRINE_BLOOD_BIBLE,				// 173

	STRID_EXPIRE_PREMIUM_SERVICE,							// 174
	STRID_NOT_ENOUGH_ENTRANCE_FEE,							// 175
	STRID_WAR_START,										// 176
	STRID_WAR_END,											// 177
	STRID_NO_WAR_IN_ACTIVE,									// 178
	STRID_WAR_STATUS,										// 179

	STRID_CANNOT_KICK_DURING_WAR,							// 180
	STRID_CANNOT_ACCEPT_MORE_JOIN,							// 181
	STRID_CANNOT_ACCEPT_DURING_WAR,							// 182

	STRID_DO_NOT_JOIN_BLOOD_WAR_EVENT,						// 183
	STRID_ALREADY_TAKE_BLOOD_WAR_EVET_ITEM,					// 184
	STRID_REQUIRE_MORE_SOCCER_BALL,							// 185
	STRID_KOREA_FIGHTING_1,									// 186
	STRID_KOREA_FIGHTING_2,									// 187
	STRID_KOREA_FIGHTING_3,									// 188
	STRID_KOREA_FIGHTING_4,									// 189
	STRID_KOREA_FIGHTING_5,									// 190
	STRID_KOREA_FIGHTING_6,									// 191
	STRID_KOREA_FIGHTING_7,									// 192
	STRID_KOREA_FIGHTING_8,									// 193
	STRID_KOREA_FIGHTING_9,									// 194
	STRID_KOREA_FIGHTING_10,								// 195
	STRID_KOREA_FIGHTING_11,								// 196
	STRID_KOREA_FIGHTING_12,								// 197
	STRID_KOREA_FIGHTING_13,								// 198
	STRID_KOREA_FIGHTING_14,								// 199
	STRID_KOREA_FIGHTING_15,								// 200
	STRID_KOREA_FIGHTING_16,								// 201
	STRID_KOREA_FIGHTING_17,								// 202
	STRID_KOREA_FIGHTING_18,								// 203
	STRID_KOREA_FIGHTING_19,								// 204
	STRID_KOREA_FIGHTING_20,								// 205

	STRID_APPLY_NEW_BILLING_INFO,							// 206

	STRID_REQUEST_APART,									// 207
	STRID_REQUEST_MEET,										// 208

	STRID_PC_NUM,											// 209
	STRID_PKZONE_PC_LIMITED,								// 210
	STRID_NOT_BEGINNER,										// 211

	STRID_LOAD_QUEST_INFO,									// 212
	STRID_END_PAY_PLAY,										// 213

	STRID_EVENT_NPC_1,										// 214
	STRID_EVENT_NPC_2,										// 215
	STRID_EVENT_NPC_3,										// 216
	STRID_EVENT_NPC_4,										// 217

	STRID_LOAD_GOODS_LIST_INFO,								// 218

	STRID_ALERT_OUSTERS,									// 219
	STRID_ALERT_OUSTERS_2,									// 220
	STRID_ALERT_SLAYER_2,									// 221
	STRID_ALERT_VAMPIRE_2,									// 222

	STRID_FAMILY_FREE_PLAY_END,								// 223
	STRID_ALREAY_LEARN_SKILL,								// 224

	STRID_GIVE_LOTTO,										// 225
	STRID_CANNOT_GIVE_LOTTO,								// 226

	STRID_FLAG_POLE,										// 227 
	STRID_CANNOT_ENTER_SUM_NEWBIE_ZONE,						// 228
	STRID_CANNOT_ENTER_LEVEL_NEWBIE_ZONE,					// 229

	STRID_OUSTERS,											// 230

	STRID_LEVEL_WAR_ONLY_FIRST_SERVER,						// 231

	STRID_TO_HIGH_LEVEL_FOR_LEVEL_WAR,						// 232

	STRID_CANNOT_ENTER_LEVEL_WAR_ZONE,						// 233

	STRID_PULL_OUT_SWEEPER,									// 234
	STRID_PICK_UP_SWEEPER,									// 235
	STRID_DROP_SWEEPER,										// 236
	STRID_PUT_SWEEPER,										// 237
	STRID_CENTER,											// 238

	STRID_LEVEL_WAR_ZONE_FREE_OPEN,                         // 239
	STRID_LEVEL_WAR_ZONE_FREE_CLOSE_1,                      // 240
	STRID_LEVEL_WAR_ZONE_FREE_CLOSE_2,                      // 241

	STRID_CANNOT_REGISTRER_WAR_YET,							// 242

	STRID_ONLY_QUEST_SLAYER_ENTER,							// 243
	STRID_ONLY_QUEST_VAMPIRE_ENTER,							// 244
	STRID_ONLY_QUEST_OUSTERS_ENTER,							// 245

	STRID_ORE,												// 246
	STRID_COUPLE_IS,										// 247
	STRID_NOT_COUPLE,										// 248

	STRID_FREE,												// 249
	STRID_REI,												// 250
	STRID_GELD,												// 251
	STRID_ZARD,												// 252
	STRID_NO_ENTER,											// 253
	STRID_SLAYER_COMMON_CASTLE,								// 254
	STRID_VAMPIRE_COMMON_CASTLE,							// 255
	STRID_OUSTERS_COMMON_CASTLE,							// 256
	STRID_NO_MASTER_CASTLE,									// 257
	STRID_TEAM,												// 258
	STRID_CLAN,												// 259
	STRID_S_CASTLE,											// 260
	STRID_REGENZONE_TOWER,									// 261

	STRID_CB_MONTHLY_PLAYER,								// 262
	STRID_CB_POINT_PLAYER,									// 263
	STRID_CB_CHANGE_TO_POINT_PLAYER,						// 264
	STRID_CB_CHANGE_TO_MONTHLY_PLAYER,						// 265
	STRID_CB_LEFT_POINT,									// 266

	STRID_SLAYER_QUESTZONE_2_1,										// 267
	STRID_SLAYER_QUESTZONE_2_2,										// 268
	STRID_SLAYER_QUESTZONE_2_3,										// 269
	STRID_SLAYER_QUESTZONE_2_4,										// 270
	STRID_SLAYER_QUESTZONE_2_5,										// 271
	STRID_SLAYER_QUESTZONE_2_6,										// 272
	STRID_SLAYER_QUESTZONE_2_7,										// 273
	STRID_SLAYER_QUESTZONE_2_8,										// 274
	STRID_SLAYER_QUESTZONE_2_9,										// 275
	STRID_SLAYER_QUESTZONE_2_10,										// 276

	STRID_VAMPIRE_QUESTZONE_2_1,										// 277
	STRID_VAMPIRE_QUESTZONE_2_2,										// 278
	STRID_VAMPIRE_QUESTZONE_2_3,										// 279
	STRID_VAMPIRE_QUESTZONE_2_4,										// 280
	STRID_VAMPIRE_QUESTZONE_2_5,										// 281
	STRID_VAMPIRE_QUESTZONE_2_6,										// 282
	STRID_VAMPIRE_QUESTZONE_2_7,										// 283
	STRID_VAMPIRE_QUESTZONE_2_8,										// 284
	STRID_VAMPIRE_QUESTZONE_2_9,										// 285
	STRID_VAMPIRE_QUESTZONE_2_10,										// 286

	STRID_OUSTERS_QUESTZONE_2_1,										// 287
	STRID_OUSTERS_QUESTZONE_2_2,										// 288
	STRID_OUSTERS_QUESTZONE_2_3,										// 289
	STRID_OUSTERS_QUESTZONE_2_4,										// 290
	STRID_OUSTERS_QUESTZONE_2_5,										// 291
	STRID_OUSTERS_QUESTZONE_2_6,										// 292
	STRID_OUSTERS_QUESTZONE_2_7,										// 293
	STRID_OUSTERS_QUESTZONE_2_8,										// 294
	STRID_OUSTERS_QUESTZONE_2_9,										// 295
	STRID_OUSTERS_QUESTZONE_2_10,										// 296

	STRID_SLAYER_MINE_ENTER,									// 297
	STRID_VAMPIRE_MINE_ENTER,								// 298
	STRID_OUSTERS_MINE_ENTER,								// 299

	STRID_SLAYER_QUESTZONE_4_1,										// 300
	STRID_SLAYER_QUESTZONE_4_2,										// 301
	STRID_SLAYER_QUESTZONE_4_3,										// 302
	STRID_SLAYER_QUESTZONE_4_4,										// 303
	STRID_SLAYER_QUESTZONE_4_5,										// 304

	STRID_VAMPIRE_QUESTZONE_4_1,										// 305
	STRID_VAMPIRE_QUESTZONE_4_2,										// 306
	STRID_VAMPIRE_QUESTZONE_4_3,										// 307
	STRID_VAMPIRE_QUESTZONE_4_4,										// 308
	STRID_VAMPIRE_QUESTZONE_4_5,										// 309

	STRID_OUSTERS_QUESTZONE_4_1,										// 310
	STRID_OUSTERS_QUESTZONE_4_2,										// 311
	STRID_OUSTERS_QUESTZONE_4_3,										// 312
	STRID_OUSTERS_QUESTZONE_4_4,										// 313
	STRID_OUSTERS_QUESTZONE_4_5,										// 314

	STRID_YELLOW_ZIMAT,			// 315
	STRID_GREEN_ZIMAT,			// 316
	STRID_BLUE_ZIMAT,			// 317
	STRID_RED_ZIMAT,			// 318
	STRID_BLACK_ZIMAT,			// 319

	STRID_YELLOW_ZIRCON,		// 320
	STRID_GREEN_ZIRCON,			// 321
	STRID_BLUE_ZIRCON,			// 322
	STRID_RED_ZIRCON,			// 323
	STRID_BLACK_ZIRCON,			// 324

	STRID_QUEST_MONSTER_1,		// 325
	STRID_QUEST_MONSTER_2,		// 326
	STRID_QUEST_MONSTER_3,		// 327
	STRID_QUEST_MONSTER_4,		// 328
	STRID_QUEST_MONSTER_5,		// 329

	STRID_NOT_SUPPORT,			// 330

	STRID_TIFFAGUES_1,			// 330
	STRID_TIFFAGUES_2,			// 330
	STRID_TIFFAGUES_3,			// 330
	STRID_TIFFAGUES_4,			// 330
	STRID_TIFFAGUES_5,			// 330
	STRID_TIFFAGUES_6,			// 330

	STRID_MAX
};

class StringPool
{

public:
	typedef hash_map<uint, string>		StringHashMap;
	typedef StringHashMap::iterator			StringHashMapItor;
	typedef StringHashMap::const_iterator	StringHashMapConstItor;

public:
	StringPool() throw(Error);
	~StringPool() throw(Error);

public:
	void clear() throw(Error);
	void load() throw(Error);

	void addString( uint strID, string sString ) throw( DuplicatedException, Error );
	
	string getString( uint strID ) throw( NoSuchElementException, Error );

	const char* c_str( uint strID ) throw( NoSuchElementException, Error );

private:
	StringHashMap m_Strings;
};

extern StringPool* g_pStringPool;

#endif // __STRING_POOL_H__