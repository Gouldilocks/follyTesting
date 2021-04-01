#include <iostream>
#include <folly/FBVector.h>
#include <vector>
#include "rudimentaryVector.h"
#include <chrono>
#include <list>
#include <fstream>
using namespace std::chrono;
int main () {
	// order: rudimentary, fb, then std
	std::list<float> times;
	float seconds;

	// initialize each of the vectors
	bad::rudimentaryVector<int> rudInts;
	folly::fbvector<int> fbInts;
	std::vector<int> stdInts;

	// declare timing variables here so as to not change results
	auto start = high_resolution_clock::now();
	auto end = high_resolution_clock::now();
	auto microsecs = duration_cast<microseconds>(end - start);
	/*
	 * Testing timing of adding a single int
	 */
	// add one element to rudimentary vector
	start = high_resolution_clock::now();
	rudInts.push_back(1);
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// add one element to fb vector
	start = high_resolution_clock::now();
	fbInts.push_back(1);
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// add one element to std vector
	start = high_resolution_clock::now();
	stdInts.push_back(1);
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// clear each of the vectors
	rudInts.clear();
	fbInts.clear();
	stdInts.clear();
	/*
	 * Testing timing of adding 100 ints
	 */

	// time rudimentary vector
	// add one element to rudimentary vector
	start = high_resolution_clock::now();
	for(int i = 0; i < 100; ++i){
		rudInts.push_back(i);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// add one element to fb vector
	start = high_resolution_clock::now();
	for(int i = 0; i < 100; ++i){
		fbInts.push_back(i);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// add one element to std vector
	start = high_resolution_clock::now();
	for(int i = 0; i < 100; ++i){
		stdInts.push_back(i);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// clear each of the vectors
	rudInts.clear();
	fbInts.clear();
	stdInts.clear();
	/*
	 * Testing timing of adding 1,000,000 ints
	 */
	// add one element to rudimentary vector
	start = high_resolution_clock::now();
	for(int i = 0; i < 1000000; ++i){
		rudInts.push_back(i);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// add one element to fb vector
	start = high_resolution_clock::now();
	for(int i = 0; i < 1000000; ++i){
		fbInts.push_back(i);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// add one element to std vector
	start = high_resolution_clock::now();
	for(int i = 0; i < 1000000; ++i){
		stdInts.push_back(i);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// clear each of the vectors
	rudInts.clear();
	fbInts.clear();
	stdInts.clear();
	bad::rudimentaryVector<std::string> rudStrings;
	folly::fbvector<std::string> fbStrings;
	std::vector<std::string> stdStrings;
	/*
	 * Testing timing of adding 1 string
	 */
	// time the rudimentary vector
	start = high_resolution_clock::now();
		rudStrings.push_back(std::string("test String"));
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// time the fb vector
	start = high_resolution_clock::now();
	fbStrings.push_back(std::string("test String"));
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// time the std vector
	start = high_resolution_clock::now();
	rudStrings.push_back(std::string("test String"));
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// clear each of the vectors
	rudStrings.clear();
	fbStrings.clear();
	stdStrings.clear();
	/*
	 * Testing timing of adding 100 strings
	 */
	// read in file data for 100 strings
	std::list<std::string> hundo_words;
	std::ifstream words_100;
	words_100.open("words_one_hundred");
	std::string temp;
	while(getline(words_100,temp,' ')){
		hundo_words.push_back(temp);
	}
	words_100.close();
	// time the rudimentary vector
	start = high_resolution_clock::now();
	for(auto it = hundo_words.begin(); it != hundo_words.end(); ++it){
		rudStrings.push_back(*it);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// time the fb vector
	start = high_resolution_clock::now();
	for(auto it = hundo_words.begin(); it != hundo_words.end(); ++it){
		fbStrings.push_back(*it);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// time the std vector
	start = high_resolution_clock::now();
	for(auto it = hundo_words.begin(); it != hundo_words.end(); ++it){
		stdStrings.push_back(*it);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// clear each of the vectors
	rudStrings.clear();
	fbStrings.clear();
	stdStrings.clear();

	/*
	 * Testing timing of adding a large text file ( the entirety of frankenstien )
	 */
	std::list<std::string> long_file;
	// pull data from text file
	std::ifstream words_longg;
	words_longg.open("words_long");
	while(getline(words_longg,temp,' ')){
		long_file.push_back(temp);
	}
	words_longg.close();

	// time the rudimentary vector
	start = high_resolution_clock::now();
	for(auto it = long_file.begin(); it != long_file.end(); ++it){
		rudStrings.push_back(*it);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// time the fb vector
	start = high_resolution_clock::now();
	for(auto it = long_file.begin(); it != long_file.end(); ++it){
		fbStrings.push_back(*it);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// time the std vector
	start = high_resolution_clock::now();
	for(auto it = long_file.begin(); it != long_file.end(); ++it){
		stdStrings.push_back(*it);
	}
	end = high_resolution_clock::now();
	microsecs = duration_cast<microseconds>(end - start);
	seconds =((float)microsecs.count())/ 1000000;
	times.push_back(seconds);

	// clear each of the vectors
	rudStrings.clear();
	fbStrings.clear();
	stdStrings.clear();

	/*
	 * Print out results to the output file
	 */
	std::ofstream output;
	output.open("outputOfast.txt");
	output << "rudimentaryVectorTime,fbVectorTime,stdVectorTime" << std::endl;
	output << "adding 1 int" << std::endl;
	auto it = times.begin();
	output << *it++ << "," << *it++ << "," << *it++ << std:: endl;
	output << "adding 100 ints" << std::endl;
	output << *it++ << "," << *it++ << "," << *it++ << std:: endl;
	output << "adding 1,000,000 ints" << std::endl;
	output << *it++ << "," << *it++ << "," << *it++ << std:: endl;
	output << "adding 1 string" << std:: endl;
	output << *it++ << "," << *it++ << "," << *it++ << std:: endl;
	output << "adding 100 strings" << std::endl;
	output << *it++ << "," << *it++ << "," << *it++ << std:: endl;
	output << "adding long text file" << std::endl;
	output << *it++ << "," << *it++ << "," << *it++ << std:: endl;
	output.close();
	return 0;
}
