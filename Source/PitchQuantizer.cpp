#include "PitchQuantizer.h"


PitchQuantizer::PitchQuantizer()
{
    notes_49 = new int[49];
    notes_120 = new int[120];
    namesVector = new vector<String>;
    notesVector = new vector< vector<int> >;

    addScale("chromatic",               1,1,1,1,1,1,1,1,1,1,1,1);
    addScale("major",                   1,0,1,0,1,1,0,1,0,1,0,1);
    addScale("natural minor",           1,0,1,1,0,1,0,1,1,0,1,0);
    addScale("harmonic minor",          1,0,1,1,0,1,0,1,1,0,0,1);
    addScale("major pentatonic",        1,0,1,0,1,0,0,1,0,1,0,0);
    addScale("minor pentatonic",        1,0,0,1,0,1,0,1,0,0,1,0);
    addScale("blues major",             1,0,1,0,1,0,0,1,0,1,0,1);
    addScale("blues minor",             1,0,0,1,0,1,0,0,1,0,1,0);
    addScale("whole tone",              1,0,1,0,1,0,1,0,1,0,1,0);
    addScale("octatonic",               1,0,1,1,0,1,1,0,1,1,0,1);
    addScale("maj 7",                   1,0,0,0,1,0,0,1,0,0,0,1);
    addScale("dom 7",                   1,0,0,0,1,0,0,1,0,0,1,0);
    addScale("min 7",                   1,0,0,1,0,0,0,1,0,0,1,0);
    addScale("aug maj 7",               1,0,0,0,1,0,0,0,1,0,0,1);
    addScale("aug 7",                   1,0,0,0,1,0,0,0,1,0,1,0);
    addScale("dim 7",                   1,0,0,1,0,0,1,0,0,1,0,0);
    addScale("dom 7 dim 5",             1,0,0,0,1,0,1,0,0,0,1,0);
    addScale("maj triad",               1,0,0,0,1,0,0,1,0,0,0,0);
    addScale("min triad",               1,0,0,1,0,0,0,1,0,0,0,0);
    addScale("aug triad",               1,0,0,0,1,0,0,0,1,0,0,0);
    addScale("dim triad",               1,0,0,1,0,0,1,0,0,0,0,0);
    addScale("5th",                     1,0,0,0,0,0,0,1,0,0,0,0);
    addScale("dim 5th",                 1,0,0,0,0,0,1,0,0,0,0,0);
    addScale("aug 5th",                 1,0,0,0,0,0,0,0,1,0,0,0);
}

PitchQuantizer::~PitchQuantizer()
{
    delete[] notes_49;
    delete[] notes_120;
    delete namesVector;
    delete notesVector;
}

void PitchQuantizer::addScale(String name, int n1, int n2, int n3, int n4,
                              int n5, int n6, int n7,int n8, int n9, int n10,
                              int n11, int n12)
{
    int note_ints[] = {n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12};
    vector<int> notes(note_ints, note_ints + sizeof(note_ints) / sizeof(int));
    notesVector->push_back(notes);
    namesVector->push_back(name);
}

vector<String> PitchQuantizer::getNames()
{
    return *namesVector;
}

float PitchQuantizer::getQuantizedPitch(int scaleIndex, int shift, float trans_value)
{
    make49NotesArray(scaleIndex, shift);
    float semitones = trans_value * 48.0f;
    float distances[49];
    int nearestIndex;

    // array of distances to each note
    for (int i = 0; i < 49; i++) {
        if (notes_49[i] == 1) {
            distances[i] = fabs(semitones - i);
        } else {
            distances[i] = 10E10f;
        }
    }
    nearestIndex = findNearest(distances, 49);
    trans_value = nearestIndex / 48.0f;
    return pow(2.0f, ((trans_value - 0.5f) * 4.0f));
}

float PitchQuantizer::getQuantizedFreq(int scaleIndex, int shift, float freq)
{
    make120NotesArray(scaleIndex, shift);
    double hzArray[120];
    double semitoneRatio = pow(2.0, 1.0/12.0);
    float distances[120];
    int nearestIndex;

    // array of 120 note frequencies
    hzArray[0] = 55.0;
    for (int i = 1; i < 120; i++) {
        hzArray[i] = hzArray[i - 1] * semitoneRatio;
    }

    // array of distances to each frequency
    for (int i = 0; i < 120; i++) {
        if (notes_120[i] == 1) {
            distances[i] = (float)fabs(freq - hzArray[i]);
        } else {
            distances[i] = 0.0f;
        }
    }
    nearestIndex = findNearest(distances, 120);
    return (float)hzArray[nearestIndex];
}

void PitchQuantizer::make49NotesArray(int scaleIndex, int shift)
{
    int shiftedScale[12];
    vector<int> scale = notesVector->at(scaleIndex);

    for(int i = 0; i < 12; i++) {
        shiftedScale[i] = scale[shift];
        shift++;
        if (shift == 12)
            shift = 0;
    }

    for (int i = 0; i < 12; i++) {
        notes_49[i] = shiftedScale[i];
        notes_49[i + 12] = shiftedScale[i];
        notes_49[i + 24] = shiftedScale[i];
        notes_49[i + 36] = shiftedScale[i];
    }
    notes_49[48] = shiftedScale[0];
}

void PitchQuantizer::make120NotesArray(int scaleIndex, int shift)
{
    int shiftedScale[12];
    vector<int> scale = notesVector->at(scaleIndex);

    for(int i = 0; i < 12; i++) {
        shiftedScale[i] = scale[shift];
        shift++;
        if (shift == 12)
            shift = 0;
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 10; j++) {
            notes_120[i + j * 12] = shiftedScale[i];
        }
    }
}

int PitchQuantizer::findNearest(float* distances, int length)
{
    float nearestValue = 10E10f;
    int nearestIndex = 0;

    for (int i = 0; i < length; i++) {
        if (distances[i] < nearestValue) {
            nearestValue = distances[i];
            nearestIndex = i;
        }
    }
    return nearestIndex;
}

