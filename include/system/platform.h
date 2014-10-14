#ifndef PLATFORM_H
#define PLATFORM_H

//
//Note:
//
//Define pre-processor macroos for DLL expor import, and system macros
//

#ifdef _WIN32
	#define SYS_WINDOWS
	//defined to disable <window.h> from defining the min and max macros
	#ifndef NOMINMAX
	#define NOMINMAX
	#endif

#elif defined (__linux__)
#define SYS_LINUX
#elif defined (__APPLE__)
#define SYS_MACOS
#endif

#ifndef STATIC_BUILD
	#ifdef SYS_WINDOWS	
		#ifdef NONCLIENT_BUILD
			#define API _declspec(dllexport)
		#else
			#define API _declspec(dllimport)	
		#endif
		//visual c++ compiler warning C4251 disable
		#ifdef _MSC_VER
			#pragma warning(disable : 4251)
		#endif
	#elif defined(SYS_LINUX) || defined(SYS_LINUX)
		#ifdef __GNUC__ >= 4
			#define API __attribute__ ((__visibility__("default")))
		#else
			#define API API
		#endif
	#endif
#else
	#define API API
#endif

#endif