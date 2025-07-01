// MyFinalProject.cpp : Final Project for CS175 called "The Big Bad Red Riding Hood". Game involving a "twist" on the Little Red Riding Hood story.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

string name = "";

class Character {
public:
    int health;
    int attack;

    // initial construct for default character
    Character() {
        health = 100;
        attack = 25;
    }

    // method for another character
    Character(int newHealth, int newAttack) {
        health = newHealth;
        attack = newAttack;
    }

    // method to damage character corresponding to attacker's attack power
    void damageChar(const Character& attacker) {
        health -= attacker.attack;
        if (health < 0) health = 0;
    }

    void defendDamageChar() {
        health -= 10;
        if (health < 0) health = 0;
    }

    // prints character health statistic
    void healthUpdate() const {
        cout << "Health: " << health << "." << endl;
    }
    
};

static bool getResponse() {
    string promptAnswer;
    string casedAnswer = "";
    bool fixedAnswer;

    while (true) {
        try {
            // user answers
            cin >> promptAnswer;
            cout << endl;

            // clears casedAnswer
            casedAnswer = "";

            // sets letters to lowercase
            for (char c : promptAnswer) {
                casedAnswer += tolower(c);
            }

            // depending on answer, function returns corresponding bool value
            // if user does not answer validly, error is caught and user tries again
            if (casedAnswer == "yes" || casedAnswer == "y" || casedAnswer == "1") {
                fixedAnswer = 1;
                return true;
            }
            else if (casedAnswer == "no" || casedAnswer == "n" || casedAnswer == "0") {
                fixedAnswer = 0;
                return false;
            }
            else {
                throw runtime_error("Your answer did not match the required criteria. Please try answering again.");
            }
        }
        catch (const runtime_error& err) {
            cout << "Exception: " << err.what() << "\n" << endl;
        }
    }
}

static void divider(int dividerLength) {
    // divider for ui sake, called function includes width
    cout << setfill('-') << setw(dividerLength) << "\n\n";
}

static void checkInventory(string inventory[], int inventorySize) {
    //print protagonist's inventory
    cout << "Inventory: " << endl;
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != "") {
            cout << "Slot " << i + 1 << ": " << inventory[i] << endl;
        }
        else {
            cout << "Slot " << i + 1 << ": Empty" << endl;
        }
    }
    cout << endl;
}

static bool checkItem(const string inventory[], int inventorySize, string& item) {
    // checks item for inventory given within parameters
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i] == item) {
            return true;
        }
    }
    return false;
}

static void defeat() {
    cout << "Unfortunately, you were bested." << endl;
    cout << "Grandma's fate is now at the hands of Little Red Riding Hood." << endl;
    cout << "Game over, " << name << endl;
}

static void win() {
    cout << "Congratulations!, you bested Little Red Riding Hood!" << endl;
    cout << "Grandma is safe!" << endl;
    cout << "Thank you for playing, " << name << endl;
}

