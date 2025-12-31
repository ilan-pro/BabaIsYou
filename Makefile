CPP = g++ -Wall -std=c++11 -fno-elide-constructors
GRAPH = -lsfml-graphics -lsfml-window -lsfml-system

MODEL_DIR = model
VIEW_DIR = vu
CTRL_DIR = controller

MODEL_SRC = $(wildcard $(MODEL_DIR)/*.cpp)
VIEW_SRC = $(wildcard $(VIEW_DIR)/*.cpp)
CTRL_SRC = $(wildcard $(CTRL_DIR)/*.cpp)

MODEL_OBJ = $(MODEL_SRC:.cpp=.o)
VIEW_OBJ = $(VIEW_SRC:.cpp=.o)
CTRL_OBJ = $(CTRL_SRC:.cpp=.o)

TARGET = baba_is_you

$(TARGET): $(MODEL_OBJ) $(CTRL_OBJ) $(VIEW_OBJ)
	$(CPP) $^ -o $@ $(GRAPH)

$(MODEL_DIR)/%.o: $(MODEL_DIR)/%.cpp
	$(CPP) -c $< -o $@

$(CTRL_DIR)/%.o: $(CTRL_DIR)/%.cpp
	$(CPP) -c $< -o $@

$(VIEW_DIR)/%.o: $(VIEW_DIR)/%.cpp
	$(CPP) -c $< -o $@

# mettre run ici si on ne veut pas que Make voit la cible directement et l'éxécute tout le temps 	
run: $(TARGET)
	./$(TARGET) 

clean:
	rm -f baba_is_you $(MODEL_OBJ) $(CTRL_OBJ) $(VIEW_OBJ) $(TARGET) 

.PHONY: clean run # faut faire attention à ce qu'il n'y ait pas de fichier de ce nom donc mettre phony