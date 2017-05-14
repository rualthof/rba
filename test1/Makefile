GTEST_DIR = /home/perfil/Desktop/rudi/googletest-release-1.7.0

all:
	#rm xx
	clear
	g++ main.cc -o xx -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) gtest-all.o -pthread -std=c++11
	./xx

compile:
	g++ -c $(GTEST_DIR)/src/gtest-all.cc -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread 


	
  	#ar -rv libgtest.a gtest-all.o

