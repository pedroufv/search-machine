#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "classes/Word.h"


TEST_CASE("Parse word: change accents, remove non allfa numeric and convert to lower case") {
    Word word;
    word.setText("guárdã-çhüvâ,");
    word.removeNonAlfa();
    REQUIRE(word.getText() == "guardachuva");
}