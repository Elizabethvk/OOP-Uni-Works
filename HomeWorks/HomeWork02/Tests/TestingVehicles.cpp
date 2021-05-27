#include "Catch2/catch_amalgamated.hpp"
#include "Vehicle.h"

TEST_CASE("Testing class Vehicle", "[vehicle]")
{
    SECTION("Testing constructor")
    {
        WHEN("The input data is bad")
        {
            REQUIRE_THROWS(Vehicle(Registration("ВA1243121AT"), "Random test with bad registration plate."));
            REQUIRE_THROWS(Vehicle(Registration("ABCDEFGH"), "Maybe maybe maybe"));
		    REQUIRE_THROWS(Vehicle(Registration("12345678"), "Another fail"));
            REQUIRE_THROWS(Vehicle(Registration("AAA123BB"), "Not valid as well"));
            REQUIRE_THROWS(Vehicle(Registration("aa12aa"), "Stop trying"));
            REQUIRE_THROWS(Vehicle(Registration("АВ1452ZZ"), "Let's see cyrillic"));
        }

        WHEN("The input data is good")
        {
            REQUIRE_NOTHROW(Vehicle(Registration("AA0099ZZ"), "Test test test a good one"));
            REQUIRE_NOTHROW(Vehicle(Registration("LE1337ET"), "Lorem ipsum dolor sit amet,\
                                                                consectetur adipiscing elit,\
                                                                sed do eiusmod tempor incididunt\
                                                                ut labore et dolore magna aliqua.\
                                                                Id leo in vitae turpis massa.\
                                                                Id porta nibh venenatis cras\
                                                                sed felis eget.\
                                                                Arcu dictum varius duis at.\
                                                                Dolor sed viverra ipsum nunc\
                                                                aliquet bibendum. "));
            REQUIRE_NOTHROW(Vehicle(Registration("A a 124 3 B b"), "Nice car!"));
            REQUIRE_NOTHROW(Vehicle(Registration("aa3333ff"), "Cool car!"));
            REQUIRE_NOTHROW(Vehicle(Registration("He8322dR"), "Wonderful car!"));
            REQUIRE_NOTHROW(Vehicle(Registration("A0000ZZ"), "10/10"));
            REQUIRE_NOTHROW(Vehicle(Registration("a a 2 3 2 1 e e"), "Always starts!"));
        }
    }

    SECTION("Testing functionality that doesn't include Person")
    {
        Vehicle test1(Vehicle(Registration("aa3333ff"), "Cool car!"));
        Vehicle test2(Vehicle(Registration("He8322dR"), "Wonderful car!"));
        Vehicle test3(Vehicle(Registration("A0000ZZ"), "10/10"));
        
        WHEN("Testing get description")
        {
            REQUIRE(test1.getDescr() == "Cool car!");
            REQUIRE(test2.getDescr() == "Wonderful car!");
            REQUIRE(test3.getDescr() == "10/10");
        }

        WHEN("Testing get registration number")
        {
            REQUIRE(test1.getRegistrationNumb() == "AA3333FF");
            REQUIRE(test2.getRegistrationNumb() == "HE8322DR");
            REQUIRE(test3.getRegistrationNumb() == "A0000ZZ");
        }

        WHEN("Testing for owner")
        {
            REQUIRE_FALSE(test1.isOwned());
            REQUIRE_FALSE(test2.isOwned());
            REQUIRE_FALSE(test3.isOwned());
        }

    }

    SECTION("Testing overloaded operators")
    {
        WHEN("Testing operator ==")
        {
            Vehicle test1(Vehicle(Registration("aa3333ff"), "Cool car!"));
            Vehicle test2(Vehicle(Registration("He8322dR"), "Wonderful car!"));
            Vehicle test3(Vehicle(Registration("Aa3333Ff"), "10/10"));
            Registration test4("hE8322Dr");
            Registration test5("u8823hd");
            string test6 = "AA3333FF";

            REQUIRE_FALSE(test1 == test2);
            REQUIRE(test1 == test3);
            REQUIRE(test2==test4);
            REQUIRE_FALSE(test2==test5);
            REQUIRE(test3 == test6);

        }

        // WHEN("Testing operator <<")
        // {
            
        // }

    }

}