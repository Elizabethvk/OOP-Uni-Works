#include "Catch2/catch_amalgamated.hpp"
#include "Vehicle.h"

TEST_CASE("Testing the relationship between Vehicle & Person", "[relationship]")
{
    SECTION("Testing from Vehicles' side")
    {
        Vehicle testCar(Registration("TX1007XT"), "James Bond's car");
        Person testPerson("James Bond", 1007);
        Person testNewOwner("Ernst Stavro Blofeld", 2015);

        // WHEN("Setting owner")
        // {
        //     REQUIRE_NOTHROW(testCar.setOwner(testPerson));
        //     // testCar.setOwner(testPerson);
        //     // CHECK(testCar.setOwner(testPerson));

        //     // bool isHeTheOwner = testCar.getOwner() == testPerson;
        //     // REQUIRE(isHeTheOwner == true);
        //     // REQUIRE(testCar.isOwned() == true);
        //     // REQUIRE((testCar.getOwner() == testNewOwner) == false);
        //     // bool isIt = (testCar.getOwner() == testNewOwner);
        //     // REQUIRE(isIt == true);
        // }

    //     WHEN("Changing owner")
    //     {
    //         REQUIRE_NOTHROW(testCar.setOwner(testPerson));
    //         REQUIRE((testCar.getOwner() == testPerson) == true);
    //         // testCar.setOwner(testNewOwner);
    //         REQUIRE_NOTHROW(testCar.setOwner(testNewOwner));
    //         REQUIRE((testCar.getOwner() == testNewOwner) == true);
    //     }

    //     WHEN("Removing owner")
    //     {
    //         REQUIRE_NOTHROW(testCar.setOwner(testPerson));
    //         REQUIRE_NOTHROW(testCar.removeOwner());
    //         // REQUIRE(testCar.getOwner() );
    //         // bool isIt = (testCar.getOwner() == testPerson);
    //         // REQUIRE(isIt == false);
    //         REQUIRE((testCar.getOwner() == testPerson) == false);
            
    //     }

    }

    SECTION("Testing from Person's side")
    {
        Person human("Angel", 9234);

        Vehicle first(Registration("AA1234ww"), "Nice");
        Vehicle second(Registration("h9342rr"), "Good");
        // Vehicle first("", "");


        WHEN("Adding vehicles")
        {
            first.setOwner(human);
            second.setOwner(human);
            // REQUIRE_NOTHROW(first.setOwner(human));
            // REQUIRE_NOTHROW(second.setOwner(human));
            REQUIRE(human.doIPossessVehicles() == true);
            REQUIRE(human.getOwnedVehNum() == 2);
            REQUIRE((human.vehiclePositionStorage(first) != -1) == true);
            REQUIRE((human.vehiclePositionStorage(second) != -1) == true);

            // REQUIRE_NOTHROW(human.removeAllOwnedVehicles());
            human.removeAllOwnedVehicles();

            REQUIRE(human.doIPossessVehicles() == false);
            REQUIRE(human.getOwnedVehNum() == 0);
            REQUIRE((human.vehiclePositionStorage(first) == -1) == true);
            REQUIRE((human.vehiclePositionStorage(second) == -1) == true);

        }

        WHEN("Inserting duplicates")
        {
            REQUIRE_THROWS(first.setOwner(human));
            REQUIRE_THROWS(second.setOwner(human));

            Vehicle faulty(Registration("AA1234ww"), "Cool description");
            REQUIRE_THROWS(faulty.setOwner(human));

            REQUIRE(human.doIPossessVehicles() == false);
            REQUIRE(human.getOwnedVehNum() == 0);

        }

        WHEN("Removing vehicles")
        {
            REQUIRE_NOTHROW(first.setOwner(human));
            REQUIRE(human.doIPossessVehicles() == true);
            REQUIRE(human.getOwnedVehNum() == 1);
            REQUIRE((human.vehiclePositionStorage(first) != -1) == true);

            REQUIRE_NOTHROW(first.removeOwner());
            REQUIRE(human.doIPossessVehicles() == false);
            REQUIRE(human.getOwnedVehNum() == 0);
            REQUIRE((human.vehiclePositionStorage(first) == -1) == true);

            
        }

        WHEN("Inserting multiple vehicles (dynamic memory)")
        {
            std::vector<Vehicle*> testCars;
			std::string firstReg = "a0000BC";

			Vehicle* newTestCar = new Vehicle(firstReg, "Testing");
			
            REQUIRE_NOTHROW((*newTestCar).setOwner(human));
			testCars.push_back(newTestCar);

            // 999 different car plates (factory101)
            unsigned j = 0, k = 0, l = 0, t = 0;
			for (unsigned i = 1; i < 1000; ++i)
			{
                ++j;
                // startingReg[1] = j;
                firstReg[1] = t;
                firstReg[2] = k;
                firstReg[3] = l;
                firstReg[4] = j;

                if (j == 9) {
                    j = 0;
                    ++l;
                }
                if (l == 9) {
                    l = 0;
                    ++k;
                }
                if (k == 9) {
                    ++t;
                }
                
                ++j;

				try 
                {
					Vehicle* newTestCar = new Vehicle(firstReg, "Just Test");
					REQUIRE_NOTHROW((*newTestCar).setOwner(human));
					testCars.push_back(newTestCar);
                    REQUIRE((human.vehiclePositionStorage(*newTestCar) != -1) == true);
				}
				catch (const std::bad_alloc& e) { //allocation error
					std::cerr << e.what() << std::endl;
					for (unsigned m = 0; m < testCars.size(); ++m) {
						delete testCars[m];
					}
                    testCars.clear();
					break;
				}
				catch (std::invalid_argument&) {
						std::cerr << "Vehicle with this car plate is already owned by this person!" << endl;
					}
					break;


            }
                // catch (...) 
                // {
                //     std::cerr << "Not sure what but it is problematic!" << endl;
                //     for (unsigned m = i; m < testCars.size(); ++m) {
				// 		delete testCars[m];
				// 	}
				// 	break;

                // }

			REQUIRE(human.getOwnedVehNum() == 1000);

			WHEN("Testing removing all cars") {
				human.removeAllOwnedVehicles();
				REQUIRE(human.getOwnedVehNum() == 0);
                REQUIRE(human.doIPossessVehicles()== false);
			}

			for (short n = 0; n < testCars.size(); ++n) {
				delete testCars[n];
			}
            testCars.clear();

        }
    }

}