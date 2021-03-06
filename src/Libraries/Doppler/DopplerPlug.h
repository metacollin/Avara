/*
    Copyright �1995, Juri Munkki
    All rights reserved.

    File: DopplerPlug.h
    Created: Friday, May 5, 1995, 16:21
    Modified: Friday, May 5, 1995, 18:34
*/

#pragma once
#include "SoundSystemDefines.h"

#define	DOPPLERPLUGSID	129

		void	ClearMemoryAreaC(long *theMem, long memCount);
typedef	void	ClearMemoryAreaFunc(long *theMem, long memCount);

typedef	short	RateMixerFunc(
				Sample			*source,
				WordSample		*dest,
				WordSample		*converter,
				short			outCount,
				long			endOffset,
				SampleIndex		*current,
				Fixed			theRate);

		short	RateMixer68K(
				Sample			*source,
				WordSample		*dest,
				WordSample		*converter,
				short			outCount,
				long			endOffset,
				SampleIndex		*current,
				Fixed			theRate);

		short	RateMixerC(
				Sample			*source,
				WordSample		*dest,
				WordSample		*converter,
				short			outCount,
				long			endOffset,
				SampleIndex		*current,
				Fixed			theRate);

typedef	void	InterleaveStereoChannelsFunc(
			WordSample	*leftCh,
			WordSample	*rightCh,
			WordSample	*blendTo,
			short		bufferSize);

		void	InterleaveStereoChannelsC(
			WordSample	*leftCh,
			WordSample	*rightCh,
			WordSample	*blendTo,
			short		bufferSize);


#ifdef DOPPLERPLUG
#ifdef THINK_C
	#if __option(a4_globals)
		#define	_INITVALUE_(a)
	#else
		#define	_INITVALUE_(a) = a
	#endif
#else
	#define	_INITVALUE_(a) = a
#endif

ClearMemoryAreaFunc				*ClearMemoryArea			_INITVALUE_(ClearMemoryAreaC);
RateMixerFunc					*RateMixer					_INITVALUE_(RateMixer68K);
InterleaveStereoChannelsFunc	*InterleaveStereoChannels	_INITVALUE_(NULL);
#else

extern	ClearMemoryAreaFunc				*ClearMemoryArea;
extern	RateMixerFunc					*RateMixer;
extern	InterleaveStereoChannelsFunc	*InterleaveStereoChannels;
#endif


enum
{	kPowerClearMemory,
	kPowerRateMixer,
	kPowerInterleave
};
