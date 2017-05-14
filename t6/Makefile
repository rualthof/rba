GTEST_DIR = /home/perfil/Desktop/rudi/googletest
GMOCK_DIR = /home/perfil/Desktop/rudi/googlemock
G_SOURCES = $(GTEST_DIR)/src/gtest-all.cc $(GMOCK_DIR)/src/gmock-all.cc

all:
	g++ -isystem ${GTEST_DIR}/include -isystem ${GMOCK_DIR}/include \
	-pthread test.cc libgmock.a 


compile:	
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
        -isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} \
        -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
		-isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} \
        -pthread -c ${GMOCK_DIR}/src/gmock-all.cc
	ar -rv libgmock.a gtest-all.o gmock-all.o
	
  	#ar -rv libgtest.a gtest-all.o

