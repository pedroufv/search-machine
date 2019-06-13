#include "Word.h"

const string &Word::getText() const {
    return text;
}

void Word::setText(const string &text) {
    Word::text = text;
}

void Word::toLower() {
    for (auto &letter : text) {
        letter = tolower(letter);
    }
}

void Word::replaceAccents() {
    // style noob to make this =D but work fine!
    if(text.find("Á") != string::npos) text.replace(text.find("Á"), string("Á").length(), "A");
    if(text.find("À") != string::npos) text.replace(text.find("À"), string("À").length(), "A");
    if(text.find("Ã") != string::npos) text.replace(text.find("Ã"), string("Ã").length(), "A");
    if(text.find("Â") != string::npos) text.replace(text.find("Â"), string("Â").length(), "A");
    if(text.find("Ä") != string::npos) text.replace(text.find("Ä"), string("Ä").length(), "A");
    if(text.find("á") != string::npos) text.replace(text.find("á"), string("á").length(), "a");
    if(text.find("à") != string::npos) text.replace(text.find("à"), string("à").length(), "a");
    if(text.find("ã") != string::npos) text.replace(text.find("ã"), string("ã").length(), "a");
    if(text.find("â") != string::npos) text.replace(text.find("â"), string("â").length(), "a");
    if(text.find("ä") != string::npos) text.replace(text.find("ä"), string("ä").length(), "a");
    if(text.find("É") != string::npos) text.replace(text.find("É"), string("É").length(), "E");
    if(text.find("È") != string::npos) text.replace(text.find("È"), string("È").length(), "E");
    if(text.find("Ẽ") != string::npos) text.replace(text.find("Ẽ"), string("Ẽ").length(), "E");
    if(text.find("Ê") != string::npos) text.replace(text.find("Ê"), string("Ê").length(), "E");
    if(text.find("Ë") != string::npos) text.replace(text.find("Ë"), string("Ë").length(), "E");
    if(text.find("é") != string::npos) text.replace(text.find("é"), string("é").length(), "e");
    if(text.find("è") != string::npos) text.replace(text.find("è"), string("è").length(), "e");
    if(text.find("ẽ") != string::npos) text.replace(text.find("ẽ"), string("ẽ").length(), "e");
    if(text.find("ê") != string::npos) text.replace(text.find("ê"), string("ê").length(), "e");
    if(text.find("ë") != string::npos) text.replace(text.find("ë"), string("ë").length(), "e");
    if(text.find("Í") != string::npos) text.replace(text.find("Í"), string("Í").length(), "I");
    if(text.find("Ì") != string::npos) text.replace(text.find("Ì"), string("Ì").length(), "I");
    if(text.find("Ĩ") != string::npos) text.replace(text.find("Ĩ"), string("Ĩ").length(), "I");
    if(text.find("Î") != string::npos) text.replace(text.find("Î"), string("Î").length(), "I");
    if(text.find("Ï") != string::npos) text.replace(text.find("Ï"), string("Ï").length(), "I");
    if(text.find("í") != string::npos) text.replace(text.find("í"), string("í").length(), "i");
    if(text.find("ì") != string::npos) text.replace(text.find("ì"), string("ì").length(), "i");
    if(text.find("ĩ") != string::npos) text.replace(text.find("ĩ"), string("ĩ").length(), "i");
    if(text.find("î") != string::npos) text.replace(text.find("î"), string("î").length(), "i");
    if(text.find("ï") != string::npos) text.replace(text.find("ï"), string("ï").length(), "i");
    if(text.find("Ó") != string::npos) text.replace(text.find("Ó"), string("Ó").length(), "O");
    if(text.find("Ò") != string::npos) text.replace(text.find("Ò"), string("Ò").length(), "O");
    if(text.find("Õ") != string::npos) text.replace(text.find("Õ"), string("Õ").length(), "O");
    if(text.find("Ô") != string::npos) text.replace(text.find("Ô"), string("Ô").length(), "O");
    if(text.find("Ö") != string::npos) text.replace(text.find("Ö"), string("Ö").length(), "O");
    if(text.find("ó") != string::npos) text.replace(text.find("ó"), string("ó").length(), "o");
    if(text.find("ò") != string::npos) text.replace(text.find("ò"), string("ò").length(), "o");
    if(text.find("õ") != string::npos) text.replace(text.find("õ"), string("õ").length(), "o");
    if(text.find("ô") != string::npos) text.replace(text.find("ô"), string("ô").length(), "o");
    if(text.find("ö") != string::npos) text.replace(text.find("ö"), string("ö").length(), "o");
    if(text.find("Ú") != string::npos) text.replace(text.find("Ú"), string("Ú").length(), "U");
    if(text.find("Ù") != string::npos) text.replace(text.find("Ù"), string("Ù").length(), "U");
    if(text.find("Ũ") != string::npos) text.replace(text.find("Ũ"), string("Ũ").length(), "U");
    if(text.find("Û") != string::npos) text.replace(text.find("Û"), string("Û").length(), "U");
    if(text.find("Ü") != string::npos) text.replace(text.find("Ü"), string("Ü").length(), "U");
    if(text.find("ú") != string::npos) text.replace(text.find("ú"), string("ú").length(), "u");
    if(text.find("ù") != string::npos) text.replace(text.find("ù"), string("ù").length(), "u");
    if(text.find("ũ") != string::npos) text.replace(text.find("ũ"), string("ũ").length(), "u");
    if(text.find("û") != string::npos) text.replace(text.find("û"), string("û").length(), "u");
    if(text.find("ü") != string::npos) text.replace(text.find("ü"), string("ü").length(), "u");
    if(text.find("Ç") != string::npos) text.replace(text.find("Ç"), string("Ç").length(), "C");
    if(text.find("ç") != string::npos) text.replace(text.find("ç"), string("ç").length(), "c");
}

void Word::removeNonAlfa() {
    for(string::iterator i = text.begin(); i != text.end(); i++)
    {
        if(!isalpha(text.at(i - text.begin())))
        {
            text.erase(i);
            i--;
        }
    }
}

void Word::parse(string text) {
    setlocale(LC_ALL, "en_US.iso88591");
    setText(text);
    replaceAccents();
    toLower();
    removeNonAlfa();
}

bool Word::operator==(const Word &rhs) const {
    return this->getText() == rhs.getText();
}
