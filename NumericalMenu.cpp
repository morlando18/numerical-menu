#include "NumericalMenu.h"

// default constructor for this class
NumericalMenu::NumericalMenu(){
    this->cancelText = "Cancel";
    this->errorText = "Error!";
    this->prompt = "choose an option:";
    this->shouldRepeat = true;
}
//add the passed in option to the menu
//returns the number assigned to the new option in the menu
int NumericalMenu::addOption(string option){

    this->option = option;
    arr[++count] = this-> option;
    return count;
}
//set the text displayed for cancellation to cancelText
// (defaults to "cancel" if not called)
void NumericalMenu::setCancelText (string cancelText){
    this->cancelText = cancelText;
}
//Set the text displayed on receipt of invalid input to errorText
//(defaults to "error!" if not called)
void NumericalMenu::setErrorText (string errorText){
    this->errorText = errorText;
}
//Set the initial prompt that precedes the menu options
// defaults to "choose an option:"
void NumericalMenu::setPrompt(string prompt){
    this->prompt = prompt;
}
// set whether or not the prompt is repeated on receipt of invalid input;
// prompt will be repeated if shouldRepeat is true. (defaults to true if not called)
void NumericalMenu::setRepeatPromptOnError(bool shouldRepeat){
    this-> shouldRepeat = shouldRepeat;
}
// Runs the menu; does not return until the user provides valid input.
// returns -1 on cancellation, and the option number otherwise
int NumericalMenu::run() const{
    do {
        cout << endl << prompt << endl << endl;
        for (int i = 1; i < count + 1; i++) cout << i << " - " << arr[i] << endl;
        cout << count + 1 << " - " << cancelText << endl << endl;
        int optionNumber;
        cin >> optionNumber;

        if (optionNumber == count + 1) {
            return -1;
        } else if (optionNumber > count || optionNumber <= 0) {
            cout << endl << errorText  << endl;

        }else {
            return optionNumber;
        }
    }while(shouldRepeat || (optionNumber > count || optionNumber <= 0));
}

//returns the current number of menu options in this menu
int NumericalMenu::size() const{
    return count;
}

