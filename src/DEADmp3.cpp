
#include "DEADmp3.h"

bool LoadMP3File(const char* filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
{
     // openfile
    SF_INFO sfinfo;
    SNDFILE* sndfile = sf_open(filename, SFM_READ, &sfinfo);
    if (!sndfile) {
        return false; 
    }

    // gei file format
    switch (sfinfo.channels) {
        case 1:
            format = AL_FORMAT_MONO16;
            break;
        case 2:
            format = AL_FORMAT_STEREO16;
            break;
        default:
            sf_close(sndfile);
            return false; 
    }
    freq = sfinfo.samplerate;

    // read file data
    std::vector<short> samples(sfinfo.frames * sfinfo.channels);
    sf_count_t num_frames = sf_readf_short(sndfile, samples.data(), sfinfo.frames);
    if (num_frames < 1) {
        sf_close(sndfile);
        return false; 
    }

    // close file
    sf_close(sndfile);

    // copy file data to buffer
    buffer.resize(samples.size() * sizeof(short));
    memcpy(buffer.data(), samples.data(), buffer.size());

    return true; 
}