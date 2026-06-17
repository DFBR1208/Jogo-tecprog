#include "Jogo.h"
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	Kawabanga::Jogo meujogo;
	meujogo.executar();
	return 0;
}