// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mx/api/EncodingData.h"
#include "mx/core/Date.h"

namespace mx
{
    namespace api
    {

////////////////////////////////////////////////////////////////////////////////
// CTOR AND COPY ///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

        EncodingDate EncodingDate::today()
        {
            const auto d = mx::core::Date::today();
            mx::api::EncodingDate result{};
            result.year = d.getYear();
            result.month = d.getMonth();
            result.day = d.getDay();
            return result;
        }

////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    }
}
