#ifndef MARKET_DATA_API_HPP_
#define MARKET_DATA_API_HPP_

#if defined(LIBRARY_HEADER_ONLY)
#define LIBRARY_API inline
#elif defined(LIBRARY_EXPORT)
#define LIBRARY_API __declspec(dllexport)
#elif defined(LIBRARY_IMPORT)
#define LIBRARY_API __declspec(dllimport)
#else
#define LIBRARY_API
#endif

#endif