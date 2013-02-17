#include "Granulator.h"

Granulator::Granulator(Parameters* parameters, const int internal_block_size)
    : outbuf_left (0)
    , outbuf_right (0)
{
    this->parameters = parameters;
    this->internal_block_size = internal_block_size;
    delay_line = new DelayLine(kBufferSeconds, internal_block_size);
    grain_param_generator = new GrainParametersGenerator(parameters, delay_line,
            this, internal_block_size);
    initialized = false;
}

Granulator::~Granulator()
{
    if (initialized)
        deleteGrains();
    delete delay_line;
    delete grain_param_generator;
}

void Granulator::prepareToPlay(float samplerate)
{
    this->samplerate = samplerate;
    parameters->setSampleRate(samplerate);
    delay_line->initialize(samplerate);

    outbuf_left = new float[internal_block_size];
    outbuf_right = new float[internal_block_size];
    for (int i = 0; i < internal_block_size; i++)
        outbuf_left[i] = outbuf_right[i] = 10E-12f;

    if (initialized)
        deleteGrains();

    for (int i = 0; i < kMaxGrains; i++)
        graincloud[i] = new Grain(samplerate,
                                  static_cast<int>(samplerate * kBufferSeconds),
                                  internal_block_size,
                                  delay_line->getDelayPointer(),
                                  outbuf_left,
                                  outbuf_right);
    initialized = true;
    active_grains = 0;
}

void Granulator::releaseResources()
{
    delete[] outbuf_left;
    delete[] outbuf_right;
    active_grains = 0;
}

void Granulator::setActiveGrains()
{
    if (!initialized)
        return;

    if (parameters->selected_grains > active_grains) {
        for (int i = active_grains; i < parameters->selected_grains; i++) {
            graincloud[i]->activate();
            active_grains++;
        }
    } else if (parameters->selected_grains < active_grains) {
        for (int i = active_grains; i > parameters->selected_grains; i--) {
            graincloud[i-1]->deactivate();
            active_grains--;
        }
    }
}

void Granulator::processInternalBlock(float* chan1, float* chan2, int sampleframes)
{
    if (active_grains != parameters->selected_grains)
        setActiveGrains();

    delay_line->writeDelayBuffer(chan1, chan2, sampleframes, parameters->freeze,
                                 parameters->param[kIngain],
                                 parameters->param[kFeedback]);
    processGrains(sampleframes);
    hardClip(outbuf_left, sampleframes);
    hardClip(outbuf_right, sampleframes);
    delay_line->writeFeedbackBuffer(outbuf_left, outbuf_right, sampleframes);
    writeOutput(chan1, chan2, outbuf_left, outbuf_right, sampleframes);
    clearOutbufs(outbuf_left, outbuf_right, sampleframes);
    chan1 += sampleframes;
    chan2 += sampleframes;
}

void Granulator::clearOutbufs(float* outbuf_left, float* outbuf_right,
                              int sampleframes)
{
    for (int i = 0; i < sampleframes; i++)
        outbuf_left[i] = outbuf_right[i] = 10E-12f;
}

void Granulator::writeOutput(float* chan1, float* chan2, float* outbuf_left,
                             float* outbuf_right, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        chan1[i] = (parameters->param[kMix] * outbuf_left[i])
                   + (parameters->dry_mix * chan1[i]);
        chan2[i] = (parameters->param[kMix] * outbuf_right[i])
                   + (parameters->dry_mix * chan2[i]);
    }
}

void Granulator::processGrains(int sampleframes)
{
    for (int i = 0; i < kMaxGrains; i++) {
        if (graincloud[i]->activated) {
            if (graincloud[i]->initialized == false) {
                graincloud[i]->initialize(grain_param_generator->getNewGrainParameters());
            }
            graincloud[i]->process(sampleframes);
            if (graincloud[i]->initialized == false) {
                graincloud[i]->initialize(grain_param_generator->getNewGrainParameters());
                graincloud[i]->process(sampleframes);
            }
        }
    }
}

void Granulator::hardClip(float* input, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        if (input[i] > 1.0f) {
            input[i] = 1.0f;
        } else if (input[i] < -1.0f) {
            input[i] = -1.0f;
        }
    }
}

void Granulator::deleteGrains()
{
    for (int i = 0; i < kMaxGrains; i++)
        delete graincloud[i];
}

