#ifndef NET_MESSAGE_H
#define NET_MESSAGE_H

DECLARE_ENUM(NETMESSAGE);

enum NETMESSAGE {
  MSG_NULL_ACTION = 0x0000,
  CMSG_BOOTME = 0x0001,
  CMSG_DBLOOKUP = 0x0002,
  SMSG_DBLOOKUP = 0x0003,
  CMSG_QUERY_OBJECT_POSITION = 0x0004,
  SMSG_QUERY_OBJ_POSITION = 0x0005,
  CMSG_QUERY_OBJECT_ROTATION = 0x0006,
  SMSG_QUERY_OBJ_ROTATION = 0x0007,
  CMSG_WORLD_TELEPORT = 0x0008,
  CMSG_TELEPORT_TO_UNIT = 0x0009,
  CMSG_ZONE_MAP = 0x000A,
  SMSG_ZONE_MAP = 0x000B,
  CMSG_DEBUG_CHANGECELLZONE = 0x000C,
  CMSG_MOVE_CHARACTER_CHEAT = 0x000D,
  SMSG_MOVE_CHARACTER_CHEAT = 0x000E,
  CMSG_RECHARGE = 0x000F,
  CMSG_LEARN_SPELL = 0x0010,
  CMSG_CREATEMONSTER = 0x0011,
  CMSG_DESTROYMONSTER = 0x0012,
  CMSG_CREATEITEM = 0x0013,
  CMSG_CREATEGAMEOBJECT = 0x0014,
  SMSG_CHECK_FOR_BOTS = 0x0015,
  CMSG_MAKEMONSTERATTACKGUID = 0x0016,
  CMSG_BOT_DETECTED2 = 0x0017,
  CMSG_FORCEACTION = 0x0018,
  CMSG_FORCEACTIONONOTHER = 0x0019,
  CMSG_FORCEACTIONSHOW = 0x001A,
  SMSG_FORCEACTIONSHOW = 0x001B,
  CMSG_PETGODMODE = 0x001C,
  SMSG_PETGODMODE = 0x001D,
  SMSG_REFER_A_FRIEND_EXPIRED = 0x001E,
  CMSG_WEATHER_SPEED_CHEAT = 0x001F,
  CMSG_UNDRESSPLAYER = 0x0020,
  CMSG_BEASTMASTER = 0x0021,
  CMSG_GODMODE = 0x0022,
  SMSG_GOD_MODE = 0x0023,
  CMSG_CHEAT_SETMONEY = 0x0024,
  CMSG_LEVEL_CHEAT = 0x0025,
  CMSG_PET_LEVEL_CHEAT = 0x0026,
  CMSG_SET_WORLDSTATE = 0x0027,
  CMSG_COOLDOWN_CHEAT = 0x0028,
  CMSG_USE_SKILL_CHEAT = 0x0029,
  CMSG_FLAG_QUEST = 0x002A,
  CMSG_FLAG_QUEST_FINISH = 0x002B,
  CMSG_CLEAR_QUEST = 0x002C,
  CMSG_SEND_EVENT = 0x002D,
  CMSG_DEBUG_AISTATE = 0x002E,
  SMSG_DEBUG_AISTATE = 0x002F,
  CMSG_DISABLE_PVP_CHEAT = 0x0030,
  CMSG_ADVANCE_SPAWN_TIME = 0x0031,
  SMSG_DESTRUCTIBLE_BUILDING_DAMAGE = 0x0032,
  CMSG_AUTH_SRP6_BEGIN = 0x0033,
  CMSG_AUTH_SRP6_PROOF = 0x0034,
  CMSG_AUTH_SRP6_RECODE = 0x0035,
  CMSG_CREATE_CHARACTER = 0x0036,
  CMSG_ENUM_CHARACTERS = 0x0037,
  CMSG_CHAR_DELETE = 0x0038,
  SMSG_AUTH_SRP6_RESPONSE = 0x0039,
  SMSG_CREATE_CHAR = 0x003A,
  SMSG_ENUM_CHARACTERS_RESULT = 0x003B,
  SMSG_DELETE_CHAR = 0x003C,
  CMSG_PLAYER_LOGIN = 0x003D,
  SMSG_NEW_WORLD = 0x003E,
  SMSG_TRANSFER_PENDING = 0x003F,
  SMSG_TRANSFER_ABORTED = 0x0040,
  SMSG_CHARACTER_LOGIN_FAILED = 0x0041,
  SMSG_LOGIN_SET_TIME_SPEED = 0x0042,
  SMSG_GAME_TIME_UPDATE = 0x0043,
  CMSG_GAMETIME_SET = 0x0044,
  SMSG_GAME_TIME_SET = 0x0045,
  CMSG_GAMESPEED_SET = 0x0046,
  SMSG_GAME_SPEED_SET = 0x0047,
  CMSG_SERVERTIME = 0x0048,
  SMSG_SERVERTIME = 0x0049,
  CMSG_PLAYER_LOGOUT = 0x004A,
  CMSG_LOGOUT_REQUEST = 0x004B,
  SMSG_LOGOUT_RESPONSE = 0x004C,
  SMSG_LOGOUT_COMPLETE = 0x004D,
  CMSG_LOGOUT_CANCEL = 0x004E,
  SMSG_LOGOUT_CANCEL_ACK = 0x004F,
  CMSG_NAME_QUERY = 0x0050,
  SMSG_QUERY_PLAYER_NAME_RESPONSE = 0x0051,
  CMSG_QUERY_PET_NAME = 0x0052,
  SMSG_QUERY_PET_NAME_RESPONSE = 0x0053,
  CMSG_QUERY_GUILD_INFO = 0x0054,
  SMSG_QUERY_GUILD_INFO_RESPONSE = 0x0055,
  CMSG_ITEM_QUERY_SINGLE = 0x0056,
  CMSG_ITEM_QUERY_MULTIPLE = 0x0057,
  SMSG_ITEM_QUERY_SINGLE_RESPONSE = 0x0058,
  SMSG_ITEM_QUERY_MULTIPLE_RESPONSE = 0x0059,
  CMSG_QUERY_PAGE_TEXT = 0x005A,
  SMSG_QUERY_PAGE_TEXT_RESPONSE = 0x005B,
  CMSG_QUERY_QUEST_INFO = 0x005C,
  SMSG_QUERY_QUEST_INFO_RESPONSE = 0x005D,
  CMSG_QUERY_GAME_OBJECT = 0x005E,
  SMSG_QUERY_GAME_OBJECT_RESPONSE = 0x005F,
  CMSG_QUERY_CREATURE = 0x0060,
  SMSG_QUERY_CREATURE_RESPONSE = 0x0061,
  CMSG_WHO = 0x0062,
  SMSG_WHO = 0x0063,
  CMSG_WHO_IS = 0x0064,
  SMSG_WHO_IS = 0x0065,
  CMSG_CONTACT_LIST = 0x0066,
  SMSG_CONTACT_LIST = 0x0067,
  SMSG_FRIEND_STATUS = 0x0068,
  CMSG_ADD_FRIEND = 0x0069,
  CMSG_DEL_FRIEND = 0x006A,
  CMSG_SET_CONTACT_NOTES = 0x006B,
  CMSG_ADD_IGNORE = 0x006C,
  CMSG_DEL_IGNORE = 0x006D,
  CMSG_GROUP_INVITE = 0x006E,
  SMSG_GROUP_INVITE = 0x006F,
  CMSG_GROUP_CANCEL = 0x0070,
  SMSG_GROUP_CANCEL = 0x0071,
  CMSG_GROUP_ACCEPT = 0x0072,
  CMSG_GROUP_DECLINE = 0x0073,
  SMSG_GROUP_DECLINE = 0x0074,
  CMSG_GROUP_UNINVITE = 0x0075,
  CMSG_GROUP_UNINVITE_GUID = 0x0076,
  SMSG_GROUP_UNINVITE = 0x0077,
  CMSG_GROUP_SET_LEADER = 0x0078,
  SMSG_GROUP_SET_LEADER = 0x0079,
  CMSG_SET_LOOT_METHOD = 0x007A,
  CMSG_GROUP_DISBAND = 0x007B,
  SMSG_GROUP_DESTROYED = 0x007C,
  SMSG_GROUP_LIST = 0x007D,
  SMSG_PARTY_MEMBER_STATS = 0x007E,
  SMSG_PARTY_COMMAND_RESULT = 0x007F,
  UMSG_UPDATE_GROUP_MEMBERS = 0x0080,
  CMSG_GUILD_CREATE = 0x0081,
  CMSG_GUILD_INVITE = 0x0082,
  SMSG_GUILD_INVITE = 0x0083,
  CMSG_GUILD_ACCEPT = 0x0084,
  CMSG_GUILD_DECLINE_INVITATION = 0x0085,
  SMSG_GUILD_DECLINE = 0x0086,
  CMSG_GUILD_INFO = 0x0087,
  SMSG_GUILD_INFO = 0x0088,
  CMSG_GUILD_GET_ROSTER = 0x0089,
  SMSG_GUILD_ROSTER = 0x008A,
  CMSG_GUILD_PROMOTE_MEMBER = 0x008B,
  CMSG_GUILD_DEMOTE_MEMBER = 0x008C,
  CMSG_GUILD_LEAVE = 0x008D,
  CMSG_GUILD_OFFICER_REMOVE_MEMBER = 0x008E,
  CMSG_GUILD_DISBAND = 0x008F,
  CMSG_GUILD_LEADER = 0x0090,
  CMSG_GUILD_MOTD = 0x0091,
  SMSG_GUILD_EVENT = 0x0092,
  SMSG_GUILD_COMMAND_RESULT = 0x0093,
  UMSG_UPDATE_GUILD = 0x0094,
  CMSG_MESSAGECHAT = 0x0095,
  SMSG_CHAT = 0x0096,
  CMSG_CHAT_JOIN_CHANNEL = 0x0097,
  CMSG_CHAT_LEAVE_CHANNEL = 0x0098,
  SMSG_CHANNEL_NOTIFY = 0x0099,
  CMSG_CHAT_CHANNEL_LIST = 0x009A,
  SMSG_CHANNEL_LIST = 0x009B,
  CMSG_CHAT_CHANNEL_PASSWORD = 0x009C,
  CMSG_CHAT_CHANNEL_SET_OWNER = 0x009D,
  CMSG_CHAT_CHANNEL_OWNER = 0x009E,
  CMSG_CHAT_CHANNEL_MODERATOR = 0x009F,
  CMSG_CHAT_CHANNEL_UNMODERATOR = 0x00A0,
  CMSG_CHAT_CHANNEL_MUTE = 0x00A1,
  CMSG_CHAT_CHANNEL_UNMUTE = 0x00A2,
  CMSG_CHAT_CHANNEL_INVITE = 0x00A3,
  CMSG_CHAT_CHANNEL_KICK = 0x00A4,
  CMSG_CHAT_CHANNEL_BAN = 0x00A5,
  CMSG_CHAT_CHANNEL_UNBAN = 0x00A6,
  CMSG_CHAT_CHANNEL_ANNOUNCEMENTS = 0x00A7,
  CMSG_CHAT_CHANNEL_MODERATE = 0x00A8,
  SMSG_UPDATE_OBJECT = 0x00A9,
  SMSG_DESTROY_OBJECT = 0x00AA,
  CMSG_USE_ITEM = 0x00AB,
  CMSG_OPEN_ITEM = 0x00AC,
  CMSG_READ_ITEM = 0x00AD,
  SMSG_READ_ITEM_RESULT_OK = 0x00AE,
  SMSG_READ_ITEM_RESULT_FAILED = 0x00AF,
  SMSG_ITEM_COOLDOWN = 0x00B0,
  CMSG_GAME_OBJ_USE = 0x00B1,
  CMSG_DESTROY_ITEMS = 0x00B2,
  SMSG_GAME_OBJECT_CUSTOM_ANIM = 0x00B3,
  CMSG_AREA_TRIGGER = 0x00B4,
  MSG_MOVE_START_FORWARD = 0x00B5,
  MSG_MOVE_START_BACKWARD = 0x00B6,
  MSG_MOVE_STOP = 0x00B7,
  MSG_MOVE_START_STRAFE_LEFT = 0x00B8,
  MSG_MOVE_START_STRAFE_RIGHT = 0x00B9,
  MSG_MOVE_STOP_STRAFE = 0x00BA,
  MSG_MOVE_JUMP = 0x00BB,
  MSG_MOVE_START_TURN_LEFT = 0x00BC,
  MSG_MOVE_START_TURN_RIGHT = 0x00BD,
  MSG_MOVE_STOP_TURN = 0x00BE,
  MSG_MOVE_START_PITCH_UP = 0x00BF,
  MSG_MOVE_START_PITCH_DOWN = 0x00C0,
  MSG_MOVE_STOP_PITCH = 0x00C1,
  MSG_MOVE_SET_RUN_MODE = 0x00C2,
  MSG_MOVE_SET_WALK_MODE = 0x00C3,
  MSG_MOVE_TOGGLE_LOGGING = 0x00C4,
  MSG_MOVE_TELEPORT = 0x00C5,
  MSG_MOVE_TELEPORT_CHEAT = 0x00C6,
  MSG_MOVE_TELEPORT_ACK = 0x00C7,
  MSG_MOVE_TOGGLE_FALL_LOGGING = 0x00C8,
  MSG_MOVE_FALL_LAND = 0x00C9,
  MSG_MOVE_START_SWIM = 0x00CA,
  MSG_MOVE_STOP_SWIM = 0x00CB,
  MSG_MOVE_SET_RUN_SPEED_CHEAT = 0x00CC,
  MSG_MOVE_SET_RUN_SPEED = 0x00CD,
  MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT = 0x00CE,
  MSG_MOVE_SET_RUN_BACK_SPEED = 0x00CF,
  MSG_MOVE_SET_WALK_SPEED_CHEAT = 0x00D0,
  MSG_MOVE_SET_WALK_SPEED = 0x00D1,
  MSG_MOVE_SET_SWIM_SPEED_CHEAT = 0x00D2,
  MSG_MOVE_SET_SWIM_SPEED = 0x00D3,
  MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT = 0x00D4,
  MSG_MOVE_SET_SWIM_BACK_SPEED = 0x00D5,
  MSG_MOVE_SET_ALL_SPEED_CHEAT = 0x00D6,
  MSG_MOVE_SET_TURN_RATE_CHEAT = 0x00D7,
  MSG_MOVE_SET_TURN_RATE = 0x00D8,
  MSG_MOVE_TOGGLE_COLLISION_CHEAT = 0x00D9,
  MSG_MOVE_SET_FACING = 0x00DA,
  MSG_MOVE_SET_PITCH = 0x00DB,
  MSG_MOVE_WORLDPORT_ACK = 0x00DC,
  SMSG_ON_MONSTER_MOVE = 0x00DD,
  SMSG_MOVE_SET_WATER_WALK = 0x00DE,
  SMSG_MOVE_SET_LAND_WALK = 0x00DF,
  SMSG_FORCE_RUN_SPEED_CHANGE = 0x00E2,
  SMSG_FORCE_RUN_BACK_SPEED_CHANGE = 0x00E4,
  SMSG_FORCE_SWIM_SPEED_CHANGE = 0x00E6,
  SMSG_FORCE_MOVE_ROOT = 0x00E8,
  SMSG_FORCE_MOVE_UNROOT = 0x00EA,
  SMSG_MOVE_KNOCK_BACK = 0x00EF,
  SMSG_MOVE_SET_FEATHER_FALL = 0x00F2,
  SMSG_MOVE_SET_NORMAL_FALL = 0x00F3,
  SMSG_MOVE_SET_HOVERING = 0x00F4,
  SMSG_MOVE_UNSET_HOVERING = 0x00F5,
  SMSG_TRIGGER_CINEMATIC = 0x00FA,
  SMSG_TUTORIAL_FLAGS = 0x00FD,
  SMSG_EMOTE = 0x0103,
  SMSG_TEXT_EMOTE = 0x0105,
  SMSG_INVENTORY_CHANGE_FAILURE = 0x0112,
  SMSG_OPEN_CONTAINER = 0x0113,
  SMSG_INSPECT_RESULTS_UPDATE = 0x0115,
  SMSG_TRADE_STATUS = 0x0120,
  SMSG_TRADE_STATUS_EXTENDED = 0x0121,
  SMSG_INITIALIZE_FACTIONS = 0x0122,
  SMSG_SET_FACTION_VISIBLE = 0x0123,
  SMSG_SET_FACTION_STANDING = 0x0124,
  SMSG_SET_PROFICIENCY = 0x0127,
  SMSG_UPDATE_ACTION_BUTTONS = 0x0129,
  SMSG_SEND_KNOWN_SPELLS = 0x012A,
  SMSG_LEARNED_SPELL = 0x012B,
  SMSG_SUPERCEDED_SPELLS = 0x012C,
  SMSG_CAST_FAILED = 0x0130,
  SMSG_SPELL_START = 0x0131,
  SMSG_SPELL_GO = 0x0132,
  SMSG_SPELL_FAILURE = 0x0133,
  SMSG_SPELL_COOLDOWN = 0x0134,
  SMSG_COOLDOWN_EVENT = 0x0135,
  SMSG_EQUIPMENT_SET_ID = 0x0137,
  SMSG_PET_CAST_FAILED = 0x0138,
  SMSG_AI_REACTION = 0x013C,
  SMSG_ATTACK_START = 0x0143,
  SMSG_ATTACK_STOP = 0x0144,
  SMSG_ATTACKSWING_NOTINRANGE = 0x0145,
  SMSG_ATTACKSWING_BADFACING = 0x0146,
  SMSG_INSTANCE_LOCK_WARNING_QUERY = 0x0147,
  SMSG_ATTACKSWING_DEADTARGET = 0x0148,
  SMSG_ATTACKSWING_CANT_ATTACK = 0x0149,
  SMSG_ATTACKER_STATE_UPDATE = 0x014A,
  SMSG_BATTLEFIELD_PORT_DENIED = 0x014B,
  CMSG_PERFORM_ACTION_SET = 0x014C,
  SMSG_RESUME_CAST_BAR = 0x014D,
  SMSG_CANCEL_COMBAT = 0x014E,
  SMSG_SPELL_BREAK_LOG = 0x014F,
  SMSG_SPELL_HEAL_LOG = 0x0150,
  SMSG_SPELL_ENERGIZE_LOG = 0x0151,
  SMSG_BREAK_TARGET = 0x0152,
  CMSG_SAVE_PLAYER = 0x0153,
  CMSG_SETDEATHBINDPOINT = 0x0154,
  SMSG_BIND_POINT_UPDATE = 0x0155,
  CMSG_GETDEATHBINDZONE = 0x0156,
  SMSG_BINDZONEREPLY = 0x0157,
  SMSG_PLAYER_BOUND = 0x0158,
  SMSG_CONTROL_UPDATE = 0x0159,
  CMSG_REPOP_REQUEST = 0x015A,
  SMSG_RESURRECT_REQUEST = 0x015B,
  CMSG_RESURRECT_RESPONSE = 0x015C,
  CMSG_LOOT_UNIT = 0x015D,
  CMSG_LOOT_MONEY = 0x015E,
  CMSG_LOOT_RELEASE = 0x015F,
  SMSG_LOOT_RESPONSE = 0x0160,
  SMSG_LOOT_RELEASE = 0x0161,
  SMSG_LOOT_REMOVED = 0x0162,
  SMSG_LOOT_MONEY_NOTIFY = 0x0163,
  SMSG_LOOT_ITEM_NOTIFY = 0x0164,
  SMSG_LOOT_CLEAR_MONEY = 0x0165,
  SMSG_ITEM_PUSH_RESULT = 0x0166,
  SMSG_DUEL_REQUESTED = 0x0167,
  SMSG_DUEL_OUT_OF_BOUNDS = 0x0168,
  SMSG_DUEL_IN_BOUNDS = 0x0169,
  SMSG_DUEL_COMPLETE = 0x016A,
  SMSG_DUEL_WINNER = 0x016B,
  CMSG_DUEL_ACCEPTED = 0x016C,
  CMSG_DUEL_CANCELLED = 0x016D,
  SMSG_MOUNT_RESULT = 0x016E,
  SMSG_DISMOUNT_RESULT = 0x016F,
  SMSG_REMOVED_FROM_PVP_QUEUE = 0x0170,
  CMSG_MOUNT_SPECIAL_ANIM = 0x0171,
  SMSG_MOUNT_SPECIAL_ANIM = 0x0172,
  SMSG_PET_TAME_FAILURE = 0x0173,
  CMSG_PET_SET_ACTION = 0x0174,
  CMSG_PET_ACTION = 0x0175,
  CMSG_PET_ABANDON = 0x0176,
  CMSG_PET_RENAME = 0x0177,
  SMSG_PET_NAME_INVALID = 0x0178,
  SMSG_PET_SPELLS_MESSAGE = 0x0179,
  SMSG_PET_MODE = 0x017A,
  CMSG_GOSSIP_HELLO = 0x017B,
  CMSG_GOSSIP_SELECT_OPTION = 0x017C,
  SMSG_GOSSIP_MESSAGE = 0x017D,
  SMSG_GOSSIP_COMPLETE = 0x017E,
  CMSG_QUERY_NPC_TEXT = 0x017F,
  SMSG_QUERY_NPC_TEXT_RESPONSE = 0x0180,
  SMSG_NPC_WONT_TALK = 0x0181,
  CMSG_QUEST_GIVER_STATUS_QUERY = 0x0182,
  SMSG_QUEST_GIVER_STATUS = 0x0183,
  CMSG_QUEST_GIVER_HELLO = 0x0184,
  SMSG_QUEST_GIVER_QUEST_LIST_MESSAGE = 0x0185,
  CMSG_QUEST_GIVER_QUERY_QUEST = 0x0186,
  CMSG_QUEST_GIVER_QUEST_AUTOLAUNCH = 0x0187,
  SMSG_QUEST_GIVER_QUEST_DETAILS = 0x0188,
  CMSG_QUEST_GIVER_ACCEPT_QUEST = 0x0189,
  CMSG_QUEST_GIVER_COMPLETE_QUEST = 0x018A,
  SMSG_QUEST_GIVER_REQUEST_ITEMS = 0x018B,
  CMSG_QUEST_GIVER_REQUEST_REWARD = 0x018C,
  SMSG_QUEST_GIVER_OFFER_REWARD_MESSAGE = 0x018D,
  CMSG_QUEST_GIVER_CHOOSE_REWARD = 0x018E,
  SMSG_QUEST_GIVER_INVALID_QUEST = 0x018F,
  CMSG_QUEST_GIVER_CANCEL = 0x0190,
  SMSG_QUEST_GIVER_QUEST_COMPLETE = 0x0191,
  SMSG_QUEST_GIVER_QUEST_FAILED = 0x0192,
  CMSG_QUEST_LOG_SWAP_QUEST = 0x0193,
  CMSG_QUEST_LOG_REMOVE_QUEST = 0x0194,
  SMSG_QUEST_LOG_FULL = 0x0195,
  SMSG_QUEST_UPDATE_FAILED = 0x0196,
  SMSG_QUEST_UPDATE_FAILED_TIMER = 0x0197,
  SMSG_QUEST_UPDATE_COMPLETE = 0x0198,
  SMSG_QUEST_UPDATE_ADD_KILL = 0x0199,
  SMSG_QUEST_UPDATE_ADD_ITEM = 0x019A,
  CMSG_QUEST_CONFIRM_ACCEPT = 0x019B,
  SMSG_QUEST_CONFIRM_ACCEPT = 0x019C,
  CMSG_PUSH_QUEST_TO_PARTY = 0x019D,
  CMSG_LIST_INVENTORY = 0x019E,
  SMSG_VENDOR_INVENTORY = 0x019F,
  CMSG_SELL_ITEM = 0x01A0,
  SMSG_SELL_ITEM = 0x01A1,
  CMSG_BUY_ITEM = 0x01A2,
  CMSG_BUY_ITEM_IN_SLOT = 0x01A3,
  SMSG_BUY_SUCCEEDED = 0x01A4,
  SMSG_BUY_FAILED = 0x01A5,
  CMSG_TAXICLEARALLNODES = 0x01A6,
  CMSG_TAXIENABLEALLNODES = 0x01A7,
  CMSG_TAXISHOWNODES = 0x01A8,
  SMSG_SHOW_TAXI_NODES = 0x01A9,
  CMSG_TAXI_NODE_STATUS_QUERY = 0x01AA,
  SMSG_TAXI_NODE_STATUS = 0x01AB,
  CMSG_TAXI_QUERY_AVAILABLE_NODES = 0x01AC,
  CMSG_ACTIVATE_TAXI = 0x01AD,
  SMSG_ACTIVATE_TAXI_REPLY = 0x01AE,
  SMSG_NEW_TAXI_PATH = 0x01AF,
  CMSG_TRAINER_LIST = 0x01B0,
  SMSG_TRAINER_LIST = 0x01B1,
  CMSG_TRAINER_BUY_SPELL = 0x01B2,
  SMSG_TRAINER_BUY_SUCCEEDED = 0x01B3,
  SMSG_TRAINER_BUY_FAILED = 0x01B4,
  CMSG_BINDER_ACTIVATE = 0x01B5,
  SMSG_PLAYERBINDERROR = 0x01B6,
  CMSG_BANKER_ACTIVATE = 0x01B7,
  SMSG_SHOW_BANK = 0x01B8,
  CMSG_BUY_BANK_SLOT = 0x01B9,
  SMSG_BUY_BANK_SLOT_RESULT = 0x01BA,
  CMSG_PETITION_SHOW_LIST = 0x01BB,
  SMSG_PETITION_SHOW_LIST = 0x01BC,
  CMSG_PETITION_BUY = 0x01BD,
  CMSG_PETITION_SHOW_SIGNATURES = 0x01BE,
  SMSG_PETITION_SHOW_SIGNATURES = 0x01BF,
  CMSG_PETITION_SIGN = 0x01C0,
  SMSG_PETITION_SIGN_RESULTS = 0x01C1,
  CMSG_OFFER_PETITION = 0x01C3,
  CMSG_TURN_IN_PETITION = 0x01C4,
  SMSG_TURN_IN_PETITION_RESULT = 0x01C5,
  CMSG_PETITION_QUERY = 0x01C6,
  SMSG_PETITION_QUERY_RESPONSE = 0x01C7,
  SMSG_FISH_NOT_HOOKED = 0x01C8,
  SMSG_FISH_ESCAPED = 0x01C9,
  CMSG_BUG = 0x01CA,
  SMSG_NOTIFICATION = 0x01CB,
  CMSG_REQUEST_PLAYED_TIME = 0x01CC,
  SMSG_PLAYED_TIME = 0x01CD,
  CMSG_QUERY_TIME = 0x01CE,
  SMSG_QUERY_TIME_RESPONSE = 0x01CF,
  SMSG_LOG_XP_GAIN = 0x01D0,
  SMSG_AURACASTLOG = 0x01D1,
  CMSG_RECLAIM_CORPSE = 0x01D2,
  CMSG_WRAP_ITEM = 0x01D3,
  SMSG_LEVEL_UP_INFO = 0x01D4,
  SMSG_RESISTLOG = 0x01D6,
  SMSG_ENCHANTMENT_LOG = 0x01D7,
  CMSG_SET_SKILL_CHEAT = 0x01D8,
  SMSG_START_MIRROR_TIMER = 0x01D9,
  SMSG_PAUSE_MIRROR_TIMER = 0x01DA,
  SMSG_STOP_MIRROR_TIMER = 0x01DB,
  CMSG_PING = 0x01DC,
  SMSG_PONG = 0x01DD,
  SMSG_CLEAR_COOLDOWN = 0x01DE,
  SMSG_PAGE_TEXT = 0x01DF,
  CMSG_SET_SHEATHED = 0x01E0,
  SMSG_COOLDOWN_CHEAT = 0x01E1,
  SMSG_SPELL_DELAYED = 0x01E2,
  CMSG_QUEST_POI_QUERY = 0x01E3,
  SMSG_QUEST_POI_QUERY_RESPONSE = 0x01E4,
  CMSG_GHOST = 0x01E5,
  CMSG_GM_INVIS = 0x01E6,
  SMSG_INVALID_PROMOTION_CODE = 0x01E7,
  SMSG_ITEM_TIME_UPDATE = 0x01EA,
  SMSG_ITEM_ENCHANT_TIME_UPDATE = 0x01EB,
  SMSG_AUTH_CHALLENGE = 0x01EC,
  CMSG_AUTH_SESSION = 0x01ED,
  SMSG_AUTH_RESPONSE = 0x01EE,
  CMSG_PET_CAST_SPELL = 0x01F0,
  SMSG_PLAY_SPELL_VISUAL = 0x01F3,
  CMSG_ZONEUPDATE = 0x01F4,
  SMSG_PARTY_KILL_LOG = 0x01F5,
  SMSG_COMPRESSED_UPDATE_OBJECT = 0x01F6,
  SMSG_PLAY_SPELL_IMPACT = 0x01F7,
  SMSG_EXPLORATION_EXPERIENCE = 0x01F8,
  CMSG_GM_SET_SECURITY_GROUP = 0x01F9,
  CMSG_GM_NUKE = 0x01FA,
  SMSG_ENVIRONMENTAL_DAMAGE_LOG = 0x01FC,
  CMSG_CHANGEPLAYER_DIFFICULTY = 0x01FD,
  SMSG_RWHOIS = 0x01FE,
  SMSG_LFG_PLAYER_REWARD = 0x01FF,
  SMSG_LFG_TELEPORT_DENIED = 0x0200,
  CMSG_UNLEARN_SPELL = 0x0201,
  CMSG_UNLEARN_SKILL = 0x0202,
  SMSG_UNLEARNED_SPELLS = 0x0203,
  CMSG_DECHARGE = 0x0204,
  CMSG_GM_TICKET_CREATE = 0x0205,
  SMSG_GM_TICKET_CREATE = 0x0206,
  CMSG_GM_TICKET_UPDATE_TEXT = 0x0207,
  SMSG_GM_TICKET_UPDATE_TEXT = 0x0208,
  SMSG_ACCOUNT_DATA_TIMES = 0x0209,
  CMSG_REQUEST_ACCOUNT_DATA = 0x020A,
  CMSG_UPDATE_ACCOUNT_DATA = 0x020B,
  SMSG_UPDATE_ACCOUNT_DATA = 0x020C,
  SMSG_CLEAR_FAR_SIGHT_IMMEDIATE = 0x020D,
  SMSG_CHANGE_PLAYER_DIFFICULTY_RESULT = 0x020E,
  CMSG_GM_TEACH = 0x020F,
  CMSG_GM_CREATE_ITEM_TARGET = 0x0210,
  CMSG_GM_TICKET_GET_TICKET = 0x0211,
  SMSG_GM_TICKET_GET_TICKET = 0x0212,
  CMSG_UNLEARN_TALENTS = 0x0213,
  SMSG_UPDATE_INSTANCE_ENCOUNTER_UNIT = 0x0214,
  SMSG_GAMEOBJECT_DESPAWN_ANIM = 0x0215,
  CMSG_GM_TICKET_DELETE_TICKET = 0x0217,
  SMSG_GM_TICKET_DELETE_TICKET = 0x0218,
  SMSG_CHAT_WRONG_FACTION = 0x0219,
  CMSG_GM_TICKET_GET_SYSTEM_STATUS = 0x021A,
  SMSG_GM_TICKET_GET_SYSTEM_STATUS = 0x021B,
  CMSG_SPIRIT_HEALER_ACTIVATE = 0x021C,
  CMSG_SET_STAT_CHEAT = 0x021D,
  SMSG_QUEST_FORCE_REMOVED = 0x021E,
  CMSG_SKILL_BUY_STEP = 0x021F,
  CMSG_SKILL_BUY_RANK = 0x0220,
  CMSG_XP_CHEAT = 0x0221,
  SMSG_SPIRIT_HEALER_CONFIRM = 0x0222,
  CMSG_CHARACTER_POINT_CHEAT = 0x0223,
  SMSG_GOSSIP_POI = 0x0224,
  CMSG_CHAT_REPORT_IGNORED = 0x0225,
  CMSG_GM_VISION = 0x0226,
  CMSG_SERVER_COMMAND = 0x0227,
  CMSG_GM_SILENCE = 0x0228,
  CMSG_GM_REVEALTO = 0x0229,
  CMSG_GM_RESURRECT = 0x022A,
  CMSG_GM_SUMMONMOB = 0x022B,
  CMSG_GM_MOVECORPSE = 0x022C,
  CMSG_GM_FREEZE = 0x022D,
  CMSG_GM_UBERINVIS = 0x022E,
  CMSG_GM_REQUEST_PLAYER_INFO = 0x022F,
  SMSG_GM_PLAYER_INFO = 0x0230,
  CMSG_GUILD_SET_RANK_PERMISSIONS = 0x0231,
  CMSG_GUILD_ADD_RANK = 0x0232,
  CMSG_GUILD_DELETE_RANK = 0x0233,
  CMSG_GUILD_SET_PUBLIC_NOTE = 0x0234,
  CMSG_GUILD_SET_OFFICER_NOTE = 0x0235,
  SMSG_LOGIN_VERIFY_WORLD = 0x0236,
  CMSG_CLEAR_EXPLORATION = 0x0237,
  CMSG_SEND_MAIL = 0x0238,
  SMSG_MAIL_COMMAND_RESULT = 0x0239,
  CMSG_MAIL_GET_LIST = 0x023A,
  SMSG_MAIL_LIST_RESULT = 0x023B,
  CMSG_BATTLEFIELD_LIST = 0x023C,
  SMSG_BATTLEFIELD_LIST = 0x023D,
  CMSG_BATTLEFIELD_JOIN = 0x023E,
  SMSG_FORCE_SET_VEHICLE_REC_ID = 0x023F,
  CMSG_SET_VEHICLE_REC_ID_ACK = 0x0240,
  CMSG_TAXICLEARNODE = 0x0241,
  CMSG_TAXIENABLENODE = 0x0242,
  CMSG_ITEM_TEXT_QUERY = 0x0243,
  SMSG_QUERY_ITEM_TEXT_RESPONSE = 0x0244,
  CMSG_MAIL_TAKE_MONEY = 0x0245,
  CMSG_MAIL_TAKE_ITEM = 0x0246,
  CMSG_MAIL_MARK_AS_READ = 0x0247,
  CMSG_MAIL_RETURN_TO_SENDER = 0x0248,
  CMSG_MAIL_DELETE = 0x0249,
  CMSG_MAIL_CREATE_TEXT_ITEM = 0x024A,
  SMSG_SPELL_MISS_LOG = 0x024B,
  SMSG_SPELL_EXECUTE_LOG = 0x024C,
  SMSG_DEBUGAURAPROC = 0x024D,
  SMSG_SPELL_PERIODIC_AURA_LOG = 0x024E,
  SMSG_SPELL_DAMAGE_SHIELD = 0x024F,
  SMSG_SPELL_NON_MELEE_DAMAGE_LOG = 0x0250,
  CMSG_LEARN_TALENT = 0x0251,
  SMSG_RESURRECT_FAILED = 0x0252,
  CMSG_TOGGLE_PVP = 0x0253,
  SMSG_ZONE_UNDER_ATTACK = 0x0254,
  CMSG_AUCTION_SELL_ITEM = 0x0256,
  CMSG_AUCTION_REMOVE_ITEM = 0x0257,
  CMSG_AUCTION_LIST_ITEMS = 0x0258,
  CMSG_AUCTION_LIST_OWNER_ITEMS = 0x0259,
  CMSG_AUCTION_PLACE_BID = 0x025A,
  SMSG_AUCTION_COMMAND_RESULT = 0x025B,
  SMSG_AUCTION_LIST_RESULT = 0x025C,
  SMSG_AUCTION_LIST_OWNER_ITEMS_RESULT = 0x025D,
  SMSG_AUCTION_BIDDER_NOTIFICATION = 0x025E,
  SMSG_AUCTION_OWNER_NOTIFICATION = 0x025F,
  SMSG_PROC_RESIST = 0x0260,
  SMSG_COMBAT_EVENT_FAILED = 0x0261,
  SMSG_DISPEL_FAILED = 0x0262,
  SMSG_SPELL_OR_DAMAGE_IMMUNE = 0x0263,
  CMSG_AUCTION_LIST_BIDDER_ITEMS = 0x0264,
  SMSG_AUCTION_LIST_BIDDER_ITEMS_RESULT = 0x0265,
  SMSG_SET_FLAT_SPELL_MODIFIER = 0x0266,
  SMSG_SET_PCT_SPELL_MODIFIER = 0x0267,
  CMSG_SET_AMMO = 0x0268,
  SMSG_CORPSE_RECLAIM_DELAY = 0x0269,
  CMSG_SET_ACTIVE_MOVER = 0x026A,
  CMSG_PET_CANCEL_AURA = 0x026B,
  CMSG_PLAYER_AI_CHEAT = 0x026C,
  CMSG_CANCEL_AUTO_REPEAT_SPELL = 0x026D,
  CMSG_STABLE_PET = 0x0270,
  CMSG_UNSTABLE_PET = 0x0271,
  CMSG_BUY_STABLE_SLOT = 0x0272,
  SMSG_STABLE_RESULT = 0x0273,
  CMSG_STABLE_REVIVE_PET = 0x0274,
  CMSG_STABLE_SWAP_PET = 0x0275,
  SMSG_PLAY_MUSIC = 0x0277,
  SMSG_PLAY_OBJECT_SOUND = 0x0278,
  CMSG_REQUEST_PET_INFO = 0x0279,
  CMSG_FAR_SIGHT = 0x027A,
  SMSG_SPELL_DISPELL_LOG = 0x027B,
  SMSG_DAMAGE_CALC_LOG = 0x027C,
  CMSG_ENABLE_DAMAGE_LOG = 0x027D,
  CMSG_GROUP_CHANGE_SUB_GROUP = 0x027E,
  CMSG_REQUEST_PARTY_MEMBER_STATS = 0x027F,
  CMSG_GROUP_SWAP_SUB_GROUP = 0x0280,
  CMSG_RESET_FACTION_CHEAT = 0x0281,
  CMSG_AUTOSTORE_BANK_ITEM = 0x0282,
  CMSG_AUTOBANK_ITEM = 0x0283,
  SMSG_RECEIVED_MAIL = 0x0285,
  SMSG_RAID_GROUP_ONLY = 0x0286,
  CMSG_SET_DURABILITY_CHEAT = 0x0287,
  CMSG_SET_PVP_RANK_CHEAT = 0x0288,
  CMSG_ADD_PVP_MEDAL_CHEAT = 0x0289,
  CMSG_DEL_PVP_MEDAL_CHEAT = 0x028A,
  CMSG_SET_PVP_TITLE = 0x028B,
  SMSG_PVP_CREDIT = 0x028C,
  SMSG_AUCTION_REMOVED_NOTIFICATION = 0x028D,
  CMSG_GROUP_RAID_CONVERT = 0x028E,
  CMSG_SET_ASSISTANT_LEADER = 0x028F,
  CMSG_BUY_BACK_ITEM = 0x0290,
  SMSG_CHAT_SERVER_MESSAGE = 0x0291,
  CMSG_SET_SAVED_INSTANCE_EXTEND = 0x0292,
  SMSG_LFG_OFFER_CONTINUE = 0x0293,
  CMSG_TEST_DROP_RATE = 0x0294,
  SMSG_TEST_DROP_RATE_RESULT = 0x0295,
  CMSG_DF_GET_JOIN_STATUS = 0x0296,
  SMSG_SHOW_MAILBOX = 0x0297,
  SMSG_RESET_RANGED_COMBAT_TIMER = 0x0298,
  SMSG_CHAT_NOT_IN_PARTY = 0x0299,
  CMSG_GMTICKETSYSTEM_TOGGLE = 0x029A,
  CMSG_CANCEL_GROWTH_AURA = 0x029B,
  SMSG_CANCEL_AUTO_REPEAT = 0x029C,
  SMSG_STAND_STATE_UPDATE = 0x029D,
  SMSG_LOOT_ALL_PASSED = 0x029E,
  SMSG_LOOT_ROLL_WON = 0x029F,
  CMSG_LOOT_ROLL = 0x02A0,
  SMSG_LOOT_START_ROLL = 0x02A1,
  SMSG_LOOT_ROLL = 0x02A2,
  CMSG_LOOT_MASTER_GIVE = 0x02A3,
  SMSG_LOOT_MASTER_LIST = 0x02A4,
  SMSG_SET_FORCED_REACTIONS = 0x02A5,
  SMSG_SPELL_FAILED_OTHER = 0x02A6,
  SMSG_GAME_OBJECT_RESET_STATE = 0x02A7,
  CMSG_REPAIR_ITEM = 0x02A8,
  SMSG_CHAT_PLAYER_NOTFOUND = 0x02A9,
  SMSG_SUMMON_REQUEST = 0x02AB,
  CMSG_SUMMON_RESPONSE = 0x02AC,
  SMSG_MONSTER_MOVE_TRANSPORT = 0x02AE,
  SMSG_PET_BROKEN = 0x02AF,
  CMSG_SERVER_BROADCAST = 0x02B2,
  CMSG_SELF_RES = 0x02B3,
  SMSG_FEIGN_DEATH_RESISTED = 0x02B4,
  CMSG_RUN_SCRIPT = 0x02B5,
  SMSG_SCRIPT_MESSAGE = 0x02B6,
  SMSG_DUEL_COUNTDOWN = 0x02B7,
  SMSG_AREA_TRIGGER_MESSAGE = 0x02B8,
  CMSG_SHOWING_HELM = 0x02B9,
  CMSG_SHOWING_CLOAK = 0x02BA,
  SMSG_LFG_ROLE_CHOSEN = 0x02BB,
  SMSG_PLAYER_SKINNED = 0x02BC,
  SMSG_DURABILITY_DAMAGE_DEATH = 0x02BD,
  CMSG_SET_EXPLORATION = 0x02BE,
  CMSG_SET_ACTION_BAR_TOGGLES = 0x02BF,
  SMSG_INIT_WORLD_STATES = 0x02C2,
  SMSG_UPDATE_WORLD_STATE = 0x02C3,
  CMSG_ITEM_NAME_QUERY = 0x02C4,
  SMSG_ITEM_NAME_QUERY_RESPONSE = 0x02C5,
  SMSG_PET_ACTION_FEEDBACK = 0x02C6,
  CMSG_CHARACTER_RENAME_REQUEST = 0x02C7,
  SMSG_CHARACTER_RENAME_RESULT = 0x02C8,
  CMSG_MOVE_SPLINE_DONE = 0x02C9,
  CMSG_MOVE_FALL_RESET = 0x02CA,
  SMSG_INSTANCE_SAVE_CREATED = 0x02CB,
  SMSG_RAID_INSTANCE_INFO = 0x02CC,
  CMSG_REQUEST_RAID_INFO = 0x02CD,
  CMSG_MOVE_TIME_SKIPPED = 0x02CE,
  CMSG_MOVE_FEATHER_FALL_ACK = 0x02CF,
  CMSG_MOVE_WATER_WALK_ACK = 0x02D0,
  CMSG_MOVE_NOT_ACTIVE_MOVER = 0x02D1,
  SMSG_PLAY_SOUND = 0x02D2,
  CMSG_BATTLEFIELD_STATUS = 0x02D3,
  SMSG_BATTLEFIELD_STATUS = 0x02D4,
  CMSG_BATTLEGROUND_PORT_AND_LEAVE = 0x02D5,
  CMSG_BATTLEMASTER_HELLO = 0x02D7,
  CMSG_MOVE_START_SWIM_CHEAT = 0x02D8,
  CMSG_MOVE_STOP_SWIM_CHEAT = 0x02D9,
  SMSG_FORCE_WALK_SPEED_CHANGE = 0x02DA,
  CMSG_FORCE_WALK_SPEED_CHANGE_ACK = 0x02DB,
  SMSG_FORCE_SWIM_BACK_SPEED_CHANGE = 0x02DC,
  CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK = 0x02DD,
  SMSG_FORCE_TURN_RATE_CHANGE = 0x02DE,
  CMSG_FORCE_TURN_RATE_CHANGE_ACK = 0x02DF,
  CMSG_LEAVE_BATTLEFIELD = 0x02E1,
  CMSG_AREA_SPIRIT_HEALER_QUERY = 0x02E2,
  CMSG_AREA_SPIRIT_HEALER_QUEUE = 0x02E3,
  SMSG_AREA_SPIRIT_HEALER_TIME = 0x02E4,
  CMSG_GM_UNTEACH = 0x02E5,
  SMSG_WARDEN_DATA = 0x02E6,
  CMSG_WARDEN_DATA = 0x02E7,
  SMSG_BATTLEFIELD_STATUS_QUEUED = 0x02E8,
  CMSG_PET_STOP_ATTACK = 0x02EA,
  SMSG_BINDER_CONFIRM = 0x02EB,
  SMSG_BATTLEGROUND_PLAYER_JOINED = 0x02EC,
  SMSG_BATTLEGROUND_PLAYER_LEFT = 0x02ED,
  CMSG_BATTLEMASTER_JOIN = 0x02EE,
  SMSG_ADDON_INFO = 0x02EF,
  CMSG_PET_UNLEARN = 0x02F0,
  SMSG_PET_UNLEARN_CONFIRM = 0x02F1,
  SMSG_PARTY_MEMBER_STATS_FULL = 0x02F2,
  CMSG_PET_SPELL_AUTOCAST = 0x02F3,
  SMSG_WEATHER = 0x02F4,
  SMSG_PLAY_TIME_WARNING = 0x02F5,
  SMSG_MINIGAME_SETUP = 0x02F6,
  SMSG_MINIGAME_STATE = 0x02F7,
  CMSG_MINIGAME_MOVE = 0x02F8,
  SMSG_MINIGAME_MOVE_FAILED = 0x02F9,
  SMSG_RAID_INSTANCE_MESSAGE = 0x02FA,
  SMSG_COMPRESSED_MOVES = 0x02FB,
  CMSG_GUILD_INFO_TEXT = 0x02FC,
  SMSG_CHAT_RESTRICTED = 0x02FD,
  SMSG_MOVE_SPLINE_SET_RUN_SPEED = 0x02FE,
  SMSG_MOVE_SPLINE_SET_RUN_BACK_SPEED = 0x02FF,
  SMSG_MOVE_SPLINE_SET_SWIM_SPEED = 0x0300,
  SMSG_MOVE_SPLINE_SET_WALK_BACK_SPEED = 0x0301,
  SMSG_MOVE_SPLINE_SET_SWIM_BACK_SPEED = 0x0302,
  SMSG_MOVE_SPLINE_SET_TURN_RATE = 0x0303,
  SMSG_MOVE_SPLINE_UNROOT = 0x0304,
  SMSG_MOVE_SPLINE_SET_FEATHER_FALL = 0x0305,
  SMSG_MOVE_SPLINE_SET_NORMAL_FALL = 0x0306,
  SMSG_MOVE_SPLINE_SET_HOVER = 0x0307,
  SMSG_MOVE_SPLINE_UNSET_HOVER = 0x0308,
  SMSG_MOVE_SPLINE_SET_WATER_WALK = 0x0309,
  SMSG_MOVE_SPLINE_SET_LAND_WALK = 0x030A,
  SMSG_MOVE_SPLINE_START_SWIM = 0x030B,
  SMSG_MOVE_SPLINE_STOP_SWIM = 0x030C,
  SMSG_MOVE_SPLINE_SET_RUN_MODE = 0x030D,
  SMSG_MOVE_SPLINE_SET_WALK_MODE = 0x030E,
  CMSG_GM_NUKE_ACCOUNT = 0x030F,
  CMSG_GM_DESTROY_ONLINE_CORPSE = 0x0311,
  CMSG_ACTIVATE_TAXI_EXPRESS = 0x0312,
  SMSG_SET_FACTION_AT_WAR = 0x0313,
  SMSG_GAMETIMEBIAS_SET = 0x0314,
  CMSG_DEBUG_ACTIONS_START = 0x0315,
  CMSG_DEBUG_ACTIONS_STOP = 0x0316,
  CMSG_SET_FACTION_INACTIVE = 0x0317,
  CMSG_SET_WATCHED_FACTION = 0x0318,
  SMSG_MOVE_SPLINE_ROOT = 0x031A,
  CMSG_SET_EXPLORATION_ALL = 0x031B,
  SMSG_INVALIDATE_PLAYER = 0x031C,
  CMSG_RESET_INSTANCES = 0x031D,
  SMSG_INSTANCE_RESET = 0x031E,
  SMSG_INSTANCE_RESET_FAILED = 0x031F,
  SMSG_UPDATE_LAST_INSTANCE = 0x0320,
  CMSG_LUA_USAGE = 0x0323,
  SMSG_PET_ACTION_SOUND = 0x0324,
  SMSG_PET_DISMISS_SOUND = 0x0325,
  SMSG_GHOSTEE_GONE = 0x0326,
  CMSG_GM_UPDATE_TICKET_STATUS = 0x0327,
  SMSG_GM_TICKET_STATUS_UPDATE = 0x0328,
  CMSG_GM_SURVEY_SUBMIT = 0x032A,
  SMSG_UPDATE_INSTANCE_OWNERSHIP = 0x032B,
  CMSG_IGNORE_KNOCKBACK_CHEAT = 0x032C,
  SMSG_CHAT_PLAYER_AMBIGUOUS = 0x032D,
  SMSG_SPELL_INSTAKILL_LOG = 0x032F,
  SMSG_SPELL_UPDATE_CHAIN_TARGETS = 0x0330,
  CMSG_CHAT_REPORT_FILTERED = 0x0331,
  SMSG_EXPECTED_SPAM_RECORDS = 0x0332,
  SMSG_SPELL_STEAL_LOG = 0x0333,
  CMSG_LOTTERY_QUERY_OBSOLETE = 0x0334,
  SMSG_LOTTERY_QUERY_RESULT_OBSOLETE = 0x0335,
  CMSG_BUY_LOTTERY_TICKET_OBSOLETE = 0x0336,
  SMSG_LOTTERY_RESULT_OBSOLETE = 0x0337,
  SMSG_CHARACTER_PROFILE = 0x0338,
  SMSG_CHARACTER_PROFILE_REALM_CONNECTED = 0x0339,
  SMSG_DEFENSE_MESSAGE = 0x033A,
  SMSG_INSTANCE_DIFFICULTY = 0x033B,
  SMSG_MOTD = 0x033D,
  SMSG_MOVE_ENABLE_TRANSITION_BETWEEN_SWIM_AND_FLY = 0x033E,
  SMSG_MOVE_DISABLE_TRANSITION_BETWEEN_SWIM_AND_FLY = 0x033F,
  CMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY_ACK = 0x0340,
  SMSG_MOVE_SET_CAN_FLY = 0x0343,
  SMSG_MOVE_UNSET_CAN_FLY = 0x0344,
  CMSG_MOVE_SET_CAN_FLY_ACK = 0x0345,
  CMSG_MOVE_SET_FLY = 0x0346,
  CMSG_SOCKET_GEMS = 0x0347,
  CMSG_ARENA_TEAM_CREATE = 0x0348,
  SMSG_ARENA_TEAM_COMMAND_RESULT = 0x0349,
  CMSG_ARENA_TEAM_QUERY = 0x034B,
  SMSG_ARENA_TEAM_QUERY_RESPONSE = 0x034C,
  CMSG_ARENA_TEAM_ROSTER = 0x034D,
  SMSG_ARENA_TEAM_ROSTER = 0x034E,
  CMSG_ARENA_TEAM_INVITE = 0x034F,
  SMSG_ARENA_TEAM_INVITE = 0x0350,
  CMSG_ARENA_TEAM_ACCEPT = 0x0351,
  CMSG_ARENA_TEAM_DECLINE = 0x0352,
  CMSG_ARENA_TEAM_LEAVE = 0x0353,
  CMSG_ARENA_TEAM_REMOVE = 0x0354,
  CMSG_ARENA_TEAM_DISBAND = 0x0355,
  CMSG_ARENA_TEAM_LEADER = 0x0356,
  SMSG_ARENA_TEAM_EVENT = 0x0357,
  CMSG_BATTLEMASTER_JOIN_ARENA = 0x0358,
  SMSG_ARENA_TEAM_STATS = 0x035B,
  CMSG_LFG_JOIN = 0x035C,
  CMSG_LFG_LEAVE = 0x035D,
  CMSG_LFG_LFR_JOIN = 0x035E,
  CMSG_LFG_LFR_LEAVE = 0x035F,
  SMSG_LFG_LFR_LIST = 0x0360,
  SMSG_LFG_PROPOSAL_UPDATE = 0x0361,
  CMSG_LFG_PROPOSAL_RESULT = 0x0362,
  SMSG_LFG_ROLE_CHECK_UPDATE = 0x0363,
  SMSG_LFG_JOIN_RESULT = 0x0364,
  SMSG_LFG_QUEUE_STATUS = 0x0365,
  CMSG_LFG_SET_COMMENT = 0x0366,
  SMSG_LFG_UPDATE_PLAYER = 0x0367,
  SMSG_LFG_UPDATE_PARTY = 0x0368,
  SMSG_LFG_UPDATE_SEARCH = 0x0369,
  CMSG_LFG_SET_ROLES = 0x036A,
  CMSG_LFG_SET_NEEDS = 0x036B,
  CMSG_LFG_SET_BOOT_VOTE = 0x036C,
  SMSG_LFG_BOOT_PROPOSAL_UPDATE = 0x036D,
  CMSG_LFG_PLAYER_LOCK_INFO_REQUEST = 0x036E,
  SMSG_LFG_PLAYER_INFO = 0x036F,
  CMSG_LFG_TELEPORT = 0x0370,
  CMSG_LFG_PARTY_LOCK_INFO_REQUEST = 0x0371,
  SMSG_LFG_PARTY_INFO = 0x0372,
  SMSG_TITLE_EARNED = 0x0373,
  CMSG_SET_TITLE = 0x0374,
  CMSG_CANCEL_MOUNT_AURA = 0x0375,
  SMSG_ARENA_ERROR = 0x0376,
  SMSG_DEATH_RELEASE_LOC = 0x0378,
  CMSG_CANCEL_TEMP_ENCHANTMENT = 0x0379,
  SMSG_FORCED_DEATH_UPDATE = 0x037A,
  CMSG_CHEAT_SET_HONOR_CURRENCY = 0x037B,
  CMSG_CHEAT_SET_ARENA_CURRENCY = 0x037C,
  SMSG_FORCE_FLIGHT_SPEED_CHANGE = 0x0381,
  CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK = 0x0382,
  SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE = 0x0383,
  CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK = 0x0384,
  SMSG_MOVE_SPLINE_SET_FLIGHT_SPEED = 0x0385,
  SMSG_MOVE_SPLINE_SET_FLIGHT_BACK_SPEED = 0x0386,
  CMSG_MAELSTROM_INVALIDATE_CACHE = 0x0387,
  SMSG_FLIGHT_SPLINE_SYNC = 0x0388,
  CMSG_SET_TAXI_BENCHMARK_MODE = 0x0389,
  SMSG_JOINED_BATTLEGROUND_QUEUE = 0x038A,
  SMSG_REALM_SPLIT = 0x038B,
  CMSG_REALM_SPLIT = 0x038C,
  CMSG_MOVE_CHANGE_TRANSPORT = 0x038D,
  SMSG_OFFER_PETITION_ERROR = 0x038F,
  SMSG_TIME_SYNC_REQUEST = 0x0390,
  CMSG_TIME_SYNC_RESPONSE = 0x0391,
  CMSG_SEND_LOCAL_EVENT = 0x0392,
  CMSG_SEND_GENERAL_TRIGGER = 0x0393,
  CMSG_SEND_COMBAT_TRIGGER = 0x0394,
  CMSG_MAELSTROM_GM_SENT_MAIL = 0x0395,
  SMSG_RESET_FAILED_NOTIFY = 0x0396,
  SMSG_REAL_GROUP_UPDATE = 0x0397,
  SMSG_LFG_DISABLED = 0x0398,
  CMSG_ACTIVE_PVP_CHEAT = 0x0399,
  CMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY = 0x039A,
  SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE = 0x039B,
  SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE_WRITE_FILE = 0x039C,
  SMSG_UPDATE_COMBO_POINTS = 0x039D,
  SMSG_VOICE_SESSION_ROSTER_UPDATE = 0x039E,
  SMSG_VOICE_SESSION_LEAVE = 0x039F,
  SMSG_VOICE_SESSION_ADJUST_PRIORITY = 0x03A0,
  CMSG_VOICE_SET_TALKER_MUTED_REQUEST = 0x03A1,
  SMSG_VOICE_SET_TALKER_MUTED = 0x03A2,
  SMSG_INIT_EXTRA_AURA_INFO_OBSOLETE = 0x03A3,
  SMSG_SET_EXTRA_AURA_INFO_OBSOLETE = 0x03A4,
  SMSG_SET_EXTRA_AURA_INFO_NEED_UPDATE_OBSOLETE = 0x03A5,
  SMSG_CLEAR_EXTRA_AURA_INFO_OBSOLETE = 0x03A6,
  CMSG_IGNORE_REQUIREMENTS_CHEAT = 0x03A8,
  SMSG_IGNORE_REQUIREMENTS_CHEAT = 0x03A9,
  SMSG_SPELL_CHANCE_PROC_LOG = 0x03AA,
  CMSG_MOVE_SET_RUN_SPEED = 0x03AB,
  SMSG_DISMOUNT = 0x03AC,
  CMSG_VOICE_SESSION_ENABLE = 0x03AF,
  SMSG_VOICE_SESSION_ENABLE = 0x03B0,
  SMSG_VOICE_PARENTAL_CONTROLS = 0x03B1,
  CMSG_GM_WHISPER = 0x03B2,
  SMSG_GM_MESSAGECHAT = 0x03B3,
  CMSG_COMMENTATOR_ENABLE = 0x03B5,
  SMSG_COMMENTATOR_STATE_CHANGED = 0x03B6,
  CMSG_COMMENTATOR_GET_MAP_INFO = 0x03B7,
  SMSG_COMMENTATOR_MAP_INFO = 0x03B8,
  CMSG_COMMENTATOR_GET_PLAYER_INFO = 0x03B9,
  SMSG_COMMENTATOR_GET_PLAYER_INFO = 0x03BA,
  SMSG_COMMENTATOR_PLAYER_INFO = 0x03BB,
  CMSG_COMMENTATOR_ENTER_INSTANCE = 0x03BC,
  CMSG_COMMENTATOR_EXIT_INSTANCE = 0x03BD,
  CMSG_COMMENTATOR_INSTANCE_COMMAND = 0x03BE,
  SMSG_CLEAR_TARGET = 0x03BF,
  CMSG_BOT_DETECTED = 0x03C0,
  SMSG_CROSSED_INEBRIATION_THRESHOLD = 0x03C1,
  CMSG_CHEAT_PLAYER_LOGIN = 0x03C2,
  CMSG_CHEAT_PLAYER_LOOKUP = 0x03C3,
  SMSG_CHEAT_PLAYER_LOOKUP = 0x03C4,
  SMSG_KICK_REASON = 0x03C5,
  CMSG_COMPLAINT = 0x03C7,
  SMSG_COMPLAINT_RESULT = 0x03C8,
  SMSG_FEATURE_SYSTEM_STATUS = 0x03C9,
  CMSG_GM_SHOW_COMPLAINTS = 0x03CA,
  CMSG_GM_UNSQUELCH = 0x03CB,
  CMSG_CHAT_CHANNEL_SILENCE_VOICE = 0x03CC,
  CMSG_CHAT_CHANNEL_SILENCE_ALL = 0x03CD,
  CMSG_CHAT_CHANNEL_UNSILENCE_VOICE = 0x03CE,
  CMSG_CHAT_CHANNEL_UNSILENCE_ALL = 0x03CF,
  CMSG_TARGET_CAST = 0x03D0,
  CMSG_TARGET_SCRIPT_CAST = 0x03D1,
  CMSG_CHAT_CHANNEL_DISPLAY_LIST = 0x03D2,
  CMSG_SET_ACTIVE_VOICE_CHANNEL = 0x03D3,
  CMSG_GET_CHANNEL_MEMBER_COUNT = 0x03D4,
  SMSG_CHANNEL_MEMBER_COUNT = 0x03D5,
  CMSG_CHAT_CHANNEL_VOICE_ON = 0x03D6,
  CMSG_CHAT_CHANNEL_VOICE_OFF = 0x03D7,
  CMSG_DEBUG_LIST_TARGETS = 0x03D8,
  SMSG_DEBUG_LIST_TARGETS = 0x03D9,
  SMSG_AVAILABLE_VOICE_CHANNEL = 0x03DA,
  CMSG_VOICE_ADD_IGNORE = 0x03DB,
  CMSG_VOICE_DEL_IGNORE = 0x03DC,
  CMSG_PARTY_SILENCE = 0x03DD,
  CMSG_PARTY_UNSILENCE = 0x03DE,
  SMSG_COMSAT_RECONNECT_TRY = 0x03E0,
  SMSG_COMSAT_DISCONNECT = 0x03E1,
  SMSG_COMSAT_CONNECT_FAIL = 0x03E2,
  SMSG_VOICE_CHAT_STATUS = 0x03E3,
  CMSG_REPORT_PVP_PLAYER_AFK = 0x03E4,
  SMSG_REPORT_PVP_AFK_RESULT = 0x03E5,
  CMSG_GUILD_BANK_ACTIVATE = 0x03E6,
  CMSG_GUILD_BANK_QUERY_TAB = 0x03E7,
  SMSG_GUILD_BANK_QUERY_RESULTS = 0x03E8,
  CMSG_GUILD_BANK_SWAP_ITEMS = 0x03E9,
  CMSG_GUILD_BANK_BUY_TAB = 0x03EA,
  CMSG_GUILD_BANK_UPDATE_TAB = 0x03EB,
  CMSG_GUILD_BANK_DEPOSIT_MONEY = 0x03EC,
  CMSG_GUILD_BANK_WITHDRAW_MONEY = 0x03ED,
  CMSG_SET_CHANNEL_WATCH = 0x03EF,
  SMSG_USERLIST_ADD = 0x03F0,
  SMSG_USERLIST_REMOVE = 0x03F1,
  SMSG_USERLIST_UPDATE = 0x03F2,
  CMSG_CLEAR_CHANNEL_WATCH = 0x03F3,
  SMSG_INSPECT_TALENT = 0x03F4,
  SMSG_GOGOGO_OBSOLETE = 0x03F5,
  SMSG_ECHO_PARTY_SQUELCH = 0x03F6,
  CMSG_SET_TITLE_SUFFIX = 0x03F7,
  CMSG_SPELL_CLICK = 0x03F8,
  SMSG_LOOT_LIST = 0x03F9,
  CMSG_GM_CHARACTER_RESTORE = 0x03FA,
  CMSG_GM_CHARACTER_SAVE = 0x03FB,
  SMSG_VOICESESSION_FULL = 0x03FC,
  CMSG_MAELSTROM_RENAME_GUILD = 0x0400,
  CMSG_GET_MIRROR_IMAGE_DATA = 0x0401,
  SMSG_MIRROR_IMAGE_COMPONENTED_DATA = 0x0402,
  SMSG_FORCE_DISPLAY_UPDATE = 0x0403,
  SMSG_SPELL_CHANCE_RESIST_PUSHBACK = 0x0404,
  CMSG_IGNORE_DIMINISHING_RETURNS_CHEAT = 0x0405,
  SMSG_IGNORE_DIMINISHING_RETURNS_CHEAT = 0x0406,
  CMSG_KEEP_ALIVE = 0x0407,
  SMSG_READY_CHECK_ERROR = 0x0408,
  CMSG_OPT_OUT_OF_LOOT = 0x0409,
  CMSG_GUILD_BANK_SET_TAB_TEXT = 0x040B,
  CMSG_SET_GRANTABLE_LEVELS = 0x040C,
  CMSG_GRANT_LEVEL = 0x040D,
  CMSG_REFER_A_FRIEND = 0x040E,
  CMSG_CHAT_CHANNEL_DECLINE_INVITE = 0x0410,
  SMSG_GROUP_ACTION_THROTTLED = 0x0411,
  SMSG_OVERRIDE_LIGHT = 0x0412,
  SMSG_TOTEM_CREATED = 0x0413,
  CMSG_TOTEM_DESTROYED = 0x0414,
  CMSG_EXPIRE_RAID_INSTANCE = 0x0415,
  CMSG_NO_SPELL_VARIANCE = 0x0416,
  CMSG_QUEST_GIVER_STATUS_MULTIPLE_QUERY = 0x0417,
  SMSG_QUEST_GIVER_STATUS_MULTIPLE = 0x0418,
  CMSG_SET_PLAYER_DECLINED_NAMES = 0x0419,
  SMSG_SET_PLAYER_DECLINED_NAMES_RESULT = 0x041A,
  CMSG_QUERY_SERVER_BUCK_DATA = 0x041B,
  CMSG_CLEAR_SERVER_BUCK_DATA = 0x041C,
  SMSG_SERVER_BUCK_DATA = 0x041D,
  SMSG_SEND_UNLEARN_SPELLS = 0x041E,
  SMSG_PROPOSE_LEVEL_GRANT = 0x041F,
  CMSG_ACCEPT_LEVEL_GRANT = 0x0420,
  SMSG_REFER_A_FRIEND_FAILURE = 0x0421,
  SMSG_MOVE_SPLINE_SET_FLYING = 0x0422,
  SMSG_MOVE_SPLINE_UNSET_FLYING = 0x0423,
  SMSG_SUMMON_CANCEL = 0x0424,
  CMSG_CHANGE_PERSONAL_ARENA_RATING = 0x0425,
  CMSG_ALTER_APPEARANCE = 0x0426,
  SMSG_ENABLE_BARBER_SHOP = 0x0427,
  SMSG_BARBER_SHOP_RESULT = 0x0428,
  CMSG_CALENDAR_GET_CALENDAR = 0x0429,
  CMSG_CALENDAR_GET_EVENT = 0x042A,
  CMSG_CALENDAR_GUILD_FILTER = 0x042B,
  CMSG_CALENDAR_ARENA_TEAM = 0x042C,
  CMSG_CALENDAR_ADD_EVENT = 0x042D,
  CMSG_CALENDAR_UPDATE_EVENT = 0x042E,
  CMSG_CALENDAR_REMOVE_EVENT = 0x042F,
  CMSG_CALENDAR_COPY_EVENT = 0x0430,
  CMSG_CALENDAR_EVENT_INVITE = 0x0431,
  CMSG_CALENDAR_EVENT_RSVP = 0x0432,
  CMSG_CALENDAR_EVENT_REMOVE_INVITE = 0x0433,
  CMSG_CALENDAR_EVENT_STATUS = 0x0434,
  CMSG_CALENDAR_EVENT_MODERATOR_STATUS = 0x0435,
  SMSG_CALENDAR_SEND_CALENDAR = 0x0436,
  SMSG_CALENDAR_SEND_EVENT = 0x0437,
  SMSG_CALENDAR_FILTER_GUILD = 0x0438,
  SMSG_CALENDAR_ARENA_TEAM = 0x0439,
  SMSG_CALENDAR_EVENT_INVITE = 0x043A,
  SMSG_CALENDAR_EVENT_INVITE_REMOVED = 0x043B,
  SMSG_CALENDAR_EVENT_STATUS = 0x043C,
  SMSG_CALENDAR_COMMAND_RESULT = 0x043D,
  SMSG_CALENDAR_RAID_LOCKOUT_ADDED = 0x043E,
  SMSG_CALENDAR_RAID_LOCKOUT_REMOVED = 0x043F,
  SMSG_CALENDAR_EVENT_INVITE_ALERT = 0x0440,
  SMSG_CALENDAR_EVENT_INVITE_REMOVED_ALERT = 0x0441,
  SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT = 0x0442,
  SMSG_CALENDAR_EVENT_REMOVED_ALERT = 0x0443,
  SMSG_CALENDAR_EVENT_UPDATED_ALERT = 0x0444,
  SMSG_CALENDAR_EVENT_MODERATOR_STATUS_ALERT = 0x0445,
  CMSG_CALENDAR_COMPLAIN = 0x0446,
  CMSG_CALENDAR_GET_NUM_PENDING = 0x0447,
  SMSG_CALENDAR_SEND_NUM_PENDING = 0x0448,
  CMSG_SAVE_DANCE = 0x0449,
  SMSG_NOTIFY_DANCE = 0x044A,
  CMSG_PLAY_DANCE = 0x044B,
  SMSG_PLAY_DANCE = 0x044C,
  CMSG_LOAD_DANCES = 0x044D,
  CMSG_STOP_DANCE = 0x044E,
  SMSG_STOP_DANCE = 0x044F,
  CMSG_SYNC_DANCE = 0x0450,
  CMSG_DANCE_QUERY = 0x0451,
  SMSG_DANCE_QUERY_RESPONSE = 0x0452,
  SMSG_INVALIDATE_DANCE = 0x0453,
  CMSG_DELETE_DANCE = 0x0454,
  SMSG_LEARNED_DANCE_MOVES = 0x0455,
  CMSG_LEARN_DANCE_MOVE = 0x0456,
  CMSG_UNLEARN_DANCE_MOVE = 0x0457,
  CMSG_SET_RUNE_COUNT = 0x0458,
  CMSG_SET_RUNE_COOLDOWN = 0x0459,
  SMSG_FORCE_PITCH_RATE_CHANGE = 0x045C,
  CMSG_FORCE_PITCH_RATE_CHANGE_ACK = 0x045D,
  SMSG_MOVE_SPLINE_SET_PITCH_RATE = 0x045E,
  CMSG_CALENDAR_EVENT_INVITE_NOTES = 0x045F,
  SMSG_CALENDAR_EVENT_INVITE_NOTES = 0x0460,
  SMSG_CALENDAR_EVENT_INVITE_NOTES_ALERT = 0x0461,
  CMSG_UPDATE_MISSILE_TRAJECTORY = 0x0462,
  SMSG_UPDATE_ACCOUNT_DATA_COMPLETE = 0x0463,
  SMSG_TRIGGER_MOVIE = 0x0464,
  CMSG_COMPLETE_MOVIE = 0x0465,
  CMSG_SET_GLYPH_SLOT = 0x0466,
  CMSG_SET_GLYPH = 0x0467,
  SMSG_ACHIEVEMENT_EARNED = 0x0468,
  SMSG_DYNAMIC_DROP_ROLL_RESULT = 0x0469,
  SMSG_CRITERIA_UPDATE = 0x046A,
  CMSG_QUERY_INSPECT_ACHIEVEMENTS = 0x046B,
  SMSG_RESPOND_INSPECT_ACHIEVEMENTS = 0x046C,
  CMSG_DISMISS_CONTROLLED_VEHICLE = 0x046D,
  CMSG_COMPLETE_ACHIEVEMENT_CHEAT = 0x046E,
  SMSG_QUEST_UPDATE_ADD_PVP_CREDIT = 0x046F,
  CMSG_SET_CRITERIA_CHEAT = 0x0470,
  SMSG_CALENDAR_RAID_LOCKOUT_UPDATED = 0x0471,
  CMSG_UNITANIMTIER_CHEAT = 0x0472,
  CMSG_CHAR_CUSTOMIZE = 0x0473,
  SMSG_CHAR_CUSTOMIZE = 0x0474,
  SMSG_PET_RENAMEABLE = 0x0475,
  CMSG_REQUEST_VEHICLE_EXIT = 0x0476,
  CMSG_REQUEST_VEHICLE_PREV_SEAT = 0x0477,
  CMSG_REQUEST_VEHICLE_NEXT_SEAT = 0x0478,
  CMSG_REQUEST_VEHICLE_SWITCH_SEAT = 0x0479,
  CMSG_PET_LEARN_TALENT = 0x047A,
  CMSG_PET_UNLEARN_TALENTS = 0x047B,
  SMSG_PHASE_SHIFT_CHANGE = 0x047C,
  SMSG_ALL_ACHIEVEMENT_DATA = 0x047D,
  CMSG_FORCE_SAY_CHEAT = 0x047E,
  SMSG_HEALTH_UPDATE = 0x047F,
  SMSG_POWER_UPDATE = 0x0480,
  CMSG_GAME_OBJ_REPORT_USE = 0x0481,
  SMSG_HIGHEST_THREAT_UPDATE = 0x0482,
  SMSG_THREAT_UPDATE = 0x0483,
  SMSG_THREAT_REMOVE = 0x0484,
  SMSG_THREAT_CLEAR = 0x0485,
  SMSG_CONVERT_RUNE = 0x0486,
  SMSG_RESYNC_RUNES = 0x0487,
  SMSG_ADD_RUNE_POWER = 0x0488,
  CMSG_QUERY_QUEST_COMPLETION_NPCS = 0x0489,
  CMSG_REMOVE_GLYPH = 0x048A,
  CMSG_DUMP_OBJECTS = 0x048B,
  SMSG_DUMP_OBJECTS_DATA = 0x048C,
  CMSG_DISMISS_CRITTER = 0x048D,
  SMSG_NOTIFY_DEST_LOC_SPELL_CAST = 0x048E,
  CMSG_AUCTION_LIST_PENDING_SALES = 0x048F,
  SMSG_AUCTION_LIST_PENDING_SALES = 0x0490,
  SMSG_MODIFY_COOLDOWN = 0x0491,
  SMSG_PET_UPDATE_COMBO_POINTS = 0x0492,
  CMSG_ENABLE_TAXI_NODE = 0x0493,
  SMSG_PRE_RESSURECT = 0x0494,
  SMSG_AURA_UPDATE_ALL = 0x0495,
  SMSG_AURA_UPDATE = 0x0496,
  CMSG_FLOOD_GRACE_CHEAT = 0x0497,
  SMSG_SERVER_FIRST_ACHIEVEMENT = 0x0498,
  SMSG_PET_LEARNED_SPELLS = 0x0499,
  SMSG_PET_UNLEARNED_SPELLS = 0x049A,
  CMSG_CHANGE_SEATS_ON_CONTROLLED_VEHICLE = 0x049B,
  CMSG_HEARTH_AND_RESURRECT = 0x049C,
  SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA = 0x049D,
  SMSG_CRITERIA_DELETED = 0x049E,
  SMSG_ACHIEVEMENT_DELETED = 0x049F,
  CMSG_SERVER_INFO_QUERY = 0x04A0,
  SMSG_SERVER_INFO_RESPONSE = 0x04A1,
  CMSG_CHECK_LOGIN_CRITERIA = 0x04A2,
  SMSG_SERVER_BUCK_DATA_START = 0x04A3,
  CMSG_SET_BREATH = 0x04A4,
  CMSG_QUERY_VEHICLE_STATUS = 0x04A5,
  SMSG_BATTLEGROUND_INFO_THROTTLED = 0x04A6,
  SMSG_PLAYER_VEHICLE_DATA = 0x04A7,
  CMSG_PLAYER_VEHICLE_ENTER = 0x04A8,
  CMSG_EJECT_PASSENGER = 0x04A9,
  SMSG_PET_GUIDS = 0x04AA,
  SMSG_CACHE_VERSION = 0x04AB,
  CMSG_CHANGE_GDF_ARENA_RATING = 0x04AC,
  CMSG_SET_ARENA_TEAM_RATING_BY_INDEX = 0x04AD,
  CMSG_SET_ARENA_TEAM_WEEKLY_GAMES = 0x04AE,
  CMSG_SET_ARENA_TEAM_SEASON_GAMES = 0x04AF,
  CMSG_SET_ARENA_MEMBER_WEEKLY_GAMES = 0x04B0,
  CMSG_SET_ARENA_MEMBER_SEASON_GAMES = 0x04B1,
  SMSG_ITEM_REFUND_INFO_RESPONSE = 0x04B2,
  CMSG_GET_ITEM_PURCHASE_DATA = 0x04B3,
  CMSG_ITEM_PURCHASE_REFUND = 0x04B4,
  SMSG_ITEM_PURCHASE_REFUND_RESULT = 0x04B5,
  CMSG_CORPSE_MAP_POSITION_QUERY = 0x04B6,
  SMSG_CORPSE_MAP_POSITION_QUERY_RESPONSE = 0x04B7,
  SMSG_LOAD_EQUIPMENT_SET = 0x04BC,
  NUM_MSG_TYPES = 0x051F,
};

#endif