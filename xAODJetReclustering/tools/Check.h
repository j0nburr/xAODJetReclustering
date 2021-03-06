// Dear emacs, this is -*- c++ -*-
#ifndef xAODJetReclustering_TOOLS_CHECK_H
#define xAODJetReclustering_TOOLS_CHECK_H

// ROOT include(s):
#include <TError.h>

#include <xAODJetReclustering/tools/Message.h>
#include <AsgTools/StatusCode.h>

/// Helper macro for checking return codes in a compact form in the code
///
/// This is pretty much a rip-off of the (ATH_)CHECK macros of the offline
/// code. It is used in the package in functions that return a TReturnCode,
/// and themselves call functions returning TReturnCode.
///
/// @param CONTEXT A context string to print an error message on failure
/// @param EXP The expression to execute in a checked manner
/// @param INFO Extra information to print with the error message to debug
///
#define CHECK( CONTEXT, EXP )                                              \
   do {                                                                    \
      if( ! EXP.isSuccess() ) {                                            \
         ::Error( CONTEXT, XAOD_MESSAGE( "Failed to execute: %s\n" ),      \
                  #EXP );                                                  \
         return StatusCode::FAILURE;                                       \
      }                                                                    \
   } while( false )

#endif // xAODJetReclustering_TOOLS_CHECK_H

