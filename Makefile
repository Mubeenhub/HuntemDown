FLAGS = -pedantic-errors -std=c++11

fight.o: fight.cpp fight.h
	g++ $(FLAGS) -c $<

menu.o: menu.cpp mymap.h Save.h
	g++ $(FLAGS) -c $<

map.o: map.cpp mymap.h fight.h Save.h
	g++ $(FLAGS) -c $<

Save.o: Save.cpp Save.h
	g++ $(FLAGS) -c $<

HuntemDown: fight.o menu.o map.o Save.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f HuntemDown fight.o menu.o map.o Save.o

.PHONY: clean
