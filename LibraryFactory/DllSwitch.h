#pragma once

#ifdef LIBRARYFACTORY_EXPORTS
#define LIBRARYFACTORY_API __declspec(dllexport)
#else
#define LIBRARYFACTORY_API __declspec(dllimport)
#endif