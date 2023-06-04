the_tests:
	clear
	clang++ -std=c++11 tests/test.c++ -o objects/test



run_tests:
	clear
	./objects/test



check_leaks:
	clear
	leaks -atExit -- ./objects/test | grep LEAK:
	# rm *LEAK*