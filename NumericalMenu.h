
#ifndef NUMERICALMENU_H_
#define NUMERICALMENU_H_

#include <iostream>
using namespace std;

class NumericalMenu {
public:
    NumericalMenu();
    int addOption(string option);
    void setCancelText (string cancelText);
    void setErrorText (string errorText);
    void setPrompt(string prompt);
    void setRepeatPromptOnError(bool shouldRepeat);
    int run() const;
    int size() const;

    string option, cancelText, errorText, prompt;
    bool shouldRepeat;

private:
    int count = 0;
    string arr[100];
    int optionNumber;


};


#endif