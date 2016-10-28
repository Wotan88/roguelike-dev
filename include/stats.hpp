class Stats{
private:
    int mStrength = 10;
    int mConstitution = 10;
    int mDexterity = 10;
    int mIntelligence = 10;
    int mWisdom = 10;
    int mCharisma = 10;
    
    int mHealth = 25;
    int mMana = 25;
    
    int mHunger = 50; //Допустим, что проценты
    int mThirst = 50;
    
    int mExp = 0;
    int mLvl = 1;
public:
        //Setters and getters
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
        mHeatlh = health;
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
        //Setters and getters
    
        //Changing stats
    void AddStrength(int strength){
        mStrength += strength;
    }
    void AddConstitution(int constitution){
        mConstitution += constitution;
    }
    void AddDexterity(int dexterity){
        mDexterity += dexterity;
    }
    void AddIntelligence(int intelligence){
        mIntelligence += intelligence;
    }
    void AddWisdom(int wisdom){
        mWisdom += wisdom;
    }
    void AddCharisma(int charisma){
        mCharisma += charisma;
    }
    void AddHealth(int health){
        mHealth += health;
    }
    void AddMana(int mana){
        mMana += mana;
    }
    void AddHunger(int hunger){
        mHunger += hunger;
    }
    void AddThirst(int thirst){
        mThirst += thirst;
    }
    void AddExp(int exp){
        mExp += exp;
    }
    void AddLvl(int lvl){
        mLvl += lvl;
    }
        //Changing stats
};