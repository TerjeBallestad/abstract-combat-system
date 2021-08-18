all: main

main:
	g++ -g -std=c++20 ACS.cpp Character.cpp Talent.cpp TalentGrid.cpp -o game