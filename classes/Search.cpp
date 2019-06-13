#include <sstream>
#include <algorithm>
#include <math.h>
#include "Search.h"

Search::Search(const string &expression, Collection collection) : expression(expression), collection(collection) {
    loadTerms();
    loadWordImportance();
    loadCoordinate();
}

const string &Search::getExpression() const {
    return expression;
}

void Search::setExpression(const string &expression) {
    Search::expression = expression;
}

const vector<Word> &Search::getTerms() const {
    return terms;
}

void Search::setTerms(const vector<Word> &terms) {
    Search::terms = terms;
}

const Collection &Search::getCollection() const {
    return collection;
}

void Search::setCollection(const Collection &collection) {
    Search::collection = collection;
}

const vector<Document> &Search::getDocumentsFound() const {
    return documentsFound;
}

void Search::setDocumentsFound(const vector<Document> &documentsFound) {
    Search::documentsFound = documentsFound;
}

const map<string, float> &Search::getWordImportance() const {
    return wordImportance;
}

void Search::setWordImportance(const map<string, float> &wordImportance) {
    Search::wordImportance = wordImportance;
}

const map<map<string, string>, float> &Search::getCoordinate() const {
    return coordinate;
}

void Search::setCoordinate(const map<map<string, string>, float> &coordinate) {
    Search::coordinate = coordinate;
}

void Search::loadTerms() {
    string streamTerm;
    stringstream strStream(expression);
    Word word;

    while (strStream >> streamTerm) {
        word.parse(streamTerm);

        terms.emplace_back(word);

        loadDocumentsFound(word);
    }

}

void Search::loadDocumentsFound(Word word) {

    for(const auto &document : collection.getDocuments()){
        if (find(document.getWords().begin(), document.getWords().end(), word) == document.getWords().end())
            continue;

        if (find(documentsFound.begin(), documentsFound.end(), document) == documentsFound.end())
            documentsFound.emplace_back(document);
    }
}

void Search::loadWordImportance() {

    int found = 0;

    for(const auto &word : terms){

        for(const auto &document : collection.getDocuments()){
            if (find(document.getWords().begin(), document.getWords().end(), word) == document.getWords().end())
                continue;

            found++;
        }

        wordImportance.insert(pair<string, float>(word.getText(), log((float) collection.getDocuments().size() / found)));
    }
}


void Search::loadCoordinate() {

    // calculete frequency x wordImportance
    for(const auto &document : collection.getDocuments()){

        for(const auto &term : terms){
            if (find(document.getWords().begin(), document.getWords().end(), term) == document.getWords().end())
                continue;

            map<string, string> coord;
            coord.insert(pair<string, string>(document.getName(), term.getText()));
            if(coordinate.find(coord) == coordinate.end()) {
                coordinate.insert(pair<map<string, string>, float>(coord, 0));
            }

            coordinate.find(coord)->second = find(documentsFound.begin(), documentsFound.end(), document).base()->getWordFrquency().find(term.getText())->second * wordImportance.find(term.getText())->second;
        }
    }
}
