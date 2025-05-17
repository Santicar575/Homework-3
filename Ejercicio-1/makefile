local:
	g++ -std=c++20 -g -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wshadow -Wdouble-promotion -Wformat=2 -Wnull-dereference -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast -Wcast-align -Wfloat-equal -Wundef -Wswitch-enum -Wswitch-default -Wmissing-declarations -Wredundant-decls -Wstrict-overflow=5 -Werror -o main main.cpp src/*.cpp -Iinclude
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
	rm main