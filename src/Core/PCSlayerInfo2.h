//////////////////////////////////////////////////////////////////////////////
// Filename    : PCSlayerInfo2.h
// Written By  : Reiot
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __PC_SLAYER_INFO_2_H__
#define __PC_SLAYER_INFO_2_H__

#include "PCInfo.h"

//////////////////////////////////////////////////////////////////////////////
// Slayer의 모든 정보(능력치,걸려있는마법 등)를 담고 있는 객체.
// GCUpdateInfo 패킷에 담겨서 클라이언트에게 전송된다.
//////////////////////////////////////////////////////////////////////////////

class PCSlayerInfo2 : public PCInfo 
{
public:
	PCType getPCType ()  { return PC_SLAYER; }
	void read (SocketInputStream & iStream);
	void write (SocketOutputStream & oStream) ;

	uint getSize () 
	{
		return szObjectID
			+ szBYTE + m_Name.size() 
			+ szSex
			+ szHairStyle
			+ szColor * 2
			+ szBYTE
			+ szAlignment
			+ szAttr* 3* 3
			+ szRank + szRankExp
			+ szExp* 3
			+ szHP* 2
			+ szMP* 2
			+ szFame
			+ szFame
			+ szGold
			+ (szSkillLevel + szSkillExp)* 6
			+ szSkillType* 4
			+ szSight
			+ szGuildID
			+ szBYTE + m_GuildName.size()
			+ szGuildMemberRank
			+ szBYTE
			+ szuint
			+ szLevel
			+ szExp
			+ szBonus
			+ szAttr
			+ szAttr
			+ szAttr;
	}

	static uint getMaxSize () 
	{
		return szObjectID
			+ szBYTE + 20
			+ szSex
			+ szHairStyle
			+ szColor* 2
			+ szBYTE
			+ szAlignment
			+ szAttr* 3* 3
			+ szRank + szRankExp
			+ szExp* 3
			+ szHP* 2
			+ szMP* 2
			+ szFame
			+ szFame
			+ szGold
			+ (szSkillLevel + szSkillExp)* 6
			+ szSkillType* 4
			+ szSight
			+ szGuildID
			+ szBYTE + 30
			+ szGuildMemberRank
			+ szBYTE
			+ szuint
			+ szLevel
			+ szExp
			+ szBonus
			+ szAttr
			+ szAttr
			+ szAttr;
	}

	string toString () ;

public :
	ObjectID_t getObjectID ()  { return m_ObjectID; }
	void setObjectID (ObjectID_t objectID)  { m_ObjectID = objectID; }

    string getName ()  { return m_Name; }
    void setName (string name)  { m_Name = (name.size() > 20) ? name.substr(0,20) : name; }

	Sex getSex ()  { return m_Sex; }
	void setSex (Sex sex)  { m_Sex = sex; }
	void setSex (string sex) 
	{
		if (sex == Sex2String[MALE]) 
			m_Sex = MALE;
		else if (sex == Sex2String[FEMALE]) 
			m_Sex = FEMALE;
		else
			throw InvalidProtocolException("invalid sex value");
	}

	HairStyle getHairStyle ()  { return m_HairStyle; }
	void setHairStyle (HairStyle hairStyle)  { m_HairStyle = hairStyle; }
	void setHairStyle (string hairStyle) 
	{
		if (hairStyle == HairStyle2String[HAIR_STYLE1])
			m_HairStyle = HAIR_STYLE1;
		else if (hairStyle == HairStyle2String[HAIR_STYLE2])
			m_HairStyle = HAIR_STYLE2;
		else if (hairStyle == HairStyle2String[HAIR_STYLE3])
			m_HairStyle = HAIR_STYLE3;
		else
			throw InvalidProtocolException("invalid hairstyle value");
	}

	Rank_t getRank ()  { return m_Rank; }
	void setRank (Rank_t rank)  { m_Rank = rank; }

	RankExp_t getRankExp ()  { return m_RankExp; }
	void setRankExp (RankExp_t rankExp)  { m_RankExp = rankExp; }

	Color_t getHairColor ()  { return m_HairColor; }
	void setHairColor (Color_t hairColor)  { m_HairColor = hairColor; }

