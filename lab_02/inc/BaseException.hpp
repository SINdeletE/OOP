#pragma once

#include <stdio.h>
#include <exception>
#include <ctime>

class BaseError: public std::exception
{
	public:
		BaseError(const char *filename,
				const char *classname,
				long line,
				const char* time,
				const char* error_info = "Base Error!") noexcept
		{
			sprintf(error_text, "FILE: %s LINE: %ld CLASS: %s TIME: %s\n"
                                "ERROR TEXT: %s",
                            filename, line, classname, time, error_info);
		}

		~BaseError() override = default;

		[[nodiscard]] const char *what() const noexcept override
		{
			return error_text;
		}

	protected:
        static constexpr const long error_text_size = 512;
		char error_text[error_text_size] {};
};

