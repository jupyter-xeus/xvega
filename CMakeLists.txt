# Copyright (c) 2020, QuantStack and XVega Contributors
#
# Distributed under the terms of the BSD 3-Clause License.
#
# The full license is in the file LICENSE, distributed with this software.

cmake_minimum_required(VERSION 3.1)
project(xvega)

set(XVEGA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

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
    ${XVEGA_INCLUDE_DIR}/xvega/base/xvega-basic.hpp
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
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/text.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/grammar/encodings/encoding-channels/position-channels/tooltip.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/utils/custom_datatypes.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/utils/xeither.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/utils/serialize.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/functions/populate_data.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/functions/populate_marks.hpp
    ${XVEGA_INCLUDE_DIR}/xvega/functions/populate_encodings.hpp
)

add_library(xvega INTERFACE)
target_include_directories(xvega INTERFACE $<BUILD_INTERFACE:${XVEGA_INCLUDE_DIR}>
                                               $<INSTALL_INTERFACE:include>)
target_link_libraries(xvega INTERFACE xtl)
target_link_libraries(xvega INTERFACE xproperty)
target_link_libraries(xvega INTERFACE nlohmann_json)

# Installation
# ============

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

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

