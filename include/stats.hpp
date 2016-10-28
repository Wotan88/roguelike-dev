class Stats {
public:
    // Setters and getters
    void setStrength(int strength);
    int getStrength();
    void setConstitution;
    int getConstitution();
    void setDexterity(int dexterity);
    int getDexterity();
    void setIntelligence(int intelligence);
    int getIntelligence();
    void setWisdom(int wisdom);
    int getWisdom();
    void setCharisma(int charisma);
    int getCharisma();
    void setHealth(int health);
    int getHealth();
    void setMana(int mana);
    int getMana();
    void setExp(int exp);
    int getExp();
    void setHunger(int hunger);
    int getHunger();
    void setThirst(int thirst);
    int getThirst();
    void setLvl(int lvl);
    int getLvl();
    
    // Changing stats
    void addStrength(int strength);
    void addConstitution(int constitution);
    void addDexterity(int dexterity);
    void addIntelligence(int intelligence);
    void addWisdom(int wisdom);
    void addCharisma(int charisma);
    void addHealth(int health);
    void addMana(int mana);
    void addHunger(int hunger);
    void addThirst(int thirst);
    void addExp(int exp);
    void addLvl(int lvl);

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
