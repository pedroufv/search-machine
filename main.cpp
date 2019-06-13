#define CATCH_CONFIG_MAIN

#include <sys/stat.h>
#include "catch.hpp"
#include "classes/Search.h"

TEST_CASE("Parse word: change accents, remove non allfa numeric and convert to lower case") {
    Word word;
    word.parse("guárdã-çhüvâ,");
    REQUIRE(word.getText() == "guardachuva");
}

TEST_CASE("Handling file") {

    mkdir("../docs", 0777);

    ofstream ofile;
    string line;

    // file 1
    string text1 = "Quem casa quer casa.\n"
                   "Porem ninguém casa.\n"
                   "Ninguém quer casa também.\n"
                   "Quer apartamento.", path1 = "../docs/d1.txt";

    ofile.open(path1);
    REQUIRE_FALSE(ofile.fail());
    REQUIRE(ofile.is_open());
    ofile << text1;
    ofile.close();

    // file 2
    string text2 = "Ninguém em casa.\n"
                   "Todos saíram.\n"
                   "Todos. Quer entrar?\n"
                   "Quem?\n"
                   "Quem?", path2 = "../docs/d2.txt";

    ofile.open(path2);
    REQUIRE_FALSE(ofile.fail());
    REQUIRE(ofile.is_open());
    ofile << text2;
    ofile.close();

    // file 3
    string text3 = "Quem esta no apartamento?\n"
                   "Ninguém, todos saíram.", path3 = "../docs/d3.txt";

    ofile.open(path3);
    REQUIRE_FALSE(ofile.fail());
    REQUIRE(ofile.is_open());
    ofile << text3;
    ofile.close();
}

TEST_CASE("Check if load word frequency on construct") {
    Document document("d1.txt", "../docs");

    REQUIRE(document.getWordFrquency().find("apartamento")->second == 1);
    REQUIRE(document.getWordFrquency().find("casa")->second == 4);
    REQUIRE(document.getWordFrquency().find("ninguem")->second == 2);
    REQUIRE(document.getWordFrquency().find("porem")->second == 1);
}

TEST_CASE("Check if last word push in the end") {
    Document document("d1.txt", "../docs");

    REQUIRE(document.getWords().back().getText() == "apartamento");
}

TEST_CASE("Check if load word frequency on construct to collection") {
    Collection collection("../docs");

    REQUIRE(collection.getWordFrquency().find("casa")->second == 5);
}

TEST_CASE("Check if doc1, doc2 and doc3 load on collection") {
    Collection collection("../docs");

    REQUIRE(collection.getDocuments().size() == 3);

    REQUIRE(collection.getDocuments().front().getName() == "d2.txt");
    REQUIRE(collection.getDocuments().at(1).getName() == "d3.txt");
    REQUIRE(collection.getDocuments().back().getName() == "d1.txt");
}

TEST_CASE("Check if terms has populed") {
    Collection collection("../docs");
    Search search("ÇásÃ tOdoS apàrtamêntõ", collection);

    REQUIRE(search.getTerms().at(0).getText() == "casa");
    REQUIRE(search.getTerms().at(1).getText() == "todos");
    REQUIRE(search.getTerms().at(2).getText() == "apartamento");
}

TEST_CASE("Check if found terms in collection") {
    Collection collection("../docs");
    Search search("apàrtamêntõ", collection);

    REQUIRE(search.getDocumentsFound().at(0).getName() == "d3.txt");
    REQUIRE(search.getDocumentsFound().at(1).getName() == "d1.txt");
    REQUIRE(search.getWordImportance().find("apartamento")->second == log((float) 3/2));
}


TEST_CASE("Check coordinate") {
    Collection collection("../docs");
    Search search("casa", collection);

    for(const auto &point : search.getCoordinate()) {

        for (const auto &docWord : point.first) {
            cout << docWord.first << " - " << docWord.second;
        }

        cout << " - value: " << point.second << endl;
    }
}