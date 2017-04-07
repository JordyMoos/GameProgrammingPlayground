#pragma once

#include <stdio.h>
#include <string>


#define GAME_LOGGING(str) \
	do \
	{ \
		printf("%s\n", std::string(str).c_str()); \
	} \
	while (0) \


#define GAME_LOG(str) \
	do \
	{ \
		printf("LOG: %s\n", std::string(str).c_str()); \
	} \
	while (0) \


#define GAME_INFO(str) \
	do \
	{ \
		printf("INFO: %s\n", std::string(str).c_str()); \
	} \
	while (0) \


#define GAME_WARNING(str) \
	do \
	{ \
		printf("WARNING: %s\n", std::string(str).c_str()); \
	} \
	while (0) \


#define GAME_ERROR(str) \
	do \
	{ \
		printf("ERROR: %s\n", std::string(str).c_str()); \
	} \
	while (0) \


#define GAME_FATAL(str) \
	do \
	{ \
		printf("FATAL: %s\n", std::string(str).c_str()); \
	} \
	while (0) \


#define GAME_ASSERT(expr) \
	do \
	{ \
		if (!(expr)) \
		{ \
			GAME_FATAL(#expr); \
		} \
	} \
	while (0) 


