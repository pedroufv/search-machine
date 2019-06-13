#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "classes/Collection.h"


TEST_CASE("Parse word: change accents, remove non allfa numeric and convert to lower case") {
    Word word;
    word.parse("guárdã-çhüvâ,");
    REQUIRE(word.getText() == "guardachuva");
}

TEST_CASE("Check if load word frequency on construct") {
    Document document("doc1", "../docs");

    REQUIRE(document.getWordFrquency().find("apartamento")->second == 1);
    REQUIRE(document.getWordFrquency().find("casa")->second == 4);
    REQUIRE(document.getWordFrquency().find("ninguem")->second == 2);
    REQUIRE(document.getWordFrquency().find("porem")->second == 1);
}

TEST_CASE("Check if last word push in the end") {
    Document document("doc1", "../docs");

    REQUIRE(document.getWords().back().getText() == "apartamento");
}

TEST_CASE("Check if load word frequency on construct to collection") {
    Collection collection("../docs");

    REQUIRE(collection.getWordFrquency().find("casa")->second == 5);
}

TEST_CASE("Check if doc1, doc2 and doc3 load on collection") {
    Collection collection("../docs");

    REQUIRE(collection.getDocuments().size() == 3);

    REQUIRE(collection.getDocuments().front().getName() == "doc3");
    REQUIRE(collection.getDocuments().at(1).getName() == "doc1");
    REQUIRE(collection.getDocuments().back().getName() == "doc2");
}