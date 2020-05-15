#pragma once

#include <Types.hpp>

#ifndef EXTERN
#    define EXTERN extern
#endif

#ifndef EXTERN_C
#    define EXTERN_C extern "C"
#endif

#ifdef GRAPHICS_NET_EXPORTS

#    ifndef GRAPHICS_NET_API_EXPORT
#        define GRAPHICS_NET_API_EXPORT __declspec(dllexport)
#    endif

#    ifndef GRAPHICS_NET_API_EXTERNC
#        define GRAPHICS_NET_API_EXTERNC EXTERN_C __declspec(dllexport)
#    endif

#    ifndef GRAPHICS_NET_API_EXTERN
#        define GRAPHICS_NET_API_EXTERN EXTERN __declspec(dllexport)
#    endif

#    ifndef GRAPHICS_NET_API_IMPORT
#        define GRAPHICS_NET_API_IMPORT __declspec(dllimport)
#    endif

#else

#    ifndef GRAPHICS_NET_API_EXPORT
#        define GRAPHICS_NET_API_EXPORT __declspec(dllimport)
#    endif

#    ifndef GRAPHICS_NET_API_EXTERNC
#        define GRAPHICS_NET_API_EXTERNC EXTERN_C __declspec(dllimport)
#    endif

#    ifndef GRAPHICS_NET_API_EXTERN
#        define GRAPHICS_NET_API_EXTERN EXTERN __declspec(dllimport)
#    endif

#    ifndef GRAPHICS_NET_API_IMPORT
#        define GRAPHICS_NET_API_IMPORT __declspec(dllexport)
#    endif

#endif
