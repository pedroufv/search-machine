#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "classes/Word.h"


TEST_CASE("Parse word: change accents, remove non allfa numeric and convert to lower case") {
    Word word;
    word.parse("guárdã-çhüvâ,");
    REQUIRE(word.getText() == "guardachuva");
}