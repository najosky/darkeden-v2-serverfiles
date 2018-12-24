//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectConcealment.h
// Written by  : crazydog
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_SQUALLY_BARRIER1__
#define __EFFECT_SQUALLY_BARRIER1__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectConcealment
//////////////////////////////////////////////////////////////////////////////

class EffectSquallyBarrier1 : public Effect 
{
public:
	EffectSquallyBarrier1(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_SQUALLY_BARRIER1; }

	void affect() throw(Error){}

	void unaffect(Creature* pCreature) throw(Error);
	void unaffect() throw(Error);

	string toString() const throw();

public:
	Level_t getLevel() const throw() { return m_Level; }
	void setLevel(Level_t Level) throw();

	EffectClass getClientEffectClass() const throw() { return m_ClientEffectClass; }
	void setClientEffectClass(EffectClass effectClass) throw() { m_ClientEffectClass = effectClass; }

private:
	Level_t 		m_Level;				// ��ų ����
	EffectClass 	m_ClientEffectClass;	// Ŭ���̾�Ʈ�� �����ٶ� ���� ����Ʈ Ŭ���� ���̵�

};

//////////////////////////////////////////////////////////////////////////////
// class EffectSquallyBarrier1Loader
//////////////////////////////////////////////////////////////////////////////

class EffectSquallyBarrier1Loader : public EffectLoader 
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_SQUALLY_BARRIER1; }
	virtual string getEffectClassName() const throw() { return "EffectSquallyBarrier1"; }

public:
	virtual void load(Creature* pCreature) throw(Error) {}
};


#endif // __EFFECT_CONCEALMENT__