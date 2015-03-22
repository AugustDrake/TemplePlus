
#pragma once

#include "addresses.h"

struct SubtitleLine {
	uint32_t startMs;
	uint32_t durationMs;
	D3DCOLOR color;
	char *fontname;
	char *text;
	SubtitleLine *nextLine;
};

struct MovieFuncs : AddressTable {	
	void(__cdecl *PlayLegalMovies)() = nullptr; // No longer used (see gamesystems.cpp)
	void(__cdecl *PlayMovie)(char* filename, int, int, int);
	void(__cdecl *PlayMovieSlide)(uint32_t, uint32_t, const SubtitleLine *subtitles, uint32_t, uint32_t);
	void(__cdecl *PlayMovieBink)(const char *filename, const SubtitleLine *subtitles, int flags, int soundtrackId);

	GlobalPrimitive<uint32_t, 0x103010F8> MovieVolume; // 0-127

	// Seems to suppress input event processing if true
	GlobalBool<0x10EF32A0> MovieIsPlaying;

	MovieFuncs() {
		rebase(PlayMovie, 0x10034100);
		rebase(PlayLegalMovies, 0x10003AC0);
		rebase(PlayMovieBink, 0x101F1BE0);
		rebase(PlayMovieSlide, 0x101F10F0);
	}

};

extern MovieFuncs movieFuncs;

void hook_movies();
