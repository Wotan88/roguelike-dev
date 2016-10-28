class Stats {
public:
    // Setters and getters
    void setStrength(int strength){
        mStrength = strength;
    }
    int getStrength(){
        return mStrength;
    }    
    void setConstitution(int constitution){
        mConstitution = constitution;
    }
    int getConstitution(){
        return mConstitution;
    }    
    void setDexterity(int dexterity){
        mDexterity = dexterity;
    }
    int getDexterity(){
        return mDexterity;
    }    
    void setIntelligence(int intelligence){
        mIntelligence = intelligence;
    }
    int getIntelligence(){
        return mIntelligence;
    }    
    void setWisdom(int wisdom){
        mWisdom = wisdom;
    }
    int getWisdom(){
        return mWisdom;
    }    
    void setCharisma(int charisma){
        mCharisma = charisma;
    }
    int getCharisma(){
        return mCharisma;
    }    
    void setHealth(int health){
        mHealh = health;
    }
    int getHealth(){
        return mHealth;
    }    
    void setMana(int mana){
        mMana = mana;
    }
    int getMana(){
        return mMana;
    }    
    void setExp(int exp){
        mExp = exp;
    }
    int getExp(){
        return mExp;
    }    
    void setHunger(int hunger){
        mHunger = hunger;
    }
    int getHunger(){
        return mHunger;
    }    
    void setThirst(int thirst){
        mThirst = thirst;
    }
    int getThirst(){
        return mThirst;
    }    
    void setLvl(int lvl){
        mLvl = lvl;
    }
    int getLvl(){
        return mLvl;
    }
    
    // Changing stats
    void addStrength(int strength){
        mStrength += strength;
    }
    void addConstitution(int constitution){
        mConstitution += constitution;
    }
    void addDexterity(int dexterity){
        mDexterity += dexterity;
    }
    void addIntelligence(int intelligence){
        mIntelligence += intelligence;
    }
    void addWisdom(int wisdom){
        mWisdom += wisdom;
    }
    void addCharisma(int charisma){
        mCharisma += charisma;
    }
    void addHealth(int health){
        mHealth += health;
    }
    void addMana(int mana){
        mMana += mana;
    }
    void addHunger(int hunger){
        mHunger += hunger;
    }
    void addThirst(int thirst){
        mThirst += thirst;
    }
    void addExp(int exp){
        mExp += exp;
    }
    void addLvl(int lvl){
        mLvl += lvl;
    }
    
private:
    int mStrength = 10;
    int mConstitution = 10;
    int mDexterity = 10;
    int mIntelligence = 10;
    int mWisdom = 10;
    int mCharisma = 10;
    
    int mHealth = 25;
    int mMana = 25;
    
    // Assuming this is percentage
    int mHunger = 50;
    int mThirst = 50;
    
    int mExp = 0;
    int mLvl = 1;
};