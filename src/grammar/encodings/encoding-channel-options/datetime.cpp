// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/encodings/encoding-channel-options/datetime.hpp"

namespace xv
{
    void to_json(nl::json& j, const DateTime& data)
    {
        serialize(j, data.year(), "year");
        serialize(j, data.quarter(), "quarter");
        serialize(j, data.month(), "month");
        serialize(j, data.date(), "date");
        serialize(j, data.day(), "day");
        serialize(j, data.hours(), "hours");
        serialize(j, data.minutes(), "minutes");
        serialize(j, data.seconds(), "seconds");
        serialize(j, data.milliseconds(), "milliseconds");
        serialize(j, data.utc(), "utc");
    }
}