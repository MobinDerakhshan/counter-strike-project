find_package(GTest REQUIRED)


add_executable(TimeTEST TimeTest.cpp)
target_link_libraries(TimeTEST GTest::gtest GTest::gtest_main my)

add_executable(IOTEST IOTest.cpp)
target_link_libraries(IOTEST GTest::gtest GTest::gtest_main my)

add_executable(WeaponTEST WeaponTest.cpp)
target_link_libraries(WeaponTEST GTest::gtest GTest::gtest_main my)

add_executable(AmmunitionTEST AmmunitionTest.cpp)
target_link_libraries(AmmunitionTEST GTest::gtest GTest::gtest_main my)

add_executable(PlayerTEST PlayerTest.cpp)
target_link_libraries(PlayerTEST GTest::gtest GTest::gtest_main my)

add_executable(TeamTEST TeamTest.cpp)
target_link_libraries(TeamTEST GTest::gtest GTest::gtest_main my)

add_executable(RoundTEST RoundTest.cpp)
target_link_libraries(RoundTEST GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main my)

add_executable(ListOfTeamTEST ListOfTeamTest.cpp)
target_link_libraries(ListOfTeamTEST GTest::gtest GTest::gtest_main my)

add_test(MyTest 
	TimeTEST 
	WeaponTEST
	AmmunitionTEST 
	PlayerTEST 
	TeamTEST 
	IOTEST
	ListOfTeamTEST
	RoundTEST)
