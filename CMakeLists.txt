# Copyright (c) 2020, QuantStack and XVega Contributors
#
# Distributed under the terms of the BSD 3-Clause License.
#
# The full license is in the file LICENSE, distributed with this software.

cmake_minimum_required(VERSION 3.8)
project(xvega)

set(XVEGA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(XVEGA_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Configuration
# ===========
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(XVEGA_INSTALL_LIBRARY_DIR "\"${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}\"")

configure_file (
    "${XVEGA_INCLUDE_DIR}/xvega/xvega_config_cling.hpp.in"
    "${XVEGA_INCLUDE_DIR}/xvega/xvega_config_cling.hpp"
)

# Versionning
# ===========

file(STRINGS "${XVEGA_INCLUDE_DIR}/xvega/xvega_config.hpp" xvega_version_defines
     REGEX "#define XVEGA_VERSION_(MAJOR|MINOR|PATCH)")
foreach(ver ${xvega_version_defines})
    if(ver MATCHES "#define XVEGA_VERSION_(MAJOR|MINOR|PATCH) +([^ ]+)$")
        set(XVEGA_VERSION_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" CACHE INTERNAL "")
    endif()
endforeach()
set(${PROJECT_NAME}_VERSION
    ${XVEGA_VERSION_MAJOR}.${XVEGA_VERSION_MINOR}.${XVEGA_VERSION_PATCH})
message(STATUS "xvega v${${PROJECT_NAME}_VERSION}")

# Build options
# =============

OPTION(XVEGA_DISABLE_OPT_NATIVE "disable -march=native / -mtune=native flag" OFF)
OPTION(XVEGA_DISABLE_TUNE_GENERIC "disable -mtune=generic flag" OFF)

OPTION(XVEGA_BUILD_STATIC "Build xvega static library" ON)
OPTION(XVEGA_BUILD_SHARED "Split xvega build into executable and library" ON)

OPTION(XVEGA_BUILD_TESTS "xvega test suite" OFF)

# Dependencies
# ============

set(xproperty_REQUIRED_VERSION 0.12.0)
find_package(xproperty ${xproperty_REQUIRED_VERSION} REQUIRED)
message(STATUS "Found xproperty: ${xproperty_INCLUDE_DIRS}/xproperty")

set(nlohmann_json_REQUIRED_VERSION 3.11.3)
find_package(nlohmann_json ${nlohmann_json_REQUIRED_VERSION} REQUIRED)
message(STATUS "Found nlohmann_json: ${nlohmann_json_INCLUDE_DIRS}/nlohmann_json")

# Target and link
# ===============

# xvega source directory
set(XVEGA_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(XVEGA_HEADERS
    ${XVEGA_INCLUDE_DIR}/xvega/xvega.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/xvega_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/xvega_config_cling.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/chart.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/title.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_arc.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_area.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_bar.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_circle.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_geoshape.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_image.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_line.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_point.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_rect.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_rule.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_square.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_text.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_tick.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/marks/mark_trail.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/selection_single.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/selection_multi.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/selection_mark.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/selection_interval.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/bindings/bind_checkbox.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/bindings/bind_input.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/bindings/bind_radio_select.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/bindings/bind_range.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/bindings/legend_stream_binding.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/streams/event_stream.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/streams/derived_stream.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/selections/streams/merged_stream.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/aggregate.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/axis.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/bin.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/condition.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/datetime.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/datum.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/field.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/header.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/impute.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/legend.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/repeatRef.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/scale.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/sort.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/stack.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/timeunit.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channel-options/value.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/detail-channel/detail.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/facet-channels/column.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/facet-channels/facet.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/facet-channels/row.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/hyperlink-channels/href.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/color.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/fill.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/fillOpacity.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/opacity.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/shape.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/size.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/stroke.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/strokeDash.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/strokeOpacity.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/mark-property-channels/strokeWidth.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/order-channel/order.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/latitude.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/longitude.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/latitude2.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/longitude2.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/x.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/y.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/x2.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/y2.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/xerror.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/xerror2.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/yerror.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/yerror2.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/text-tooltip-channels/key.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/text-tooltip-channels/text.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/text-tooltip-channels/tooltip.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/view_compositions.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/data_format.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/data_format/json_data_format.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/data_format/csv_data_format.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/data_format/tsv_data_format.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/data_format/dsv_data_format.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/data_format/topo_data_format.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/data_source/named_data.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/data_source/url_data.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/data_source/inline_data.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/generator/sequence_generator.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/generator/sphere_generator.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/data/generator/graticule_generator.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_aggregate.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_bin.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_calculate.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_density.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_flatten.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_fold.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_impute.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_join_aggregate.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_loess.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_lookup.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_pivot.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_quantile.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_regression.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_sample.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_stack.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_timeunit.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/transformations/transform_window.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/area_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/auto_size_params.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/axis_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/bar_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/base_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/box_plot_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/composition_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/error_band_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/error_bar_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/header_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/legend_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/line_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/mark_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/overlay_mark_def.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/projection_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/range_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/rect_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/scale_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/selection_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/style_config_index.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/tick_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/title_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/config/view_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/utils/custom_datatypes.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/utils/random_string.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/utils/xany.hpp
)

set(XVEGA_SOURCES
    ${XVEGA_SOURCE_DIR}/utils/serialize.hpp  # private header
    ${XVEGA_SOURCE_DIR}/grammar/chart.cpp
    ${XVEGA_SOURCE_DIR}/grammar/title.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/aggregate.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/axis.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/bin.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/condition.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/datetime.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/header.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/impute.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/legend.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/repeatRef.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/scale.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/sort.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/timeunit.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channel-options/value.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/detail-channel/detail.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/facet-channels/column.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/facet-channels/facet.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/facet-channels/row.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/hyperlink-channels/href.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/color.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/fill.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/fillOpacity.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/opacity.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/shape.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/size.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/stroke.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/strokeDash.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/strokeOpacity.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/mark-property-channels/strokeWidth.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/order-channel/order.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/latitude.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/longitude.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/latitude2.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/longitude2.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/x.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/y.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/x2.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/y2.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/xerror.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/xerror2.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/yerror.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/position-channels/yerror2.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/text-tooltip-channels/key.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/text-tooltip-channels/text.cpp
    ${XVEGA_SOURCE_DIR}/grammar/encodings/encoding-channels/text-tooltip-channels/tooltip.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_arc.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_area.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_bar.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_circle.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_geoshape.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_image.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_line.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_point.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_rect.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_rule.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_square.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_text.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_tick.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks/mark_trail.cpp
    ${XVEGA_SOURCE_DIR}/grammar/marks_private.hpp  # private header
    ${XVEGA_SOURCE_DIR}/grammar/selections/bindings/bind_checkbox.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/bindings/bind_input.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/bindings/bind_radio_select.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/bindings/bind_range.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/bindings/legend_stream_binding.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/streams/derived_stream.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/streams/event_stream.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/streams/merged_stream.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/selection_mark.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/selection_single.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/selection_multi.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections/selection_interval.cpp
    ${XVEGA_SOURCE_DIR}/grammar/selections_private.hpp  # private header
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/json_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/csv_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/tsv_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/dsv_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/topo_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format_private.hpp  # private header
    ${XVEGA_SOURCE_DIR}/grammar/data/data_source/named_data.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_source/url_data.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_source/inline_data.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/generator/sequence_generator.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/generator/sphere_generator.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/generator/graticule_generator.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_aggregate.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_bin.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_calculate.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_density.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_flatten.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_fold.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_impute.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_join_aggregate.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_loess.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_lookup.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_pivot.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_quantile.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_regression.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_sample.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_stack.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_timeunit.cpp
    ${XVEGA_SOURCE_DIR}/grammar/transformations/transform_window.cpp
    ${XVEGA_SOURCE_DIR}/grammar/view_compositions.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/area_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/auto_size_params.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/axis_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/bar_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/base_config_private.hpp  # private header
    ${XVEGA_SOURCE_DIR}/grammar/config/box_plot_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/composition_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/error_band_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/error_bar_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/header_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/legend_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/line_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/mark_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/overlay_mark_def.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/projection_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/range_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/rect_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/scale_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/selection_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/style_config_index.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/tick_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/title_config.cpp
    ${XVEGA_SOURCE_DIR}/grammar/config/view_config.cpp
    ${XVEGA_SOURCE_DIR}/utils/custom_datatypes.cpp
    ${XVEGA_SOURCE_DIR}/utils/random_string.cpp
)

# Targets and link - Macros
# =========================

set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
string(TOUPPER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib; ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")

macro(xvega_set_common_options target_name)
    set_target_properties(${target_name} PROPERTIES CXX_EXTENSIONS OFF CXX_STANDARD_REQUIRED 17)

    target_compile_features(${target_name} PRIVATE cxx_std_17)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
        CMAKE_CXX_COMPILER_ID MATCHES "Intel")

        target_compile_options(${target_name} PUBLIC -Wunused-parameter -Wextra -Wreorder)
    
        # Mtune generic/native
        if (XVEGA_DISABLE_OPT_NATIVE AND NOT XVEGA_DISABLE_TUNE_GENERIC)
            target_compile_options(${target_name} PUBLIC -mtune=generic)
        elseif (XVEGA_DISABLE_TUNE_GENERIC)
            # Do not pass optflags.
        else ()
            # PowerPC does not support -march
            if (CMAKE_SYSTEM_PROCESSOR MATCHES "ppc|powerpc")
                target_compile_options(${target_name} PUBLIC -mtune=native)
            elseif (NOT EMSCRIPTEN)
                target_compile_options(${target_name} PUBLIC -march=native)
            endif ()
        endif ()
    endif ()

    if (APPLE)
        set_target_properties(${target_name} PROPERTIES
            MACOSX_RPATH ON
        )
    else ()
        set_target_properties(${target_name} PROPERTIES
            BUILD_WITH_INSTALL_RPATH 1
            SKIP_BUILD_RPATH FALSE
        )
    endif ()

    set_target_properties(${target_name} PROPERTIES
        INSTALL_RPATH_USE_LINK_PATH TRUE
    )
endmacro()

# Common macro for shared and static library xvega
macro(xvega_create_target target_name linkage output_name)
    string(TOUPPER "${linkage}" linkage_upper)

    if (NOT ${linkage_upper} MATCHES "^(SHARED|STATIC)$")
        message(FATAL_ERROR "Invalid library linkage: ${linkage}")
    endif ()

    add_library(${target_name} ${linkage_upper} ${XVEGA_SOURCES} ${XVEGA_HEADERS})
    xvega_set_common_options(${target_name})

    if (MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    endif (MSVC)

    set_target_properties(${target_name} PROPERTIES
                          PUBLIC_HEADER "${XVEGA_HEADERS}"
                          # COMPILE_DEFINITIONS "XEUS_SQLITE_EXPORTS"
                          PREFIX ""
                          VERSION ${${PROJECT_NAME}_VERSION}
                          SOVERSION ${XVEGA_VERSION_MAJOR}
                          OUTPUT_NAME "lib${output_name}")

    target_compile_definitions(${target_name} PUBLIC "XVEGA_EXPORTS")

    target_include_directories(${target_name}
                               PUBLIC
                               ${XVEGA_INCLUDE_DIRS}
                               $<BUILD_INTERFACE:${XVEGA_INCLUDE_DIR}>
                               $<INSTALL_INTERFACE:include>)

    target_link_libraries(${target_name} PUBLIC xproperty)
endmacro()

# xvega
# =====

set(XVEGA_TARGETS "")

if (XVEGA_BUILD_SHARED)
    # Build libraries
    xvega_create_target(xvega SHARED xvega)
    list(APPEND XVEGA_TARGETS xvega)
endif ()

if (XVEGA_BUILD_STATIC)
    # On Windows, a static library should use a different output name
    # to avoid the conflict with the import library of a shared one.
    if (CMAKE_HOST_WIN32)
        xvega_create_target(xvega-static STATIC xvega-static)
    else ()
        xvega_create_target(xvega-static STATIC xvega)
    endif ()
    list(APPEND XVEGA_TARGETS xvega-static)
endif ()

# Tests
# =====

if(XVEGA_BUILD_TESTS)
    add_subdirectory(test)
endif()

# Installation
# ============

include(CMakePackageConfigHelpers)

set(XVEGA_CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}" CACHE STRING "install path for xvegaConfig.cmake")

# Install xvega
if (XVEGA_BUILD_SHARED OR XVEGA_BUILD_STATIC)
    install(TARGETS ${XVEGA_TARGETS}
            EXPORT ${PROJECT_NAME}-targets
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
    # This guarantees the headers' folders won't be flatten when
    # installed
    install(DIRECTORY ${XVEGA_INCLUDE_DIR}/xvega
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    # Makes the project importable from the build directory
    export(EXPORT ${PROJECT_NAME}-targets
           FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")
endif ()

# Configure 'xvegaConfig.cmake' for a build tree
set(XVEGA_CONFIG_CODE "####### Expanded from \@XVEGA_CONFIG_CODE\@ #######\n")
set(XVEGA_CONFIG_CODE "${XVEGA_CONFIG_CODE}set(CMAKE_MODULE_PATH \"${CMAKE_CURRENT_SOURCE_DIR}/cmake;\${CMAKE_MODULE_PATH}\")\n")
set(XVEGA_CONFIG_CODE "${XVEGA_CONFIG_CODE}##################################################")
configure_package_config_file(${PROJECT_NAME}Config.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
                              INSTALL_DESTINATION ${PROJECT_BINARY_DIR})
                              # INSTALL_DESTINATION ${XVEGA_CMAKECONFIG_INSTALL_DIR})

# Configure 'xvegaConfig.cmake' for an install tree
set(XVEGA_CONFIG_CODE "")
configure_package_config_file(${PROJECT_NAME}Config.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}Config.cmake"
                              INSTALL_DESTINATION ${XVEGA_CMAKECONFIG_INSTALL_DIR})

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
                                 VERSION ${${PROJECT_NAME}_VERSION}
                                 COMPATIBILITY AnyNewerVersion)

# Remove CMAKE_SIZEOF_VOID_P from xvegaConfigVersion.cmake so that an xvegaConfig.cmake
# generated for a 64 bit target can be used for 32 bit targets and vice versa.
set(CMAKE_SIZEOF_VOID_P ${_XVEGA_CMAKE_SIZEOF_VOID_P})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
              DESTINATION ${XVEGA_CMAKECONFIG_INSTALL_DIR})

if (XVEGA_BUILD_SHARED)
    install(EXPORT ${PROJECT_NAME}-targets
            FILE ${PROJECT_NAME}Targets.cmake
            DESTINATION ${XVEGA_CMAKECONFIG_INSTALL_DIR})
endif ()
