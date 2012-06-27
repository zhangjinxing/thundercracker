/* -*- mode: C; c-basic-offset: 4; intent-tabs-mode: nil -*-
 *
 * STIR -- Sifteo Tiled Image Reducer
 * M. Elizabeth Scott <beth@sifteo.com>
 *
 * Copyright <c> 2011 Sifteo, Inc. All rights reserved.
 */

#ifndef _ENCODER_H
#define _ENCODER_H

#include <stdio.h>
#include <vector>
#include <string>
#include "sifteo/abi.h"

class AudioEncoder {
public:
    virtual ~AudioEncoder() {}
    virtual void encodeFile(const std::string &path, std::vector<uint8_t> &out) = 0;
    virtual uint32_t encodeBuffer(void *buf, uint32_t bufsize) = 0;

    virtual const char *getTypeSymbol() = 0;
    virtual const char *getName() = 0;
    virtual const _SYSAudioType getType() = 0;
    
    static AudioEncoder *create(std::string name);
};


class PCMEncoder : public AudioEncoder {
public:
    virtual void encodeFile(const std::string &path, std::vector<uint8_t> &out);
    virtual uint32_t encodeBuffer(void *buf, uint32_t bufsize);

    virtual const char *getTypeSymbol() {
        return "_SYS_PCM";
    }

    virtual const _SYSAudioType getType() {
        return _SYS_PCM;
    }

    virtual const char *getName() {
        return "Uncompressed PCM";
    }
};

class ADPCMEncoder : public AudioEncoder {
public:
    ADPCMEncoder() :
        index(0),
        predsample(0)
    {}
    virtual void encodeFile(const std::string &path, std::vector<uint8_t> &out);
    virtual uint32_t encodeBuffer(void *buf, uint32_t bufsize);

    virtual const char *getTypeSymbol() {
        return "_SYS_ADPCM";
    }

    virtual const _SYSAudioType getType() {
        return _SYS_ADPCM;
    }

    virtual const char *getName() {
        return "ADPCM";
    }

private:
    unsigned index;
    int predsample;

    unsigned encodeSample(int sample);
};

#endif
