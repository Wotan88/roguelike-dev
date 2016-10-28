#include "stats.hpp"

// Setters and getters
void game::Stats::setStrength(int strength){
	mStrength = strength;
}
int game::Stats::getStrength(){
    return mStrength;
}    
void game::Stats::setConstitution(int constitution){
    mConstitution = constitution;
}
int game::Stats::getConstitution(){
    return mConstitution;
}    
void game::Stats::setDexterity(int dexterity){
	mDexterity = dexterity;
}
int game::Stats::getDexterity(){
    return mDexterity;
}    
void game::Stats::setIntelligence(int intelligence){
    mIntelligence = intelligence;
}
int game::Stats::getIntelligence(){
    return mIntelligence;
}    
void game::Stats::setWisdom(int wisdom){
    mWisdom = wisdom;
}
int game::Stats::getWisdom(){
    return mWisdom;
}    
void game::Stats::setCharisma(int charisma){
    mCharisma = charisma;
}
int game::Stats::getCharisma(){
    return mCharisma;
}    
void game::Stats::setHealth(int health){
    mHealth = health;
}
int game::Stats::getHealth(){
    return mHealth;
}    
void game::Stats::setMana(int mana){
    mMana = mana;
}
int game::Stats::getMana(){
    return mMana;
}    
void game::Stats::setExp(int exp){
    mExp = exp;
}
int game::Stats::getExp(){
    return mExp;
}    
void game::Stats::setHunger(int hunger){
    mHunger = hunger;
}
int game::Stats::getHunger(){
    return mHunger;
}    
void game::Stats::setThirst(int thirst){
    mThirst = thirst;
}
int game::Stats::getThirst(){
    return mThirst;
}    
void game::Stats::setLvl(int lvl){
	mLvl = lvl;
}
int game::Stats::getLvl(){
	return mLvl;
}
    
// Changing stats
void game::Stats::addStrength(int strength){
	mStrength += strength;
}
void game::Stats::addConstitution(int constitution){
	mConstitution += constitution;
}
void game::Stats::addDexterity(int dexterity){
	mDexterity += dexterity;
}
void game::Stats::addIntelligence(int intelligence){
	mIntelligence += intelligence;
}
void game::Stats::addWisdom(int wisdom){
	mWisdom += wisdom;
}
void game::Stats::addCharisma(int charisma){
	mCharisma += charisma;
}
void game::Stats::addHealth(int health){
	mHealth += health;
}
void game::Stats::addMana(int mana){
	mMana += mana;
}
void game::Stats::addHunger(int hunger){
	mHunger += hunger;
}
void game::Stats::addThirst(int thirst){
	mThirst += thirst;
}
void game::Stats::addExp(int exp){
	mExp += exp;
}
void game::Stats::addLvl(int lvl){
	mLvl += lvl;
}