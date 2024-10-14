#include<iostream>
#include<string>
using namespace std;
void startAdventure();
void exploreLibrary();
void hiddenBasement();
void atticEscape();
void exploreKitchen();
void encounterGhost();
void findSecretRoom();
int main(){
    cout<<"Welcome to the Extended Haunted Mansion Mystery!"<<endl;
    cout<<"Your goal is to escape the haunted mansion by making smart decisions."<<endl;
    startAdventure();
    return 0;
}
void startAdventure(){
    char choice;
    cout<<"You find yourself in the main hall of the mansion. You feel a chill in the air."<<endl;
    cout<<"You see a grand staircase leading to the attic (A), a door to the basement (B), a strange old library (L), and a dark kitchen (K)."<<endl;
    cout<<"Where do you want to go? Enter A for attic, B for basement, L for library, or K for kitchen: ";
    while(true){
        cin>>choice;
        if(choice=='A'||choice=='a'){
            atticEscape();
            break;
        }
        else if(choice=='B'||choice=='b'){
            hiddenBasement();
            break;
        }
        else if(choice=='L'||choice=='l'){
            exploreLibrary();
            break;
        }
        else if(choice=='K'||choice=='k'){
            exploreKitchen();
            break;
        }
        else{
            cout<<"Invalid choice. Please enter A, B, L, or K: ";
        }
    }
}
void exploreLibrary(){
    char choice;
    cout<<"The library is dark and filled with dusty old books. You hear whispers as you browse the shelves."<<endl;
    cout<<"You find a hidden lever behind one of the books."<<endl;
    cout<<"Do you want to (P)ull the lever or (I)gnore it and leave?"<<endl;
    cout<<"Enter P to pull the lever or I to ignore it: ";
    while(true){
        cin>>choice;
        if(choice=='P'||choice=='p'){
            cout<<"You pull the lever and a secret passage to a hidden room opens!"<<endl;
            findSecretRoom();
            break;
        }
        else if(choice=='I'||choice=='i'){
            cout<<"You decide to leave the library and return to the main hall."<<endl;
            startAdventure();
            break;
        }
        else{
            cout<<"Invalid choice. Please enter P or I: ";
        }
    }
}
void hiddenBasement(){
    char choice;
    cout<<"You descend into the dark, damp basement. Strange noises echo in the distance."<<endl;
    cout<<"You find an ancient chest and a creepy door at the far end."<<endl;
    cout<<"Do you want to (O)pen the chest, (E)nter the door, or (R)eturn to the main hall?"<<endl;
    cout<<"Enter O to open the chest, E to enter the door, or R to return: ";
    while(true){
        cin>>choice;
        if(choice=='O'||choice=='o'){
            cout<<"You open the chest and find a glowing key! This could be your way out!"<<endl;
            cout<<"You take the key and return to the main hall."<<endl;
            startAdventure();
            break;
        }
        else if(choice=='E'||choice=='e'){
            cout<<"You enter the creepy door and encounter a ghost!"<<endl;
            encounterGhost();
            break;
        }
        else if(choice=='R'||choice=='r'){
            cout<<"You return to the main hall, leaving the basement behind."<<endl;
            startAdventure();
            break;
        }
        else{
            cout<<"Invalid choice. Please enter O, E, or R: ";
        }
    }
}
void encounterGhost(){
    char choice;
    cout<<"A ghostly figure appears, blocking your path!"<<endl;
    cout<<"Do you want to (T)alk to the ghost, (R)un away, or (F)ight it?"<<endl;
    cout<<"Enter T to talk, R to run, or F to fight: ";
    while(true){
        cin>>choice;
        if(choice=='T'||choice=='t'){
            cout<<"You try to communicate with the ghost. It seems to understand you and vanishes, leaving behind a clue."<<endl;
            cout<<"The clue leads you to believe there's something important in the attic."<<endl;
            startAdventure();
            break;
        }
        else if(choice=='R'||choice=='r'){
            cout<<"You run back to the main hall in fear."<<endl;
            startAdventure();
            break;
        }
        else if(choice=='F'||choice=='f'){
            cout<<"You try to fight the ghost, but it's too strong! The ghost overpowers you, and you lose."<<endl;
            return;
        }
        else{
            cout<<"Invalid choice. Please enter T, R, or F: ";
        }
    }
}
void exploreKitchen(){
    char choice;
    cout<<"The kitchen is old and abandoned. You hear the faint sound of footsteps behind you."<<endl;
    cout<<"Do you want to (S)earch the kitchen or (R)eturn to the main hall?"<<endl;
    cout<<"Enter S to search or R to return: ";
    while(true){
        cin>>choice;
        if(choice=='S'||choice=='s'){
            cout<<"You search the kitchen and find a mysterious key inside the oven!"<<endl;
            cout<<"You take the key and return to the main hall."<<endl;
            startAdventure();
            break;
        }
        else if(choice=='R'||choice=='r'){
            cout<<"You return to the main hall, leaving the kitchen behind."<<endl;
            startAdventure();
            break;
        }
        else{
            cout<<"Invalid choice. Please enter S or R: ";
        }
    }
}
void findSecretRoom(){
    char choice;
    cout<<"You enter the secret room and find a hidden safe. The air feels colder here."<<endl;
    cout<<"Do you want to (O)pen the safe or (R)eturn to the main hall?"<<endl;
    cout<<"Enter O to open or R to return: ";
    while(true){
        cin>>choice;
        if(choice=='O'||choice=='o'){
            cout<<"You open the safe and find a note. The note says 'The attic holds the secret to escape.'"<<endl;
            startAdventure();
            break;
        }
        else if(choice=='R'||choice=='r'){
            cout<<"You return to the main hall, leaving the secret room behind."<<endl;
            startAdventure();
            break;
        }
        else{
            cout<<"Invalid choice. Please enter O or R: ";
        }
    }
}
void atticEscape(){
    char choice;
    cout<<"The attic is cold and filled with strange noises. You see a locked door and a window."<<endl;
    cout<<"You can try to (U)se the key you found or (S)mash the window to escape."<<endl;
    cout<<"Enter U to use the key or S to smash the window: ";
    while(true){
        cin>>choice;
        if(choice=='U'||choice=='u'){
            cout<<"The key fits! You open the door and escape the haunted mansion. Congratulations, you survived!"<<endl;
            break;
        }
        else if(choice=='S'||choice=='s'){
            cout<<"You smash the window and try to climb out, but the ghosts catch you! You failed to escape."<<endl;
            break;
        }
        else{
            cout<<"Invalid choice. Please enter U or S: ";
        }
    }
}