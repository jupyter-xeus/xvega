// Copyright (c) 2020, QuantStack and XVega Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef XVEGA_ALL_HPP
#define XVEGA_ALL_HPP

// Config
#include "xvega_config.hpp"

// All marks
#include "grammar/marks/mark_arc.hpp"	
#include "grammar/marks/mark_area.hpp"	
#include "grammar/marks/mark_bar.hpp"	
#include "grammar/marks/mark_circle.hpp"	
#include "grammar/marks/mark_geoshape.hpp"	
#include "grammar/marks/mark_image.hpp"	
#include "grammar/marks/mark_line.hpp"	
#include "grammar/marks/mark_point.hpp"	
#include "grammar/marks/mark_rect.hpp"	
#include "grammar/marks/mark_rule.hpp"	
#include "grammar/marks/mark_square.hpp"	
#include "grammar/marks/mark_text.hpp"	
#include "grammar/marks/mark_tick.hpp"	
#include "grammar/marks/mark_trail.hpp"	

// All selections
#include "grammar/selections/selection_single.hpp"	
#include "grammar/selections/selection_multi.hpp"	
#include "grammar/selections/selection_interval.hpp"

// Transformations
#include "grammar/transformations/transform_aggregate.hpp"	
#include "grammar/transformations/transform_bin.hpp"	
#include "grammar/transformations/transform_calculate.hpp"	
#include "grammar/transformations/transform_density.hpp"	
#include "grammar/transformations/transform_flatten.hpp"	
#include "grammar/transformations/transform_fold.hpp"	
#include "grammar/transformations/transform_impute.hpp"	
#include "grammar/transformations/transform_join_aggregate.hpp"	
#include "grammar/transformations/transform_loess.hpp"	
#include "grammar/transformations/transform_pivot.hpp"	
#include "grammar/transformations/transform_quantile.hpp"	
#include "grammar/transformations/transform_regression.hpp"	
#include "grammar/transformations/transform_sample.hpp"	
#include "grammar/transformations/transform_stack.hpp"	
#include "grammar/transformations/transform_timeunit.hpp"	
#include "grammar/transformations/transform_window.hpp"
#include "grammar/transformations/transform_lookup.hpp"	

// Chart
#include "grammar/chart.hpp"

// View compositions
#include "grammar/view_compositions.hpp"

#endif
