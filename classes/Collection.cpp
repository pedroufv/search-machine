#include "Collection.h"

Collection::Collection(const string &path) : path(path) {
    read();
}

const string &Collection::getPath() const {
    return path;
}

void Collection::setPath(const string &path) {
    Collection::path = path;
}

const vector<Document> &Collection::getDocuments() const {
    return documents;
}

void Collection::setDocuments(const vector<Document> &documents) {
    Collection::documents = documents;
}

const map<string, int> &Collection::getWordFrquency() const {
    return wordFrquency;
}

void Collection::setWordFrquency(const map<string, int> &wordFrquency) {
    Collection::wordFrquency = wordFrquency;
}

void Collection::read() {
    loadDocuments();
}

void Collection::loadDocuments() {
    DIR*    dir;
    dirent* pdir;

    dir = opendir(path.c_str());

    while ((pdir = readdir(dir)) != NULL) {
        if(strcmp(pdir->d_name, ".") == 0 || strcmp(pdir->d_name, "..") == 0) {
            continue;
        }

        Document document(pdir->d_name, path);

        documents.emplace_back(document);
        addWordFrequency(document);
    }

    closedir(dir);

}

void Collection::addWordFrequency(Document document) {

    if(document.getWordFrquency().empty())
        return;

    for (const auto &item : document.getWordFrquency()) {
        if (wordFrquency.find(item.first) == wordFrquency.end()) {
            wordFrquency.insert(pair<string, int>(item.first, 0));
        }

        wordFrquency.find(item.first)->second += item.second;
    }
}
