#ifndef PITCHQUANTIZER_H
#define PITCHQUANTIZER_H

#include "../JuceLibraryCode/JuceHeader.h"
#include <math.h>
#include <vector>
#include "Misc.h"

using namespace std;

class PitchQuantizer
{
public:
    PitchQuantizer();
    ~PitchQuantizer();
    float getQuantizedPitch(int scale, int scaleKey, float trans);
    float getQuantizedFreq(int scaleIndex, int shift, float freq);
    vector<String> getNames();

private:
    void addScale(String name, int n1, int n2, int n3, int n4, int n5,
                  int n6, int n7, int n8, int n9, int n10, int n11, int n12);
    int findNearest(float* distances, int length);
    void make49NotesArray(int scaleIndex, int shift);
    void make120NotesArray(int scaleIndex, int shift);

    vector<String>* namesVector;
    vector< vector<int> >* notesVector;
    int* notes_49;
    int* notes_120;
};

#endif //PITCHQUANTIZER_H

/*
chromatic			    0 1 2 3 4 5 6 7 8 9 10 11
major				      0 2 4 5 7 9 11
natural minor		  0 2 3 5 7 8 10
harmonic minor		0 2 3 5 7 8 11
major pentatonic 	0 2 4 7 9
minor pentatonic 	0 3 5 7 10
blues major			  0 2 4 7 9
blues minor			  0 3 5 8 10
whole tone			  0 2 4 6 8 10
octatonic 			  0 2 3 5 6 8 9 11
maj 7             0 4 7 11
dom 7             0 4 7 10
min 7             0 3 7 10
aug maj 7         0 4 8 11
aug 7             0 4 8 10
dim 7             0 3 6 9
dom 7 dim 5       0 4 6 10
maj	triad         0 4 7
min	triad         0 3 7
aug	triad         0 4 8
dim triad         0 3 6
5th               0 6
Dim 5th           0 5
Aug 5th           0 8
*/
