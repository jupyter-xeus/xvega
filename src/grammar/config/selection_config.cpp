// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include "xvega/grammar/config/selection_config.hpp"
#include "../../utils/serialize.hpp"

namespace xv
{
    void to_json(nl::json& j, const interval_selection_config& data)
    {
        serialize(j, data.bind(), "bind");
        serialize(j, data.clear(), "clear");
        serialize(j, data.empty(), "empty");
        serialize(j, data.encodings(), "encodings");
        serialize(j, data.fields(), "fields");
        serialize(j, data.init(), "init");
        serialize(j, data.mark(), "mark");
        serialize(j, data.on(), "on");
        serialize(j, data.resolve(), "resolve");
        serialize(j, data.translate(), "translate");
        serialize(j, data.zoom(), "zoom");
    }

    void to_json(nl::json& j, const multi_selection_config& data)
    {
        serialize(j, data.bind(), "bind");
        serialize(j, data.clear(), "clear");
        serialize(j, data.empty(), "empty");
        serialize(j, data.encodings(), "encodings");
        serialize(j, data.fields(), "fields");
        serialize(j, data.init(), "init");
        serialize(j, data.nearest(), "nearest");
        serialize(j, data.on(), "on");
        serialize(j, data.resolve(), "resolve");
        serialize(j, data.toggle(), "toggle");
    }

    void to_json(nl::json& j, const single_selection_config& data)
    {
        serialize(j, data.bind(), "bind");
        serialize(j, data.clear(), "clear");
        serialize(j, data.empty(), "empty");
        serialize(j, data.encodings(), "encodings");
        serialize(j, data.fields(), "fields");
        serialize(j, data.init(), "init");
        serialize(j, data.nearest(), "nearest");
        serialize(j, data.on(), "on");
        serialize(j, data.resolve(), "resolve");
    }

    void to_json(nl::json& j, const selection_config& data)
    {
        serialize(j, data.interval(), "interval");
        serialize(j, data.multi(), "multi");
        serialize(j, data.single(), "single");
    }
}