#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "classes/Word.h"
#include "classes/Document.h"


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