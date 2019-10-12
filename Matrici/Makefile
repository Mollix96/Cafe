#
# Opzioni per il compilatore.
# === STANDARD ===
# Per compilare seguendo lo standard ANSI C usare -ansi oppure -std=c89
#
# === OPTIMIZATION ===
# Default:    -O0
# Livello 1:  -O1
# Livello 2:  -O2 # NOTA: la tail-recursion viene ottimizzata a partire da questo livello.
# Livello 3:  -O3
#
# === DEBUG_MODE ===
# Se impostato come true, aggiunge l'opzione -g.
#
COMPILER     = g++
STANDARD     = -std=c++14
OPTIMIZATION = -O0
DEBUG_MODE   = false
OTHERS       = -pedantic-errors -Wall -Werror -Wextra

#
# Librerie.
#
LIBRARIES    = -lc

#
# Nome dell'eseguibile.
#
EXECUTABLE   = run_me.exe

#
# File sorgente e file oggetto.
#
C_SOURCES    = main.cpp matrice.cpp
C_OBJECTS    = $(C_SOURCES:.c=.o)



#
# Concatena le opzioni.
#
OPTIONS      = ${STANDARD} ${OPTIMIZATION} ${OTHERS}

# Controllo debug mode.
ifeq ($(DEBUG_MODE), true)
	OPTIONS  += -g
endif



#
# Build.
#
all: $(EXECUTABLE)

$(EXECUTABLE): $(C_OBJECTS)
	$(COMPILER) $(OPTIONS) -o $@ $(C_OBJECTS) $(LIBRARIES)
        
%.o:    %.c
	$(COMPILER) $(OPTIONS) -c $<



#
# Clean.
#
clean:
	rm -f *.o
