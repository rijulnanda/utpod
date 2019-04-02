final: UtPodDriver.o UtPod.o Song.o
	 g++ -o driver UtPodDriver.o UtPod.o Song.o
UtPodDriver.o: UtPodDriver.cpp UtPod.h Song.h
	g++ -c UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp
