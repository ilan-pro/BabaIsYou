# Compilateur et flags
CPP      = g++
CFLAGS   = -Wall -std=c++11 -fno-elide-constructors
GRAPH    = -lsfml-graphics -lsfml-window -lsfml-system

# Répertoires
MODEL_DIR  = model
CTRL_DIR   = controller
VIEW_DIR   = vu

# Sources
MODEL_SRC = $(wildcard $(MODEL_DIR)/*.cpp)
CTRL_SRC  = $(wildcard $(CTRL_DIR)/*.cpp)
VIEW_SRC  = $(wildcard $(VIEW_DIR)/*.cpp)

# Objets
MODEL_OBJ = $(MODEL_SRC:.cpp=.o)
CTRL_OBJ  = $(CTRL_SRC:.cpp=.o)
VIEW_OBJ  = $(VIEW_SRC:.cpp=.o)

# Cible finale
TARGET = baba_is_you

# Règle principale
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(MODEL_OBJ) $(CTRL_OBJ) $(VIEW_OBJ)
	$(CPP) $(CFLAGS) $^ -o $@ $(GRAPH)

# Compilation des fichiers .cpp en .o
$(MODEL_DIR)/%.o: $(MODEL_DIR)/%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(CTRL_DIR)/%.o: $(CTRL_DIR)/%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(VIEW_DIR)/%.o: $(VIEW_DIR)/%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(MODEL_OBJ) $(CTRL_OBJ) $(VIEW_OBJ) $(TARGET)

.PHONY: all clean
