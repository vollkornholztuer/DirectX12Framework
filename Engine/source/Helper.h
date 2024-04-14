#pragma once
#include <exception>

#define YT_EVAL_HR(hr, error) if ((hr) != S_OK) { std::cout << "API Error: " << error << " At file: " << __FILE__ << std::endl; }
#define PRINT_W_N(message) std::wcout << message << std::endl;
	// Print WCHAR (W) in new line (N)
#define PRINT_N(message) std::cout << message << std::endl; // regular print

#ifdef _DEBUG
#define YT_ASSERT(exp) if (!(exp)) { std::cout << "Critical error in file: " << __FILE__ << std::endl; throw; }
#else 
#define YT_ASSERT(exp)
#endif // _DEBUG