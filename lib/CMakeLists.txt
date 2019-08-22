# Copyright 2011,2012,2016 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(
    ${Boost_INCLUDE_DIR}
    ${QWT_INCLUDE_DIRS}
    ${QT_INCLUDE_DIRS}
)
link_directories(
    ${Boost_LIBRARY_DIRS}
    ${QWT_LIBRARY_DIRS}
    ${QT_LIBRARIES}
)

list(APPEND quantum_sources
  gate.cc
  gates_X_impl.cc
  gates_Y_impl.cc
  gates_Z_impl.cc
  gates_H_impl.cc
  gates_T_impl.cc
  gates_S_impl.cc
  gates_CNOT_impl.cc
  gates_junction_impl.cc
  controllers_Coprocessor_impl.cc
  controllers_Simulator_impl.cc
  controllers_Initializer_impl.cc
  controllers_readout_impl.cc
  controllers_wait_impl.cc
  controllers_sync_impl.cc
  measurements_Constellation_impl.cc
  measurements_Bloch_impl.cc
  measurements_Detector_impl.cc
)

set(quantum_sources "${quantum_sources}" PARENT_SCOPE)
if(NOT quantum_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT quantum_sources)

add_library(gnuradio-quantum SHARED ${quantum_sources})
target_link_libraries(gnuradio-quantum ${Boost_LIBRARIES} ${GNURADIO_ALL_LIBRARIES})
set_target_properties(gnuradio-quantum PROPERTIES DEFINE_SYMBOL "gnuradio_quantum_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-quantum PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-quantum RUNTIME_COMPONENT "quantum_runtime" DEVEL_COMPONENT "quantum_devel")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(
    ${CPPUNIT_INCLUDE_DIRS}
    ${QWT_INCLUDE_DIRS}
)

list(APPEND test_quantum_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_quantum.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_quantum.cc
)

add_executable(test-quantum ${test_quantum_sources})

target_link_libraries(
  test-quantum
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${Boost_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  ${QWT_LIBRARY_DIRS}
  gnuradio-quantum
)

GR_ADD_TEST(test_quantum test-quantum)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")