int main()
{
    cout << "Welcome to The Big Bad Riding Hood!\n" << endl;

    // get user's name
    cout << "Hello user, please state your name!\n" << endl;

    // getline of name
    getline(cin, name);
    cout << "Thank you, " << name << ".\n" << endl;

    // divider 
    divider(64);

    // introduce setting and instructions
    cout << "In the woods, Little Red Riding Hood is about to set off on an adventure to grandma's house." << endl;
    cout << "A little secret is her plans are a bit more grave than previously thought." << endl;
    cout << "It is your primary duty to stop Little Red Riding Hood in her tracks and prevent the untimely death of grandma.\n" << endl;

    cout << "When asked questions, you will be prompted (y/n). You may type \"y\" or \"yes\" or \"n\" or \"no\"!" << endl;
    cout << "Okay, " << name << ". Now, you are now the Big Bad Wolf.\n" << endl;

    // divider
    divider(64);

    // ask if begin
    cout << "Would you like to begin? (y/n)\n" << endl;
    bool startQuestion = getResponse();

    // if user does not want to begin the game prompts them to try again
    while (startQuestion == 0) {
        cout << "Uh oh! Let's try again!" << endl;
        cout << "Would you like to begin? (y/n)\n" << endl;
        startQuestion = getResponse();
    }
    cout << "Great let's get started!\n" << endl;
    divider(32);

    // protagonist's inventory
    string inventory[4];
    for (int i = 0; i < 4; i++) {
        inventory[i] = "";
    }

    // GAME STARTS HERE
    cout << "PROLOGUE\n" << endl;
    divider(16);

    cout << "In the house of Little Red Riding Hood, you see her getting ready to make her trip to Grandma's house." << endl;
    cout << "However, as Riding Hood is walking out the door, you notice a bottle labeled \"XXX\" on her kitchen counter." << endl;
    cout << "Dismayed at the thought of Riding Hood trying to poison her dear grandmother, you decide you have to intervene.\n" << endl;

    // ask if continue
    cout << "Would you like to continue? (y/n)\n" << endl;
    bool continueQuestion = getResponse();

    // if user does not want to begin the game prompts them to try again
    while (continueQuestion == 0) {
        cout << "Uh oh! Let's try again!" << endl;
        cout << "Would you like to continue? (y/n)\n" << endl;
        continueQuestion = getResponse();
    }

    // divider
    divider(32);

    // FLOWER FOREST
    checkInventory(inventory, 4);
    cout << "FLOWER FOREST\n" << endl;
    divider(16);

    cout << "Following Little Red Riding Hood out into the forest, you both stumble into the great flower forest." << endl;
    cout << "The landscape is surrounded by beautiful fields of luscious green and colorful flowers." << endl;
    cout << "You notice Riding Hood being a little too enticed by the flowers and begins falling a bit off the beaten path.\n" << endl;

    cout << "She stumbles on a branch and leaves behind a bottle of red wine." << endl;
    cout << "Do you pick it up? (y/n)\n" << endl;
    bool pickUpWine = getResponse();

    // if user takes the wine, it is added to their inventory
    if (pickUpWine) {
        inventory[0] = "Red Wine";
        cout << "After taking the wine, ";
    }
    else {
        cout << "Nevertheless, ";
    }
    cout << "you continue to follow her increasingly eerie path into the woods.\n" << endl;

    // divider
    divider(32);

    // OVERGROWTH FOREST
    checkInventory(inventory, 4);
    cout << "OVERGROWTH FOREST\n" << endl;
    divider(16);

    // big bad wolf goes under a bridge
    cout << "Looking up into the dense forest, you can barely make out the sun peering into the swaying leaves." << endl;
    cout << "Despite your hesitancy, you continue to follow Riding Hood's footsteps." << endl;
    cout << "You see a bridge further on into the forest and decide to hide under it, anticipating Riding Hood's passage over it.\n" << endl;

    // next events are random and dependent upon a dice roll
    srand((unsigned int)time(0)); // create seed using time(0) function
    int bridgeCheck = rand() % 4 + 1; // dice roll

    switch (bridgeCheck) {
    case 1:
        // big bad wolf eats some berries from the bridge
        cout << "Now underneath the rickety bridge, you find some berries and decide to eat them." << endl;
        cout << "Because of the berries' sedative nature, you fall asleep.\n" << endl;
        cout << "Upon your awakening, you walk back up onto the bridge and find that there is a key left behind." << endl;
        cout << "Do you take the key? (y/n)\n" << endl;
        break;
    case 2:
        // big bad wolf falls asleep under the bridge
        cout << "Now underneath the bridge, you find the cobblestone to be quite comfortable." << endl;
        cout << "You consider how long of a day you've had and decide to take a quick nap.\n" << endl;
        cout << "Once you awaken you realize it has been quite a long time." << endl;
        cout << "However, you notice a key left behind atop the bridge. Do you take it? (y/n)\n" << endl;
        break;
    case 3:
        // big bad wolf encounters riding hood
        cout << "As you begin to settle underneath the bridge, you hear the chime of a keychain." << endl;
        cout << "You peek above the base of the bridge to see Riding Hood traveling with an ornate skeleton key.\n" << endl;
        cout << "You feel inclined to take it as its brass is quite enticing." << endl;
        cout << "Do you take it? (y/n)\n" << endl;
        break;
    case 4:
        // big bad wolf is swept away by the river
        cout << "As you carefully step down into the basin of the river underneath the bridge, you lose your balance.\n" << endl;
        cout << "You are quite suddenly swept up off of your feet and directed into the river below.\n" << endl;
        cout << "In a panic, you think to grab onto something, anything that will bring you back to land." << endl;
        cout << "You are just within reach of a dark piece of brass, do you grab on? (y/n)\n" << endl;
        break;
    }

    // user prompted to take key
    bool grabKey = getResponse();

    // if user takes the key, it is added to their inventory
    if (grabKey) {
        inventory[1] = "Skeleton Key";
    }

    // story continues
    cout << "Only after properly getting your footing do you continue onto the path, now with Riding Hood out of sight.\n" << endl;

    // divider
    divider(32);

    // ALPINE FOREST
    checkInventory(inventory, 4);
    cout << "ALPINE FOREST\n" << endl;
    divider(16);

    // riding hood stops to admire trees and you can take the cake from her bag
    cout << "Now in a more well-lit area, you find it much easier to scout Little Red Riding Hood." << endl;
    cout << "She, seemed to be enamored by the incredibly tall trees, stops to admire them.\n" << endl;
    cout << "With your keen pickpocketing skills, you feel like you may be able to rummage through her bag without her noticing." << endl;
    cout << "Do you peruse her bag? (y/n)\n" << endl;

    // user prompted to take key
    bool goThroughBag = getResponse();

    // if user takes the key, it is added to their inventory
    if (goThroughBag) {
        inventory[2] = "Red Velvet Cake";
    }

    cout << "Only after you had just backed off, she picks up her things once more and continues on.\n" << endl;

    // divider
    divider(32);

    // ALPINE FOREST
    checkInventory(inventory, 4);
    cout << "GRANDMA'S HOUSE\n" << endl;
    divider(16);

    cout << "Finally, after your long trek into the various places in the woods, you find yourself at Grandma's House." << endl;
    cout << "Arriving before Little Red Riding Hood, you decide to make your way in.\n" << endl;
    cout << "Approaching the door, you find a keyhole and search your inventory for a key." << endl;

    string item = "Skeleton Key";

    // calls function to check for item
    if (checkItem(inventory, 4, item)) {
        cout << "The skeleton key is in your inventory!\n" << endl;
    }
    else {
        cout << "The skeleton key is not in your inventory." << endl;
        defeat();
        return 0;
    }

    // enter grandmas house
    cout << "You enter the humble abode and look around, finding what appears to be the bedroom." << endl;
    cout << "You knock on the door.\n" << endl;
    cout << "Grandma opens the door and is incredibly startled by your appearance." << endl;
    cout << "You calm down granny and quickly explain the details of Riding Hood's plot." << endl;
    cout << "While she is apprehensive, she eventually comes to terms and asks what the next plan is.\n" << endl;
    cout << "Quickly drafting up a plan, you decide to hide grandma so you can take the fall in order to save grandma." << endl;
    cout << "However, you need a disguise so that Little Red Riding Hood won't know it's you." << endl;

    // user prompted to put on wardrobe
    cout << "Do you put on Grandma's wardrobe? (y/n)\n" << endl;

    // user prompted to put on grandma's clothes
    bool wearGrandmasClothes = getResponse();

    // if user does so, it is added to their inventory and they get +20 protection
    if (wearGrandmasClothes) {
        inventory[3] = "Grandma's Wardrobe";
    }

    cout << "Suddenly, you hear a knocking at the door." << endl;
    cout << "You tense up as the door creaks open.\n" << endl;

    cout << "\t\"Hi Grandma! It's me! I've got something special for you!\"" << endl;
    cout << "\t\"What big ears you have, Grandma!" << endl;
    cout << "\t\"And what big eyes you have, Grandma!" << endl;
    cout << "\t\"And big teeth you have, Grandma!\n" << endl;

    cout << "\"The better to eat you with, my dear.\" You reply.\n" << endl;
    
    // divider 
    divider(32);

    // FIGHT
    checkInventory(inventory, 4);
    cout << "CLIMAX\n" << endl;
    cout << "This is the turn-based RPG portion of the game." << endl;
    cout << "You will be prompted to either defend or attack." << endl;
    cout << "Good luck!\n" << endl;
    divider(16);

    // creates little red riding hood and the big bad wolf's stats using the character class
    Character ridingHood(100, 20);  // little red riding hood has 100 health and 20 undefended attack power
    Character badWolf(100, 25);  // the big bad wolf has 100 health and 25 undefended attack power

    // protection increases by 20 if previously opted to wear grandma's wardrobe
    if (wearGrandmasClothes) {
        badWolf.health += 20;
    }

    // turn-based portion of the game. attacks left undefended deal attack power, attacks defended or a defense without attack yield 10 damage.

    // initialize riding hood's random action check
    bool ridingHoodCheck;
    bool defendCheck;
    bool attackCheck;

    while (true) {
        // your turn
        cout << "Its your turn! Would you like to attack? (y/n)\n" << endl;
        attackCheck = getResponse();

        // riding hood has 50/50 chance to defend herself
        srand((unsigned int)time(0)); // create seed using time(0) function
        ridingHoodCheck = rand() % 2; // dice roll

        if (attackCheck) {
            if (ridingHoodCheck) {
                cout << "You attacked!" << endl;
                cout << "However, Riding Hood defended herself." << endl;
                cout << "You lose 10 health points." << endl;
                // if riding hood defended, and you attacked, you take 10 damage
                badWolf.defendDamageChar();
            }
            else {
                cout << "You attacked!" << endl;
                cout << "It was very effective!" << endl;
                cout << "Riding Hood loses 25 health points." << endl;
                // if riding hood did not defend, and you attacked, you deal 25 damage
                ridingHood.damageChar(badWolf);
            }
        }
        else {
            if (ridingHoodCheck) {
                cout << "You opted to not attack." << endl;
                cout << "However, Riding Hood defended herself!" << endl;
                cout << "Riding Hood loses 10 health points." << endl;
                // if riding hood defended, and you did not attack, riding hood takes 10 damage
                ridingHood.defendDamageChar();
            }
            else {
                cout << "You opted to not attack." << endl;
                cout << "Riding Hood did not defend herself either." << endl;
                // if riding hood did not defend, and you did not attack, turn ends
            }
        }
        cout << "End of turn.\n" << endl;

        // the stats of either character
        cout << "Little Red Riding Hood: ";
        ridingHood.healthUpdate();

        cout << "Big Bad Wolf: ";
        badWolf.healthUpdate();

        // check if either player died after turn
        if (ridingHood.health <= 0) {
            cout << "Little Red Riding Hood fainted!\n" << endl;
            win();
            return 0;
        }

        if (badWolf.health <= 0) {
            cout << "You fainted!\n" << endl;
            defeat();
            return 0;
        }

        // riding hood's turn
        cout << endl << "Now it is Little Riding Hood's turn. Would you like to defend yourself? (y/n)\n" << endl;
        defendCheck = getResponse();

        // riding hood has 50/50 chance to attack
        srand((unsigned int)time(0)); // create seed using time(0) function
        ridingHoodCheck = rand() % 2; // dice roll
        if (defendCheck) {
            if (ridingHoodCheck) {
                cout << "Riding Hood attacked!" << endl;
                cout << "However, you defended yourself!" << endl;
                cout << "Riding Hood loses 10 health points." << endl;
                // if riding hood attacked, and you defended, riding hood takes 10 damage
                ridingHood.defendDamageChar();
            }
            else {
                cout << "Riding Hood opted to not attack." << endl;
                cout << "However, you defended yourself!" << endl;
                cout << "You lose 10 health points." << endl;
                // if riding hood did not attack, and you defended, you take 10 damage
                badWolf.defendDamageChar();
            }
        }
        else {
            if (ridingHoodCheck) {
                cout << "Riding Hood attacked!" << endl;
                cout << "It was very effective!" << endl;
                cout << "You lose 20 health points." << endl;
                // if riding hood attacked, and you did not defend, you take 20 damage
                badWolf.damageChar(ridingHood);
            }
            else {
                cout << "Riding Hood opted to not attack." << endl;
                cout << "You did not defend yourself either." << endl;
                // if riding hood did not attack, and you did not defend, turn continues
            }
        }
        cout << "End of turn.\n" << endl;

        // the stats of either character
        cout << "Little Red Riding Hood: ";
        ridingHood.healthUpdate();

        cout << "Big Bad Wolf: ";
        badWolf.healthUpdate();
        cout << endl;

        // check if either player died after turn
        if (ridingHood.health <= 0) {
            cout << "Little Red Riding Hood fainted!\n" << endl;
            win();
            return 0;
        }

        if (badWolf.health <= 0) {
            cout << "You fainted!\n" << endl;
            defeat();
            return 0;
        }
    }

    return 0;
}
