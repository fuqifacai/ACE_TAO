
// -*- C++ -*-
// Plan_Analyzer_svnt_export.h,v 1.1 2005/09/06 19:57:22 wotte Exp
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl PLAN_ANALYZER_SVNT
// ------------------------------
#ifndef PLAN_ANALYZER_SVNT_EXPORT_H
#define PLAN_ANALYZER_SVNT_EXPORT_H

#include "ace/config-all.h"

#if !defined (PLAN_ANALYZER_SVNT_HAS_DLL)
#  define PLAN_ANALYZER_SVNT_HAS_DLL 1
#endif /* ! PLAN_ANALYZER_SVNT_HAS_DLL */

#if defined (PLAN_ANALYZER_SVNT_HAS_DLL) && (PLAN_ANALYZER_SVNT_HAS_DLL == 1)
#  if defined (PLAN_ANALYZER_SVNT_BUILD_DLL)
#    define PLAN_ANALYZER_SVNT_Export ACE_Proper_Export_Flag
#    define PLAN_ANALYZER_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define PLAN_ANALYZER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* PLAN_ANALYZER_SVNT_BUILD_DLL */
#    define PLAN_ANALYZER_SVNT_Export ACE_Proper_Import_Flag
#    define PLAN_ANALYZER_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define PLAN_ANALYZER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* PLAN_ANALYZER_SVNT_BUILD_DLL */
#else /* PLAN_ANALYZER_SVNT_HAS_DLL == 1 */
#  define PLAN_ANALYZER_SVNT_Export
#  define PLAN_ANALYZER_SVNT_SINGLETON_DECLARATION(T)
#  define PLAN_ANALYZER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* PLAN_ANALYZER_SVNT_HAS_DLL == 1 */

// Set PLAN_ANALYZER_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (PLAN_ANALYZER_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define PLAN_ANALYZER_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define PLAN_ANALYZER_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !PLAN_ANALYZER_SVNT_NTRACE */

#if (PLAN_ANALYZER_SVNT_NTRACE == 1)
#  define PLAN_ANALYZER_SVNT_TRACE(X)
#else /* (PLAN_ANALYZER_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define PLAN_ANALYZER_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (PLAN_ANALYZER_SVNT_NTRACE == 1) */

#endif /* PLAN_ANALYZER_SVNT_EXPORT_H */

// End of auto generated file.
