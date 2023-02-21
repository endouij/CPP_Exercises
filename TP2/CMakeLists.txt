
add_executable(translator
    translator.cpp
)

target_compile_features(translator PRIVATE cxx_std_17)
target_compile_options(translator PRIVATE
	-Wall
	-Wextra
	-Werror
)
