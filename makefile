CC = g++
CPPFLAGS = -std=c++20 -Wall -Wno-misleading-indentation -g

main: main.o game.o turnlist.o turn.o player.o damagecalc.o combatant.o wizard.o brawler.o rogue.o attack.o game.h

game.o: turnlist.o player.o damagecalc.o turnlist.h player.h damagecalc.h

turnlist.o: turn.o turn.h

turn.o:

player.o: combatant.o wizard.o brawler.o rogue.o combatant.h wizard.h brawler.h rogue.h

damagecalc.o:

combatant.o: attack.o damagecalc.o turn.o attack.h damagecalc.h turn.h

wizard.o: attack.o attack.h

brawler.o: attack.o attack.h

rogue.o: attack.o attack.h

attack.o:


tar: clean
	tar cvfz project1.tar.gz *.h *.cpp ?akefile

clean cls:
	rm -f main *.o *~ \#*

