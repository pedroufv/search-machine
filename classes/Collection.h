#ifndef SEARCH_MACHINE_COLLECTION_H
#define SEARCH_MACHINE_COLLECTION_H


#include <dirent.h>
#include <cstring>
#include "Document.h"

class Collection {

private:
    string path;
    vector<Document> documents;
    map<string, int> wordFrquency;

    void read();
    void loadDocuments();
    void addWordFrequency(Document document);

public:
    Collection(const string &path);

    const string &getPath() const;

    void setPath(const string &path);

    const vector<Document> &getDocuments() const;

    void setDocuments(const vector<Document> &documents);

    const map<string, int> &getWordFrquency() const;

    void setWordFrquency(const map<string, int> &wordFrquency);

};


#endif //SEARCH_MACHINE_COLLECTION_H
