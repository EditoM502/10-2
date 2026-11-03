#ifndef INREADER_H
#define INREADER_H
#include <string>
using namespace std;

class InReader {
public:
    int readGuess(int min, int max); // Reads a guess from the input stream within the specified range
    bool YesNo(const string& prompt) const; // Reads a yes/no response from the input stream

};



#endif // INREADER_H