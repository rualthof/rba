GTEST_DIR = /home/perfil/Desktop/rba/googletest
GMOCK_DIR = /home/perfil/Desktop/rba/googlemock

G_SOURCES = $(GTEST_DIR)/src/gtest-all.cc $(GMOCK_DIR)/src/gmock-all.cc

TESTFILE = queue_test.cc

example:
	g++ -isystem ${GTEST_DIR}/include -isystem ${GMOCK_DIR}/include \
	-pthread ${TESTFILE} libgmock.a 

compile:	
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
        -isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} \
        -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
		-isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} \
        -pthread -c ${GMOCK_DIR}/src/gmock-all.cc
	
	ar -rv libgmock.a gtest-all.o gmock-all.o
	
  	#ar -rv libgtest.a gtest-all.o

