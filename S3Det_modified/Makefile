

CC = g++

LIBRARY =Newmat10D/libnewmat.a cluster-1.49/src/libcluster.a -L./boost/lib
LIBRARY_STATIC=Newmat10D/libnewmat.a cluster-1.49/src/libcluster.a boost/lib/libboost_regex.a
INCLUDE =-I./Newmat10D -I./Subset_library/ -I./boost/include
LINK_DYNAMIC=-lm  -lboost_regex


default: all

all:
	tar -zxvf Newmat10D.tar.gz
	cd Newmat10D && tar -zxvf newmat10D.tar.gz
	cp Newmat10D/nm_gnu.mak Newmat10D/Makefile
	make -C Newmat10D

	tar -zxvf cluster-1.49.tar.gz
	cd ./cluster-1.49 && perl Makefile.PL
	make -C cluster-1.49
	
	tar -zxvf boost_1_42_0.tar.gz
	cd boost_1_42_0 && ./bootstrap.sh --prefix=../boost --with-libraries=regex
	cd boost_1_42_0 && ./bjam install
	cd boost_1_42_0/libs/regex/build && make -fgcc.mak
	cd boost_1_42_0/libs/regex/build/gcc && ln -s libboost_regex-gcc-1_42.a libboost_regex.a

	$(CC) -c -g Subset_library/subset.C -o Subset_library/subset.o

	# STATIC COMPILATION
	$(CC) -c S3det_for_Treedetserver_v2.2.cpp $(INCLUDE)
	$(CC) -o S3det_v2.2.exe S3det_for_Treedetserver_v2.2.o ./Subset_library/subset.o -lm $(LIBRARY_STATIC) 

	$(CC) -c MCdet_scores_v2.1.cpp $(INCLUDE)
	$(CC) -o MCdet_v2.1.exe MCdet_scores_v2.1.o -lm $(LIBRARY_STATIC)

	# DYNAMIC COMPILATION
	# $(CC) -o S3det_v2.1.exe S3det_for_Treedetserver_v2.1.o ./Subset_library/subset.o -lm $(LIBRARY) $(LINK_DYNAMIC)
	# $(CC) -o MCdet_v2.1.exe MCdet_scores_v2.1.o -lm $(LIBRARY) $(LINK_DYNAMIC)

# clean:
# 	make clean -C cluster-1.49
# 	make clean -C boost_1_42_0
# 	cd Newmat10D && rm *.o && rm libnewmat.a
# 	rm Subset_library/subset.o
# 	rm S3det_v2.1.exe
# 	rm MCdet_v2.1.exe