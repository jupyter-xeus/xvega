# Copyright (c) 2020, QuantStack and XVega Contributors
#
# Distributed under the terms of the BSD 3-Clause License.
#
# The full license is in the file LICENSE, distributed with this software.

cmake_minimum_required(VERSION 3.1)
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

# Dependencies
# ============

set(xtl_REQUIRED_VERSION 0.6.11)
find_package(xtl ${xtl_REQUIRED_VERSION} REQUIRED)
message(STATUS "Found xtl: ${xtl_INCLUDE_DIRS}/xtl")

set(xproperty_REQUIRED_VERSION 0.10.1)
find_package(xproperty ${xproperty_REQUIRED_VERSION} REQUIRED)
message(STATUS "Found xproperty: ${xproperty_INCLUDE_DIRS}/xproperty")

set(nlohmann_json_REQUIRED_VERSION 3.7.3)
find_package(nlohmann_json ${nlohmann_json_REQUIRED_VERSION} REQUIRED)
message(STATUS "Found nlohmann_json: ${nlohmann_json_INCLUDE_DIRS}/nlohmann_json")

# Build
# =====

set(XVEGA_HEADERS
    ${XVEGA_INCLUDE_DIR}/xvega/xvega.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/xvega_config.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/xvega_config_cling.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/base/xvega-base.hpp
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
    ${XVEGA_INCLUDE_DIR}/xvega/utils/custom_datatypes.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/utils/xeither.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/utils/serialize.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/utils/random_string.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/functions/populate_data.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/functions/populate_marks.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/functions/populate_encodings.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/functions/populate_selections.hpp
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
)

set(XVEGA_SOURCES
    ${XVEGA_SOURCE_DIR}/base/xvega-base.cpp
    ${XVEGA_SOURCE_DIR}/functions/populate_data.cpp
    ${XVEGA_SOURCE_DIR}/functions/populate_encodings.cpp
    ${XVEGA_SOURCE_DIR}/functions/populate_marks.cpp
    ${XVEGA_SOURCE_DIR}/functions/populate_selections.cpp
    ${XVEGA_SOURCE_DIR}/utils/custom_datatypes.cpp
    ${XVEGA_SOURCE_DIR}/utils/random_string.cpp
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
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/json_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/csv_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/tsv_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/dsv_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_format/topo_data_format.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_source/named_data.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_source/url_data.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/data_source/inline_data.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/generator/sequence_generator.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/generator/sphere_generator.cpp
    ${XVEGA_SOURCE_DIR}/grammar/data/generator/graticule_generator.cpp
)

add_library(xvega SHARED ${XVEGA_SOURCES} ${XVEGA_HEADERS})
target_include_directories(xvega PUBLIC $<BUILD_INTERFACE:${XVEGA_INCLUDE_DIR}>
                                               $<INSTALL_INTERFACE:include>)
target_link_libraries(xvega PUBLIC xtl)
target_link_libraries(xvega PUBLIC xproperty)
# target_link_libraries(xvega PUBLIC nlohmann_json)

# set_target_properties(xvega PROPERTIES
#                       LINKER_LANGUAGE CXX
#                       PUBLIC_HEADER DESTINATION "${XVEGA_HEADERS}"
#                       COMPILE_DEFINITIONS "XVEGA_EXPORTS"
#                       PREFIX ""
#                       VERSION ${${PROJECT_NAME}_VERSION}
#                       SOVERSION ${${PROJECT_NAME}_VERSION}
#                       OUTPUT_NAME "libxvega")

# Installation
# ============

install(TARGETS xvega
        EXPORT ${PROJECT_NAME}-targets)

# Makes the project importable from the build directory
export(EXPORT ${PROJECT_NAME}-targets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")

install(DIRECTORY ${XVEGA_INCLUDE_DIR}/xvega
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(XVEGA_CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}" CACHE STRING "install path for xvegaConfig.cmake")

configure_package_config_file(${PROJECT_NAME}Config.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
                              INSTALL_DESTINATION ${XVEGA_CMAKECONFIG_INSTALL_DIR})

# xvega is header-only and does not depend on the architecture.
# Remove CMAKE_SIZEOF_VOID_P from xvegaConfigVersion.cmake so that an xvegaConfig.cmake
# generated for a 64 bit target can be used for 32 bit targets and vice versa.
set(_XVEGA_CMAKE_SIZEOF_VOID_P ${CMAKE_SIZEOF_VOID_P})
unset(CMAKE_SIZEOF_VOID_P)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
                                 VERSION ${${PROJECT_NAME}_VERSION}
                                 COMPATIBILITY AnyNewerVersion)
set(CMAKE_SIZEOF_VOID_P ${_XVEGA_CMAKE_SIZEOF_VOID_P})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${XVEGA_CMAKECONFIG_INSTALL_DIR})
install(EXPORT ${PROJECT_NAME}-targets
        FILE ${PROJECT_NAME}Targets.cmake
        DESTINATION ${XVEGA_CMAKECONFIG_INSTALL_DIR})

