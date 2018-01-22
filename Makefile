roomba: simulate_roomba.cpp RandomRoomba.cpp SmartRandom.cpp SmarterRandom.cpp SmarterRandom.h SmartRandom.h Floor.hpp RandomRoomba.h Room.hpp Roomba.hpp 
	g++ -g simulate_roomba.cpp RandomRoomba.cpp SmartRandom.cpp SmarterRandom.cpp -o roomba

clean:
	rm roomba