	Color_t getSkinColor ()  { return m_SkinColor; }
	void setSkinColor (Color_t skinColor)  { m_SkinColor = skinColor; }

	BYTE getMasterEffectColor ()  { return m_MasterEffectColor; }
	void setMasterEffectColor (BYTE masterEffectColor)  { m_MasterEffectColor = masterEffectColor; }

	Alignment_t getAlignment()  { return m_Alignment; }
	void setAlignment(Alignment_t Alignment)  { m_Alignment = Alignment; }

    Attr_t getSTR (AttrType attrType = ATTR_CURRENT) 
	{ 
		if (m_STR[attrType] > maxSlayerAttr) throw Error("STR out of range"); 
		return m_STR[attrType]; 
	}
    void setSTR (Attr_t str, AttrType attrType = ATTR_CURRENT) 
	{ 
		if (str > maxSlayerAttr) throw Error("STR out of range"); 
		m_STR[attrType] = str; 
	}

	Attr_t getDEX (AttrType attrType = ATTR_CURRENT) 
	{ 
		if (m_DEX[attrType] > maxSlayerAttr) throw Error("DEX out of range"); 
		return m_DEX[attrType]; 
	}
	void setDEX (Attr_t dex, AttrType attrType = ATTR_CURRENT) 
	{ 
		if (dex > maxSlayerAttr) throw Error("DEX out of range"); 
		m_DEX[attrType] = dex; 
	}

	Attr_t getINT (AttrType attrType = ATTR_CURRENT) 
	{ 
		if (m_INT[attrType] > maxSlayerAttr) throw Error("INT out of range"); 
		return m_INT[attrType]; 
	}
	void setINT (Attr_t inte, AttrType attrType = ATTR_CURRENT) 
	{ 
		if (inte > maxSlayerAttr) throw Error("INT out of range"); 
		m_INT[attrType] = inte; 
	}

	Exp_t getSTRExp ()  { return m_STRExp; };
	void setSTRExp(Exp_t STRExp)  { m_STRExp = STRExp; }

	Exp_t getDEXExp ()  { return m_DEXExp; };
	void setDEXExp(Exp_t DEXExp)  { m_DEXExp = DEXExp; }

	Exp_t getINTExp ()  { return m_INTExp; };
	void setINTExp(Exp_t INTExp)  { m_INTExp = INTExp; }

	HP_t getHP (AttrType attrType = ATTR_CURRENT)  { return m_HP[attrType]; }
	void setHP (HP_t hp, AttrType attrType = ATTR_CURRENT)  { m_HP[attrType] = hp; }
	void setHP (HP_t curHP, HP_t maxHP)  { m_HP[ATTR_CURRENT] = curHP; m_HP[ATTR_MAX] = maxHP; }

	MP_t getMP (AttrType attrType = ATTR_CURRENT)  { return m_MP[attrType]; }
	void setMP (MP_t mp, AttrType attrType = ATTR_CURRENT)  { m_MP[attrType] = mp; }
	void setMP (MP_t curMP, MP_t maxMP)  { m_MP[ATTR_CURRENT] = curMP; m_MP[ATTR_MAX] = maxMP; }

	Fame_t getFame ()  { return m_Fame; }
	void setFame (Fame_t fame)  { m_Fame = fame; }

	Fame_t getKillPoint ()  { return m_KillPoint ; }
	void setKillPoint (Fame_t KillPoint)  { m_KillPoint = KillPoint ; }

	Gold_t getGold ()  { return m_Gold; }
	void setGold (Gold_t gold)  { m_Gold = gold; }

	SkillLevel_t getSkillDomainLevel (SkillDomain domain)  { return m_DomainLevels[ domain ]; }
	void setSkillDomainLevel (SkillDomain domain, SkillLevel_t skillLevel)  { m_DomainLevels[ domain ] = skillLevel; }

	SkillExp_t getSkillDomainExp (SkillDomain domain)  { return m_DomainExps[ domain ]; }
	void setSkillDomainExp (SkillDomain domain, SkillExp_t skillExp)  { m_DomainExps[ domain ] = skillExp; }

	void setSkillDomain (SkillDomain domain, SkillLevel_t skillLevel, SkillExp_t skillExp)  { m_DomainLevels[ domain ] = skillLevel; m_DomainExps[ domain ] = skillExp; }

	Sight_t getSight ()  { return m_Sight; }
	void setSight (Sight_t sight)  { m_Sight = sight; }

	SkillType_t getHotKey(BYTE pos)  { return m_HotKey[pos]; }
	void setHotKey(BYTE pos, SkillType_t SkillType)  { m_HotKey[pos] = SkillType; }

	BYTE getCompetence(void) const { return m_Competence; }
	void setCompetence(BYTE competence) { m_Competence = competence; }

	GuildID_t getGuildID(void) const { return m_GuildID; }
	void setGuildID(GuildID_t GuildID ) { m_GuildID = GuildID; }

	string getGuildName() const { return m_GuildName; }
	void setGuildName( string guildName ) { m_GuildName = guildName; }

	GuildMemberRank_t getGuildMemberRank() const { return m_GuildMemberRank; }
	void setGuildMemberRank( GuildMemberRank_t guildMemberRank ) { m_GuildMemberRank = guildMemberRank; }

	uint getUnionID(void) const { return m_UnionID; }
	void setUnionID(uint UnionID ) { m_UnionID = UnionID; }

	Level_t	getAdvancementLevel() const { return m_AdvancementLevel; }
	void setAdvancementLevel( Level_t level ) { m_AdvancementLevel = level; }

	Exp_t	getAdvancementGoalExp() const { return m_AdvancementGoalExp; }
	void setAdvancementGoalExp( Exp_t exp ) { m_AdvancementGoalExp = exp; }

	Bonus_t	getAttrBonus() const { return m_AttrBonus; }
	void setAttrBonus( Bonus_t bonus ) { m_AttrBonus = bonus; }

	Attr_t getAttackBloodBurstPoint() const { return m_AttackBloodBurstPoint; }
	void setAttackBloodBurstPoint( Attr_t point ) { m_AttackBloodBurstPoint = point; }

	Attr_t getDefenseBloodBurstPoint() const { return m_DefenseBloodBurstPoint; }
	void setDefenseBloodBurstPoint( Attr_t point ) { m_DefenseBloodBurstPoint = point; }

	Attr_t getPartyBloodBurstPoint() const { return m_PartyBloodBurstPoint; }
	void setPartyBloodBurstPoin( Attr_t point ) { m_PartyBloodBurstPoint = point; }
private:

	// PC's ObjectID
	ObjectID_t m_ObjectID;

	// PC name
	string m_Name;

	// PC sex, hair style
	Sex m_Sex;
	HairStyle m_HairStyle;

	// hair color, skin color
	Color_t m_HairColor;
	Color_t m_SkinColor;
	BYTE	m_MasterEffectColor;

	// Alignment
	Alignment_t m_Alignment;

	// Attributes
	Attr_t m_STR[3];
	Attr_t m_DEX[3];
	Attr_t m_INT[3];

	// Attributes Exp
	Exp_t m_STRExp;
	Exp_t m_DEXExp;
	Exp_t m_INTExp;

	// 계급
	Rank_t		m_Rank;
	RankExp_t	m_RankExp;

	// HP,MP (current / max)
	HP_t m_HP[2];
	MP_t m_MP[2];	

	// Fame/Gold
	Fame_t m_Fame;
	Fame_t m_KillPoint;
	Gold_t m_Gold;

	// skill domains
	SkillLevel_t m_DomainLevels[6];
	SkillExp_t m_DomainExps[6];

	// sight 
	Sight_t m_Sight;

	// 길드 정보

    // 핫 키
	SkillType_t m_HotKey[4];

	BYTE m_Competence;

	GuildID_t m_GuildID;
	string m_GuildName;
	GuildMemberRank_t m_GuildMemberRank;
	
	uint m_UnionID;

	Level_t m_AdvancementLevel;
	Exp_t m_AdvancementGoalExp;

	Bonus_t m_AttrBonus;

	Attr_t	m_AttackBloodBurstPoint;
	Attr_t	m_DefenseBloodBurstPoint;
	Attr_t	m_PartyBloodBurstPoint;

	BYTE	m_AttackSpeed;
};

#endif	// __PC_SLAYER_INFO_2_H__
