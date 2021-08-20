// This file is part of the AliceVision project.
// Copyright (c) 2016 AliceVision contributors.
// This Source Code Form is subject to the terms of the Mozilla Public License,
// v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <aliceVision/numeric/numeric.hpp>

#define ALICEVISION_VERSION_MAJOR 2
#define ALICEVISION_VERSION_MINOR 4
#define ALICEVISION_VERSION_REVISION 0

// Preprocessor to string conversion
#define ALICEVISION_TO_STRING_HELPER(x) #x
#define ALICEVISION_TO_STRING(x) ALICEVISION_TO_STRING_HELPER(x)

// AliceVision version as a string; for example "0.9.0".
#define ALICEVISION_VERSION_STRING ALICEVISION_TO_STRING(ALICEVISION_VERSION_MAJOR) "." \
                             ALICEVISION_TO_STRING(ALICEVISION_VERSION_MINOR) "." \
                             ALICEVISION_TO_STRING(ALICEVISION_VERSION_REVISION)

namespace aliceVision {

class Version
{
public:
    Version()
        : _v(Vec3i::Zero())
    {}

    explicit Version(const Vec3i & v)
        : _v(v)
    {
    }

    Version(int major, int minor, int micro)
        : _v(major, minor, micro)
    {
    }

    Version& operator=(const Vec3i& other)
    {
        _v = other;
        return *this;
    }

    bool operator<(const Version& other) const
    {
        for (Vec3i::Index i = 0; i < 3; i++)
        {
            if (_v[i] < other._v[i])
                return true;
            if (_v[i] > other._v[i])
                return false;
        }
        return false; // equal
    }
    bool operator<=(const Version& other) const { return !operator>(other); }
    bool operator>(const Version& other) const
    {
        for(Vec3i::Index i = 0; i < 3; i++)
        {
            if(_v[i] > other._v[i])
                return true;
            if(_v[i] < other._v[i])
                return false;
        }
        return false; // equal
    }
    bool operator>=(const Version& other) const { return !operator<(other); }

private:
    Vec3i _v;
};

}